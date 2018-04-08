/*
  Solves small and large datasets
  Just fills a 3x67 rectangle until the area we want is reached
*/
#include <iostream>

using namespace std;

//3*67 is 201 > max A of 200
#define MAXROWS 3
#define MAXCOLS 67
#define NUMDIRS 3

//DX/DY array to check to the left
const int DX[] = {1, 0, -1};
const int DY[] = {-1, -1, -1};

//Returns true if the 3 grid locations to the left of the target
//are already filled
bool leftThreeFilled(int row, int col, bool grid[MAXROWS][MAXCOLS])
{
  for(int i = 0; i < NUMDIRS; i++)
    if(!grid[row + DX[i]][col + DY[i]])
      return false;

  return true;
}

int main()
{
  int TC;
  cin>>TC;

  for(int l = 0; l < TC; l++)
  {
    int A;
    cin>>A;
    int maxCol = 67;

    int row = 3 + l*3, col = 3, rowDiff = l*3 + 2, colDiff = 2, rowP, colP;
    bool solved = false, grid[MAXROWS][MAXCOLS];

    //init grid
    for(int i = 0; i < MAXROWS; i++)
      for(int j = 0; j < MAXCOLS; j++)
        grid[i][j] = false;

    while(!solved)
    {
      while((!leftThreeFilled(row - rowDiff, col - colDiff, grid) || col >= maxCol))
      {
          cout<<row<<" "<<col<<endl;
          cin>>rowP;
          cin>>colP;

          if(rowP == 0 && colP == 0){solved = true; break;}
          if(rowP == -1 && colP == -1){cerr<<"Recieved -1 -1 as output\n"; solved = true; break;}

          grid[rowP - rowDiff][colP - colDiff] = true;
      }
      //Advance to a more useful position
      while(col < maxCol && leftThreeFilled(row - rowDiff, col - colDiff, grid))
        col++;
    }
  }
}
