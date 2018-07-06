#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int tc;
   cin>>tc;

   for(int loop = 0; loop < tc; loop++)
   {
      int n, m, total = 0;
      cin>>n>>m;
      vector<int> a;

      for(int i = 0; i < n; i++)
      {
         int x;
         cin>>x;
         a.push_back(x);
      }

      for(int i = 0; i < n; i++)
      {
         //get sum from i to n-1
         int sum = 0;
         for(int j = i; j < n; j++)
            sum += a[j];

         if(sum % m == 0)
         {
            cout<<sum<<" mod "<<m<<" = 0"<<endl;
            total++;
         }

         //first remove n - 1 and check the sum, then n - 2, then n - 3, and eventually i by itself
         for(int j = n - 1; j > i; j--)
         {
            sum -= a[j];
            if(sum % m == 0)
            {
               cout<<sum<<" mod "<<m<<" = 0"<<endl;
               total++;
            }
         }
      }
      cout<<total<<endl;
   }
}
