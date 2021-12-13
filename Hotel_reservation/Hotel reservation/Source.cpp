// Matias Tuoinen 21Tietob 
// Hotel reservation program.
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

//functions
void room_check();  //check if room is taken or not
void random();


int main() {
	/* Here I make the main menu where you can select what you want to do.
	Also calling other parts of code here so they can choose what they want to do*/
	int options;
	bool error, menu = true;



	//Simple main menu for choosing options
	cout << "_______________________________________________________" << endl;
	cout << "	 Welcome to the hotel reservation" << endl;
	cout << "_______________________________________________________" << endl;
	cout << "If you want to reserve a room type 1" << endl;
	cout << "If you want to see what rooms have been reserved type 2" << endl;
	cout << "If you want to search a specific room or check-in key type 3" << endl;
	cout << "If you want to quit type 4" << endl;



	// checking the input
	do {
		error = false;
		cout << "Type here and press enter:  ";
		cin >> options;

		if (cin.fail()) {
			cout << "Error. Enter your number again!" << endl;
			error = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
		else if (options > 3) {
			cout << "Error that option doesn't exist. Enter your number again!";
			error = true;
			cin.clear();
			cin.ignore(80, '\n');
		}

	} while (options);


	switch (options)
	{

		menu = false;

		switch (choice) {

		case 1:
			cout << "______________________________________________________________" << endl;
			cout << "		Room reservation" << endl;
			cout << "______________________________________________________________" << endl;

			random();
			break;

		case 2:
			return 0;

		default:
			cout << "You have to choose between 1 and 2!";

		}

	}





	return 0;
}

void random() {
	int reservation_number, a, b, c, d, e;

	srand(time(NULL));

	a = 10000 * (rand() % 10);
	b = 1000 * (rand() % 10);
	c = 100 * (rand() % 10);
	d = 10 * (rand() % 10);
	e = 1 * (rand() % 10);
	reservation_number = a + b + c + d + e;

	cout << reservation_number << endl;



}