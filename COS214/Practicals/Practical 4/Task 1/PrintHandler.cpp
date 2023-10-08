#include "PrintHandler.h"

PrintHandler::~PrintHandler() {
}

void PrintHandler::handleRequest(string type, string message) {
    if (user->getVerified()){
        if (type == "print"){
            cout << message << endl;        
        }
        else {
            Handler::handleRequest(type, message);
        }
    }
    else {
        cout << "User not verified" << endl;
        Handler::handleRequest(type, message);
    }

}