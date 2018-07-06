#include <iostream>

char keyboard[3][9];

const int numdirs = 8;
int DX[] = {0, 0, 1, -1, 1, -1, 1, -1};
int DY[] = {1, -1, 0, 0, -1, 1, 1, -1};

using namespace std;

void FillKeyboard()
{
   char currChar = 'a';
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 9; j++)
      {
         keyboard[i][j] = currChar;
         currChar += 1;
      }
   }
}

bool isValid(int i, int j)
{
   return i >= 0 && i < 3 && j >= 0 && j < 9;
}

//is c a neighbor to the char at row col
bool isANeighbor(int row, int col, char c)
{
   for(int i = 0; i < numdirs; i++)
   {
      int newRow = row + DX[i];
      int newCol = col + DY[i];

      if(isValid(newRow, newCol) && keyboard[newRow][newCol] == c)
         return true;
   }
   return false;
}

bool areNeighbors(char c1, char c2)
{
   if(c1 == c2)
      return true;
   int i, j;
   bool found = false;
   //find indexs of c1
   for(i = 0; i < 3; i++)
   {
      for(j = 0; j < 9; j++)
      {
         if(keyboard[i][j] == c1)
         {
            found = true;
            break;
         }
      }
      if(found)
         break;
   }
   //c1 is at index i and j
   return isANeighbor(i, j, c2);
}

int Eval(string s1, string s2, int curIndex)
{
   if(curIndex == s1.length())
      return 2;

   if(!areNeighbors(s1[curIndex], s2[curIndex]))
      return 3;

   return Eval(s1, s2, curIndex + 1);
}

int Eval(string s1, string s2)
{
   if(s1 == s2)
      return 1;

   if(s1.length() != s2.length())
      return 3;

   return Eval(s1, s2, 0);
}

int main()
{
   FillKeyboard();

   int tc;
   cin>>tc;

   for(int l = 0; l < tc; l++)
   {
      string s1, s2;
      cin>>s1>>s2;
      cout<<Eval(s1, s2)<<endl;
   }
}
