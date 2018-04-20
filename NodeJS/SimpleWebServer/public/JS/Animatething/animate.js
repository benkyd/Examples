let angle = 0;
let w = 24;
let ma;
let maxD;

function setup() {
  createCanvas(400, 400, WEBGL);
  ma = atan(cos(QUARTER_PI));
  maxD = dist(0, 0, 200, 200);
}

function draw() {
  background(100);
  ortho(-400, 400, 400, -400, 0, 1000);
  rotateX(-ma);
  rotateY(-QUARTER_PI);

  for (let z = 0; z < height; z += w) {
    for (let x = 0; x < width; x += w) {
      push();
      let d = dist(x, z, width / 2, height / 2);
      let offset = map(d, 0, maxD, -PI + 2, PI + 2);
      let a = angle + offset;
      let h = floor(map(sin(a), 0, 1, 100, 300));
      translate(x - width / 2, 0, z - height / 2);
      normalMaterial();
      box(w, h, w);
      pop();
    }
  }

  angle -= 0.05;
}
