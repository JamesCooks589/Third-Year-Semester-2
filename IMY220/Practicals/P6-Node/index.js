const http = require('http');
const fs = require('fs');
const { checkDate, checkName } = require('./eventValidator');

const server = http.createServer((req, res) => {
    //Output a simple message to the console
    console.log('User joined the server');

    //Read 'events.json' file
    fs.readFile('events.json', 'utf8', (err, data) => {
        //Check for errors
        if (err) {
            console.log(`Error: ${err}`);
            res.writeHead(404, { 'Content-Type': 'text/plain' });
            res.end('404 Not Found');
            return;
        } else {
            //Parse JSON data into an object
            const events = JSON.parse(data);

            //Set HTTP response header
            res.writeHead(200, { 'Content-Type': 'text/html' });

            //create an html table with 4 headings 'Event name' 'Event description' 'Event date' 'Event details'
            res.write('<table border="1">');
            res.write('<tr>');
            res.write('<th>Event name</th>');
            res.write('<th>Event description</th>');
            res.write('<th>Event date</th>');
            res.write('<th>Event details</th>');
            res.write('</tr>');

            //Loop through the events object with for each
            events.forEach(event => {
                const title = event.title;
                const date = event.date;

                //Check if the event validity
                const validDate = checkDate(date);
                const validName = checkName(title);

                let details = '';
                if (validDate){
                    details += 'Event is in date range. ';
                }
                else{
                    details += 'Event is not in date range. ';
                }
                if (validName){
                    details += 'Event name is valid';
                }
                else{
                    details += 'Event name is not valid';
                }

                res.write('<tr>');
                res.write(`<td>${title}</td>`);
                res.write(`<td>${event.description}</td>`);
                res.write(`<td>${date}</td>`);
                res.write(`<td>${details}</td>`);
                res.write('</tr>');
            }
            );

            //Close the table
            res.write('</table>');

            //End the response
            res.end();
        }
    }
    );
}
);
console.log('Server started on port 8888');
server.listen(8888);