#include "firstHandler.h"

void FirstHandler::handleRequest(string type, string message) {
    //If the type is a request for a nonce then generate nonce and send it back to the user
    if (type == "nonce") {
        //Generate nonce
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 9);
        string nonce = "";
        for (int i = 0; i < 10; i++) {
            nonce += to_string(dis(gen));
        }

        //Set the nonce for the user
        user->setNonce(nonce);
        //Send the nonce to the next handler
        Handler::handleRequest("generatedNonce", nonce);
    }
    //Else send the message to the next handler
    else {
        cout << "First handler sending it to GenerateToken" << endl;
        Handler::handleRequest(type, message);
    }
}

//Destructor
FirstHandler::~FirstHandler() {
}
