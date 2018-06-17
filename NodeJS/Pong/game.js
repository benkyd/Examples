let c = document.getElementById("canv");
let ctx = c.getContext("2d");

let playerP = {
    width: 30,
    height: 60,
    x: 30 / 2,
    y: ctx.canvas.height / 2
}


window.addEventListener("keydown", onKeyDown, false);

function onKeyDown(event) {
    switch (event.key) {
        case 'W':
        case 'w':
            playerP.y++;
            break;
        case 'S':
        case 's':
            playerP.x--;
            break;
    }
}

function gameLoop() {
    draw();
}

function draw() {
    ctx.clearRect(0, 0, ctx.canvas.width, ctx.canvas.height);

    ctx.fillStyle="#FFFFFF";
    ctx.fillRect(0, 0, 400, 400);

    ctx.fillStyle="#FF00FF";
    ctx.fillRect(playerP.x, playerP.y, playerP.w, playerP.h);
}

setInterval(gameLoop, 10);
