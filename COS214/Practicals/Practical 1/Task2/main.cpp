//Carter Shin u21470864 & James Cooks u21654680
#include "consumerCreator.h"
#include <iostream>
using namespace std;
int main() {
    consumerCreator consumerCreator;

    // Test the parsing for OData/XML
    consumerCreator.setConsumer("OData");
    consumer* odataConsumer = consumerCreator.createConsumer();

    if (odataConsumer) {
        string odataInput = 
R"(
<section> 
    section 1
    <section> 
        subsection 2
        subitem 3 
    </section>
    subitem 4 
</section>
)";
        cout << odataConsumer->printData(odataInput) << endl;
        delete odataConsumer;
    } else {
        cout << "Consumer type not valid" << endl;
    }

    // Test the parsing for JSON
    consumerCreator.setConsumer("JSON");
    consumer* jsonConsumer = consumerCreator.createConsumer();

    if (jsonConsumer) {
        string jsonInput = "{\n   section 1 \n{\n      subsection 2\n      subitem 3\n   }\n   subitem 4\n}";
        cout << jsonConsumer->printData(jsonInput) << endl;
        delete jsonConsumer;
    } else {
        cout << "Consumer type not valid" << endl;
    }

    return 0;
}