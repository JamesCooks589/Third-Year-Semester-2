//Carter Shin u21470864 & James Cooks u21654680
#include "jsonConsumer.h"

string jsonConsumer::parseData(string data)
{
   string result = "";
    //Check the input data line by line
    stringstream ss(data);

    string line;
    while (getline(ss, line))
    {
        //If the line contains  "{" or "}", ignore it
        if (line.find("{") != string::npos || line.find("}") != string::npos)
        {
            result += "";
        }
        //else add the line to the result
        else
        {
            result += line + "\n";
        }
    }


    return result; 
}
