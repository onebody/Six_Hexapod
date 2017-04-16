#include <PS2X_lib.h>  //for v1.6
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

/******************************************************************
 * set pins connected to PS2 controller:
 *   - 1e column: original
 *   - 2e colmun: Stef?
 * replace pin numbers by the ones you use
 ******************************************************************/
#define PS2_DAT        13  //14    
#define PS2_CMD        11  //15
#define PS2_SEL        10  //16
#define PS2_CLK        12  //17

/******************************************************************
 * select modes of PS2 controller:
 *   - pressures = analog reading of push-butttons
 *   - rumble    = motor rumbling
 * uncomment 1 of the lines for each mode selection
 ******************************************************************/
//#define pressures   true
#define pressures   false
//#define rumble      true
#define rumble      false

PS2X ps2x; // create PS2 Controller Class

//right now, the library does NOT support hot pluggable controllers, meaning
//you must always either restart your Arduino after you connect the controller,
//or call config_gamepad(pins) again after connecting the controller.

int error = 0;
byte type = 0;
byte vibrate = 0;

// Reset func
void (* resetFunc) (void) = 0;

#define PLAY_CTL_INIT           0
#define PLAY_CTL_FORWARD        1
#define PLAY_CTL_LEFT           2
#define PLAY_CTL_RIGHT          3
#define PLAY_CTL_BACK           4
#define PLAY_CTL_STAND          5
#define PLAY_CTL_DOWN           6
#define PLAY_CTL_LIFTUPALL      7



// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

void setup()
{
  //32路舵机控制器拨码开关都置1
  Serial.begin(115200);
  //
  servo_setup();
  
  ps2x_setup();
  //
  control(PLAY_CTL_INIT);
  
}

void loop() {

  /* You must Read Gamepad to get new values and set vibration values
     ps2x.read_gamepad(small motor on/off, larger motor strenght from 0-255)
     if you don't enable the rumble, use ps2x.read_gamepad(); with no values
     You should call this at least once a second
   */
  if (error == 1) { //skip loop if no controller found
    resetFunc();
  }

  if (type == 2) {
    //Guitar Hero Controller
    ps2x_Guitar_Hero_Controller();
  } else {
    //DualShock Controller
    ps2x_DualShock_Controller();
  }

  //delay(50);
}

