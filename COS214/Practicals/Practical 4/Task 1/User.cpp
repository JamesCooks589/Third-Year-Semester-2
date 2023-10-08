#include "User.h"

User::User(string username, string privateKey, bool verified) {
    this->username = username;
    this->privateKey = privateKey;
    this->verified = verified;
}

User::~User() {
}

//Getters

string User::getUsername() {
    return username;
}

string User::getPrivateKey() {
    return privateKey;
}

string User::getNonce() {
    return nonce;
}

string User::getToken() {
    return token;
}

bool User::getVerified() {
    return verified;
}

//Setters

void User::setUsername(string username) {
    this->username = username;
}

void User::setPrivateKey(string privateKey) {
    this->privateKey = privateKey;
}

void User::setNonce(string nonce) {
    this->nonce = nonce;
}

void User::setToken(string token) {
    this->token = token;
}

void User::setVerified(bool verified) {
    this->verified = verified;
}

//Functions

string User::signNonce(string nonce) {
    return nonce + privateKey;
}

