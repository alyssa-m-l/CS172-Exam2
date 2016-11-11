#ifndef CITIZEN_H
#define CITIZEN_H
#include <iostream>
#include <vector>
using namespace std;
//I affirm that all code given below was written solely by me, Alyssa La Fleur, and that any help I received adhered to the rules stated for this exam

//Class for Citizens of the city
class Citizen
{
private:
	//Variables for Citizen, including first and last name of  the citizen, thier id, and their favorite color
	string firstName;
	string lastName;
	string color;
	int id;
public:
	//Constructor for Citizen, with inputs for all variables
	Citizen(int id, string firstName, string lastName, string color);
	//Copy constructor for Citizen, with input of pointer to other Citizen object
	Citizen(Citizen* citizen);
	//Getter for first name
	string getFirstName();
	//Getter for last name
	string getLastName();
	//Getter for id
	int getId();
	//Getter and setter functions for color
	string getFavoriteColor();
	void setFavoriteColor(string color);
};

#endif
