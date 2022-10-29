#include "Movie_library.h"
using namespace std;

int main()
{
  movie_Library libby;
  libby.readFile("file.txt");
  libby.print();
  
  return 0;
}
