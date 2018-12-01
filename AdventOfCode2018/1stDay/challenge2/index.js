const fs = require('fs');
let input = fs.readFileSync('input.txt')
                .toString()
                .split('\n')
                .map((x) => parseInt(x));

let seenFrequencies = new Set([0]);
let total = 0;
let i = 0;

while (true) {
    if (i === input.length) {
        i = 0;
        continue;
    }
    total += input[i];
    if (seenFrequencies.has(total)) {
        break;
    }
    seenFrequencies.add(total);
    i++;
}

console.log(total)
