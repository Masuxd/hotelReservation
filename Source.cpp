// Matias Tuoinen 21Tietob 
// Hotel reservation program.
#include <iostream>
using namespace std;
void room_check();  //check if room is taken or not




int main() {
	/* Here I make the main menu where you can select what you want to do. 
	Also calling other parts of code here so they can choose what they want to do*/
	int options; 
	bool error;



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
		else if (options > 3){
			cout << "Error that option doesn't exist. Enter your number again!";
			error = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
		
	} while (error);
	

	switch (options)
	{
	case 1:
		cout << "______________________________________________________________"<< endl;
		cout << "		Room reservation"<< endl;
		cout << "______________________________________________________________"<< endl;

	default:
		break;
	}

	
	
	
	
	return 0;
}