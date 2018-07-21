console.log('Connecting to server')

var socket = io.connect('benkyd.duckdns.org:8081');
let temp = [];

socket.on('connect', function(data) {
    socket.emit('handshake', 'client');
});

socket.on('handshake', function(data) {
    socket.emit('ready');
});

socket.on('temp', function(data) {
    console.log(data);
    addPoint(data);
});

socket.on('lasthour', function(data) {
    console.log(data);
    data.forEach(point => {
        if (point != NaN || point != null || point != 'undefined' || point != 'NaN' || point != 'null' || point != 'undefined') {
            addPoint(point);
        }
    });
});
