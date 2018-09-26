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

//This is broken AF.
app.post('/api/progress', (req, res, next) => {
  progress = req.body.progress;
  res.status(200).end(JSON.stringify({
    status: 'completed'
  }));
});