#pragma once

#include "Handler.h"
#include "User.h"

#include <string>
#include <iostream>

using namespace std;

/**
 * @class PrintHandler
 * @brief Handles a "print" request by checking user verification.
 *
 * This class represents the last handler in the chain of responsibility
 * design pattern. It handles "print" requests by checking if the user is verified.
 * If the user is verified, it prints out the message supplied by the user. Otherwise,
 * it returns an error indicating that the user isn't verified.
 */
class PrintHandler : public Handler {
public:
    /**
     * @brief Constructor for PrintHandler.
     * @param successor The next handler in the chain.
     * @param user A pointer to the User associated with the request.
     */
    PrintHandler(Handler* successor, User* user) : Handler(successor), user(user) {}

    /**
     * @brief Destructor for PrintHandler.
     */
    ~PrintHandler();

    /**
     * @brief Handle a request.
     *
     * This method handles "print" requests. It checks whether the user is verified.
     * If the user is verified, it prints out the supplied message. Otherwise, it returns
     * an error indicating that the user isn't verified.
     *
     * @param type The type of the request.
     * @param message The message associated with the request.
     */
    void handleRequest(string type, string message) override;

private:
    /**
     * A pointer to the User associated with this handler.
     */
    User* user;
};
