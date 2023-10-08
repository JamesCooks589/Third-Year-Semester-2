#pragma once

#include "Handler.h"
#include "User.h"

#include <string>
#include <iostream>


using namespace std;

class ValidateToken : public Handler {
    public:
        ValidateToken(Handler* successor, User* user) : Handler(successor), user(user) {}
        ~ValidateToken();

        void handleRequest(string type, string message) override;

        string token;
    private:
        User* user;
};