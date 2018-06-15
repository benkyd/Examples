let c = document.getElementById("canv");
let ctx = c.getContext("2d");

let screenHeight = 40;
let screenWidth = 40;
let grid = []; //0 = nothing, 1 = snake, 2 = apple

let direction = 0; //0 = up, 1 = right, 2 = down, 3 = left 

let snakeX = 20;
let snakeY = 20;

window.addEventListener("keydown", onKeyDown, false);

for (let i = 0; i < screenHeight; i++) {
    grid[i] = [];
    for (let j = 0; j < screenWidth; j++) {
        grid[i][j] = 0;
    }
}

function onKeyDown(event) {
    switch (event.key) {
        case 'w':
        case 'W':
            direction = 0;
            break;
        case 'd':
        case 'D':
            direction = 1;
            break;
        case 's':
        case 'S':
            direction = 2;
            break;
        case 'a':
        case 'A':
            direction = 3;
            break;
    }
}

function gameLoop() {
    for (let i = 0; i < screenHeight; i++) {
        for (let j = 0; j < screenWidth; j++) {
            grid[i][j] = 0;
        }
    }
    
    if (direction == 0) {
        snakeY--;
    } else if (direction == 1) {
        snakeX++;
    } else if (direction == 2) {
        snakeY++;
    } else if (direction == 3) {
        snakeX--;
    }

    grid[snakeX][snakeY] = 1;

    render();
}

function render() {
    for (let i = 0; i < screenHeight; i++) {
        for (let j = 0; j < screenWidth; j++) {
            if (grid[i][j] == 0) {
                ctx.fillStyle="#FFFFF0";
            } else if (grid[i][j] == 1) {
                ctx.fillStyle="#FF0000";
            } else {
                ctx.fillStyle="#00FF00";
            }
            ctx.fillRect(i * 10, j * 10, 400 / screenHeight, 400 / screenWidth);
        }
    }
}

setInterval(gameLoop, 100);
