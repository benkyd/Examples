const SerialPort = require('serialport');
const parsers = SerialPort.parsers;
const fs = require('fs');
let express = require('express');  
let app = express();  
let server = require('http').createServer(app);  
let io = require('socket.io')(server);
/* COMMUNICATION WITH ARDUINO AND CLENSING OF DATA */

let lastHour = []
let history = [];
let temperature;
const parser = new parsers.Readline({
    delimiter: '\r\n'
});
  
const port = new SerialPort('COM3', {
    baudRate: 115200
});

port.pipe(parser);

port.on('open', () => {
    console.log('Serial connection on COM3 initialized')
});

port.on('data', (data) => {
    let temp = parseFloat(data.toString());
    if (temp == NaN) return;
    if (temp == NaN) return;
    if (temp == undefined) return;
    if (temp == null) return;
    if (temp + 5 < temperature) return;
    if (temp - 5 > temperature) return;
    temperature = temp;
});

/* SIMPLE WEBSERVER */

app.use('/', express.static(__dirname + '/client'));  
app.get('/', function(req, res) {  
    res.sendFile(__dirname + '/client/index.html');
});
app.listen(7000);
console.log('Server listening on 8081')

/* WEBSOCKETS */

server.listen(7001);

io.on('connection', (socket) => {  
    let ip = socket.request.connection.remoteAddress;
    if (ip.startsWith('::ffff:')) ip = ip.substring(7);

    socket.on('handshake', function(data) {
        console.log('New client connecting at ' + ip)
        socket.emit('handshake', 'server');
    });

    socket.on('ready', function(data) {
        console.log('Handshake with ' + ip + ' successful')
        socket.emit('lasthour', lastHour);

        setInterval(() => {
            socket.emit('temp', [temperature, temperature * 2]);
        }, 60000);
    });

    socket.on('another', function(data) {
        socket.emit('temp', [temperature, temperature * 2]);
    });
});

setInterval(() => {
    history.push(temperature);
    lastHour.push(temperature);
    if (lastHour.length > 60) lastHour.splice(0,1);
    fs.appendFileSync('client/history.csv', `${new Date().toLocaleString()},${temperature}\n`)
}, 60000)
