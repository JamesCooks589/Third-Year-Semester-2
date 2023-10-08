#pragma once

#include "Handler.h"
#include "User.h"

#include <string>
#include <iostream>
#include <random>

using namespace std;

class FirstHandler : public Handler {
    public:
        FirstHandler(Handler* successor, User* user) : Handler(successor), user(user) {}
        virtual ~FirstHandler();


        void handleRequest(string type, string message) override;

    private:
        User* user;
};