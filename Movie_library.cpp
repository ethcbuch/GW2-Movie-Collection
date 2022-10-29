#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <string>
#include "Movie.h"
#include "Movie_libray.h"

using namepspace std;


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
      inputFile >> inny.movePrice;
      inputFile >> inny.releaseYear;
      inputFile.get();
      movies.insertSorted();
      getline(inputFile, inny.movieTitle);
    }
};

void movie_Library::insertSorted()
{
  movies.sort();
}

void movie_Library::print()
{
  for(it = movies.begin(); it != movies.end(); it++)
    {
      cout << it->movieTitle << " " << it->directorName << " " << it->movieRuntime << " " << it->movieFormat << " " << it->moviePrice << " " << it->releaseYear << endl;
}
