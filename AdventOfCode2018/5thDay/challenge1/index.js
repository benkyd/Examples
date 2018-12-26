const day4 = require('./istolethisfromsomeone');
const fs = require('fs');

console.log('Part 1: ' + day4.part1(fs.readFileSync('input.txt').toString()));
console.log('Part 2: ' + day4.part2(fs.readFileSync('input.txt').toString()));
