const c = document.getElementById('canv');
const ctx = c.getContext('2d');

/*<==== DEFINING GAME CONSTANTS ====>*/
const CANVAS_SIZE = {x: 400, y: 600};
const GAME_SIZE = {x: 8, y: 12};
const BLOCK_SIZE = {x: CANVAS_SIZE.x / GAME_SIZE.x, y: CANVAS_SIZE.y / GAME_SIZE.y};
const GAME_STATE = 0; // 0 = playing, 1 = lost
const UPDATE_RATE = 20; // updates per second

const BACKGROUND_COLOUR = '#8D7F76';
const SNAKE_COLOUR = '#B62946';
const APPLE_COLOUR = '#2CC427';

/*<==== DEFINING CLASS STRUCTURES ====>*/
class Apple {
    constructor() {

    }

    spawn() {

    }

    update() {

    }
}

class Snake {
    constructor() {
        this.snake = [ ];
        this.direction = 2; // 0 = up, 1 = left, 2 = down, 3 = right
        this.pos = {x: 0, y: 0};
    }

    spawn() {

    }

    freeze() {

    }

    update() {

    }
}

class Block {
    constructor(x, y) {
        this.pos = {x: x, y: y};
    }
}

/*<==== GAME INITIALIZATION  ====>*/
let GameGrid = [ [] ]; // 0 = empty, 1 = snake / block, 2 = apple;
for (let i = 0; i < GAME_SIZE.x; i++) {
    GameGrid[i] = [];
    for (let j = 0; j < GAME_SIZE.y; j++) {
        GameGrid[i][j] = 0;
    }
}

let ActiveSnake = new Snake();
let ActiveApple = new Apple();

/*<==== GAME LOGIC AND EVENT HANDLING ====>*/
function gameLoop() {

}

function handleKeyDown(event) {
    switch (event.key) {
        case 'w':
        case 'W':
            ActiveSnake.direction = 0;
            break;
        case 'd':
        case 'D':
            ActiveSnake.direction = 1;
            break;
        case 's':
        case 'S':
            ActiveSnake.direction = 2;
            break;
        case 'a':
        case 'A':
            ActiveSnake.direction = 3;
            break;
    }
}

window.addEventListener('keydown', handleKeyDown);
setInterval(gameLoop, 1000 / UPDATE_RATE);
