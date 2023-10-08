#pragma once

#include <string>
#include <iostream>

using namespace std;

class Handler {
    public:
        Handler(Handler* successor) : successor(successor) {}
        virtual ~Handler() {}
        virtual void handleRequest(string type, string message) {
            if (successor != nullptr) {
                successor->handleRequest(type, message);
            }
            else {
                cout << "End of the line bucko." << endl;
            }
        }

    protected:
        Handler* successor;
};