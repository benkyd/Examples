const express = require('express');
const request = require('snekfetch');
const bodyParser = require('body-parser');
const fs = require('fs');

let port = 8080;
let app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static('./client'));

let apiKey = '8787dcc902ae16212b6325ad5628b4c1'
let lat;
let long;
let units = 'auto';

app.get('/', function (req, res) {
    res.sendFile( __dirname + '/client');
}); 

app.get('/weather', async function (req, res) {
    console.log('New Request from ' + req.connection.remoteAddress);
    let ext = ['°C', '°F'];
    let chos;
    lat = req.query.lat;
    long = req.query.long;
    if (!req.query.celsius) {
        units = 'si';
        chos = 0;
    } else {
        units = 'us';
        chos = 1;
    }

    let weather = await startreq();
    
    if (weather.toString() != -1) {
        res.end(weather.toString() + ext[chos]);
    } else {
        res.end('Invalid Coordinates');
    }
    
});

async function startreq() {
    try {
        let req = request.get(`https://api.darksky.net/forecast/${apiKey}/${lat},${long}`)
        req.query('units', units)
        let res = await req.send();

        return res.body.currently.summary + ', ' + res.body.currently.temperature;
    } catch (e) {
        return -1;
    }
}

let server = app.listen(port);
console.log(`App listening at ${port}`);
