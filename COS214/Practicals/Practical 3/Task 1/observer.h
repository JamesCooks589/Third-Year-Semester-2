#ifndef OBSERVER_H
#define OBSERVER_H

class Contract;

class Observer 
{
    public: 
        virtual void update(const Contract* c) = 0;
        virtual ~Observer(){};
};

#endif