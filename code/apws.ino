#include <LiquidCrystal.h> 

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
 int sensor_pin = A0; 
int output_value= 0;
int moisture_percentage= 0;
void setup(){ 
  pinMode(4,OUTPUT); 
      
  
  Serial.begin(9600);
    delay(1000); 
  Serial.println("AUTOMATIC PLANT WATERING SYSTEM"); 
  lcd.begin(28, 2); 
   lcd.setCursor(0, 0); 
  
  char *a[] = {"A", "U", "T","0", "M","A","T","I","C","P","L","A","N","T","W","S"}; 
  for (int i = 0; i < 16; i++) { 
    lcd.print(a[i]); 
    delay(500); 
  } 
  delay (1000); 
 
  
  lcd.setCursor(16, 1); 
  
  lcd.autoscroll(); 
  
  char *b[] = {"D", "E", "V","E", "L","O","P","E","D"," ","B","Y"," ","G","R","O","U","P"}; 
  for (int i = 0; i < 18; i++) { 
    lcd.print(b[i]); 
    delay(500); 
  } 
  delay (2000); 
  
  lcd.noAutoscroll(); 
  lcd.clear(); 
  
}
void loop(){
 output_value=analogRead(sensor_pin);
 Serial.print("\n\nAnalog Value: ");
  Serial.print(output_value);
  
  moisture_percentage = map(output_value, 1023, 200, 0, 100);
  lcd.clear();
lcd.print("MOISTURE");
delay(1000);


lcd.print(moisture_percentage);
  
  lcd.println("%");
  
 
  if(  moisture_percentage<35){
    digitalWrite(4,HIGH);
    
  }
  else{
    digitalWrite(4,LOW);
  }
  delay(1000);
}
 
