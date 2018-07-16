class Cacti {
    constructor() {
        this.y = world.ground + 10;
        this.x = 900;
        this.width = 15;
        this.height = 30;
    }

    update() {
        this.x -= player.velocityX;
    }

    draw() {
        ctx.fillStyle="#FFFFFF";
        ctx.fillRect(this.x - 2, this.y, this.width + 4, this.height);
        ctx.fillStyle="#000000";
        ctx.fillRect(this.x, this.y, this.width, this.height);
    }
}

class ThiccCacti {
    constructor() {
        this.y = world.ground ;
        this.x = 900;
        this.width = 30;
        this.height = 40;
    }

    update() {
        this.x -= player.velocityX;
    }

    draw() {
        ctx.fillStyle="#FFFFFF";
        ctx.fillRect(this.x - 2, this.y, this.width + 4, this.height);
        ctx.fillStyle="#000000";
        ctx.fillRect(this.x, this.y, this.width, this.height);
    }
}
