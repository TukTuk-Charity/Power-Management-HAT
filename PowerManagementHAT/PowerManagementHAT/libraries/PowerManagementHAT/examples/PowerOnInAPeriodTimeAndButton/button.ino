bool checkButton() {
  if (buttonPressed) { // check if button has been pressed
    Serial.println("BUTTON pressed!");
    unsigned long debounce_time = millis();
    while (buttonPressed) { // wait button to be released
      if (!digitalRead(BUTTON_PIN)) {// the button is still being pressed
        debounce_time = millis();
      }
      if (millis() - debounce_time > DEBOUNCE_DELAY) {  // wait 50 ms before considering the button released so we are sure it is not bouncing
        buttonPressed = false; //reset flag
      }
      delay(1);
    }
    time = millis() - timePress;
    Serial.println("BUTTON released!");
    Serial.print("BUTTON press time: ");
    Serial.println(time);
    delay(10);
    if (time >= BUTTON_TIME_MS) { // check if the button has been pressed long enough
      Serial.println("Pi will sleep due to button");
      return true;                // exit the wait loop and wake / turn off pi
    }
  }
  return false;
}
