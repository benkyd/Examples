class World {
    constructor() {
        this.gravity = 1;
        this.ground = 300;
    }

    update() {

    }

    draw() {
        ctx.beginPath();
        ctx.moveTo(0, this.ground + 40 - 7);
        ctx.lineTo(800, this.ground + 40 - 7);
        ctx.stroke();
    }

    reset() {
        this.gravity = 1.3;
        this.ground = 300;
    }
}
