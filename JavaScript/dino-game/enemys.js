function spawnEnemys() {
    let r = Math.floor(Math.random() * 100);

    if (2 > r) {
        for (let i = 0; i < cacti.length; i++) {
            if (cacti[i].x > 700) {
                console.log('Spawn failed')
                return;
            }
        }
    
        if (r == 1) {
            cacti.push(new Cacti());
        } else {
            cacti.push(new ThiccCacti);
        }
    }
}

function updateEnemys() {
    for (let i = 0; i < cacti.length; i++) {
        cacti[i].update();
    }
}

function despawnEnemys() {
    for (let i = 0; i < cacti.length; i++) {
        if (cacti[i].x < -cacti[i].width) {
            cacti.splice(1, i)
        }
    }
}

function drawEnemys() {
    for (let i = 0; i < cacti.length; i++) {
        cacti[i].draw();
    }
}
