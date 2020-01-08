#include <DigiJoystick.h>
#include <oddebug.h>
#include <osccal.h>
#include <osctune.h>
#include <usbconfig-prototype.h>
#include <usbconfig.h>
#include <usbdrv.h>
#include <usbportability.h>


int maxBaseline = 0;
// determined through trail and error. max is usually ~550 and min is
usually ~280
int minLimit = 280;
int hallSensor = 0;
byte brakePressure = 0;

void setup() {
  maxBaseline = analogRead(1);
  // Do nothing? It seems as if the USB hardware is ready to go on reset
}


void loop() {
  hallSensor = analogRead(1); //Read A1
  hallSensor = constrain(hallSensor, minLimit, maxBaseline);
  brakePressure = map(hallSensor,maxBaseline,minLimit,0,255);

  DigiJoystick.setSLIDER((byte) brakePressure);



  // it's best to use DigiJoystick.delay() because it knows how to talk to
  // the connected computer - otherwise the USB link can crash with the
  // regular arduino delay() function
  DigiJoystick.delay(50); // wait 50 milliseconds
}
