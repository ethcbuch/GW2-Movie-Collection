#ifndef MOVIE_H
#define MOVIE_H
#include <string>
struct movie {
  std::string movieTitle = "";
  std::string directorName = "";
  int movieRuntime = 0;
  std::string movieFormat = "";
  float moviePrice = 0;
  int releaseYear = 0;
};
#endif //MOVIE_H
