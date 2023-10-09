#pragma once

#include "Handler.h"
#include "User.h"

#include <string>
#include <iostream>
#include <random>

using namespace std;
/**
 * @class FirstHandler
 * @brief Handles a specific type of request in a chain of responsibility.
 *
 * This class represents a concrete handler in the chain of responsibility
 * design pattern. It handles a specific type of request based on the provided
 * type and message.
 */

class FirstHandler : public Handler {
    public:
        /**
         * @brief Constructor for FirstHandler.
         * @param successor The next handler in the chain.
         * @param user A pointer to the User associated with the request.
         */
        FirstHandler(Handler* successor, User* user) : Handler(successor), user(user) {}
        virtual ~FirstHandler();

        /**
         * @brief Handle a request.
         *
         * This method handles a request of a specific type with the given message.
         * For "nonce" requests, it generates a nonce value, sends that value along the
         * chain to the generateToken with type "generatedNonce" for verification, and
         * sets the user's nonce variable.
         *
         * @param type The type of the request.
         * @param message The message associated with the request.
         */
        void handleRequest(string type, string message) override;

    private:
        User* user;
};