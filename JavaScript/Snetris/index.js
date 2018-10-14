const c = document.getElementById('canv');
const ctx = c.getContext('2d');

/*<==== GAME CONSTANTS ====>*/
const CANVAS_SIZE = {x: 400, y: 600};
const GAME_SIZE = {x: 8, y: 12};
const BLOCK_SIZE = {x: CANVAS_SIZE.x / GAME_SIZE.x, y: CANVAS_SIZE.y / GAME_SIZE.y};

const GAME_STATE = 0; // 0 = playing, 1 = lost
const UPDATE_RATE = 5; // updates per second
const ANIMATE_RATE = 60; // updates per second

const BACKGROUND_COLOUR = '#8D7F76';
const SNAKE_COLOUR = '#B62946';
const APPLE_COLOUR = '#2CC427';

/*<==== CLASS STRUCTURES ====>*/
class Apple {
    constructor() {
        this.pos = { };
        while (true) {
            this.pos.x = Math.floor((Math.random() * GAME_SIZE.x - 1) + 1);
            this.pos.y = Math.floor((Math.random() * GAME_SIZE.y / 2) + 1);
            if (this.pos.x == 0 || this.pos.x == 1) {
                // Checks to make sure it doesnt spawn anywhere illegal
            } else {
                break;
            }
        }
    }
    
    update() {
        if (ActiveSnake.head.x == this.pos.x && ActiveSnake.head.y == this.pos.y) {
            // freeze snake and return state
            return 'collide';
        }
    }
    
    draw() {
        GameGrid[this.pos.x][this.pos.y] = 2;
    }
}

class Snake {
    constructor() {
        this.tail = [{x: 1, y: 0}, {x: 0, y: 0}, {x: -1, y: 0}, {x: -2, y: 0}];
        this.head = {x: 1, y: 0};
        this.direction = 1; // 0 = up, 1 = right, 2 = down, 3 = left
        this.frozen = false;
    }

    update() {        
        let newPos = { };
        newPos.x = this.head.x;
        newPos.y = this.head.y;

        if (this.direction == 0) {
            newPos.y = this.head.y - 1;
        } else if (this.direction == 1) {
            newPos.x = this.head.x + 1;
        } else if (this.direction == 2) {
            newPos.y = this.head.y + 1;
        } else {
            newPos.x = this.head.x - 1;           
        }

        if (newPos.x + 1 < 0) {
            newPos.x = GAME_SIZE.x - 1; 
        } else if (newPos.x > GAME_SIZE.x - 1) {
            newPos.x = 0; 
        }

        if (newPos.y + 1 < 0) {
            newPos.y = GAME_SIZE.y - 1; 
        } else if (newPos.y > GAME_SIZE.y - 1) {
            newPos.y = 0; 
        }

        this.tail.pop();
        let newTail = [ ];
        newTail.push(newPos);

        for (let i = 0; i < this.tail.length; i++) {
            newTail.push(this.tail[i]);
        }

        this.tail = newTail;
        this.head = this.tail[0];
    }

    draw() {
        for (let i = 0; i < this.tail.length; i++) {
            if (this.tail[i].x < 0 || this.tail[i].y < 0 || this.tail[i].x > GAME_SIZE.x || this.tail[i].y > GAME_SIZE.y) { 
            } else {
                GameGrid[this.tail[i].x][this.tail[i].y] = 1;
            } 
        }
    }
}

class Block {
    constructor(tail) {
        this.blocks = tail;
        this.falling = true;
        this.pixelPos;
        this.targetGamePos;
        this.targetPixelPos;
    }
}

/*<==== GAME INITIALIZATION ====>*/
let GameGrid = [ ]; // 0 = empty, 1 = snake, 2 = apple
for (let i = 0; i < GAME_SIZE.x; i++) {
    GameGrid[i] = [ ];
    for (let j = 0; j < GAME_SIZE.y; j++) {
        GameGrid[i][j] = 0;
    }
}

let Blocks = [ ];
let ActiveSnake = new Snake();
let ActiveApple = new Apple();

/*<==== GAME LOGIC AND EVENT HANDLING ====>*/
let stop = false;
function gameLoop() {
    if (!stop) {
        clear();
        if (ActiveSnake.frozen == false) {
            ActiveSnake.update();
        }

        let didColide = ActiveApple.update();
        if (didColide == 'collide') {
            Blocks.push(new Block(ActiveSnake.tail));
            ActiveApple = new Apple();
            ActiveSnake = new Snake();
        }
        
        ActiveSnake.draw();
        ActiveApple.draw();
        draw();
    }
}

function animationLoop() {
    if (!stop) {
        // loop through Boxes and if a box is in the falling
        // state, then apply animation
    }
}

function drawAnimation() {
    
}

function draw() {
    for (let i = 0; i < GAME_SIZE.x; i++) {
        for (let j = 0; j < GAME_SIZE.y; j++) {
            switch (GameGrid[i][j]) {
                case 0:
                    ctx.fillStyle = BACKGROUND_COLOUR;
                    break;
                case 1:
                    ctx.fillStyle = SNAKE_COLOUR;
                    break;
                case 2:
                    ctx.fillStyle = APPLE_COLOUR;
                    break;
            }
            if (GameGrid[i][j] != 2) {
                ctx.fillRect(i * BLOCK_SIZE.x, j * BLOCK_SIZE.y, BLOCK_SIZE.x, BLOCK_SIZE.y);
            } else {
                ctx.fillRect(i * BLOCK_SIZE.x + BLOCK_SIZE.x / 3, j * BLOCK_SIZE.y + BLOCK_SIZE.y / 3, BLOCK_SIZE.x / 3, BLOCK_SIZE.y / 3);
            }
        }
    }
}

function clear() {
    for (let i = 0; i < GAME_SIZE.x; i++)
        for (let j = 0; j < GAME_SIZE.y; j++)
            GameGrid[i][j] = 0;
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
setInterval(animationLoop, 1000 / ANIMATE_RATE);
