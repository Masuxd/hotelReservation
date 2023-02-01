// Matias Tuoinen 21Tietob 
// Hotel reservation program.
#include "Reservations.h" //including my header file where most of functions and declerations are.
using namespace std;




int main(int argc, const char* argv[])
{


    //Runs HotelReservationSystem from header file 
    ReservationSystem reservationSystem;

    reservationSystem.makeReservation();
    reservationSystem.searchRoom();
   



    return 0;
}