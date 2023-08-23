//Carter Shin u21470864 & James Cooks u21654680
#include "client.h"

void Client::printData(const std::string& data) {
    std::string formattedData = parseData(data);
    std::cout << "Formatted Data: " << formattedData << std::endl;
}
