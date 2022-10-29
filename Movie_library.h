#ifndef MOVIE_LIBRARY_H
#define MOVIE_LIBRARY_H

#include "Movie.h"
#include <list>

class movie_Library {
 private:
  std::list<movie> movies;
  std::list<movie>::iterator it;

 public:
  void readFile(std::string file);
  void writeFile(std::string file);
  void findMovie(std::string movie);
  void insertSorted(movie sortee);
  void directorSearch(std::string director);
  void removeMovie(std::string movie);
  void print();

};

#endif //MOVIE_LIBRARY_H
