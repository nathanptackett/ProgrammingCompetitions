/*
Only solves small data set
Just runs trouble sort and checks for errors
*/


#include <iostream>
#include <string>

using namespace std;

void reverseArray(int arr[], int start, int end);
void TroubleSort(int arr[], int length);
int sortMistake(int arr[], int length);

int main()
{
    int tc;
    cin>>tc;

    for(int loop = 1; loop <= tc; loop++)
    {
        int N;
        cin>>N;
        int num[N];

        for(int i = 0; i < N; i++)
            cin>>num[i];

        TroubleSort(num, N);
        int mistakeIndex = sortMistake(num, N);

        string result;
        if(mistakeIndex >= 0)
            result = to_string(mistakeIndex);
        else
            result = "OK";

        cout<<"Case #"<<loop<<": "<<result<<"\n";
    }
}

int sortMistake(int arr[], int length)
{
    for(int i = 1; i < length; i++)
    {
        if(arr[i - 1] > arr[i])
            return i - 1;
    }
    return -1;
}

void TroubleSort(int arr[], int length)
{
    bool done = false;

    while(!done)
    {
        done = true;
        for(int i = 0; i < length - 2; i++)
        {
            if(arr[i] > arr[i + 2])
            {
                done = false;
                reverseArray(arr, i, i+2);
            }
        }
    }
}

/* Function to reverse arr[] from start to end*/
void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
