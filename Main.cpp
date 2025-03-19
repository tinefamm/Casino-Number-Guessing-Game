#include <iostream>
#include <random>
#include <math.h>
#include <ctype.h>

// To have a better randomity, I've tried this generation
std::random_device rd; 
std::mt19937 mt(rd());

class Casino
{
private:
	int difficulty;
	float bet;
	int random_number;
public:
	Casino(int difficulty, float bet) // Every time an Object is createad, it generate his random number
		: difficulty(difficulty), bet(bet)
	{
		std::uniform_int_distribution<int> uniform_dist(1, 10 * difficulty);
		random_number = uniform_dist(mt);
	};

	float reward()
	{
		return this->bet * std::pow(10.0f, difficulty); 
	}

	int maxNumber() const 
	{
		return 10 * difficulty;
	}

	void winCondition(int num)
	{
		if (num == random_number)
			std::cout << "You won " << reward() << "$, congratulation!" << std::endl;
		else
			std::cout << "You lost!" << std::endl;
	}
};

int main()
{
	int difficulty, num;
	float bet = 0;
		
	do
	{
		std::cout << "Please enter a difficulty bewtween 1 to 3:" << std::endl;
		std::cin >> difficulty;

		if (std::cin.fail()) // Check if it's an integer
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Svuota il buffer
			std::cout << "Invalid input. Please enter a number between 1 and 3." << std::endl;
			difficulty = 0;
		}
	} 
	while (difficulty != 1 && difficulty != 2 && difficulty != 3);
	
	do
	{
		std::cout << "How much do you want to bet?" << std::endl;
		std::cin >> bet;

		if (std::cin.fail()) // Check if it's an integer
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Svuota il buffer
			std::cout << "Invalid input. Please enter a positive number." << std::endl;
			bet = 0;
		}
	} while (bet <= 0);
	
	Casino player(difficulty, bet); // Create the "profile"

	do
	{
		std::cout << "Choose a number between 1 and " << player.maxNumber() << ": " << std::endl;
		std::cin >> num;

		if (std::cin.fail()) // Check if it's an integer
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Svuota il buffer
			std::cout << "Invalid input. Please enter a positive number between 1 and " << player.maxNumber() << std::endl;
			bet = 0;
		}
	} while (num < 1 || num > player.maxNumber());

	player.winCondition(num);

	std::cin.get();
}