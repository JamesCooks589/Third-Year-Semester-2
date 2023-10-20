//James Cooks u21654680

//Connect to mongoDB
const { MongoClient } = require('mongodb');

const uri = "mongodb+srv://Test:Test1234@clustermccluster.pwjvbxq.mongodb.net/?retryWrites=true&w=majority";
const client = new MongoClient(uri);

const startDate = '2022/10/08';
const endDate = '2022/10/26';

async function run() {
    try {
        const database = client.db('DBExample');
        const collection = database.collection('events');

        // Query
        const query = {
            "locations": {
                $elemMatch: {
                    "area": "Brooklyn",
                    "date": {
                        $gte: startDate,
                        $lte: endDate
                    }
                }
            }
        };
        const options = { projection: { _id: 0, name: 1, description: 1 } };

        // Execute query and use await
        const cursor = await collection.find(query, options).toArray();

        // print a message if no documents were found
        if (cursor.length === 0) {
            console.log("No documents found!");
        } else {
            //Display results with square brackets
            console.log("[");
            cursor.forEach(doc => console.log(doc));
            console.log("]");

            //I opted to manually display the brackets otherwise I stringify the array
        }
    } finally {
        await client.close();
    }
}

run().catch(console.dir);
