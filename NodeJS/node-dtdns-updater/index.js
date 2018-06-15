const snekfetch = require('snekfetch');
const fs = require('fs');

let verbose = false;

if (process.argv.indexOf('-v') >= 0 || process.argv.indexOf('--verbose') >= 0) {
  verbose = true;
}

let config = {};
if (!fs.existsSync('./config.json')) {
  config.id = 'dtdns domain';
  config.pw = 'dtdns account password';
  config.ip = 'ip to point (let blank for current ip)';
  config.delay = 120000;
  fs.writeFileSync('./config.json', JSON.stringify(config));
  console.error('Please configure the newly created config.json');
  process.exit(-1);
}
else {
  let text = fs.readFileSync('./config.json');
  config = JSON.parse(text);
}

if (verbose === true) {
  log(`Delay set to ${config.delay}`);
  if (config.ip) {
    log(`Pointed ip is ${config.ip}`);
  }
  else {
    log('Pointed ip is current ip');
  }
  log('Started in verbose mode');
}

async function update() {
  if (verbose) {
    log('Attempting GET request.');
  }
  try {
    let req = snekfetch.get('https://www.dtdns.com/api/autodns.cfm')
      .query('id', config.id)
      .query('pw', config.pw);
    if (config.ip !== '') {
      req.query('ip', config.ip);
    }
    req.query('client', 'NodeDtDUp');
    let res = await req.send();
    if (verbose) {
      log(`Server response : ${res.body}`);
    }
  }
  catch (e) {
    if (verbose) {
      log(e);
    }
  }
}

/* eslint-disable */

function log(message) {
  let date = new Date();
  console.log('[' + date.getFullYear() + '/' + date.getDate() + '/' + (date.getMonth() + 1) + '-' + date.getHours() + ':' + date.getMinutes() + ':' + date.getSeconds() + ']' + message);

/* eslint-enable */

update();

setInterval(update, config.delay);
