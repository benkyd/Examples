var socket = io.connect('http://benkyd.duckdns.org:8083');

let name;

window.addEventListener('keydown', (event) => {
    if (event.code == 'Enter') messagesend();
})

function messagesend() {
    if (!name) {
        while (name == null || name == undefined) {
            name = prompt('Enter your name:');
            tempname = name.replace(/^\s+/, '').replace(/\s+$/, '');
            if (tempname === '') {
                name = undefined;
            }
        }
    }

    let message = document.getElementById('in').value;

    if (message == '' || message == ' ') {
        document.getElementById('in').value = '';
        return;
    }

    tempmessage = message.replace(/^\s+/, '').replace(/\s+$/, '');
    if (tempname === '') {
        document.getElementById('in').value = '';
        return;
    }

    socket.emit('outward', {name: name, message: message})
    document.getElementById('in').value = '';
}

socket.on('receive', (data) => {
    console.log(data);
    document.getElementById('chat').value = document.getElementById('chat').value + data;
    document.getElementById('chat').scrollTop = document.getElementById('chat').scrollHeight; 
});

