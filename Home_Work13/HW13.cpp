#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>

enum class readParameters
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
bool checkWinCindition(std::string guessWord, std::string resultAfterGuess, const int wordLength);
void printNewRoundMenu(std::string inputString, std::string resultAfterGuess, std::string usedUnmatchLetters, int currentAttemptsCounter);
void printWinMenu(std::string guessWord, const int maxAttempts, int currentAttemptsCounter);
void printlossMenu(std::string guessWord);
void printError(std::string errors);
std::string readSavedData(std::string saveDataToFile, readParameters parameterToRead);
std::string getCurrentDate();
void writeSaveData(std::string date, std::string word, std::string status, const std::string saveDataToFile);

int main()
{
	const int usualWordsCount = 212;
	const int wordsOfTheDayCount = 219;
	const int wordLength = 5;
	const int maxAttempts = 10;

	const std::string usualWordsFile = "UsualWords.txt";
	const std::string wordOfTheDayFile = "DayWord.txt";
	const std::string saveDataToFile = "SaveData.txt";

	std::string today = getCurrentDate();

	while (true)
	{
		printMainMenu();

		std::string mainModeChoise = "";
		std::cin >> mainModeChoise;
		std::cin.ignore(1000, '\n');
		std::string mainModeError = mainModeErrors(mainModeChoise);


		std::string guessWord = "";
		std::string wordOfTheDayGuessStatus = "false";

		if (mainModeError != "")
		{
			printError(mainModeError);
		}

		else if (mainModeChoise == "0")
		{
			return 0;
		}

		else if (mainModeChoise == "1")
		{
			guessWord = generateWord(usualWordsFile, usualWordsCount, wordLength);
			std::cout << std::endl;
			std::cout << "!!!Usual Mode!!!";
		}

		else if (mainModeChoise == "2")
		{
			std::cout << std::endl;
			std::cout << "!!!Word of the Day Mode!!!";
			std::string gameDate = readSavedData(saveDataToFile, readParameters::Date);

			if (gameDate == today)
			{
				std::string gameStatus = readSavedData(saveDataToFile, readParameters::Status);
				if (gameStatus == "true")
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
			else
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
				printlossMenu(guessWord);
				break;
			}

			std::cout << std::endl;
			std::cout << "Your input: ";
			std::string inputString = "";
			std::cin >> inputString;
			std::cin.ignore(1000, '\n');
			std::string gameModeError = gameModeErrors(inputString, wordLength);

			if (gameModeError != "")
			{
				printError(gameModeError);
			}

			else if (inputString == "0")
			{
				std::cout << std::endl;
				std::cout << "Starting Over";
				std::cout << std::endl;
				break;
			}

			else
			{
				currentAttemptsCounter--;

				for (int i = 0; i < wordLength; i++)
				{
					inputString[i] = tolower(inputString[i]);
				}

				unmatchedLettersList(inputString, guessWord, wordLength, usedUnmatchLetters);
				std::string resultAfterGuess = intermidiateWordResult(inputString, guessWord, wordLength);

				bool winCondition = checkWinCindition(guessWord, resultAfterGuess, wordLength);

				if (!winCondition)
				{
					printNewRoundMenu(inputString, resultAfterGuess, usedUnmatchLetters, currentAttemptsCounter);
				}
				else
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
	bool inputContainsLetters = std::any_of(mainModeChoise.begin(), mainModeChoise.end(), std::isalpha);
	bool lengthNotEqualOne = (mainModeChoise.length() != 1);
	bool wrongNumber = (mainModeChoise != "0" && mainModeChoise != "1" && mainModeChoise != "2");

	if (lengthNotEqualOne)
	{
		inputErrors = " Input has wrong length ";
	}

	else if (inputContainsLetters)
	{
		inputErrors = " Input contain letters ";
	}

	else if (wrongNumber)
	{
		inputErrors = " Wrong number ";
	}

	return inputErrors;
}

std::string gameModeErrors(std::string inputString, int wordLength)
{
	std::string inputErrors = "";
	bool inputContainsDigits = std::any_of(inputString.begin(), inputString.end(), std::isdigit);
	bool lengthNotEqualFive = (inputString.length() != wordLength);
	bool lengthNotEqualOne = (inputString.length() != 1);
	bool wrongNumber = (inputString != "0");

	if (lengthNotEqualFive && lengthNotEqualOne)
	{
		inputErrors = " Input has wrong length ";
	}

	else if (inputContainsDigits && lengthNotEqualOne)
	{
		inputErrors = " Input contain digits ";
	}

	else if (wrongNumber && !lengthNotEqualOne)
	{
		inputErrors = " Wrong control value ";
	}

	return inputErrors;
}

std::string generateWord(const std::string WordsFile, const int WordsCount, const int wordLengt)
{
	std::srand(std::time(nullptr));
	const double wordNumber = std::rand() % WordsCount;

	std::fstream inputFile;
	inputFile.open(WordsFile, std::ios::in);

	if (!inputFile)
	{
		std::cout << "Critical Error File With Words Not Found";
		return "";
	}

	std::string generatedString = "";

	for (int i = 0; i < WordsCount; i++)
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
	std::string resultAfterGuess(wordLength, '*');

	for (int i = 0; i < wordLength; i++)
	{
		if (guessWord[i] == inputString[i])
		{
			resultAfterGuess[i] = toupper(inputString[i]);
		}
	}

	for (int i = 0; i < wordLength; i++)
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
	for (int i = 0; i < wordLength; i++)
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

bool checkWinCindition(std::string guessWord, std::string resultAfterGuess, const int wordLength)
{
	for (int i = 0; i < wordLength; i++)
	{
		if (guessWord[i] != tolower(resultAfterGuess[i]))
		{
			return false;
		}
		else if (i == wordLength - 1)
		{
			return true;
		}
	}
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

void printlossMenu(std::string guessWord)
{
	std::cout << std::endl;
	std::cout << "No attempts left try again" << std::endl;
	std::cout << "The Word was " << "\"" << guessWord << "\"";
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
