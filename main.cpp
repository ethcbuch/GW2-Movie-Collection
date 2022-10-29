#include "Movie_library.h"
using namespace std;

int main()
{
  movie_Library libby;
  movie temp;

  temp.movieTitle = "Eternal";
  temp.directorName = "Pain and Suffering";
  temp.movieRuntime = 57;
  temp.movieFormat = "Digital";
  temp.moviePrice = 1.34;
  temp.releaseYear = 2022;
  
  libby.readFile("file.txt");
  libby.findMovie("THE");
  libby.directorSearch("Fenny Ferrisbottom");
  libby.directorSearch("K. Ericson");
  libby.addMovie(temp);
  libby.print();
  libby.writeFile("test.txt");
  return 0;
}
