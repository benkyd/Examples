const fs = require('fs');
const bodyParser = require('body-parser');
const utils = require('./utils');
let express = require('express');  
let app = express();  
let server = require('http').createServer(app);  
let io = require('socket.io')(server);

app.use('/', express.static(__dirname + '/client'));  
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));


io.on('connection', (socket) => {  
    let ip = socket.request.connection.remoteAddress;
    if (ip.startsWith('::ffff:')) ip = ip.substring(7);
    console.log(`${utils.currenttime()} new client connected at ${ip}`)

    socket.on('outward', async function(data) {

        // let rate = await rateLimit(socket);
        // if (rate == -1) return;
        name = data.name;
        message = data.message;

        let validate = validateMessage(message, socket);
        if (validate == -1) return;

        console.log(`${utils.currenttime()} ${name} {${ip}}: ${message}`);

        socket.broadcast.emit('receive', `${name}: ${message} \n`);
        socket.emit('receive', `${name}: ${message} \n`);
    });
});

function validateMessage(message) {
    if (message.length >= 2000) {
        socket.emit('receive', `YOU HAVE EXEDED THE 2000 CHARICTER LIMIT: MESSAGE NOT SENT \n`);
    }
}

let requests = [];
async function rateLimit(socket) {
    if (requests.indexOf(socket.request.connection.remoteAddress) != -1) {
        socket.emit('receive', `YOU ARE BEING RATE LIMITED, WAIT 1/2 SECOND\n`);
        await utils.sleep('10');

        while (requests.indexOf(socket.request.connection.remoteAddress) != -1) {
            requests.splice(requests.indexOf(socket.request.connection.remoteAddress), 1);
        }
        return -1;
    }
    requests.push(socket.request.connection.remoteAddress);
}

app.listen(8082);
server.listen(8083);
console.log('Server listening on 8082 and sockets are listening on 8083')
