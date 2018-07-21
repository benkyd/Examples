const MAX_POINTS = 60;
const X_MAX = 60;
const Y_MAX = 40;
const X_DIV = 5;
const Y_DIV = 4;

let canvas = document.getElementById('graph');
let ctx = canvas.getContext('2d');
let points = [];

function addPoint(temp) {
    if (points.length <= MAX_POINTS) {
        points.push(temp);
    }
    else {
        for (let i = 0; i <= MAX_POINTS - 1; i++) {
            points[i] = points[i + 1];
        }
        points[MAX_POINTS] = temp;
    }

    ctx.clearRect(0, 0, canvas.width, canvas.height);

    ctx.strokeStyle = "black";
    ctx.font = "20px Courrier New";
    ctx.textAlign="right";
    for (let i = X_DIV; i < MAX_POINTS; i += X_DIV) {
        ctx.beginPath();
        ctx.moveTo(i * (canvas.width / MAX_POINTS), 0);
        ctx.lineTo(i * (canvas.width / MAX_POINTS), canvas.height);
        ctx.stroke();
    }

    for (let i = Y_DIV; i < Y_MAX; i += Y_DIV) {
        ctx.fillText(Y_MAX - i , canvas.width - 1, i * (canvas.height / Y_MAX) - 2);
        ctx.beginPath();
        ctx.moveTo(0, i * (canvas.height / Y_MAX));
        ctx.lineTo(canvas.width, i * (canvas.height / Y_MAX));
        ctx.stroke();
    }

    ctx.strokeStyle = "blue";
    for (let i = 0; i < points.length && points.length > 1; i++) {
        ctx.beginPath();
        ctx.moveTo(i * (canvas.width / MAX_POINTS), canvas.height - (points[i] * 10));
        ctx.lineTo((i + 1) * (canvas.width / MAX_POINTS), canvas.height - (points[i + 1] * 10));
        ctx.stroke();
    }
}
