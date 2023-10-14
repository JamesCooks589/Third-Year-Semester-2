#pragma once

#include <string>
#include <iostream>

using namespace std;

/**
 * @class Handler
 * @brief Abstract base class for handling requests in a chain of responsibility.
 *
 * This abstract base class defines the interface for concrete handlers in the
 * chain of responsibility design pattern. It provides a method for handling requests
 * and has a reference to a successor handler in the chain.
 */
class Handler {
public:
    /**
     * @brief Constructor for Handler.
     * @param successor A pointer to the next handler in the chain.
     */
    Handler(Handler* successor) : successor(successor) {}

    /**
     * @brief Destructor for Handler (virtual to allow for proper cleanup in derived classes).
     */
    virtual ~Handler() {}

    /**
     * @brief Handle a request.
     *
     * This method defines the interface for handling requests. It can be overridden
     * in concrete handler classes to provide specific request handling behavior.
     *
     * @param type The type of the request.
     * @param message The message associated with the request.
     */
    virtual void handleRequest(string type, string message) {
        if (successor != nullptr) {
            successor->handleRequest(type, message);
        } else {
            cout << "End of the line bucko." << endl;
        }
    }

protected:
    /**
     * A pointer to the next handler in the chain.
     */
    Handler* successor;
};
