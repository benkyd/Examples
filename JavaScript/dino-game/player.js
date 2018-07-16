class Player {
    constructor() {
        this.x = 50;
        this.y = world.ground;
        this.width = 20;
        this.height = 40;
        this.velocityX = 5;
        this.velocityY = 0;
        this.onGround = true;
        this.ground = world.ground;
        this.ducking = false;
        this.score = 0;
    }

    jump() {
        if (this.onGround) {
            this.velocityY = -17;
            this.onGround = false;
        }
    }

    duck() {
        if (!this.ducking) {
            this.ducking = true;
            this.height = 20;
            this.y += 20;
            this.ground += 20;
        }
    }

    stand() {
        if (this.ducking) {
            this.ducking = false;
            this.height = 40;
            this.y = world.ground;
            this.ground = world.ground;
        }
    }

    update() {
        if (!this.onGround) {
            this.velocityY += world.gravity;
            this.y += this.velocityY;
            // console.log(this.y)
            if (this.y >= this.ground) {
                this.onGround = true;
                this.y = this.ground;
                // console.log('landed')
                return;
            }
        }
    }

    draw() {
        ctx.fillStyle="#FFFFFF";
        ctx.fillRect(this.x - 2, this.y, this.width + 4, this.height);
        ctx.fillStyle="#000000";
        ctx.fillRect(this.x, this.y, this.width, this.height);
    }

    reset() {
        this.x = 50;
        this.y = 300;
        this.width = 20;
        this.height = 40;
        this.velocityX = 5;
        this.velocityY = 0;
        this.onGround = true;
        this.score = 0;
    }
}
