const fs = require('fs');
let input = fs.readFileSync('input.txt').toString().split('\n').join('');
console.log(eval(input));
