#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// Define the pins
const int flexPin = A0; // Pin for the flex sensor
#define blue 2          // Blue LED pin
#define green 3         // Green LED pin
#define red 4           // Red LED pin

// Create objects for software serial and DFPlayer Mini
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27 for 16x2 LCD

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Sign Language to");
  lcd.setCursor(0, 1);
  lcd.print("Speech Convert");
  delay(6000);
  lcd.clear();

  // Initialize pins
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  
  // Initialize serial communications
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);
  Serial.println();
  Serial.println(F("Initializing DFPlayer..."));

  // Initialize DFPlayer Mini
  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1. Please recheck the connection!"));
    Serial.println(F("2. Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.volume(30); // Set volume (0 to 30)
}

void loop() {
  int flexValue = analogRead(flexPin); // Read the flex sensor value
  Serial.println(flexValue); // Print the sensor value for debugging

  if (flexValue > 320) { // No Bend; Blue LED Glows
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    Serial.println("Please Give Me Water");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cmd 1");
    lcd.setCursor(0, 1);
    lcd.print("I Feel Sleepy");
    myDFPlayer.play(1); // Play audio file 1
    delay(1000);
  }
  else if (flexValue < 320 && flexValue > 280) { // Small Bend; Green LED Glows
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(red, LOW);
    Serial.println("Please Give Me Food");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cmd 2");
    lcd.setCursor(0, 1);
    lcd.print("Give Me Food");
    myDFPlayer.play(2); // Play audio file 2
    delay(1000);
  }
  else if (flexValue < 200 && flexValue > 100) { // Medium Bend; Green LED Glows
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(red, LOW);
    Serial.println("Give Me Water");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cmd 3");
    lcd.setCursor(0, 1);
    lcd.print("Give Me Water");
    myDFPlayer.play(3); // Play audio file 3
    delay(1000);
  }
  else { // Larger Bend; RED LED Glows
    if (flexValue > 100) {
      digitalWrite(red, HIGH);
    }
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No Sign Language");
  }
  delay(50);
}
