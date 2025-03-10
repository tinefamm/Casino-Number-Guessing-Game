#include <iostream>
#include <random>
#include <math.h>

std::random_device rd;
std::mt19937 mt(rd());

class Casino
{
private:
	int difficulty;
	float bet;
	int random_number;
public:
	Casino(int difficulty, float bet)
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
	float bet;
		
	do
	{
		std::cout << "Please enter a difficulty bewtween 1 to 3:" << std::endl;
		std::cin >> difficulty;
	} 
	while (difficulty < 1 || difficulty > 3);
	
	do
	{
		std::cout << "How much do you want to bet?" << std::endl;
		std::cin >> bet;
	} while (bet <= 0);
	
	Casino player(difficulty, bet);

	do
	{
		std::cout << "Choose a number between 1 and " << player.maxNumber() << ": " << std::endl;
		std::cin >> num;
	} while (num < 1 || num > player.maxNumber());

	player.winCondition(num);

	std::cin.get();
}