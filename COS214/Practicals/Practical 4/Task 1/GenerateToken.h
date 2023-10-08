#pragma once

#include "Handler.h"
#include "User.h"

#include <string>
#include <iostream>
#include <random>

using namespace std;

class GenerateToken : public Handler {
    public:
        GenerateToken(Handler* successor, User* user) : Handler(successor), user(user) {}
        ~GenerateToken();

        void handleRequest(string type, string message) override;

        string nonce;
    private:
        User* user;
};