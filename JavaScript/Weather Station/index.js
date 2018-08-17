const SerialPort = require('serialport');
const parsers = SerialPort.parsers;
const fs = require('fs');
let express = require('express');  
let app = express();


const parser = new parsers.Readline({
    delimiter: '\r\n'
});

const port = new SerialPort('COM3', {
    baudRate: 115200
});

port.pipe(parser);

let temperature;

port.on('data', async (data) => {
    if (data.toString().startsWith('VALID')) {
        if (parseFloat(data.toString().substring(5)) % 1) {} else return;

        let temp = parseFloat(data.toString().substring(5));
        temperature = temp;
        console.log(temp);
    }
});
