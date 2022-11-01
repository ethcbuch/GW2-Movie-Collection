#include "Movie_library.h"
#include <iostream>

using namespace std;

int main()
{
  movie_Library libby;
  movie m1;
  movie m2;
  string fileName;
  string outputName;
  string keyword;
  string directorInput;
  char input;
 
  do {
  cout << "Welcome to the ERROR 404 Movie Collection program! You may select one of the following options: " << endl;
  cout << "+------------------------------------------------------------------------------------------------+" << endl;
  cout << " 1) Read a list of movies from a file" << endl;
  cout << " 2) Write the movie collection to a file" << endl;
  cout << " 3) Print the movie collection" << endl;
  cout << " 4) Search for a movies by a keyword" << endl;
  cout << " 5) Search for movies by a director" << endl;
  cout << " 6) Add a movie" << endl;
  cout << " 7) Delete a movie from the colletion" << endl;
  cout << " 8) Exit the program" << endl;
  cout << "+------------------------------------------------------------------------------------------------+" << endl;
  cout << "Please enter your choice now: ";
  cin >> input;

  switch(input) {
  case '1':
    {
      cout << "Enter a valid file name: ";
      cin >> fileName;
      libby.readFile(fileName);
      cout << "Successfully read from file" << endl << endl;
      
      break;
    }
  case '2':
    {
    cout << "Enter a file name to output to: ";
    cin >> outputName;
    libby.writeFile(outputName);
    cout << "Successfully wrote to file" << endl << endl;
						    
    break;
    }
  case '3':
    {
    cout << endl;
    libby.print();
    cout << endl;

    break;
    }
  case '4':
    {
    cout << "Please enter a keyword to look up movies by: ";
    cin.get();
    getline(cin, keyword);

    libby.findMovie(keyword);

    cout << endl;
      
    break;
    }
  case '5':
    {
    cout << "Please enter a director to search to search by: ";
    getline(cin, directorInput);
    libby.directorSearch(directorInput);
    cout << endl;

    break;
    }
  case '6':
    {
    cout << "Please provide information for new movie: " << endl;
    cout << "Movie Title: ";
    getline(cin, m1.movieTitle);
    cout << "Director Name: ";
    getline(cin, m1.directorName);
    cout << "Format: ";
    cin >> m1.movieFormat;
    cout << "Runtime: ";
    cin >> m1.movieRuntime;
    cout << "Year: ";
    cin >> m1.releaseYear;
    cout << "Price: ";
    cin >> m1.moviePrice;
    cout << endl;

    libby.insertSorted(m1);
    
    cout << "Successfully added movie!" << endl << endl;
    break;
  }
  case '7':
    {
    cout << "Please provide information for which movie to delete: " << endl;
    cin.get();
    getline(cin, m1.movieTitle);

    libby.removeMovie(m1.movieTitle);
    cout << "Successfully removed movie!";
    cout << endl;
    
    break;
    }
  case '8':
    {
    cout << "Thank you for using the Movie Collection program. Have a nice day! " << endl;;
    break;
    }
  default:
    {
    cout << "Please enter a valid input!" << endl << endl;
    cin >> input;
    }
  }
  }
  while (input != '8');
  
  return 0;
}
