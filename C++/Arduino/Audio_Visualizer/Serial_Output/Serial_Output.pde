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
  int out = int(map(10+vol*200, 0, 100, 0, 11));
  println(out);
  port.write(Integer.toString(out));
  port.write(" ");
}