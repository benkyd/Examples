const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');

const app = express();

// Done with HTTP so that it's easier to use websockets in the future
const server = require('http').createServer(app);
console.log('Server Settup');

// Server homepage
app.use(express.static('./static'));
if (!fs.existsSync('./movies/')) {
    fs.mkdirSync('./movies');
    console.log('Please provide a movies folder and put movies in it');
    process.exit(1);
}
app.use(express.static('./movies'));

app.listen(80);
console.log('App listening on port 80');


app.get('/movies', async (req, res) => {
    let response = [];

    let movies = fs.readdirSync('./movies');
    for (movie of movies) {
        response.push(movie);
    }

    res.send(JSON.stringify(response));
});

