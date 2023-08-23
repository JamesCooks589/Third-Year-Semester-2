//Carter Shin u21470864 & James Cooks u21654680
#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <string>

using namespace std;

class primitive{
    public:
        string shape;
        string getShape();
        void setShape(string shape);
    protected:
        virtual string toString()=0;
};

#endif