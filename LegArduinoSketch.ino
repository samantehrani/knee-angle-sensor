#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

#define BNO055_SAMPLERATE_DELAY_MS (100)

Adafruit_BNO055 upperLeg = Adafruit_BNO055(0,BNO055_ADDRESS_A);
Adafruit_BNO055 lowerLeg = Adafruit_BNO055(1,BNO055_ADDRESS_B);

void setup(void)
{
  Serial.begin(9600);
  
  /* Initialise the sensor */
  if(!upperLeg.begin())
  {
    
    Serial.print("Ooops,Upper Leg Issue");
    while(1);
  }else if ( !lowerLeg.begin() ){
    Serial.print("Ooops,Lower Leg Issue");
    while(1);
  }

  delay(1000);

  upperLeg.setExtCrystalUse(true);
  lowerLeg.setExtCrystalUse(true);
}

void loop(void)
{
  imu::Vector<3> upperLegEuler = upperLeg.getVector(Adafruit_BNO055::VECTOR_EULER);
  imu::Vector<3> lowerLegEuler = lowerLeg.getVector(Adafruit_BNO055::VECTOR_EULER);
  /* Display the floating point data of Upper Leg */
  Serial.print("X: ");
  Serial.print(upperLegEuler.x());
  Serial.print(" Y: ");
  Serial.print(upperLegEuler.y());
  Serial.print(" Z: ");
  Serial.print(upperLegEuler.z());
  Serial.print("\t\t");
  
/* Display the floating point data of Lower Leg */
  Serial.print("X: ");
  Serial.print(lowerLegEuler.x());
  Serial.print(" Y: ");
  Serial.print(lowerLegEuler.y());
  Serial.print(" Z: ");
  Serial.print(lowerLegEuler.z());
  Serial.print("\t\t");



  Serial.println();
  /*
  // Quaternion data
  imu::Quaternion quat = bno.getQuat();
  Serial.print("qW: ");
  Serial.print(quat.w(), 4);
  Serial.print(" qX: ");
  Serial.print(quat.y(), 4);
  Serial.print(" qY: ");
  Serial.print(quat.x(), 4);
  Serial.print(" qZ: ");
  Serial.print(quat.z(), 4);
  Serial.print("\t\t");
  */

  

  delay(BNO055_SAMPLERATE_DELAY_MS);
}
