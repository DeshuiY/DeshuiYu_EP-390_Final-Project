#include <Adafruit_LSM6DSOX.h>
// # 用library 的内容

/******************** CONSTANTS ********************/
// SPI Pins
#define LSM_CS 10     // CS (Chip Select) pin
#define LSM_SCK 13    // SCK (Serial Clock) pin
#define LSM_MISO 19   // MISO (Master In Slave Out) pin
#define LSM_MOSI 18   // MOSI (Master Out Slave In) pin
#define fsr1_PIN 14

// I2C Pins
// Note that the functions below don't explicitly make use of
// these pins, but they are defined for educational purposes.
#define LSM_SCL0 19   // SCL (Serial Clock) pin
#define LSM_SDA0 18   // SDA (Serial Data) pin

/**
 * Create enumerator data type called SerialProtocol.
 */
typedef enum {

  // enum daytype 
  I2C_PROTOCOL,
  SPI_PROTOCOL,
  SPI_CSONLY_PROTOCOL
} SerialProtocol;

Adafruit_LSM6DSOX sox;
SerialProtocol mode = I2C_PROTOCOL;

// One million microseconds in one second
float loopRateInMicroseconds = 10000;   // 10000us = 10ms

int fsr1;

// Below is Ultrasonic

const int trigPin = 9;

// defin the Trigger pin， trigPin is connected to 9 on the Arduino(same to the Tennsy 4.0)

const int echoPin = 10;

// defin the Echo pin, echoPin is connected to 10 on the Arduino(same to the Tennsy 4.0)

float duration, distance;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing");

  initLSM6DSOX();


  // Below is Ultrasonic

  pinMode(trigPin, OUTPUT);

  // sets trigPin as an output pin

  pinMode(echoPin, INPUT);

  //sets echoPin as an input pin

 
}

void loop() {
  // Get a new normalized sensor event
  sensors_event_t accel, gyro, temp;
  sox.getEvent(&accel, &gyro, &temp);

  // Print sensor data
  printTemperature(temp);
  printAcceleration(accel);
  printAngularVelocity(gyro);


  fsr1 = 1023 - analogRead(A0); // Pressure Sensor
  Serial.print("fsr1/ ");
  Serial.println(fsr1);



  // Refresh rate
  delayMicroseconds(loopRateInMicroseconds);



  // Below is the  Ultrasonic 

  digitalWrite(trigPin, LOW);  

  // sets the trigPin to low to ensure it starts in a low state before seeding pulse

	delayMicroseconds(2);  

  // delay time (measured in Microsenconds)

	digitalWrite(trigPin, HIGH);  

  // sends high signal on the trigPin for triggering the sensor to send out a sound pulse

	delayMicroseconds(10); 

  // keep the signal high for 10 microseconds

	digitalWrite(trigPin, LOW);  

  // sets trigPin back to low signal (end the pulse)

  duration = pulseIn(echoPin, HIGH);

  // The timer starts when echoPin is HIGH, and stops when echoPin turns LOW.



  distance = (duration*.0343)/2;

  // 0.0343 means 343 meters per second (speed of sound in air) converted to centimeters per microsecond.

  
  // division by 2 because we need to consider the send and receive.



  // Header-based System
  Serial.print("d/ ");

  // print the text "Distance" to the console, print on the same line

  Serial.println(distance);

  delay(100);


  

}



/******************** PRINT FUNCTIONS ********************/
/**
 * The following print statements use a header/subheader system.
 * These syntax considerations are important:
 *     The first print statement is a header for the value.
 *     The second print statement is a subheader for the value.
 *     Each header and subheader must be followed by a space as a data separator.
 *     Each value must be printed using a line break.
 *     The / after each header and subheader is a convention and not required.
 */
void printTemperature(sensors_event_t temp) {
  // In programming, multiple operations in one line follow PEMDAS
  float fahrenheit = temp.temperature * 1.8 + 32;
  
  Serial.print("temp/ ");
  Serial.print("c/ ");
  Serial.println(temp.temperature);

  Serial.print("temp/ ");
  Serial.print("f/ ");
  Serial.println(fahrenheit);
}

void printAcceleration(sensors_event_t accel) {
  // Acceleration is measured in m/s^2
  float x = accel.acceleration.x;
  float y = accel.acceleration.y;
  float z = accel.acceleration.z;

  Serial.print("acc/ ");
  Serial.print("x/ ");
  Serial.println(x);

  Serial.print("acc/ ");
  Serial.print("y/ ");
  Serial.println(y);

  Serial.print("acc/ ");
  Serial.print("z/ ");
  Serial.println(z);
}

void printAngularVelocity(sensors_event_t gyro) {
  // Angular velocity is measured in radians/s
  float x = gyro.gyro.x;
  float y = gyro.gyro.y;
  float z = gyro.gyro.z;

  Serial.print("gyro/ ");
  Serial.print("x/ ");
  Serial.println(x);

  Serial.print("gyro/ ");
  Serial.print("y/ ");
  Serial.println(y);

  Serial.print("gyro/ ");
  Serial.print("z/ ");
  Serial.println(z);
}


/******************** INITIALIZER ********************/
/**
 * Initialize IMU
 */
void initLSM6DSOX() {
  while (!Serial)
    delay(10);  // Pause until serial console opens

  // Pause program if specified mode doesn't detect a connected sensor in related pins
  switch (mode) {
  case I2C_PROTOCOL:
    if (!sox.begin_I2C()) {
      Serial.println("Failed to find LSM6DSOX chip with I2C");
      while (1)
        delay(10);
    }
    break;
  case SPI_PROTOCOL:
    if (!sox.begin_SPI(LSM_CS, LSM_SCK, LSM_MISO, LSM_MOSI)) {
      Serial.println("Failed to find LSM6DSOX chip with SPI");
      while (1)
        delay(10);
    }
    break;
  case SPI_CSONLY_PROTOCOL:
    if (!sox.begin_SPI(LSM_CS)) {
      Serial.println("Failed to find LSM6DSOX chip with SPI (only CS)");
      while (1)
        delay(10);
    }
    break;
  }

  Serial.println("LSM6DSOX found!");

  /********************* ACCELEROMETER RANGES *********************/
  // sox.setAccelRange(LSM6DS_ACCEL_RANGE_2_G);
  Serial.print("Accelerometer range set to: ");
  switch (sox.getAccelRange()) {
  case LSM6DS_ACCEL_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case LSM6DS_ACCEL_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case LSM6DS_ACCEL_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case LSM6DS_ACCEL_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }

  // sox.setAccelDataRange(LSM6DS_RATE_12_5_HZ);
  Serial.print("Accelerometer data rate set to: ");
  switch(sox.getAccelDataRate()) {
  case LSM6DS_RATE_SHUTDOWN:
    Serial.println("0 Hz");
    break;
  case LSM6DS_RATE_12_5_HZ:
    Serial.println("12.5 Hz");
    break;
  case LSM6DS_RATE_26_HZ:
    Serial.println("26 Hz");
    break;
  case LSM6DS_RATE_52_HZ:
    Serial.println("52 Hz");
    break;
  case LSM6DS_RATE_104_HZ:
    Serial.println("104 Hz");
    break;
  case LSM6DS_RATE_208_HZ:
    Serial.println("208 Hz");
    break;
  case LSM6DS_RATE_416_HZ:
    Serial.println("416 Hz");
    break;
  case LSM6DS_RATE_833_HZ:
    Serial.println("833 Hz");
    break;
  case LSM6DS_RATE_1_66K_HZ:
    Serial.println("1.66 kHz");
    break;
  case LSM6DS_RATE_3_33K_HZ:
    Serial.println("3.33 kHz");
    break;
  case LSM6DS_RATE_6_66K_HZ:
    Serial.println("6.66 kHz");
    break;
  }

  /********************* GYROSCOPE RANGES *********************/
  // sox.setGyroRange(LSM6DS_GYRO_RANGE_250_DPS);
  Serial.print("Gyroscope range set to: ");
  switch (sox.getGyroRange()) {
  case LSM6DS_GYRO_RANGE_125_DPS:
    Serial.println("125 degrees/s");
    break;
  case LSM6DS_GYRO_RANGE_250_DPS:
    Serial.println("250 degrees/s");
    break;
  case LSM6DS_GYRO_RANGE_500_DPS:
    Serial.println("500 degrees/s");
    break;
  case LSM6DS_GYRO_RANGE_1000_DPS:
    Serial.println("1000 degrees/s");
    break;
  case LSM6DS_GYRO_RANGE_2000_DPS:
    Serial.println("2000 degrees/s");
    break;
  case ISM330DHCX_GYRO_RANGE_4000_DPS:
    Serial.println("4000 degrees/s is an unsupported range for the DSOX");
    break;
  }

  // sox.setGyroDataRange(LSM6DS_RATE_12_5_HZ);
  Serial.print("Gyro data rate set to: ");
  switch(sox.getGyroDataRate()) {
  case LSM6DS_RATE_SHUTDOWN:
    Serial.println("0 Hz");
    break;
  case LSM6DS_RATE_12_5_HZ:
    Serial.println("12.5 Hz");
    break;
  case LSM6DS_RATE_26_HZ:
    Serial.println("26 Hz");
    break;
  case LSM6DS_RATE_52_HZ:
    Serial.println("52 Hz");
    break;
  case LSM6DS_RATE_104_HZ:
    Serial.println("104 Hz");
    break;
  case LSM6DS_RATE_208_HZ:
    Serial.println("208 Hz");
    break;
  case LSM6DS_RATE_416_HZ:
    Serial.println("416 Hz");
    break;
  case LSM6DS_RATE_833_HZ:
    Serial.println("833 Hz");
    break;
  case LSM6DS_RATE_1_66K_HZ:
    Serial.println("1.66 kHz");
    break;
  case LSM6DS_RATE_3_33K_HZ:
    Serial.println("3.33 kHz");
    break;
  case LSM6DS_RATE_6_66K_HZ:
    Serial.println("6.66 kHz");
    break;
  }
}
