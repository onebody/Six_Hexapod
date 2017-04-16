

void ps2x_Guitar_Hero_Controller() {
  ps2x.read_gamepad();          //read controller
  if (ps2x.ButtonPressed(GREEN_FRET))
    Serial.println("Green Fret Pressed");
  if (ps2x.ButtonPressed(RED_FRET))
    Serial.println("Red Fret Pressed");
  if (ps2x.ButtonPressed(YELLOW_FRET))
    Serial.println("Yellow Fret Pressed");
  if (ps2x.ButtonPressed(BLUE_FRET))
    Serial.println("Blue Fret Pressed");
  if (ps2x.ButtonPressed(ORANGE_FRET))
    Serial.println("Orange Fret Pressed");

  if (ps2x.ButtonPressed(STAR_POWER))
    Serial.println("Star Power Command");

  if (ps2x.Button(UP_STRUM))         //will be TRUE as long as button is pressed
    Serial.println("Up Strum");
  if (ps2x.Button(DOWN_STRUM))
    Serial.println("DOWN Strum");

  if (ps2x.Button(PSB_START))        //will be TRUE as long as button is pressed
    Serial.println("Start is being held");
  if (ps2x.Button(PSB_SELECT))
    Serial.println("Select is being held");

  if (ps2x.Button(ORANGE_FRET)) {    // print stick value IF TRUE
    Serial.print("Wammy Bar Position:");
    Serial.println(ps2x.Analog(WHAMMY_BAR), DEC);
  }

}


void ps2x_DualShock_Controller() {
  ps2x.read_gamepad(false, vibrate); //read controller and set large motor to spin at 'vibrate' speed

  if (ps2x.Button(PSB_START)) {       //will be TRUE as long as button is pressed
    Serial.println("Start is being held");
  }
  if (ps2x.Button(PSB_SELECT)) {
    Serial.println("Select is being held");
    pwm.setPWM(15, 0, SERVOMIN);
  }

  if (ps2x.Button(PSB_PAD_UP)) {
    //will be TRUE as long as button is pressed
    // 前进
    Serial.print("Up held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);

    control(PLAY_CTL_FORWARD);
  }

  if (ps2x.Button(PSB_PAD_RIGHT)) {
    // 右转
    Serial.print("Right held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
    control(PLAY_CTL_RIGHT);
  }

  if (ps2x.Button(PSB_PAD_LEFT)) {
    // 左转
    Serial.print("LEFT held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);

    control(PLAY_CTL_LEFT);
  }

  if (ps2x.Button(PSB_PAD_DOWN)) {
    // 后退
    Serial.print("DOWN held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);

    control(PLAY_CTL_BACK);
  }

  vibrate = ps2x.Analog(PSAB_CROSS);  //this will set the large motor vibrate speed based on how hard you press the blue (X) button
  if (ps2x.NewButtonState()) {        //will be TRUE if any button changes state (on to off, or off to on)
    if (ps2x.Button(PSB_L3)) {
      Serial.println("L3 pressed");

    }

    if (ps2x.Button(PSB_R3)) {
      Serial.println("R3 pressed");
    }

    if (ps2x.Button(PSB_L2)) {
      Serial.println("L2 pressed");
      //站立
      control(PLAY_CTL_STAND);
    }

    if (ps2x.Button(PSB_R2)) {
      Serial.println("R2 pressed");
      //蹲下
      control(PLAY_CTL_DOWN);
    }

    if (ps2x.Button(PSB_TRIANGLE)) {
      Serial.println("Triangle pressed");
    }
  }


  if (ps2x.ButtonPressed(PSB_CIRCLE))  {
    //will be TRUE if button was JUST pressed
    Serial.println("Circle just pressed");
  }

  if (ps2x.NewButtonState(PSB_CROSS)) {
    //will be TRUE if button was JUST pressed OR released
    Serial.println("X just changed");
    //把所有的脚抬起来
    control(PLAY_CTL_LIFTUPALL);
  }

  if (ps2x.ButtonReleased(PSB_SQUARE)) {
    //will be TRUE if button was JUST released
    Serial.println("Square just released");
  }


  if (ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) {
    //print stick values if either is TRUE
    Serial.print("Stick Values:");
    Serial.print(ps2x.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_LX), DEC);
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_RY), DEC);
    Serial.print(",");
    Serial.println(ps2x.Analog(PSS_RX), DEC);
  }
}

