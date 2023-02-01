#pragma once
#include "Hotel.h"


//====================================================================
class ReservationSystem
{
public:

	ReservationSystem(){}
	~ReservationSystem(){}

// void that makes reservations happen.
    void makeReservation()
    {
        //if bool is true it ask for reservation if it is false it doesn't
        bool makeNewReservation = true;

        while (makeNewReservation)
        {
            string name;
            
            cout << "Give name: ";
            getline(cin, name);


            int roomNumber = -1;

            bool reservationSuccessful = false;

            while (!reservationSuccessful)
            {

                roomNumber = IntegerInputInQuestion("Give number of the room you want to reserve: ");
                                
                reservationSuccessful = hotel.reserveRoom(roomNumber, name);

                if (!reservationSuccessful)
                {
                    cout << "That room is not available. Please select another one.\n";
                }
            }


            //ask user for how many days he or she want to be at hotel and gives out the cost.
            int numberOfNights = IntegerInputInQuestion("Give how many nights you want to stay: ");
            hotel.RervationsNumberOfNights(numberOfNights, roomNumber);
            int roomPrice = hotel.getReservationPrice(roomNumber);
            hotel.print(roomNumber);


            
            

            //asking if user wants to continue the program or stop
            string option;
            cout << "Would you like to make a new reservation (yes/no): ";
            getline(cin, option);

            if (option == "no")
                makeNewReservation = false;

           

         
        }
        
            
    }

// searches room based on check-In number or name.
    void searchRoom()
    {
        bool searchRoom = true;
        
        string searchWant;
        cout << "would you like to search for a room? (yes/no): ";
        getline(cin, searchWant);


        if (searchWant == "no")
            searchRoom = false;

        while(searchWant == "yes")
        {
            string search;
            cout << "would you like to search with name or check-in number?(num/name)";
            getline(cin, search);

            if (search == "num")
            {
                int checkInNumber = IntegerInputInQuestion("Give your check-in number: ");
                hotel.getReservationWithCheckInNumber(checkInNumber);

                
                cout << "would you like to continue searching?(yes/no): ";
                getline(cin, searchWant);

                if (searchWant == "no")
                    searchRoom = false;


            }
            else if (search == "name")
            {
                string name;

                cout << "Give your name: ";
                getline(cin, name);

                hotel.getReservationWithName(name);

                cout << "would you like to continue searching?(yes/no): ";
                getline(cin, searchWant);

                if (searchWant == "no")
                    searchRoom = false;
                 
            }
       }
            

        


    }
	
		
		

private:



    //This takes input checks if it is integer and then gives it as integer to be used.
    int IntegerInputInQuestion(string outputString)
    {
        bool validInput = false;
        string inputString = "";

        while (!validInput)
        {
            cout << outputString;
            getline(cin, inputString);
            if (checkIfNumber(inputString))
                validInput = true;
                
        }
        return stoi(inputString);
    }

    //=====================================================================================
     // used this as referance stackoverflow as referance to create this string checker (referance 1.)

    bool checkIfNumber(string& string)
    {
        bool checkIfNumber = true;
        //takes string lenthg and runs isdigit, 
        //that check if its a number, until index is bigger than lenght of string
        for (int i = 0; i < string.length(); i++)
        {
            if (!isdigit(string[i]))
                checkIfNumber = false;
        }
        return checkIfNumber;

    }

//=====================================================================================

    Hotel hotel;
};
