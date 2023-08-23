//Carter Shin u21470864 & James Cooks u21654680
#include "consumerCreator.h"
#include "jsonConsumer.h"
#include "odataConsumer.h"
#include <iostream>

void consumerCreator::setConsumer(string type)
{
    //Checks if type is JSON or OData 
    if (type == "JSON")
    {
        consumerType = "JSON";
    }
    else if (type == "OData"){
        consumerType = "OData";
    }
    //If not, error message
    else {
        //Error message
        cout << "Invalid consumer type" << endl;
    }
}

string consumerCreator::getConsumer()
{
    return consumerType;
}

consumer* consumerCreator::createConsumer()
{
    //Instantiates a new consumer based on the type
   if (consumerType == "JSON")
   {
        return new jsonConsumer();
   }
   else if (consumerType == "OData")
   {
        return new odataConsumer();
   }
    
}
