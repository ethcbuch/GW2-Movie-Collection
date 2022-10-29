#ifndef MOVIE_LIBRARY_H
#define MOVIE_LIBRARY_H

#include "Movie.h"
#include <list>

class movie_Library {
 private:
  std::list<movie> movies;
  std::list<movie>::iterator it;

 public:
  void read_from_file(std::string file);
  void write_to_file(std::string file);
  void insert_sorted();
  void find_movie(std::string movie);
  void director_search(std::string director);
  void remove_movie(std::string movie);
  void print();

};

#endif //MOVIE_LIBRARY_H
