#include <fstream>
#include <iostream>
#include <string>
#include "Player.h"
#include "SummaryCards.h"

int main()
{

	cout << "Hello and Welcome to Powergrid\n\n";

	Player PL1 = Player("Yassine", 50, RED);

	PL1.grabhouses();

	cout << PL1 << endl;

	SummaryCards overviewCard = SummaryCards(PL1);
	cout << overviewCard;

	std::ofstream outfile("players.txt", std::ios_base::app);
	if (outfile.is_open()) {
		outfile << PL1;
		outfile << overviewCard;//test

		outfile.close();
	}
	else cout << "cannot open the file ";

	system("pause");
	return 0;
}