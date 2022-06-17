const { text } = require('express');
const express = require('express');
const app = express();
const port = 3000;
const { SerialPort } = require('serialport')


// or
//import { SerialPort } from 'serialport'



// Create a port
const arduinoSerialPort = new SerialPort({
  path: '/dev/cu.usbserial-2220',
  baudRate: 9600,
}, function (err) {
    if (err) {
      return console.log('Error: ', err.message)
    }
});

/*

let SerialPort = require('serialport');

var port = 3000;
var arduinoCOMPort = '/dev/cu.usbserial-210';
/*sp = SerialPort.SerialPort;

const serialport = new SerialPort({ path: '/dev/example', baudRate: 9600 })
serialport.write('ROBOT POWER ON')
*/
//var arduinoSerialPort = new SerialPort.SerialPort(
//    arduinoCOMPort, {path:'/dev/example', baudrate: 9600});
arduinoSerialPort.on('open',function() {
  console.log('Serial Port  is opened.');
});
app.get('/', function (req, res) {
    return res.send("Bem vindo ao programa");
})
app.get('/:action', function (req, res) {
   var action = req.params.action || req.param('action');
    if(action == 'led1on'){
        arduinoSerialPort.write("a");
        return res.send('Led1 light is on!');
    }
    if(action == 'led2on'){
      arduinoSerialPort.write("b");
      return res.send('Led2 light is on!');
    }
    if(action == 'led3on'){
      arduinoSerialPort.write("c");
      return res.send('Led3 light is on!');
    }
    if(action == 'alloff') {
        arduinoSerialPort.write("d");
        return res.send("Led light is off!");
    }
    
    return res.send('Action: ' + action);
});
app.listen(port, function () {
console.log('Example app listening on port http://0.0.0.0:' + port + '!');
});