import processing.serial.*;
import processing.sound.*;

AudioIn input;
Amplitude analyzer;
Serial port;

void setup() {
  size(200, 200);
  port = new Serial(this, "COM3", 9600);

  input = new AudioIn(this, 0);
  input.start();
  analyzer = new Amplitude(this);
  analyzer.input(input);
}

void draw() {
  float vol = analyzer.analyze();
  float normal = 10+vol*200;
  int out = int(map(normal, 0, 60, 0, 11));
  port.write(Integer.toString(out));
  port.write(" ");
}