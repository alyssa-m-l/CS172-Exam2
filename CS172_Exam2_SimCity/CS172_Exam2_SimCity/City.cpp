#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "City.h"
using namespace std;
//I affirm that all code given below was written solely by me, Alyssa La Fleur, and that any help I received adhered to the rules stated for this exam

//Constructor for the city class, input of name of city
City::City(string cityName_new)
{
	//Setting the name of the city with the inputted name
	cityName = cityName_new;
	//Setting population size to 0
	popSize = 0;
	//Creating temporary holder variables for data inputted from the file if it exists
	int temp = 0;
	string tempFirst, tempLast, tempColor;
	//Creating file name and opening the fine for input
	string filename = cityName_new + "ClassLog.txt";
	fstream file(filename.c_str(), ios::in);
	//If the file exists, imports all data
	if (!file.fail())
	{
		//Reads unitl end of file for all citizens
		while (!file.eof())
		{
			file >> temp >> tempFirst >> tempLast >> tempColor;
			//stops multiple readings of the last line of the file by checking the end of file again before adding the citizens to the population array
			if (!file.eof())
			{
				//Adding citizens to the population vector and increasing the population size
				citizensOfCity.push_back(&Citizen(temp, tempFirst, tempLast, tempColor));
				popSize++;
			}
		}
	}
	//Closing file
	file.close();
}

//City deconstructor for writing the citizens of the city to a text file
City::~City()
{
	//Creating file name, and opening file
	string filename = cityName + "ClassLog.txt";
	int length = popSize;
	ofstream file;
	file.open(filename.c_str());
	//Outputting all citizens into file
	for (int i = 0; i < popSize; i++)
	{
		//Writing to file with requested spaces
		file << citizensOfCity[i].getId() << " " << citizensOfCity[i].getFirstName() << " " << citizensOfCity[i].getLastName() << " " << citizensOfCity[i].getFavoriteColor() << endl;
	}
	//Closing file
	file.close();
}

//Getter for city name
string City::getCityName()
{
	return cityName;
}

//Getter for population size
int City::populationSize()
{
	return popSize;
}

//Getter for pointer to the citizen at a given index in the population vector
Citizen* City::getCitizenAtIndex(int index)
{
	return &citizensOfCity[index];
}

//Function to add a citizen with input of a pointer to a citizen object using the Citizen copy constructor
void City::addCitizen(Citizen* citizen)
{
	//No new used with Citizen created as all news and olds are in main.cpp for running the program, also, the program works fine without it
	//increases population size and creates a Citizen object and adds it to the vector with the copy constructor
	popSize++;
	citizensOfCity.push_back(Citizen(citizen));
}

//Returns a pointer to a citizen with a given id number in the vector
Citizen* City::getCitizenWithId(int id_search)
{
	//Sorting through all citizens in population vector's id numbers to find and return the first match found
	bool didFind = false;
	int length = citizensOfCity.size();
	for (int i = 0; i < length; i++)
	{
		if (citizensOfCity[i].getId() == id_search)
		{
			return &citizensOfCity[i];
			didFind = true;
		}
	}
	//If no match is found, and no default was specified in the problem, function outputs a error message and returns the first citizen in the array
	if (!didFind)
	{
		cout << "No citizen with that id, returning first citizen of city by default." << endl;
		return &citizensOfCity[0];
	}
}

//Function to return a vector of pointers to citizens which have the same favorite color as the inputted color
vector<Citizen*> City::getCitizensForFavoriteColor(string color_search)
{
	//Creating the vector to be returned
	vector <Citizen*> favColorSearch;
	//Sorting through population vector to find citizens with the same favorite color, and add them to the vector to be returned
	for (int i = 0; i < citizensOfCity.size(); i++)
	{
		if (citizensOfCity[i].getFavoriteColor() == color_search)
		{
			favColorSearch.push_back(&citizensOfCity[i]);
		}
	}
	//Returning vector
	return favColorSearch;
}