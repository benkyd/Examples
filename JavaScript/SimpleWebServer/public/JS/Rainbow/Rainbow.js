var bandsize = 500;
var gapsize = 50;
var position = 1;
var subtractionamount = 0;
var backgroundcol = 230;

function setup() {

  createCanvas(800, 800);
  background(backgroundcol);


  noStroke();
  fill(255, 0, 0)
  arc(width / 2, height / 2, bandsize, bandsize, PI, PI);

  subtractionamount = gapsize * position;
  position++;
  fill(255, 69, 0);
  arc(width / 2, height / 2, bandsize - subtractionamount, bandsize  - subtractionamount, PI, PI);

  subtractionamount = gapsize * position;
  position++;
  fill(255, 215, 0);
  arc(width / 2, height / 2, bandsize - subtractionamount, bandsize - subtractionamount, PI, PI);

  subtractionamount = gapsize * position;
  position++;
  fill(65, 105, 225);
  arc(width / 2, height / 2, bandsize - subtractionamount, bandsize - subtractionamount, PI, PI);

  subtractionamount = gapsize * position;
  position++;
  fill(50, 205, 50);
  arc(width / 2, height / 2, bandsize - subtractionamount, bandsize - subtractionamount, PI, PI);

  subtractionamount = gapsize * position;
  position++;
  fill(75, 0, 130);
  arc(width / 2, height / 2, bandsize - subtractionamount, bandsize - subtractionamount, PI, PI);

  subtractionamount = gapsize * position;
  position++;
  fill(138, 43, 226);
  arc(width / 2, height / 2, bandsize - subtractionamount, bandsize - subtractionamount, PI, PI);

  subtractionamount = gapsize * position;
  position++;
  fill(backgroundcol);
  arc(width / 2, height / 2, bandsize - subtractionamount, bandsize - subtractionamount, PI, PI);


}

function draw() {

}
