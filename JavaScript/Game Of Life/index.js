/*
    Author(s): Ben (plane000)#8618
    Created: 25/06/2018
    Last Updated: 25/06/2018
    Last Updated by: Ben (plane000)#8618
*/

let c = document.getElementById("canv");
let ctx = c.getContext("2d");

let canvasSize = 400;
let gridSize = 40;
let grid = makeGridArr(gridSize); //0 = dead, 1 = alive
let next;

for (let i = 0; i < gridSize; i++) {
    for (let j = 1; j < gridSize; j++) {
        grid[i][j] = Math.round(Math.random());
    }
}

async function gameLoop() {
    next = makeGridArr(gridSize);
    update();
    draw();
}

function update() {
    for (let i = 0; i < gridSize; i++) {
        for (let j = 0; j < gridSize; j++) {
            let state = grid[i][j];
        
            let neighbors = countNeighbors(grid, i, j)

            if (state == 0 && neighbors == 3) {
                next[i][j] = 1;
            } else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
                next[i][j] = 0;
            } else {
                next[i][j] = state;
            }
        }
    }
    grid = next;
}

function countNeighbors(arr, x, y) {
    let sum = 0;
    for (let i = -1; i < 2; i++) {
      for (let j = -1; j < 2; j++) {
        sum += arr[(x + i + gridSize) % gridSize] [(y + j + gridSize) % gridSize];
      }
    }
    sum -= arr[x][y];
    return sum;
}

function makeGridArr(size) {
    arr = [];
    for (let i = 0; i < size; i++) {
        arr[i] = [];
        for (let j = 0; j < size; j++) {
            arr[i][j] = 0;
        }
    }
    return arr;
}

function draw () {
    ctx.fillStyle = "#FFFFFF";
    ctx.fillRect(0, 0, canvasSize, canvasSize);

    for (let i = 0; i < gridSize; i++) {
        for (let j = 0; j < gridSize; j++) {
            if (grid[i][j] == 0) {
                ctx.fillStyle = "#FFFFFF";
            } else {
                ctx.fillStyle = "#000000";
            }
            
            ctx.fillRect(i * 10, j * 10, canvasSize / gridSize, canvasSize / gridSize);
        }
    }
}

setInterval(gameLoop, 100);
