#include <iostream>
#include "eORM.h"
#include "newDATABASE.h"
#include "databaseADAPTER.h"

int main() {
    eORM orm;
    std::cout << orm.select("users") << std::endl;  //outputs: SELECT * FROM users

    newDATABASE new_db;
    databaseADAPTER adapter(&new_db);
    std::cout << adapter.select("users") << std::endl;  //outputs: SELECT * FROM users

    return 0;
}
