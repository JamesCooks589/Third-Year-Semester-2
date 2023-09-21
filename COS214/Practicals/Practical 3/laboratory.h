#pragma once
#include <string>

using namespace std;

class Laboratory {
    private:
    //two parallel arrays for storing item to be researched and time taken to research
    string* items;
    int* times;
    int capacity;
    int current;
    public:
    Laboratory(int iCapacity);
    ~Laboratory();
    void addItem(string item, int time);
    void removeItem(string item);
    int getTime(string item);
    string toString();
};
