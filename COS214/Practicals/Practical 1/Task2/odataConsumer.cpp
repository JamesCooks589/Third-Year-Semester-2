//Carter Shin u21470864 & James Cooks u21654680
#include "odataConsumer.h"

string odataConsumer::parseData(string data)
{
    string result = "";
    //Check the input data line by line
    stringstream ss(data);

    string line;
    while (getline(ss, line))
    {
        //If the line contains  <section> or </section>, ignore it
        if (line.find("<section>") != string::npos || line.find("</section>") != string::npos)
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
