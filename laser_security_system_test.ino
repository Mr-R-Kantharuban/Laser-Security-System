#include <LiquidCrystal.h>
int Laser = 2; 

int ldr=A0; 
int red_light_pin= A2;
int green_light_pin =A3 ;
int blue_light_pin = A4;
int x = 0; 
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  
  Serial.begin(9600); 
   
pinMode (Laser,OUTPUT); 
pinMode(ldr,INPUT);

  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
digitalWrite(Laser,LOW);  

  lcd.begin(16, 2);
  
}
void loop(){
    digitalWrite(Laser,HIGH);      
   x=analogRead(ldr);
   Serial.println(x);
   if(x<100)
   {
    RGB_color(0, 0, 255); // Red
    
  delay(1000);
  lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Object is safe");
  lcd.setCursor(0,1);
   lcd.print(" locked :)");
  
   }
   else
   {
   RGB_color(255, 0, 0); // Blue
   Serial.println("Someone arrived!!");
  delay(1000);
  lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("  DANGER !!");
  lcd.setCursor(0,1);
   lcd.print("System disturbed");
   }
        
  
}
  void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
