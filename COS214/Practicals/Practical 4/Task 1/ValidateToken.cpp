#include "ValidateToken.h"

void ValidateToken::handleRequest(string type, string message) {
    //If the type is "generatedToken" store the token
    if (type == "generatedToken") 
    {
        token = message; 
    }
    else if (type == "validateToken")
    {
        if (token == "")
        {
            cout << "No token has been generated yet." << endl;
        }
        else if (token == message)
        {
            //If the token matches the passed in message then the token is valid send to next handler
            user->setVerified(true);
        }
        else
        {
            cout << "Token is invalid." << endl;
        }
        
    }
    else
    {
        //If the type is not "generatedToken" send to next handler
        cout << "ValidateToken sending it to PrintHandler" << endl;
        Handler::handleRequest(type, message);
    }
}


//Destructor
ValidateToken::~ValidateToken() {
}