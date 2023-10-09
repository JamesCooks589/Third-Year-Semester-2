#include "databaseADAPTER.h"

databaseADAPTER::databaseADAPTER(newDATABASE* new_database) : new_database(new_database){}

std::string databaseADAPTER::select(std::string table){
    //translate the grammar
    std::string command = new_database->select(table);
    size_t from_pos = command.find("FROM ");
    size_t select_pos = command.find(" SELECT *");
    return "SELECT * FROM " + command.substr(from_pos + 5, select_pos - from_pos - 5);
}
