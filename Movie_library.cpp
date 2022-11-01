#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <string>
#include "Movie.h"
#include "Movie_library.h"

#define RESET "\033[0m"
#define BOLDWHITE "\033[1m\033[37m"
#define WHITE "\033[37m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDCYAN "\033[1m\033[36m"

using namespace std;

string movie_Library::toLower(string str)
{
  for(unsigned int i = 0; i < str.size(); i++)
    {
      char c = str[i];
      if(65 <= c && c <= 90)
	{
	  str[i] = c + 32;
	}
    }
  return str;
}

void movie_Library::readFile(string file)
{
  ifstream inputFile;
  movie inny;
  inputFile.open(file);  
  getline(inputFile, inny.movieTitle);
  while(inputFile)
    {
      getline(inputFile, inny.directorName);
      inputFile >> inny.movieRuntime;
      inputFile.get();
      getline(inputFile, inny.movieFormat);
      inputFile >> inny.moviePrice;
      inputFile >> inny.releaseYear;
      inputFile.get();
      insertSorted(inny);
      getline(inputFile, inny.movieTitle);
    }
  movies.pop_front();
}

void movie_Library::writeFile(std::string file)
{
  ofstream outputFile;
  movie outy;
  outputFile.open(file);  
  for(it = movies.begin(); it != movies.end(); it++)
    {
      outputFile << it->movieTitle << endl;
      outputFile << it->directorName << endl;
      outputFile << it->movieRuntime << endl;
      outputFile << it->movieFormat << endl;
      outputFile << it->moviePrice << endl;
      outputFile << it->releaseYear << endl;
    }
  outputFile.close();
}

void movie_Library::insertSorted(movie sortee)
{
  if(movies.empty())
    {
      movies.push_back(sortee);
      return;
    }
  
  for(it = movies.begin(); it != movies.end(); it++)
    {
      if(it->movieTitle > sortee.movieTitle) //Before
	{
	  movies.insert(it, sortee);
	  return;
	}
    }
  movies.push_back(sortee);
}

void movie_Library::findMovie(string sub)
{
  string subL = toLower(sub);
  int n = 0;
  cout << "All movies containing the keyword " << subL << " are: " << endl;
  for(it = movies.begin(); it != movies.end(); it++)
    {
      if(toLower(it->movieTitle).find(subL) != string::npos)
	{
	  cout << "Movie: " << it->movieTitle << endl;
	  n++;
	}
    }
  if(n > 0)
    {
      cout << n << " movies have been found!" << endl;
    }
  else if(n == 0)
    {
      cout << n << " movies have been found!" << endl;
    }
}

void movie_Library::directorSearch(std::string director)
{
  int n = 0;
  cout << "Director " << director << " has made the following movies: " << endl;
  for(it = movies.begin(); it != movies.end(); it++)
    {
      if(it->directorName == director)
	{
	  cout << "Movie: " << it->movieTitle << " is a " << it->movieFormat << " that runs for " << it->movieRuntime
	       << " minutes, was released in " << it->releaseYear << ", and costs $" << it->moviePrice << "!" << endl;
	  n++;
	}
    }
  if(n == 0)
    {
      cout << n << " movies have been found!" << endl;
    }
}

void movie_Library::addMovie(movie input)
{
  insertSorted(input);
}

void movie_Library::removeMovie(std::string movie)
{
  for(it = movies.begin(); it != movies.end(); it++)
    {
      if(it->movieTitle == movie)
	{
	  movies.erase(it);
	  return;
	}
    }
}


void movie_Library::print()
{
  int n = 0;
  cout << "All movies in the collection are: " << endl;
  cout << BOLDCYAN << left << setw(30) << "Movie Name" << setw(25) << "Director" << setw(9) << "Format" << setw(9) << "Runtime" << setw(6) << "Year" << setw(6) << "Price" << RESET << endl;
  cout << "+-----------------------------------------------------------------------------------+" << endl;
  for(it = movies.begin(); it != movies.end(); it++)
    {
      cout << left << BOLDWHITE;
      cout << setw(30) << it->movieTitle << setw(25) << it->directorName << setw(9) << it->movieFormat << setw(9) << it->movieRuntime << setw(6) << it->releaseYear << "$" << setw(6) << it->moviePrice << RESET << endl;
      n++;
    }
  cout << "+-----------------------------------------------------------------------------------+" << endl;
  cout << "For a whopping total of " << n << " movies in the collection!" << endl;
}
