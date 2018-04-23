//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#include "ATM.h"         //include modules header files

//---------------------------------------------------------------------------

//main application

int main() { 
	//create the application
	ATM theATM; // default constructor called here
    //run it
	theATM.activateCashPoint();
	//destroy it - destructor called here
	return 0;
}
