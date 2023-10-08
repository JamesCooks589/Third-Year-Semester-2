#pragma once

#include "Handler.h"
#include "User.h"

#include <string>
#include <iostream>

using namespace std;

class PrintHandler : public Handler {
    public:
        PrintHandler(Handler* successor, User* user) : Handler(successor), user(user) {}
        ~PrintHandler();

        void handleRequest(string type, string message) override;

    private:
        User* user;
};