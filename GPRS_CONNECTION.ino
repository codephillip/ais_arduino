
void getMetrics(void)
{
  //Serial.println("");
  serialSIM900.println("AT+CGATT?");
  delay(100);
  toSerial();


  // bearer settings
  serialSIM900.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(2000);
  toSerial();

  // bearer settings
  serialSIM900.println("AT+SAPBR=3,1,\"APN\",\"internet\"");
  delay(2000);
  toSerial();

  // bearer settings
  serialSIM900.println("AT+SAPBR=1,1");
  delay(2000);
  toSerial();
  
  // initialize http service
  serialSIM900.println("AT+HTTPINIT");
  delay(2000);
  toSerial();
  

 
  Serial.println("Fetching trigger");
  serialSIM900.print("AT+HTTPPARA=\"URL\",\"http://188.226.134.212:8000/api/v1/metrics?format=json");
  serialSIM900.println("\"");
 
  delay(2000);
  toSerial();
  delay(2000);


  // set http action type 0 = GET, 1 = POST, 2 = HEAD
  serialSIM900.println("AT+HTTPACTION=0");
  delay(6000);
  toSerial();

  // read server response
  serialSIM900.println("AT+HTTPREAD"); 
  delay(1000);
  toSerial();
  //delay(5000);

  serialSIM900.println("");
  serialSIM900.println("AT+HTTPTERM");
  toSerial();
  delay(300);

  serialSIM900.println("");
  delay(1000);
 }



void getTriggers(void)
{
  //Serial.println("");
  serialSIM900.println("AT+CGATT?");
  delay(100);
  toSerial();


  // bearer settings
  serialSIM900.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(2000);
  toSerial();

  // bearer settings
  serialSIM900.println("AT+SAPBR=3,1,\"APN\",\"internet\"");
  delay(2000);
  toSerial();

  // bearer settings
  serialSIM900.println("AT+SAPBR=1,1");
  delay(2000);
  toSerial();
  
  // initialize http service
  serialSIM900.println("AT+HTTPINIT");
  delay(2000);
  toSerial();
  

 
  Serial.println("Receiving trigger");
  serialSIM900.print("AT+HTTPPARA=\"URL\",\"http://188.226.134.212:8000/api/v1/triggers?format=json");
  serialSIM900.println("\"");
 
  delay(2000);
  toSerial();
  delay(2000);


  // set http action type 0 = GET, 1 = POST, 2 = HEAD
  serialSIM900.println("AT+HTTPACTION=0");
  delay(6000);
  toSerial();

  // read server response
  serialSIM900.println("AT+HTTPREAD"); 
  delay(1000);
  toSerial();
  //delay(5000);

  serialSIM900.println("");
  serialSIM900.println("AT+HTTPTERM");
  toSerial();
  delay(300);

  serialSIM900.println("");
  delay(1000);
 }
   
  void toSerial()
{
  while(serialSIM900.available()!=0)
  {
    Serial.write(serialSIM900.read());
  }
}





/*troubleshooting codes
600 Not HTTP PDU
601 Network Error
602 No memory
603 DNS Error
604 Stack Busy
*/
