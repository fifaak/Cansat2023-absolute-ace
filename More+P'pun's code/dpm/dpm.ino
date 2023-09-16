// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Servo.h>


#define LIMIT_SWITCH_PIN 3
Servo servo0;  // create servobjecto  to control a servo
Servo servo1;  // create servo object to control a servo
Adafruit_MPU6050 mpu;

bool start = false;
int count_start = 0;
bool setservo = false;
int count = 0;
bool csdeploy = false;
unsigned long time;
unsigned long start_at = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LIMIT_SWITCH_PIN, INPUT);
  while (!Serial)
    delay(10);                   // will pause Zero, Leonardo, etc until serial console opens
  Wire.begin();                  //begin the wire comunication
  Wire.beginTransmission(0x68);  //begin, Send the slave adress (in this case 68)
  Wire.write(0x6B);              //make the reset (place a 0 into the 6B register)
  Wire.write(0x00);
  Wire.endTransmission(true);    //end the transmission
  Wire.beginTransmission(0x68);  //begin, Send the slave adress (in this case 68)
  Wire.write(0x1B);              //We want to write to the GYRO_CONFIG register (1B hex)
  Wire.write(0x10);              //Set the register bits as 00010000 (1000dps full scale)
  Wire.endTransmission(true);    //End the transmission with the gyro
  Wire.beginTransmission(0x68);  //Start communication with the address found during search.
  Wire.write(0x1C);              //We want to write to the ACCEL_CONFIG register
  Wire.write(0x10);              //Set the register bits as 00010000 (+/- 8g full scale range)
  Wire.endTransmission(true);

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);


  servo0.attach(11);
  servo1.attach(12);
  Serial.println("");
     servo0.write(150);
      servo1.write(150);
  delay(100);
}

void loop() {

  sensors_event_t a, g, temp;

      
 






if (start == true) {

    mpu.getEvent(&a, &g, &temp);

    time = millis();
      delay(100);

    if (start_at == 0) {
      start_at = time;
    }

    else if (a.acceleration.y - 10 > 60 && start == false) {
      start = true;



    }

    else {
      Serial.println(a.acceleration.x - 10);
    }
    //
    if (start == true && csdeploy == false && (time - start_at) > 10000 && start_at != 0) {
      csdeploy = true;
      servo0.write(0);
      servo1.write(0);
      Serial.println("Safety deployment: deploy!!");
    } else if (start == true && csdeploy == false && (time - start_at) > 6000 && start_at != 0) {
      if ((abs(a.gyro.x) > 9 or a.gyro.y < 6)) {
        if (a.acceleration.y - 10 < 5 && abs(a.acceleration.y) < 5) {
          count++;
        }
        Serial.println(count);

        if (count > 3) {
          Serial.print("normal deployment: deploy!!");
          csdeploy = true;
          servo0.write(0);
          servo1.write(0);
        }
      } else {
        Serial.print("         ");
        Serial.println(count);
      }
    }

    Serial.print(csdeploy);
    Serial.print(" , ");


    Serial.println(time - start_at);
  }
}
