#include<iostream>
#include "Citizen.h"
#include <vector>
using namespace std;
//I affirm that all code given below was written solely by me, Alyssa La Fleur, and that any help I received adhered to the rules stated for this exam

//See Citizen.h for more comprehensive descriptions of functions
//Constructor with input for all variables in Citizen class
Citizen::Citizen(int id_new, string firstName_new, string lastName_new, string color_new)
{
	id = id_new;
	firstName = firstName_new;
	lastName = lastName_new;
	color = color_new;
}

//Copy constructor for Citizen
Citizen::Citizen(Citizen* citizen)
{
	//Copying all data from inputted Citizen pointer to new Citizen variables
	id = citizen->getId();
	firstName = citizen->getFirstName();
	lastName = citizen->getLastName();
	color = citizen->getFavoriteColor();
}

//Getter for first name
string Citizen::getFirstName()
{
	return firstName;
}

//Getter for last name
string Citizen::getLastName()
{
	return lastName;
}

//Getter for id
int Citizen::getId()
{
	return id;
}

//Getter for favorite color of the citizen
string Citizen::getFavoriteColor()
{
	return color;
}

//Setter for the favorite color of the citizen
void Citizen::setFavoriteColor(string color_new)
{
	color = color_new;
}