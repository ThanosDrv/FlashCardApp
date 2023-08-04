#include <iostream>
#include <vector>
#include <string>


class Card
{
private:
	std::string front;
	std::string back;

public:
	void _write_front() 
	{
		std::cout << "Write the front of the card" << std::endl;
		std::cin >> front;
		
	}

	void _write_back()
	{
		std::cout << "Write the back of the card" << std::endl;
		std::cin >> back;
	}
	
	std::string _card_front()
	{
		return front;
	}

	std::string _card_back() 
	{
		return back;
	}

};


class Deck
{
private:
	std::string name;
	std::vector<Card> cards;

public:
	void add_card()
	{
		Card card;

		card._write_front();
		card._write_back();
		
		cards.push_back(card);
	}

	void add_name()
	{
		std::cin >> name;
	}

	std::string Front()
	{
		return cards[0]._card_front();
	}

	std::string Back()
	{
		return cards[0]._card_back();
	}

	void print_name()
	{
		std::cout << name;
	}
};

Deck new_deck(std::vector<Deck> decks)
{
	Deck deck;

	std::cout << "Enter the name of the new deck:" << std::endl;
	deck.add_name();

	return deck;
}

int main()
{
	bool f = true;
	int choice;

	std::vector<Deck> decks;

	while (f)
	{
		std::cout << "Choices:" << std::endl;
		std::cout << "1. Create New Deck" << std::endl;
		std::cout << "2." << std::endl;
		std::cout << "3." << std::endl;
		std::cout << "4. End." << std::endl;

		std::cout << "input the number of your choice:";
		std::cin >> choice;

		while (choice < 1 || choice > 4)
		{
			std::cout << "invalid choice. Please try again:" << std::endl;
			std::cin >> choice;
		}

		switch (choice)
		{
		case 1:
			std::cout << "Creating new deck:" << std::endl;
			decks.push_back(new_deck(decks));

			std::cout << "A new deck has been created with the name:" << decks.back().print_name() << std::endl;

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			f = false;
			break;
		}
	}

	std::cout << "Program ending..." << std::endl;

	return 0;
}

