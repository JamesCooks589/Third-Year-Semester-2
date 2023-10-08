#include "User.h"
#include "firstHandler.h"
#include "GenerateToken.h"
#include "ValidateToken.h"
#include "PrintHandler.h"

int main(int argc, char const *argv[])
{
    User* James = new User("James", "semaJ", false);

    //Make chain of responsibility
    Handler* printHandler = new PrintHandler(nullptr, James);
    Handler* validateToken = new ValidateToken(printHandler, James);
    Handler* generateToken = new GenerateToken(validateToken, James);
    Handler* firstHandler = new FirstHandler(generateToken, James);

    //Make request
    firstHandler->handleRequest("nonce", "");
    firstHandler->handleRequest("generateToken", James->signNonce(James->getNonce()));
    firstHandler->handleRequest("validateToken", James->getToken());
    firstHandler->handleRequest("print", "Hello World");

    cout << "END OF PROGRAM" << endl;


    return 0;
}
