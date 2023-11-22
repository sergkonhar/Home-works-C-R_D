// Task#7 : Home work 


#include <iostream>
#include <iomanip>

int main()
{

	// Task#8 

	std::cout << "\n\nTask#7\n\n";

	int bestResult = 0;
	int predictionValue = 0;
	int attempts = 0;
	int valueToPridict = 0;
	const int maxValue = 50;
	


	while (true) {

		int attempts = 0;
		std::srand(std::time(nullptr));

		valueToPridict = std::rand() % (maxValue + 1);


		std::cout << "Game Start" << std::endl;
		std::cout << "You need predict the number" << std::endl;
		std::cout << "Input your prediction between 0 and 50 (For exit input -1): ";
		std::cin >> predictionValue;
		std::cout << std::endl;


		if (predictionValue == -1) {
			std::cout << "\nExit from game" << std::endl;
			break;

		}
		else if (predictionValue > 50 || predictionValue < -1)
		{
			std::cout << "\nIncorrect value start from beginning" << std::endl;
			continue;



		}

		else
		{
			

			while (true)
			{
				std::cout << valueToPridict;
				
				if (predictionValue == -1) {
					std::cout << "\nExit round" << std::endl;
					break;

				}
				else if (predictionValue > 50 || predictionValue < -1)
				{
					std::cout << "\nIncorrect value start round over" << std::endl;
					std::cout << "\nInput value: ";
					std::cin >> predictionValue;
					std::cout << std::endl;
					continue;



				}






				if (predictionValue == valueToPridict)
				{
					attempts += 1;

					std::cout << "\nYou Win" << std::endl;

					std::cout << "Attempts: " << attempts << std::endl;

					if (bestResult == 0)
					{
						bestResult = attempts;
						std::cout << "Your best result is: " << bestResult << std::endl;
						break;
					}
					else if (attempts >= bestResult)
					{
						std::cout << "Your best result is: " << bestResult << std::endl;
						break;
					}
					else
					{
						bestResult = attempts;
						std::cout << "Your best result is: " << bestResult << std::endl;
						break;

					}

				}

				else if (predictionValue > valueToPridict && predictionValue - valueToPridict >= 20)
				{

					std::cout << "\nIncorrect value and it's way bigger than should be" << std::endl;
					std::cout << "Try again: ";
					std::cin >> predictionValue;
					attempts += 1;
					continue;
				}

				else if (predictionValue > valueToPridict && predictionValue - valueToPridict >= 10)
				{

					std::cout << "\nIncorrect value and it's slaightly bigger than should be" << std::endl;
					std::cout << "Try again: ";
					std::cin >> predictionValue;
					attempts += 1;
					continue;

				}

				else if (predictionValue < valueToPridict && valueToPridict - predictionValue >= 20)
				{

					std::cout << "\nIncorrect value and it's way lesser than should be" << std::endl;
					std::cout << "Try again: ";
					std::cin >> predictionValue;
					attempts += 1;
					continue;

				}

				else if (predictionValue < valueToPridict && valueToPridict - predictionValue >= 10)
				{

					std::cout << "\nIncorrect value and it's slaightly lesser than should be" << std::endl;
					std::cout << "Try again: ";
					std::cin >> predictionValue;
					attempts += 1;
					continue;

				}

				else if (valueToPridict < predictionValue)
				{

					std::cout << "\nIncorrect value and it's just a bit bigger than should be" << std::endl;
					std::cout << "Try again: ";
					std::cin >> predictionValue;
					attempts += 1;
					continue;

				}

				else
				{
					std::cout << "\nIncorrect value and it's just a bit lesser than should be" << std::endl;
					std::cout << "Try again: ";
					std::cin >> predictionValue;
					attempts += 1;
					continue;
				}

			}

		}








	}
	
	
	
}

