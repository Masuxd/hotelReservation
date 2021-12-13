// Matias Tuoinen 21Tietob 
// Hotel reservation program.
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

//functions
void room_check();  //check if room is taken or not.
bool random();  //random checkin room generator.


struct reservation {
	string first_name;
	string last_name;
	int room_number;
	int check_in_number;
};


int main() {
	/* Here I make the main menu where you can select what you want to do.
	Also calling other parts of code here so they can choose what they want to do.*/
	int options, i, reservations;
	const int max_index = 300;
	bool error, menu = true;
	reservation res[max_index];

		/*if (reservation > max_index) {
			cout << "All rooms are reserved.";

		}
		*/


	//Simple main menu for choosing options.
	cout << "_______________________________________________________" << endl;
	cout << "	 Welcome to the hotel reservation" << endl;
	cout << "_______________________________________________________" << endl;
	cout << "If you want to reserve a room type 1" << endl;
	cout << "If you want to see what rooms have been reserved type 2" << endl;
	cout << "If you want to search a specific room or check-in key type 3" << endl;
	cout << "If you want to quit type 4" << endl;



	// error checker gotten from moodle but modified little bit to get it working.
	do {
		//Simple main menu for choosing options.
		cout << "_______________________________________________________" << endl;
		cout << "	 Welcome to the hotel reservation" << endl;
		cout << "_______________________________________________________" << endl;
		cout << "If you want to reserve a room type 1" << endl;
		cout << "If you want to see what rooms have been reserved type 2" << endl;
		cout << "If you want to search a specific room or check-in key type 3" << endl;
		cout << "If you want to quit type 4" << endl;
		cout << "Type here and press enter:  ";
		cin >> options;
		error = false;


		//gives error message if input is wrong
		if (cin.fail()) {
			cout << "Error. Enter your number again!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		//simple switch case what is the menu what I will be using.
			switch (options) {

				case 1:
					cout << "______________________________________________________________" << endl;
					cout << "		Room reservation" << endl;
					cout << "______________________________________________________________" << endl;
					cout << "Please type in first name here: ";
					cin >> res[i].first_name;
					
					cout << "Please type in last name here: ";
					cin >> res[i].last_name;

					random();
					res[i].check_in_number = random();;

					i++;

		

					cout << endl;
					break;

				case 2:
					cout << "Goodbye";
					return 0;
					break;

				default:
					cout << "You have to choose between 1 and 2!";
					cout << endl;
				}
		
	} while (options);
	






	



	return 0;
}

bool random() {
	int reservation_number, a, b, c, d, e;

	srand(time(0));
	//this generates diffrent numbers from 0-9. I multiply them to to get one big number that we can use give room check-in numbers. 
	a = 10000 * (rand() % 10);
	b = 1000 * (rand() % 10);
	c = 100 * (rand() % 10);
	d = 10 * (rand() % 10);
	e = 1 * (rand() % 10);
	reservation_number = a + b + c + d + e;
	
	//just prints our equation seen above.
	cout << "Your reservation number is" << reservation_number << endl;

	return reservation_number;
}