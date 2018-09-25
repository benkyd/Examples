const express = require('express');
const bodyParser = require('body-parser');

let app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));
let progress = 0;

app.listen(80);

app.use(express.static(__dirname + '/client'));
app.get('/', (req, res, next) => {
    res.status(200).sendFile('index.html');
});

app.get('/progress', (req, res, next) => {
    res.status(200).end(JSON.stringify({
        progress: progress
    }));
});

app.post('/progress', (req, res, next) => {
    progress = req.body.progress;
    res.status(200).end(JSON.stringify({
        status: 'completed'
    }));
});
