const express = require('express');
const bodyParser = require('body-parser');

let app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({
  extended: true
}));
let progress = 0;

if (process.argv.length >= 3) {
  app.listen(parseInt(process.argv[2]));
} else {
  app.listen(80);
}

app.use(express.static(__dirname + '/client'));

app.get('/api/progress', (req, res, next) => {
  res.status(200).end(JSON.stringify({
    progress: progress
  }));
});

//Wow this is broken. Child prodigy workaround deployed.
app.post('/api/progress', (req, res, next) => {
  progress = JSON.parse(Object.keys(req.body)[0]).progress;
  res.status(200).end(JSON.stringify({
    status: 'completed'
  }));
});