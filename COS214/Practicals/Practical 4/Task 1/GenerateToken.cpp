#include "generateToken.h"

void GenerateToken::handleRequest(string type, string message) {
    if (type == "generatedNonce"){
        this->nonce = message;
    }
    else if (type == "generateToken")
    {
        //If nonce is empty then the user has not requested a nonce yet send error message
        if (nonce == "") {
            cout << "Error: User has not requested a nonce yet." << endl;
        }
        //Else if local nonce matches passed in message then generate token
        else if (user->signNonce(nonce) == message) {
            //Generate token
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(0, 9);
            string token = "";
            for (int i = 0; i < 10; i++) {
                token += to_string(dis(gen));
            }

            //Set the token for the user
            user->setToken(token);
            //Send the token to the next handler
            Handler::handleRequest("generatedToken", token);
        }
        //Else nonce does not match passed in message send error message
        else {
            cout << "Error: Nonce does not match." << endl;
        }
    }
    //Else send the message to the next handler
    else {
        cout << "GenerateToken sending it to ValidateToken" << endl;
        Handler::handleRequest(type, message);
    }
    

}

//Destructor
GenerateToken::~GenerateToken() {
}