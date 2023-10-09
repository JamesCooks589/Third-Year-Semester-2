#include "eORM.h"

std::string eORM::select(std::string table) {
    return "SELECT * FROM " + table;
}
