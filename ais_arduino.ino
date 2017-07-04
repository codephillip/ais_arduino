#include <SoftwareSerial.h>

//SIM900 RX is connected to Arduino D10
#define SIM900_RX_PIN 7

//SIM900 TX is connected to Arduino D11
#define SIM900_TX_PIN 8
int water_valve = 6;

//Create software serial object to communicate with SIM900
SoftwareSerial serialSIM900(SIM900_RX_PIN, SIM900_TX_PIN);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  serialSIM900.begin(9600);
  delay(2000);
  pinMode(water_valve, OUTPUT);
  Serial.println("Setup Complete!");
}

void loop() {
  // put your main code here, to run repeatedly:
  int count = 0;
  int smv = 0;
  while(count < 10) {
     Serial.print("Moisture Sensor Value:");
    //read soil moisture value every one second
    smv += analogRead(A5);
    Serial.println(smv);
    delay(3000);
    count++;
  }

  //take average
  smv = smv / 10;
  Serial.print("average smv: ");
  Serial.println(smv);   
  
  getMetrics();
  getTriggers();

  delay(240000);
  //open water valve
  digitalWrite(water_valve, HIGH);
  delay(1000);       
  // close water valve
  digitalWrite(water_valve, LOW);   
  delay(1000); 

}
