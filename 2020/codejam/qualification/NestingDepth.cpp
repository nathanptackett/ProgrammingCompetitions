#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char** argv)
{
    int T;
    cin>>T;
    for(int c = 1; c <= T; c++)
    {
        std::string input;
        std::stringstream output;
        cin>>input;

        int cur_depth = 0;
        for(int i = 0; i < input.size(); i++)
        {
            int next_num = (int)(input[i] - '0');
            while(cur_depth < next_num) {
                cur_depth++;
                output << '(';
            }
            while(cur_depth > next_num) {
                cur_depth--;
                output << ')';
            }
            output << input[i];
        }
        while(cur_depth > 0) {
            cur_depth--;
            output << ')';
        }

        cout<<"Case #"<<c<<": "<<output.str()<<endl;
    }
}