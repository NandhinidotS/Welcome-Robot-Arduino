#include <Servo.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// ---------- PINS ----------
#define TRIG_PIN 7
#define ECHO_PIN 6
#define SERVO_PIN 9

// DFPlayer
// Arduino D10 (RX) <- DFPlayer TX
// Arduino D11 (TX) -> DFPlayer RX
SoftwareSerial mp3Serial(10, 11);

DFRobotDFPlayerMini player;
Servo hand;

// ---------- SETTINGS ----------
const int DETECT_DISTANCE = 20;

const int NORMAL_POSITION = 90;
const int OPEN_POSITION = 40;

bool personDetected = false;


// ---------- ULTRASONIC ----------
float getDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0)
  {
    return 999;
  }

  return duration * 0.0343 / 2;
}


// ---------- SETUP ----------
void setup()
{
  Serial.begin(9600);
  mp3Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  hand.attach(SERVO_PIN);

  // Start in normal position
  hand.write(NORMAL_POSITION);

  Serial.println("Starting DFPlayer...");

  if (!player.begin(mp3Serial))
  {
    Serial.println("DFPlayer connection failed!");

    while (1);
  }

  Serial.println("DFPlayer connected!");

  // FULL VOLUME
  player.volume(30);

  delay(1000);

  Serial.println("WELCOME ROBOT READY");
}


// ---------- MAIN LOOP ----------
void loop()
{
  float distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  // =================================================
  // PERSON IS LESS THAN 20 CM
  // =================================================

  if (distance < DETECT_DISTANCE)
  {
    // First detection
    if (!personDetected)
    {
      personDetected = true;

      Serial.println("PERSON DETECTED!");
      Serial.println("Distance < 20 cm");

      // Servo OPEN
      hand.write(OPEN_POSITION);

      // Start audio
      player.play(1);

      Serial.println("SERVO: OPEN");
      Serial.println("SPEAKER: ON");
    }

    // Keep servo OPEN
    hand.write(OPEN_POSITION);

    // Keep audio playing continuously
    if (player.readState() == 0)
    {
      player.play(1);
    }
  }


  // =================================================
  // PERSON IS 20 CM OR FARTHER
  // =================================================

  else
  {
    if (personDetected)
    {
      personDetected = false;

      Serial.println("PERSON MOVED AWAY");
      Serial.println("Distance >= 20 cm");

      // Stop audio
      player.stop();

      // Servo NORMAL
      hand.write(NORMAL_POSITION);

      Serial.println("SPEAKER: OFF");
      Serial.println("SERVO: NORMAL");
    }
  }

  delay(100);
}
