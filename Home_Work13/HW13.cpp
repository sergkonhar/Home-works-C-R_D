#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>

enum class readParameters //defines which string to read from save file
{
	Date,
	Word,
	Status
};

void printMainMenu();
void printGameStartedMenu(int attempts);
std::string mainModeErrors(std::string mainModeChoise);
std::string gameModeErrors(std::string inputString, int wordLength);
std::string intermidiateWordResult(std::string inputString, std::string guessWord, const int wordLength);
std::string generateWord(const std::string WordsFile, const int WordsCount, const int wordLengt);
void unmatchedLettersList(std::string inputString, std::string guessWord, const int wordLength, std::string& usedUnmatchLetters);
bool checkWinCondition(std::string guessWord, std::string resultAfterGuess, const int wordLength);
void printNewRoundMenu(std::string inputString, std::string resultAfterGuess, std::string usedUnmatchLetters, int currentAttemptsCounter);
void printWinMenu(std::string guessWord, const int maxAttempts, int currentAttemptsCounter);
void printlossMenu(std::string guessWord, std::string mainModeChoise);
void printError(std::string errors);
std::string readSavedData(std::string saveDataToFile, readParameters parameterToRead);
std::string getCurrentDate();
void writeSaveData(std::string date, std::string word, std::string status, const std::string saveDataToFile);

int main()
{
	const int usualWordsCount = 212; //number of words for usual mode, changing this requires changing number of words in data base
	const int wordsOfTheDayCount = 219; //number of words for word of the day mode, changing this requires changing number of words in data base
	const int wordLength = 5; //word length, changing this requires to update words data base
	const int maxAttempts = 10; //number of attempts to guess the word

	const std::string usualWordsFile = "UsualWords.txt"; //file with words data base
	const std::string wordOfTheDayFile = "DayWord.txt"; //file with words data base
	const std::string saveDataToFile = "SaveData.txt"; //file with save data

	while (true)
	{
		std::string today = getCurrentDate(); 

		printMainMenu();

		std::string mainModeChoise = "";
		std::cin >> mainModeChoise;
		std::cin.ignore(1000, '\n');
		std::string mainModeError = mainModeErrors(mainModeChoise); // form the eeror string


		std::string guessWord = "";
		std::string wordOfTheDayGuessStatus = "false"; 

		if (mainModeError != "") //if error string now empty this mean there are error and program will restart
		{
			printError(mainModeError);
			continue;
		}

		else if (mainModeChoise == "0")  // if parameter is 0 program will ends
		{
			return 0;
		}

		else if (mainModeChoise == "1") //if parameter is 1 usual mode will start and generate guess word each time new
		{
			guessWord = generateWord(usualWordsFile, usualWordsCount, wordLength);
			std::cout << std::endl;
			std::cout << "!!!Usual Mode!!!";
		}

		else if (mainModeChoise == "2") //if parameter is 2 word of the day mode will start
		{
			std::cout << std::endl;
			std::cout << "!!!Word of the Day Mode!!!";
			std::string gameDate = readSavedData(saveDataToFile, readParameters::Date);

			if (gameDate == today) //check if this mode was started today
			{
				std::string gameStatus = readSavedData(saveDataToFile, readParameters::Status);
				if (gameStatus == "true") //check if the word was guessed in case of true will print "return tomorrow" in case of false read the word to guess from file
				{
					std::cout << std::endl;
					std::cout << "The Word of the day alredy guessed return tomorrow";
					std::cout << std::endl;
					continue;
				}
				else
				{
					guessWord = readSavedData(saveDataToFile, readParameters::Word);
				}
			}
			else //if mode was not started today then generate new word, update date, update status with false and change the word
			{
				
				guessWord = generateWord(wordOfTheDayFile, wordsOfTheDayCount, wordLength);
				writeSaveData(today, guessWord, wordOfTheDayGuessStatus, saveDataToFile);
			}

		}
		int currentAttemptsCounter = maxAttempts;
		
		std::string usedUnmatchLetters = "";
		printGameStartedMenu(maxAttempts);
		
		while (true)
		{
			if (currentAttemptsCounter == 0)
			{
				printlossMenu(guessWord, mainModeChoise);
				break;
			}

			std::cout << std::endl;
			std::cout << "Your input: ";
			std::string inputString = "";
			std::cin >> inputString;
			std::cin.ignore(1000, '\n');
			std::string gameModeError = gameModeErrors(inputString, wordLength); //form the string with error in guessing phase

			if (gameModeError != "") // if errors present in input show the eeror message and not count as attempt
			{
				printError(gameModeError);
				continue;
			}

			else if (inputString == "0") // if input is 0 then return to main menu
			{
				std::cout << std::endl;
				std::cout << "Starting Over";
				std::cout << std::endl;
				break;
			}

			else
			{
				currentAttemptsCounter--;

				for (int i = 0; i < wordLength; i++) //transform all input letters to lower case for comparison
				{
					inputString[i] = tolower(inputString[i]);
				}

				unmatchedLettersList(inputString, guessWord, wordLength, usedUnmatchLetters); //fprm the list of words that not in the word
				std::string resultAfterGuess = intermidiateWordResult(inputString, guessWord, wordLength); //create intermidiate string

				bool winCondition = checkWinCondition(guessWord, resultAfterGuess, wordLength); //check if the word is guessed

				if (!winCondition) //if word no guessed than printing new round menu
				{
					printNewRoundMenu(inputString, resultAfterGuess, usedUnmatchLetters, currentAttemptsCounter);
				}
				else //if word guessed print win menu and update save file with true status if mode wa word of the day
				{
					printWinMenu(guessWord, maxAttempts, currentAttemptsCounter);
					if (mainModeChoise == "2")
					{
						wordOfTheDayGuessStatus = "true";
						writeSaveData(today, guessWord, wordOfTheDayGuessStatus, saveDataToFile);
					}
					break;
				}
			}
		}

	}
}

void printMainMenu()
{
	std::cout << std::endl;
	std::cout << "!Hello this is Wordl Game!" << std::endl;
	std::cout << "For start game in usual mode Enter 1" << std::endl;
	std::cout << "For start game in Word of the day mode Enter 2" << std::endl;
	std::cout << "For exit the game Enter 0" << std::endl;
	std::cout << "Your input: ";
}

void printGameStartedMenu(int attempts)
{
	std::cout << std::endl;
	std::cout << "Yor word generated try to guess it in " << attempts << " attempts" << std::endl;
	std::cout << "To start game enter your guess" << std::endl;
	std::cout << "To return to presious menu enter 0" << std::endl;
	std::cout << "If the letter in result is uppercase this mean it correctlly guessed" << std::endl;
	std::cout << "If the letter in result is lowercase this mean it in wrong place" << std::endl;
}

std::string mainModeErrors(std::string mainModeChoise)
{
	std::string inputErrors = "";
	
	bool inputContainsLettersOrSpecialChar = std::any_of(mainModeChoise.begin(), mainModeChoise.end(), [](char a) {if (!std::isdigit(a)) { return true; } return false; });
	bool lengthNotEqualOne = (mainModeChoise.length() != 1);
	bool wrongNumber = (mainModeChoise != "0" && mainModeChoise != "1" && mainModeChoise != "2");

	if (lengthNotEqualOne)
	{
		inputErrors = " Input has wrong length ";
	}

	else if (inputContainsLettersOrSpecialChar)
	{
		inputErrors = " Input contain letters or special characters ";
	}

	else if (wrongNumber)
	{
		inputErrors = " Wrong control value ";
	}

	return inputErrors;
}

std::string gameModeErrors(std::string inputString, int wordLength)
{
	std::string inputErrors = "";
	bool inputContainsDigitsOrSpecialChar = std::any_of(inputString.begin(), inputString.end(), [](char a) {if (!std::isalpha(a)) { return true; } return false; });
	bool lengthNotEqualFive = (inputString.length() != wordLength);
	bool lengthNotEqualOne = (inputString.length() != 1);
	bool wrongNumber = (inputString != "0");

	if (lengthNotEqualFive && lengthNotEqualOne)
	{
		inputErrors = " Input has wrong length ";
	}

	else if (inputContainsDigitsOrSpecialChar && lengthNotEqualOne)
	{
		inputErrors = " Input contain digits or special characters ";
	}

	else if (wrongNumber && !lengthNotEqualOne && !inputContainsDigitsOrSpecialChar)
	{
		inputErrors = " Wrong control value ";
	}

	else if (wrongNumber && !lengthNotEqualOne && inputContainsDigitsOrSpecialChar)
	{
		inputErrors = "  Input contain digits or special characters ";
	}

	return inputErrors;
}

std::string generateWord(const std::string WordsFile, const int WordsCount, const int wordLengt)
{
	std::srand(std::time(nullptr)); //generate random number
	const double wordNumber = std::rand() % WordsCount;

	std::fstream inputFile; 
	inputFile.open(WordsFile, std::ios::in);

	if (!inputFile)
	{
		std::cout << "Critical Error File With Words Not Found";
		return "";
	}

	std::string generatedString = "";

	for (int i = 0; i < WordsCount; i++) //read requaired line from file
	{
		inputFile >> generatedString;
		if (i == static_cast<int> (wordNumber))
		{
			break;
		}
	}
	for (int i = 0; i < wordLengt; i++)
	{
		generatedString[i] = tolower(generatedString[i]);
	}
	return generatedString;
}

std::string intermidiateWordResult(std::string inputString, std::string guessWord, const int wordLength)
{
	std::string resultAfterGuess(wordLength, '*'); //generate string consist of *

	for (int i = 0; i < wordLength; i++) //check is there any correct letters in correct position
	{
		if (guessWord[i] == inputString[i])
		{
			resultAfterGuess[i] = toupper(inputString[i]);
		}
	}

	for (int i = 0; i < wordLength; i++) //check is there any correct letters in wrong position
	{
		if (!isupper(resultAfterGuess[i]))
		{
			for (int j = 0; j < wordLength; j++)
			{
				if (guessWord[i] == inputString[j] && resultAfterGuess[j] == '*')
				{
					resultAfterGuess[j] = inputString[j];
					break;
				}
			}
		}
	}
	return resultAfterGuess;
}

void unmatchedLettersList(std::string inputString, std::string guessWord, const int wordLength, std::string& usedUnmatchLetters)
{
	for (int i = 0; i < wordLength; i++) //check if letter present in the word if not check if it already in unmatched letters string
	{
		char toTest = inputString[i];
		bool toGuessStringContainsLetter = std::any_of(guessWord.begin(), guessWord.end(), [toTest](char a) {return toTest == a; });
		bool usedUnmatchContainsLetter = std::any_of(usedUnmatchLetters.begin(), usedUnmatchLetters.end(), [toTest](char a) {return toTest == a; });

		if (!toGuessStringContainsLetter)
		{
			if (!usedUnmatchContainsLetter)
			{
				usedUnmatchLetters += inputString[i];
				usedUnmatchLetters += " ";
			}
		}
	}
}

bool checkWinCondition(std::string guessWord, std::string resultAfterGuess, const int wordLength)
{
	for (int i = 0; i < wordLength; i++)
	{
		if (guessWord[i] != tolower(resultAfterGuess[i]))
		{
			return false;
		}
	}
	return true;
}

void printNewRoundMenu(std::string inputString, std::string resultAfterGuess, std::string usedUnmatchLetters, int currentAttemptsCounter)
{
	std::cout << std::endl;
	std::cout << "Your string: " << inputString << std::endl;
	std::cout << "Result string: " << resultAfterGuess << std::endl;
	std::cout << "Letters that not in the word to guess: " << usedUnmatchLetters << std::endl;
	std::cout << "Attempts left: " << currentAttemptsCounter << std::endl;
	std::cout << std::endl;
}

void printWinMenu(std::string guessWord, const int maxAttempts, int currentAttemptsCounter)
{
	std::cout << std::endl;
	std::cout << "You win in " << maxAttempts - currentAttemptsCounter << " Attempts " << " The word was " << "\"" << guessWord << "\"";
	std::cout << std::endl;
}

void printlossMenu(std::string guessWord, std::string mainModeChoise)
{
	std::cout << std::endl;
	std::cout << "No attempts left try again" << std::endl;
	if (mainModeChoise=="1")
	{
		std::cout << "The Word was " << "\"" << guessWord << "\"";
	}	
	std::cout << std::endl;
}

void printError(std::string errors)
{
	std::cout << std::endl;
	std::cout << "Input is incorrect, error: " << errors << std::endl;;
	std::cout << "Try reinput";
	std::cout << std::endl;
}

std::string readSavedData(std::string saveDataToFile, readParameters parameterToRead)
{
	std::string stringData = "";
	std::fstream inputFile;
	inputFile.open(saveDataToFile, std::ios::in);
	if (!inputFile)
	{
		std::cout << "Critical Error File With Save Not Found";
		return "";
	}
	else if (parameterToRead == readParameters::Date)
	{
		inputFile >> stringData;
		inputFile.close();
		return stringData;
	}
	else if (parameterToRead == readParameters::Word)
	{
		inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		inputFile >> stringData;
		inputFile.close();
		return stringData;


	}
	else if (parameterToRead == readParameters::Status)
	{
		inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		inputFile >> stringData;
		inputFile.close();
		return stringData;
	}
	return "";
}

std::string getCurrentDate()
{
	std::string currentDate = "";
	std::time_t currentTime = std::time(nullptr);
	std::tm* localTime = localtime(&currentTime);
	int year = static_cast<int>(localTime->tm_year) + 1900;
	int month = static_cast<int>(localTime->tm_mon) + 1;
	int day = static_cast<int>(localTime->tm_mday);
	currentDate = (std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year));
	return currentDate;
}

void writeSaveData(std::string date, std::string word, std::string status, const std::string saveDataToFile)
{
	std::fstream outputFile;
	outputFile.open(saveDataToFile, std::ios::out);
	if (!outputFile)
	{
		std::cout << "Critical Error File With Save Not Found";
	}
	else 
	{
		outputFile << date;
		outputFile << "\n";
		outputFile << word;
		outputFile << "\n";
		outputFile << status;
		outputFile << "\n";
		outputFile.close();
	}
}
