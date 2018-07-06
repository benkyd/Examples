const fs = require('fs');
const request = require('sync-request');
const jimp = require('jimp');
const https = require('https');

function loadUsernames(path) {
    if (!fs.existsSync(path)) {
        console.log(`ERROR: there is no ${path}`);
        process.exit();
    }
    let text = fs.readFileSync(path).toString();
    let out = [];
    text.split('\n').forEach((line) => {
        out.push(line.replace(/\r/, ''));
    });
    return out;
}

function getFaces(usernames) {
    usernames.forEach((username) => {
        https.get(`https://api.mojang.com/users/profiles/minecraft/${username}`, (uuid_resp) => {
            let uuid_data = '';
            uuid_resp.on('data', (chunk) => {
                uuid_data += chunk;
            });
            uuid_resp.on('end', () => {
                if (uuid_data) {
                    let uuid = JSON.parse(uuid_data).id;
                    https.get(`https://sessionserver.mojang.com/session/minecraft/profile/${uuid}`, (img_resp) => {
                        let img_data = '';
                        img_resp.on('data', (chunk) => {
                            img_data += chunk;
                        });
                        img_resp.on('end', () => {
                            let res = JSON.parse(img_data);
                            let link = JSON.parse(Buffer.from(res.properties[0].value, 'base64').toString('ascii')).textures.SKIN.url;
                            jimp.read(link, function (err, lenna) {
                                if (err) throw err;
                                lenna.crop(8,8,8,8)
                                     .resize(256, 256, jimp.RESIZE_NEAREST_NEIGHBOR)
                                     .write(`images/${username}.png`);

                                console.log(`${username}'s skin cropped successfully`);
                            });
                        });

                    }).on("error", (err) => {
                        console.log(`ERROR: Couldn't get ${username}'s skin!`);
                    });
                }
                else {
                    console.log(`ERROR: Couldn't get ${username}'s UUID!`);
                }
            });
        }).on("error", (err) => {
            console.log(`ERROR: Couldn't get ${username}'s UUID!`);
        });
    });
}

let usernames = loadUsernames('names.txt');
getFaces(usernames);

