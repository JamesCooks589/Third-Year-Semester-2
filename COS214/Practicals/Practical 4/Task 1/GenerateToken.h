#pragma once

#include "Handler.h"
#include "User.h"

#include <string>
#include <iostream>
#include <random>

using namespace std;

/**
 * @class GenerateToken
 * @brief Handles two types of requests: "generatedNonce" and "generateToken".
 *
 * This class represents a concrete handler in the chain of responsibility
 * design pattern. It handles two types of requests:
 * 1. "generatedNonce": Updates its local nonce value upon receiving this request.
 * 2. "generateToken": Verifies the user's nonce with its own nonce and the user's key.
 *    If valid, it generates a new token and performs two actions:
 *    - Sets the user's token variable.
 *    - Sends "generatedToken" to the next object in the chain for user verification.
 */
class GenerateToken : public Handler {
public:
    /**
     * @brief Constructor for GenerateToken.
     * @param successor The next handler in the chain.
     * @param user A pointer to the User associated with the request.
     */
    GenerateToken(Handler* successor, User* user) : Handler(successor), user(user) {}

    /**
     * @brief Destructor for GenerateToken.
     */
    ~GenerateToken();

    /**
     * @brief Handle a request.
     *
     * This method handles two types of requests: "generatedNonce" and "generateToken".
     * - For "generatedNonce" requests, it updates its local nonce.
     * - For "generateToken" requests, it verifies the user's nonce and generates a new token
     *   if the verification is successful. It then sets the user's token and sends
     *   "generatedToken" to the next object in the chain for further verification.
     *
     * @param type The type of the request.
     * @param message The message associated with the request.
     */
    void handleRequest(string type, string message) override;

    /**
     * The nonce value used for nonce-based requests.
     */
    string nonce;

private:
    /**
     * A pointer to the User associated with this handler.
     */
    User* user;
};
