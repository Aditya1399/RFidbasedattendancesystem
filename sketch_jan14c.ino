#include <SPI.h>
#include <MFRC522.h>
#include "SoftwareSerial.h"
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
SoftwareSerial ser(2,3); // RX, TX 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  ser.begin (115200);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Put RFID Card to Scan...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("User No./Name:    ");
  content.toUpperCase();
  if (content.substring(1) == "C3 4C 2D 24" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("1-Aditya Dogra");
    ser.write(1);
    Serial.println();
    
    delay(3000);
  }
   if (content.substring(1) ==  "01 15 C9 1F" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("2-Tracy Witney");
    ser.write(2);
    Serial.println();
    
    delay(3000);
  }
   if (content.substring(1) == "B9 BF 62 1B" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("3-Lucinda Ambrey");
    ser.write(3);
    Serial.println();
    
    delay(3000);
  }
   if (content.substring(1) == "C9 17 AF E3" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("4-Simon Jones");
    ser.write(4);
    Serial.println();
    
    delay(3000);
  }
   if (content.substring(1) == "D9 4D 0C 1B" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("5-Dimitri Levrock");
    ser.write(5);
    Serial.println();
    
    delay(3000);
  }
    if (content.substring(1) ==  "3B 06 A9 1B" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("6-Jasmine Joseph");
    ser.write(6);
    Serial.println();
    
    delay(3000);
  }
  }
