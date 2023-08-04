#include <iostream>
#include <vector>
#include <string>
#include <random>

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

	std::string print_name()
	{
		return name;
	}

	std::vector<Card> return_cards()
	{
		return cards;
	}
};


//Creates a new deck and adds it to the vector of decks
Deck new_deck(std::vector<Deck> decks)
{
	Deck deck;

	std::cout << "Enter the name of the new deck:" << std::endl;
	deck.add_name();

	return deck;
}


//Shows the contents of deck vector
void view(std::vector<Deck> decks)
{
	for (int i = 0; i < decks.size(); i++)
	{
		std::cout << i << ". " << decks[i].print_name() << std::endl;
	}
}


//Shuffling the deck to review the cards
void review(Deck deck)
{
	std::vector<Card> cards = deck.return_cards();
	int size = cards.size();
	for (int i = 0; i < size*10; i++)
	{
		int range = size + 1;
		int rand1 = rand() % range;
		int rand2 = rand() % range;

		Card temp = cards[rand1];
		cards[rand1] = cards[rand2];
		cards[rand2] = temp;
	}
	char enter;
	for (int i = 0; i < size; i++)
	{
		std::cout << cards[i]._card_front() << std::endl;
		std::cout << "Press enter to view the back" << std::endl;
		std::cin >> enter;
		std::cout << cards[i]._card_back() << std::endl;
	}
}


int main()
{
	bool f = true;
	int choice;
	int num;
	char answer = 'y';

	std::vector<Deck> decks;

	while (f)
	{
		std::cout << "Choices:" << std::endl;
		std::cout << "1. Create New Deck" << std::endl;
		std::cout << "2. View Contents" << std::endl;
		std::cout << "3. Review Deck" << std::endl;
		std::cout << "4. Add a card to the deck" << std::endl;
		std::cout << "5. End." << std::endl;

		std::cout << "input the number of your choice:";
		std::cin >> choice;

		while (choice < 1 || choice > 5)
		{
			std::cout << "invalid choice. Please try again: " << std::endl;
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
			std::cout << "List of decks created:" << std::endl;
			view(decks);

			break;

		case 3:
			std::cout << "What deck do you want to review? enter the view number:" << std::endl;
			std::cin >> num;
			while (num > decks.size() || num < 0)
			{
				std::cout << "Invalid value. Try again:" << std::endl;
				std::cin >> num;
			}
			review(decks[num]);
			
			break;

		case 4:
			while (answer == 'y')
			{
				std::cout << "Enter the number of the deck you want to add cards:" << std::endl;
				std::cin >> num;

				while (num < 0 || num > decks.size())
				{
					std::cout << "invalid value. Try again:" << std::endl;
					std::cin >> num;
				}
				decks[num].add_card();

				std::cout << "Do you want to add more cards? (y/n)" << std::endl;
				std::cin >> answer;
			}

			break;
		case 5:

			f = false;
			break;
		}
	}

	std::cout << "Program ending..." << std::endl;

	return 0;
}

