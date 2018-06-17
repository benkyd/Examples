const Discord = require('discord.js');
const fs = require('fs');

let config = { }
const client = new Discord.Client( {
    autoReconnect: true,
});

function createConfig() {
    config = {
        Token: 'DISCORD TOKEN',
        NowPlaying: 'NOW PLAYING'
    };
}

function load() {
    config = JSON.parse(fs.readFileSync('config.json'));
}

function save() {
    fs.writeFileSync('config.json', JSON.stringify(config, null, 4));
}

if (!fs.existsSync('config.json')) {
    createConfig();
    save();
    console.log('Exiting... Add your token to the config.json file');
    process.exit();
}

load();
client.login(config.Token);

client.on('ready', () => {
    console.log('SELFBOT HAS LOGGED IN...');
});

client.on('message', async (message) => {
    client.user.setActivity(config.NowPlaying);
    if(message.content.startsWith('@!')) {
        let msg = message.content.substring(3);
        config.NowPlaying = msg;
        save();
        client.user.setActivity(config.NowPlaying);
        console.log(message.content);
    }
});