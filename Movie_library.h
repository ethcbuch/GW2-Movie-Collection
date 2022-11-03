/**
 * @author Ethan Buchanan and Hunter Johnson
 * @date 2022-11-03
 * @brief Movie_library class definition
 * 
 * Movie Library class, reads from a file and allows the user to interact with a list of movies
 */

#ifndef MOVIE_LIBRARY_H
#define MOVIE_LIBRARY_H
#include "Movie.h"
#include <list>


/**
 * A list of movies that is read from a file, allows to search for movies, director, add and remove from the list
 * , and allows to write the list to a file.
 *
 * @class movie_Library Movie_library.h "GW2-Movie-Collection/Movie_library.h"
 * @brief Class defintions
 *
 */
class movie_Library {
 public:

/**
 * Reads from a file a list of movies
 *
 * @param std::string file The file being read from
 * @pre A valid file exsists
 * @return void 
 * @post The file has been read into a list and sorted
 * 
 */
  void readFile(std::string file);

/**
 * Writes the list to a file
 *
 * @param std::string file The file being wrote to
 * @post THe list has been written to a file
 * 
 */
  void writeFile(std::string file);
  

/**
 * Sorts the list by Movie title in alphabetical order
 *
 * @param movie sortee A movie object contianing the movie's information 
 * @return void 
 * @post The list has been sorted;
 * 
 */
  void insertSorted(movie sortee);

/**
 * Iterates through the list and prints out movies based on the input string
 *
 * @param std::string sub THe substring to search the list by
 * @pre 
 * @return void 
 * @post Prints out the movies if any are found from the substring
 * 
 */
  void findMovie(std::string sub);

/**
 * Searches for movies based on the dierctor of the movie
 *
 * @param std::string director The director to be searched by
 * @pre 
 * @return void 
 * @post All movies by a certain director are printed
 * 
 */
  void directorSearch(std::string director);

/**
 * Adds a movie to the lis
 *
 * @param movie input The movie object to be added to the list
 * @pre 
 * @return void 
 * @post A new movie has been added and sorted into the list
 * 
 */
  void addMovie(movie input);

/**
 * Removes a movie from the list
 *
 * @param std::string movie The movie to be deleted from the list
 * @pre 
 * @return void 
 * @post the movie has been deleted from the list
 * 
 */
  void removeMovie(std::string movie);

/**
 *
 * Prints all the movies in the list
 * 
 */
  void print();
  
 private:
  std::list<movie> movies;
  std::list<movie>::iterator it;

/**
 * Sets the string to be lowercase so we dont have to worry about case when searching for a movie title
 *
 * @param std::string str The string to be made lowercase
 * @pre 
 * @return std::string the lowercased string is returned
 * @post The string has been made lowercase
 * 
 */
  std::string toLower(std::string str);
};

#endif //MOVIE_LIBRARY_H
