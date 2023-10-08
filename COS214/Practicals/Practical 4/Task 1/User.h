#pragma once

#include <string>
#include <iostream>


using namespace std;

class User {
    public:
        User(string username, string privateKey, bool verified = false);
        ~User();

        //Getters
        string getUsername();
        string getPrivateKey();
        string getNonce();
        string getToken();
        bool getVerified();

        //Setters
        void setUsername(string username);
        void setPrivateKey(string privateKey);
        void setNonce(string nonce);
        void setToken(string token);
        void setVerified(bool verified);

        //Functions
        string signNonce(string nonce);
        // void makeRequest(string type, string message);

    private:
        string username;
        string privateKey;
        string nonce;
        string token;
        bool verified;
};