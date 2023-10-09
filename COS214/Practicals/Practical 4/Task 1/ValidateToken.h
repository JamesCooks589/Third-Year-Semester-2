#pragma once

#include "Handler.h"
#include "User.h"

#include <string>
#include <iostream>

using namespace std;

/**
 * @class ValidateToken
 * @brief Handles two types of requests: "generatedToken" and "validateToken".
 *
 * This class represents a concrete handler in the chain of responsibility
 * design pattern. It handles two types of requests:
 * 1. "generatedToken": Updates its local token variable upon receiving this request.
 * 2. "validateToken": Validates the user's token with the payload/message in the request.
 *    If the token matches, it sets the user's verified field to true.
 */
class ValidateToken : public Handler {
public:
    /**
     * @brief Constructor for ValidateToken.
     * @param successor The next handler in the chain.
     * @param user A pointer to the User associated with the request.
     */
    ValidateToken(Handler* successor, User* user) : Handler(successor), user(user) {}

    /**
     * @brief Destructor for ValidateToken.
     */
    ~ValidateToken();

    /**
     * @brief Handle a request.
     *
     * This method handles two types of requests: "generatedToken" and "validateToken".
     * - For "generatedToken" requests, it updates its local token.
     * - For "validateToken" requests, it validates the user's token with the payload/message.
     *   If the token matches, it sets the user's verified field to true.
     *
     * @param type The type of the request.
     * @param message The message associated with the request.
     */
    void handleRequest(string type, string message) override;

    /**
     * The token value used for "generatedToken" requests.
     */
    string token;

private:
    /**
     * A pointer to the User associated with this handler.
     */
    User* user;
};
