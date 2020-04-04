#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
    int T;
    cin>> T;
    for(int c = 1; c <= T; c++)
    {
        int N;
        cin >> N;
        int diag = 0;
        int row_repeated = 0;
        int col_repeated = 0;
        std::map<int, int> row_store;
        std::map<int, int> col_store;
        bool row_repeats[N];
        bool col_repeats[N];
        memset(row_repeats, 0x0, sizeof(row_repeats));
        memset(col_repeats, 0x0, sizeof(col_repeats));
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                int x;
                cin >> x;

                if(i == j)
                    diag += x;

                if(++row_store[i << 16 | x] >= 2)
                {
                    if(!row_repeats[i])
                    {
                        row_repeats[i] = true;
                        row_repeated++;
                    }
                }
                if(++col_store[j << 16 | x] >= 2)
                {
                    if(!col_repeats[j])
                    {
                        col_repeats[j] = true;
                        col_repeated++;
                    }
                }
            }
        }
        cout<<"Case #"<<c<<": "<<diag<<" "<<row_repeated<<" "<<col_repeated<<endl;
    }
}