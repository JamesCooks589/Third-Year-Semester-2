#pragma once

#include <string>
#include <iostream>

using namespace std;

/**
 * @class User
 * @brief Represents a user with various attributes and methods.
 *
 * This class represents a user in the system, with attributes such as username,
 * private key, nonce, token, and verification status. It provides getters and setters
 * for these attributes and includes a method to sign a nonce using the private key.
 */
class User {
public:
    /**
     * @brief Constructor for User.
     * @param username The username of the user.
     * @param privateKey The private key associated with the user.
     * @param verified The verification status of the user (default is false).
     */
    User(string username, string privateKey, bool verified = false);

    /**
     * @brief Destructor for User.
     */
    ~User();

    // Getters
    string getUsername();
    string getPrivateKey();
    string getNonce();
    string getToken();
    bool getVerified();

    // Setters
    void setUsername(string username);
    void setPrivateKey(string privateKey);
    void setNonce(string nonce);
    void setToken(string token);
    void setVerified(bool verified);

    /**
     * @brief Sign a nonce using the user's private key.
     *
     * This method takes the user's nonce value and concatenates it with the user's
     * private key to create a signature.
     *
     * @param nonce The nonce value to sign.
     * @return The signature created by signing the nonce.
     */
    string signNonce(string nonce);

private:
    string username;
    string privateKey;
    string nonce;
    string token;
    bool verified;
};
