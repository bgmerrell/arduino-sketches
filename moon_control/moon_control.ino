#include <IRremote.h>

IRsend irsend;

int snd_val;
const int SND_THRESHOLD = 450;
const int POST_SIGNAL_DELAY = 10;
// increment phase
unsigned int signal_buf[] = {6400, 500, 1650, 1500, 600, 450, 1650, 1500, 600, 450, 1650, 450, 1600, 500, 1650, 1500, 600};
// auto mode
// unsigned int signal_buf[] = {6450, 450, 1650, 1500, 600, 450, 1650, 1500, 650, 400, 1650, 500, 1600, 1550, 550, 500, 1650};

unsigned int RETRIES = 3;
unsigned int HZ = 38;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
    int sensorValue = analogRead(A0);
    if (sensorValue >= SND_THRESHOLD) {
      Serial.print("Sending raw @ HZ: ");
      Serial.println(HZ);
      irsend.sendRaw(signal_buf, 17, HZ);
      delay(POST_SIGNAL_DELAY);
    }
}
