#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct TTask{
    int start;
    int end;
    int i;

    bool operator <(TTask rhs)
    {
        return start < rhs.start;
    }
} TTask;

int main(int argc, char** argv)
{
    int T;
    cin>>T;
    for(int c = 1; c <= T; c++)
    {
        std::vector<TTask> tasks;
        bool C = true, J = true, impossible = false;
        TTask C_task, J_task;
        int N;
        cin >> N;
        char output[N + 1];
        output[N] = 0;
        for(int i = 0; i < N; i++)
        {
            TTask t;
            cin>>t.start>>t.end;
            t.i = i;
            tasks.push_back(t);
        }
        sort(tasks.begin(), tasks.end());

        for(int i = 0; i < tasks.size(); i++)
        {
            if(!C)
                if(tasks[i].start >= C_task.end)
                    C = true;
            if(!J)
                if(tasks[i].start >= J_task.end)
                    J = true;
            if(C)
            {
                C = false;
                C_task = tasks[i];
                output[C_task.i] = 'C';
            }
            else if(J)
            {
                J = false;
                J_task = tasks[i];
                output[J_task.i] = 'J';
            }
            else
            {
                impossible = true;
                break;
            }
        }
        cout<<"Case #"<<c<<": ";
        if(impossible)
            cout<<"IMPOSSIBLE\n";
        else
            cout<<output<<endl;
    }
}