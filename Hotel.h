#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Structures to store information
//=====================================================================================
struct Reservation
{
    string name         = "";
    int roomNumber      = -1;
    int checkInNumber   = -1;
    int numberOfNights  =  0;

};


//=====================================================================================



struct Room
{
    int   roomNumber = -1;
    int   price      = 0;
    bool  inUse      = false;
};

//=====================================================================================

class Hotel
{
public:
    Hotel()
    {
        addRooms();
    }
//=====================================================================================
 
//basic that adds room as much it generateRandomIntiger has generated.
    ~Hotel(){}

    void addRooms()
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        // generate random number between 40-300
        int numberOfRooms = generateRandomIntiger(minNumberOfRooms, maxNumberOfRooms);
        int cost = generateRandomIntiger(minPayment, maxPayment);


        for (int i = 0; i < numberOfRooms; i++)
        {
            Room newRoom;
            newRoom.roomNumber = i+1;
            newRoom.inUse      = true;
            newRoom.price      = cost;
            rooms.push_back(newRoom);
        }
    }

//=====================================================================================
    
    //generates random Intiger to be used in other programs
    int generateRandomIntiger(int min, int max) 
    {

     

        srand(static_cast<unsigned int>(time(nullptr)));

        int number = rand() % max + min;


        return number;
    }



//=====================================================================================


    // Checks if you can reserve room and if you can stores that that room is now taken
    bool reserveRoom(int roomNumber, string name)
    {
        bool reserveSuccess = true;

        int checkInNumber = generateCheckInNumber();

       
        if (isRoomReserved(roomNumber) || roomNumber < 0 || roomNumber > 300)
        {
            // room is reserved
            reserveSuccess = false;
        }
        else
        {
            // if room is not reserved, make reservation
            Reservation reservation;
            reservation.name = name;
            reservation.checkInNumber = checkInNumber;
            reservation.roomNumber = roomNumber;

            reservations.push_back(reservation);

            

        }

        return reserveSuccess;
    }

    //=====================================================================================


    int generateCheckInNumber()
    {
        bool checInNumberExist = true;
        int checkInNumber = -1;

        while (checInNumberExist)
        {
            checkInNumber = generateRandomNumber();
            if (!checkInNumberIsInUse(checkInNumber))
            {
                checInNumberExist = false;
            }
        }

        return checkInNumber;
    }


    //=====================================================================================

//generates the check-In number to be used

    int generateRandomNumber()
    {
        // give a new seed
        srand(static_cast<unsigned int>(time(nullptr)));
        // generate random number between 10 000 and 99 999
        int randomNumber = rand() % 90000 + 10000;
        return randomNumber;
    }


//just puts checkInNumber to use
    //=====================================================================================

    bool checkInNumberIsInUse(int checkInNumber)
    {
        bool checkInNumberInUse = false;

        for (Reservation reservation : reservations)
        {
            if (reservation.checkInNumber == checkInNumber)
                checkInNumberInUse = true;
        }
        return checkInNumberInUse;
    }


    //=====================================================================================
//checks if the room is reserved or not

    bool isRoomReserved(int roomNumber)
    {
        bool roomReserved = false;

        for (Reservation reservation : reservations)
        {
            if (reservation.roomNumber == roomNumber)
                roomReserved = true;
        }
        return roomReserved;
    }

 //=====================================================================================
//counts how much it will cost to stay
   void costOfNight(string daysString)
    {


        int payment;
        int Daysint = stoi(daysString);

        payment = Daysint * 100;
        
        cout << "Cost of your stay will be " << payment << "e" << endl;
        cout << endl;
    }

//=====================================================================================
//gets the reservation of number of nights
   void RervationsNumberOfNights(int numberOfNights, int roomNumber)
   {
       for (Reservation& reservation : reservations)
       {
           if (reservation.roomNumber == roomNumber)
               reservation.numberOfNights = numberOfNights;
       }
   }
     
 //=====================================================================================
//just prices reservation
   int getReservationPrice(int roomNumber)
   {
       int price = -1;

       for (Reservation reservation : reservations)
       {
           if (reservation.roomNumber == roomNumber)
           {
               price = getRoomPrice(roomNumber) * reservation.numberOfNights;

               

              

           }
       }
       return price;
   }



//print all information it has of the user
   void print(int roomNumber)
   {
       for (Reservation reservation : reservations)
       {
           
           cout << "Your Reservation was successful.\n";
           cout << "Your information\n";
           cout << "-------------------------------------------------------\n";
           cout << "Name: " << reservation.name << endl;
           cout << "Check-in number: " << reservation.checkInNumber << endl;
           cout << "Room number: " << reservation.roomNumber << endl;
           cout << "Price of stay: " << getRoomPrice(reservation.roomNumber) * reservation.numberOfNights << endl;
           cout << endl;
       }
   }




//=====================================================================================
  //finds reservation with check-in number and displays the information
   int getReservationWithCheckInNumber(int checkInNumber)
   {
       bool reservationFound = false;

       for (Reservation reservation : reservations)
       {
           
           if (reservation.checkInNumber == checkInNumber)
           {
               reservationFound = true;
              
               cout << "Your information\n";
               cout << "-------------------------------------------------------\n";
               cout << "Name: " << reservation.name << endl;
               cout << "Check-in number: " << reservation.checkInNumber << endl;
               cout << "Room number: " << reservation.roomNumber << endl;
               cout << "Room is reserved for: " << reservation.numberOfNights << " nights" << endl;
           }

       }
       return checkInNumber;
   }

   


//=====================================================================================

//displays information gotten from searching with name.
   string getReservationWithName(string name)
   {
       bool reservationFound = false;

       for (Reservation reservation : reservations)
       {
           if (reservation.name == name)
           {
               reservationFound = true;

               cout << "Your information\n";
               cout << "-------------------------------------------------------\n";
               cout << "Name: " << reservation.name << endl;
               cout << "Check-in number: " << reservation.checkInNumber << endl;
               cout << "Room number: " << reservation.roomNumber << endl;
               cout << "Room is reserved for: " << reservation.numberOfNights << " nights" << endl;
               
           }

       }
       return name;
   }



private:
    vector<Reservation> reservations;
    vector<Room> rooms;

    //gives diffrent values to be used inside class.

    const int maxNumberOfRooms = 300;
    const int minNumberOfRooms = 40;
    const int minPayment = 30;
    const int maxPayment = 70;
  
//=====================================================================================

//gets the price of the room from room struct.
    int getRoomPrice(int roomNumber)
    {
        int price = -1;

        for (Room room : rooms)
        {
            if (room.roomNumber == roomNumber)
                price = room.price;
        }
        return price;
    }




    //=====================================================================================
};
