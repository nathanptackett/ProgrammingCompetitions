/*
  Solves small and large datasets
*/

#include <iostream>
#include <string>

using namespace std;

int ComputeDamage(string instr);
void PrintResult(int testCase, int minSwaps);
int SolveSmall(string inst, int D);
int SolveBig(string inst, int D);
bool SwapRight(string& s, int i);
int SwapRightInto(string &s, int curIndex, int destIndex, int maxDamage);
bool SwapLeft(string& s, int i);
int ComputeMinDamage(string instr);

int main()
{
    int Tc;
    cin>>Tc;

    for(int loop = 1; loop <= Tc; loop++)
    {
        int D;
        cin>>D;
        string inst;
        cin>>inst;

        //See if we are already good
        if(ComputeDamage(inst) <= D)
        {
            PrintResult(loop, 0);
            continue;
        }

        //See if it is even possible
        if(ComputeMinDamage(inst) > D)
        {
          PrintResult(loop, -1);
          continue;
        }

        //See how many swaps it takes
        int numSwaps = SolveBig(inst, D);
        PrintResult(loop, numSwaps);
    }
}

int SolveBig(string s, int D)
{
    int lastIndex = s.size() - 1;
    int numSwaps = 0;
    bool solved = false;

    while(!solved)
    {
      bool SeenS = false;
      int swapIndex = 0;
      for(int i = lastIndex; i >= 0; i--)
      {
        //If we haven't seen an S. See if this is an S, or continue
        if(!SeenS)
        {
          if(s[i] == 'S')
          {
            SeenS = true;
            swapIndex = i;
          }
          continue;
        }

        //get out of this block of s's and find the C
        if(s[i] == 'S') continue;

        //We are at the first C!
        numSwaps += SwapRightInto(s, i, swapIndex, D);

        //See if we solved it
        solved = ComputeDamage(s) <= D;
        if(solved) return numSwaps;

        //break out of this loop
        break;
      }
    }
    return numSwaps;
}

int SwapRightInto(string &s, int curIndex, int destIndex, int maxDamage)
{
    int numSwaps = 0;
    for(int i = curIndex; i < destIndex; i++)
    {
      if(!SwapRight(s, i)) return numSwaps;
      numSwaps++;

      //We don't need to swap anymore
      if(ComputeDamage(s) <= maxDamage) return numSwaps;
    }
    return numSwaps;
}

int ComputeMinDamage(string str)
{
  int res = 0;
  for(int i = 0; i < str.size(); i++)
    if(str[i] == 'S')
      res++;

  return res;
}

//Only one 'C' continue swapping to the right until less than D. if never happens, return -1
int SolveSmall(string inst, int D)
{
    int strlen = inst.length(), numSwaps = 0;

    for(int i = 0; i < strlen; i++)
    {
        if(inst[i] != 'C')
            continue;

        //We are at the C
        for(int j = i; j < strlen - 1; j++)
        {
            numSwaps++;
            SwapRight(inst, j);
            if(ComputeDamage(inst) <= D) return numSwaps;
        }
    }

    if(ComputeDamage(inst) < D)
        return numSwaps;
    return -1;
}


//Max O(32) which might as well be O(1)
int ComputeDamage(string instr)
{
    int length = instr.length();
    int totalDamage = 0, beamDamage = 1;

    for(int i = 0; i < length; i++)
    {
        if(instr[i] == 'C')
            beamDamage<<=1;
        else
            totalDamage+=beamDamage;
    }

    return totalDamage;
}

//O(1)
bool SwapLeft(string& s, int i)
{
    if(i > 0)
    {
        char temp = s[i - 1];
        s[i - i] = s[i];
        s[i] = temp;
        return true;
    }
    return false;
}

//O(1)
bool SwapRight(string& s, int i)
{
    int size = s.length();
    if(i < size - 1)
    {
        char temp = s[i + 1];
        s[i + 1] = s[i];
        s[i] = temp;
        return true;
    }
    return false;
}

void PrintResult(int testCase, int minSwaps)
{
    string result;
    if(minSwaps >= 0)
        result = to_string(minSwaps);
    else
        result = "IMPOSSIBLE";

    cout<<"Case #"<<testCase<<": "<<result<<"\n";

}
