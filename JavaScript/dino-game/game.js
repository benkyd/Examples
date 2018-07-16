 /*
    Author(s): Ben (plane000)#8618
    Created: 11/07/2018
    Last Updated: 16/07/2018
    Last Updated by: Ben (plane000)#8618
*/

let c = document.getElementById("canv");
let ctx = c.getContext("2d");

let player;
let world;
let cacti;

function initialize() {
    world = new World();
    world.reset();
    player = new Player();
    player.reset();
    cacti = [];
}

function gameLoop() {
    cls();

    world.update();

    spawnEnemys();
    despawnEnemys();
    updateEnemys();

    player.update();

    colide();

    drawEnemys();

    world.draw();
    player.draw();

    player.velocityX += 0.001;
    player.score++;
}

function cls() {
    ctx.fillStyle="#FFFFFF" // white
    ctx.fillRect(0, 0, 800, 400);
}   

window.addEventListener('keydown', (event) => {
    if (event.code == 'Space' || event.code == 'ArrowUp' || event.code == 'KeyW') {
        console.log('jump');
        player.jump();
    }
    if (event.code == 'ShiftLeft' || event.code == 'ArrowDown' || event.code == 'KeyS') {
        console.log('duck');
        player.duck();
    }
});

window.addEventListener('keyup', (event) => {
    if (event.code == 'ShiftLeft' || event.code == 'ArrowDown' || event.code == 'KeyS') {
        player.stand();
    }
});

initialize();
setInterval(gameLoop, 1000 / 60)
