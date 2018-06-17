/*
    Author(s): Ben (plane000)#8618
    Created: 14/06/2018
    Last Updated: 16/06/2018
    Last Updated by: Ben (plane000)#8618
*/

let c = document.getElementById("canv");
let ctx = c.getContext("2d");

let lost = false;

let gridSize = 40;
let grid = []; //0 = nothing, 1 = snake, 2 = apple

let direction = 3; //0 = up, 1 = right, 2 = down, 3 = left 

let snake = [[Math.floor(Math.random() * gridSize), Math.floor(Math.random() * gridSize)]];
let apple;

for (let i = 0; i < gridSize; i++) {
    grid[i] = [];
    for (let j = 0; j < gridSize; j++) {
        grid[i][j] = 0;
    }
}

window.addEventListener("keydown", onKeyDown, false);
spawnApple();
render();
draw();

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

async function gameLoop() {
    if (!lost) {
        await updateSnake();
        await checkColisions();
        render();
        draw();
    } else {
        for (let i = 0; i < gridSize; i++) {
            for (let j = 0; j < gridSize; j++) {
                grid[i][j] = 0;
            }
        }
        snake = [[Math.floor(Math.random() * gridSize), Math.floor(Math.random() * gridSize)]];
        spawnApple();
        render();
        draw();
        lost = false;
    }
}

function updateSnake() {
    let newX;
    let newY;
    if (direction == 0) {
        newX = snake[snake.length - 1][0];
        newY = snake[snake.length - 1][1] - 1;
    } else if (direction == 1) {
        newX = snake[snake.length - 1][0] + 1;
        newY = snake[snake.length - 1][1];
    } else if (direction == 2) {
        newX = snake[snake.length - 1][0];
        newY = snake[snake.length - 1][1] + 1;
    } else if (direction == 3) {
        newX = snake[snake.length - 1][0] - 1;
        newY = snake[snake.length - 1][1];
    }
        
    
    try {
        grid[snake[0][0]][snake[0][1]] = 0;
    } catch (e) {
        
    }
    snake.push([newX, newY]);
    snake.shift(1);
}

function checkColisions() {
    if (apple[0] == snake[[snake.length - 1][0]][0] && apple[1] == snake[[snake.length - 1][0]][1] ) {
        snake.push([apple[0], apple[1]]);
        apple = [];
        spawnApple();
    }
    if  (grid[snake[[snake.length - 1][0]][0]][snake[[snake.length - 1][0]][1]] == 1) {
        lost = true;
    }
    if (snake[[snake.length - 1][0]][0] < 1) {
        lost = true;
    }
    if (snake[[snake.length - 1][0]][0] > gridSize - 2) {
        lost = true;
    }
    if (snake[[snake.length - 1][0]][1] < 1) {
        lost = true;
    }
    if (snake[[snake.length - 1][0]][1] > gridSize - 1) {
        lost = true;
    }
}

function spawnApple() {
    let spawned = false
    while (!spawned) {
        let x = Math.floor(Math.random() * gridSize);
        let y = Math.floor(Math.random() * gridSize);
        if (grid[x][y] != 1 && x != 0 && y != 0) {
            apple = [x, y];
            spawned = true;
            break;
        }
    }
}

function render() {   
    for (let s = 0; s < snake.length; s++) {
        grid[snake[s][0]][snake[s][1]] = 1;
    }
    grid[apple[0]][apple[1]] = 2;
}

function draw() {
    for (let i = 0; i < gridSize; i++) {
        for (let j = 0; j < gridSize; j++) {
            if (grid[i][j] == 0) {
                ctx.fillStyle="#FFFFF0";
            } else if (grid[i][j] == 1) {
                ctx.fillStyle="#FF0000";
            } else {
                ctx.fillStyle="#00FF00";
            }
            ctx.fillRect(i * 10, j * 10, 400 / gridSize, 400 / gridSize);
        }
    }
}

setInterval(gameLoop, 100);
