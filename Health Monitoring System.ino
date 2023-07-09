#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int hot = 87; //set hot parameter
const int cold = 75;

void setup()
{
  lcd.begin(16, 2); 
  pinMode(A2, INPUT); //sensor
  pinMode(6, OUTPUT); //blue
  pinMode(7, OUTPUT); //green
  pinMode(8, OUTPUT); //red
  Serial.begin(9600);
}

void loop()
{
 
  int sensor = analogRead(A1);
  float voltage = (sensor / 1024.0) * 5.0;
  float tempC = (voltage - .5) * 100;
  float tempF = (tempC * 1.8) + 32;

  
  if (tempF < cold) { //cold
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    Serial.println(" It's Cold.");
    lcd.setCursor(0,0);          
  	lcd.print("   Patient Body ");
    lcd.setCursor(0,1);          
  	lcd.print("   Temp :");
    lcd.setCursor(10,1);          
  	lcd.print(tempF);
    lcd.setCursor(14,1);
    lcd.print("F");
   
  }
  else if (tempF >= hot) { //hot
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH); 
    Serial.println(" It's Hot.");
   lcd.print("   Patient Body ");
    lcd.setCursor(0,1);          
  	lcd.print("   Temp :");
    lcd.setCursor(10,1);          
  	lcd.print(tempF);
    lcd.setCursor(14,1);
    lcd.print("F");         
    }
  else { //fine
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    Serial.println(" Temperature is Just Perfect.");
    lcd.print("   Patient Body ");
    lcd.setCursor(0,1);          
  	lcd.print("   Temp :");
    lcd.setCursor(10,1);          
  	lcd.print(tempF);
    lcd.setCursor(14,1);
    lcd.print("F");        
  }
  delay(500);
  }