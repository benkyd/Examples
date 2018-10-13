#include <Keyboard.h>

void setup() {
  Keyboard.begin();
  Mouse.begin();

  delay(1000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');    
  Keyboard.releaseAll();
  delay(100);
  Keyboard.print("cmd");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(100);

  Keyboard.print("tree");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();  
}

void loop() {}
