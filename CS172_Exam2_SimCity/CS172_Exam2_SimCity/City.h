#ifndef CITY_H
#define CITY_H
#include <iostream>
#include "Citizen.h"
#include <vector>
using namespace std;
//I affirm that all code given below was written solely by me, Alyssa La Fleur, and that any help I received adhered to the rules stated for this exam

class City
{
private:
	//Member variables for city name, a vector of Citizens in the city, and the population size fo the city
	string cityName;
	vector <Citizen> citizensOfCity;
	int popSize;
public:
	//Constructor function for city, with name used to check for text files of logged citizens
	City(string cityName);
	//Deconstructor for city, which overwrites the city text file of citizens with updates citizens if any changes occured
	~City();
	//Getter for city name
	string getCityName();
	//Getter for city population size
	int populationSize();
	//Function to return the pointer to a citizen at a given index
	Citizen* getCitizenAtIndex(int index);
	//Function to add a Citizen to the city's population by copying the Citizen's informationa and creating a new Citizen object
	void addCitizen(Citizen* citizen);
	//Function to return a pointer to the Citizen for an inputted id
	Citizen* getCitizenWithId(int id);
	//Function to return a vector fo pointers to all citizens in the city which have a given favorite color
	vector<Citizen*> getCitizensForFavoriteColor(string color);
};

#endif

