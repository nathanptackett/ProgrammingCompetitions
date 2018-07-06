#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int minPresses(int x1, int x2, int t)
{
  int minPresses = 0;
  //small 2 big
  if(x1 < x2)
  {
    int straightThere = x2 - x1 - 1;
    int to0thentoThere = x1 + 1 + t - x2;

    minPresses = min(straightThere, to0thentoThere);
  }
  //big 2 small
  else
  {
    int straightThere = x1 - x2 + 1;
    int toEndThenToThere = t - x1 - 1 + x2;

    minPresses = min(straightThere, toEndThenToThere);
  }

  return minPresses;
}

int main()
{
  //to go from song i to j in the forward direction, it takes j - i - 1 presses
  //to go from song i to j in the backwards direction, it takes i - j + 1
  //STILL NEED TO HANDLE WRAP AROUND BUT LET ME START CODING

  int n;
  cin>>n;

  for(int loop = 0; loop < n; loop++)
  {
    int tracks, num2play, lastNum;
    ll sum = 0;
    cin>>tracks>>num2play;
    bool firstPass = true;
    for(int i = 0; i < num2play; i++)
    {
      int x;
      cin>>x;
      if(firstPass)
      {
        firstPass = false;
        lastNum = x;
        continue;
      }

      //find min to get from lastNum to x
      int minnum;
      sum += (minnum = minPresses(lastNum, x, tracks));
      #ifdef DEBUG
        cout<<"CURSUM IS "<<sum<<endl;
        cout<<"THAT MINNUM WAS "<<minnum<<endl;
      #endif
      lastNum = x;
    }

    cout<<sum<<endl;
  }
}
