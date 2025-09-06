// #include <LiquidCrystal_I2C.h>  // Including the LiquidCrystal_I2C library

// LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initializing the LCD screen with I2C address, 16 columns, and 2 rows
const int ledPinR = 33;  // Pin for the first LED (Red)
const int ledPinY = 26;  // Pin for the second LED (Yellow)
const int ledPinG = 27;  // Pin for the third LED (Green)
const int water_level_changed = 0;

#define water_level_sensor_pin 34
#define WATER_MIN 0
#define WATER_MAX 4093

void setup() {
  Serial.begin(9600);
  if (Serial) Serial.println("Serial is open");
  pinMode(ledPinR, OUTPUT);  // Configuring the pin as an output
  pinMode(ledPinY, OUTPUT);  // Configuring the pin as an output
  pinMode(ledPinG, OUTPUT);  // Configuring the pin as an output
  // pinMode(water_level_sensor_pin, INPUT);
  // attachInterrupt(digitalPinToInterrupt(water_level_sensor_pin), water_level_alarm, CHANGE);
  digitalWrite(ledPinR, LOW);  // Initializing the state as low (LED off)
  digitalWrite(ledPinY, LOW);  // Initializing the state as low (LED off)
  digitalWrite(ledPinG, LOW);  // Initializing the state as low (LED off)

  // lcd.init();  // Initializing the LCD screen
  // lcd.backlight();  // Turning on the LCD backlight

  // lcd.setCursor(0, 0);  // Setting the cursor position to column 0, row 0
  // lcd.print("School Sur Seine!");  // Displaying the text "School Sur Seine!"

  // lcd.setCursor(7, 1);  // Setting the cursor position to column 7, row 1
  // lcd.print(":)");  // Displaying the symbol ":)"

  // delay(5000);  // Waiting for 5 seconds

  // lcd.clear();  // Clearing the LCD screen
}

// void water_level_alarm(void) {
// water_level_changed =true;
// water_level_changed = analogRead(water_level_sensor_pin);

// }

void loop() {
  // lcd.setCursor(0, 0);  // Setting the cursor position to column 0, row 0
  // lcd.print("Value :");  // Displaying the text "Value :"
  // lcd.print(value);  // Displaying the read value
  // lcd.print("    ");  // Displaying empty spaces to clear previous characters
  // lcd.setCursor(0, 1);  // Setting the cursor position to column 0, row 1
  // lcd.print("Level :");  // Displaying the text "Level :"
  water_level_changed = analogRead(water_level_sensor_pin);
  level = map(water_level_changed, WATER_MIN, WATER_MAX, 0, 4);

  if (water_level_changed < 10) {
    Serial.println("Kopi Habis");
    // Serial.println(water_level_changed);
    delay(500);
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinY, LOW);
    digitalWrite(ledPinG, LOW);
  } else if (water_level_changed >= 100 && water_level_changed < 3000) {
    Serial.println("Kopi Hampir Habis     ");
    // Serial.println(water_level_changed);
    delay(500);
    digitalWrite(ledPinR, HIGH);
    digitalWrite(ledPinY, LOW);
    digitalWrite(ledPinG, LOW);
  } else if (water_level_changed >= 3000 && water_level_changed < 4093) {
    Serial.println("Kopi tinggal Setengahnya  ");
    // Serial.println(water_level_changed);
    delay(500);
    digitalWrite(ledPinY, HIGH);
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinG, LOW);
  } else if (water_level_changed >= 4093) {
    Serial.println("Kopi Full    ");
    // Serial.println(water_level_changed);
    delay(500);
    digitalWrite(ledPinG, HIGH);
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinY, LOW);
  }
}
