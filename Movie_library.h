#ifndef MOVIE_LIBRARY_H
#define MOVIE_LIBRARY_H

#include "Movie.h"
#include <list>

class movie_Library {
 private:
  std::list<movie> movies;
  std::list<movie>::iterator it;
  std::string toLower(std::string str);
  
 public:
  void readFile(std::string file);
  void writeFile(std::string file);
  void insertSorted(movie sortee);
  void findMovie(std::string sub);
  void directorSearch(std::string director);
  void addMovie(movie input);
  void removeMovie(std::string movie);
  void print();

};

#endif //MOVIE_LIBRARY_H
