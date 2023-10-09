#include "newDATABASE.h"

std::string newDATABASE::select(std::string table) {
    return "FROM " + table + " SELECT *";
}
