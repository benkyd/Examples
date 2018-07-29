const fs = require('fs');
const ytdl = require('ytdl-core');

let videos = [];

if (!fs.existsSync('./videos.txt')) {
    console.log('Could not find videos.txt, make sure it exists and has youtube links, each on new lines');
    process.exit();
}

let text = fs.readFileSync('./videos.txt').toString();
text.split('\n').forEach((line) => {
    videos.push(line.replace(/\r/, ''));
});

videos.forEach((url) => {
    if (ytdl.validateURL(url)) {
        ytdl.getInfo(url, (err, info) => {
            if (err) {
                console.log(`An error occured while downloading '${url}'`)
            } else {
                let title = info.title;

                try {
                    let stream = ytdl(url, {quality: 'highest'}).pipe(fs.createWriteStream(`${title}.mp4`));
                    stream.on('finish', () => console.log(`Finish downloading ${title}`));
                } catch (e) {
                    console.log(`An error occured while downloaing '${title}' retrying`)
                    try {
                        let stream = ytdl(url, {quality: 'highest'}).pipe(fs.createWriteStream(`${title}.mp4`));
                        stream.on('finish', () => console.log(`Finish downloading '${title}'`));
                    } catch (e) {
                        console.log(`Unable to download '${title}'`)
                    }
                }
                console.log(`Downloading '${title}'`);
            }
        })
    } else console.log(`Video ${url} was not found`);
});
