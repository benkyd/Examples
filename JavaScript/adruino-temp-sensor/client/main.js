console.log('Connecting to server')

var socket = io.connect('benkyd.duckdns.org:7001');
let temp = [];

socket.on('connect', function(data) {
    socket.emit('handshake', 'client');
});

socket.on('handshake', function(data) {
    socket.emit('ready');
});

socket.on('temp', function(data) {
    console.log(data);
    if (data[0] * 2 != data[1]) socket.emmit('another');
    addPoint(data[0]);
});

socket.on('lasthour', function(data) {
    console.log(data);
    data.forEach(point => {
        if (point != NaN || point != null || point != 'undefined' || point != 'NaN' || point != 'null' || point != 'undefined') {
            addPoint(point);
        }
    });
});
