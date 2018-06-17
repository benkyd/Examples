const fs = require('fs');
const Jimp = require('jimp');


let str = 'Hello, world! ┌─－─┬ － │ １ │ ２ │   ♖ │ ♘ │ \n HEllo'

//let str ='┌─－─┬─－─┬─－─┬─－─┬─－─┬─－─┬─－─┬─－─┬─－─┐ \n' +
//         '│ － │ １ │ ２ │ ３ │ ４ │ ５ │ ６ │ ７ │ ８ │ \n' +
//         '├─－─╆━－━┿━－━┿━－━┿━－━┿━－━┿━－━┿━－━┿━－━┥ \n' +
//         '| Ａ ┃ ♖ │ ♘ │ ♗ │ ♕ │ ♔ │ ♗ │ ♘ │ ♖ | \n' +
//         '├─－─╂─－─┼─－─┼─－─┼─－─┼─－─┼─－─┼─－─┼─－─┤ \n' +
//         '| Ｂ ┃ ♙ │ ♙ │ ♙ │ ♙ │ ♙ │ ♙ │ ♙ │ ♙ | \n' +
//         '├─－─╂─－─┼─－─┼─－─┼─－─┼─－─┼─－─┼─－─┼─－─┤ \n' +
//         '| Ｃ ┃ － │ － │ － │ － │ － │ － │ － │ － | \n' +
//         '├─－─╂─－─┼─－─┼─－─┼─－─┼─－─┼─－─┼─－─┼─－─┤ \n' +
//         '| Ｄ ┃ － │ － │ － │ － │ － │ － │ － │ － | \n' +
//         '├─－─╂─－─┼─－─┼─－─┼─－─┼─－─┼─－─┼─－─┼─－─┤ \n' +
//         '| Ｅ ┃ － │ － │ － │ － │ － │ － │ － │ － | \n' +
//         '├─－─╂─－─┼─－─┼─－─┼─－─┼─－─┼─－─┼─－─┼─－─┤ \n' +
//         '| Ｆ ┃ － │ － │ － │ － │ － │ － │ － │ － | \n' +
//         '├─－─╂─－─┼─－─┼─－─┼─－─┼─－─┼─－─┼─－─┼─－─┤ \n' +
//         '| Ｇ ┃ ♟ │ ♟ │ ♟ │ ♟ │ ♟ │ ♟ │ ♟ │ ♟ | \n' +
//         '├─－─╂─－─┼─－─┼─－─┼─－─┼─－─┼─－─┼─－─┼─－─┤ \n' +
//         '| Ｈ ┃ ♜ │ ♞ │ ♝ │ ♚ │ ♛ │ ♝ │ ♞ │ ♜ | \n' +
//         '└─－─┸─－─┴─－─┴─－─┴─－─┴─－─┴─－─┴─－─┴─－─┘ \n';

Jimp.read("resources/start.png").then(function (image) {
    image.resize(1200, 1200);
    
    Jimp.loadFont(Jimp.FONT_SANS_32_BLACK).then(function (font) {
        image.print(font, 10, 10, str);
        image.write('resources/chess/img.png');
    });

}).catch(function (err) {
    console.error(err);
});

//var flag = new Jimp(200, 200, (err2, base) => {
//    image.contain(604, 303, Jimp.RESIZE_BICUBIC, (err3, src) => {
//        base.composite(src, 0, 88)
//            .composite(background, 0, 0)
//            .getBuffer(Jimp.MIME_PNG, (err4, buffer) => {
//                //message.channel.send(new Discord.Attachment(buffer));
//            });
//    });
//});