#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
int main()
{
   int t;
   cin>>t;

   for(int loop = 0; loop < t; loop++)
   {
      int N;
      cin>>N;

      int P = N/2 + N % 2;
      ll Q = N;

      Q = Q - P;
      P = 1;

      cout<<P<<" ";

      //Results are too big to store in memory, but are always in the form 10^x, so just print a 1 followed by X zeros
      cout<<1;
      for(int i = 0; i < Q; i++)
         cout<<0;
      cout<<endl;
   }
}
