#include <MsTimer2.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <avr/wdt.h>
#include <TimerOne.h>

  
/*
 *UNIVERSIDAD TÉCNICA DEL NORTE
   FICA-CIERCOM
   MICROPROCESADOS

   Nombre: Christofer Macas
   Fecha: 28-07-2019

   Temas:
 Estimados estudiantes: Realizar un programa que reinicie el sistema al tener la hora 00:10:50. Cuando vuelva a funcionar,
 deberá empezar con la hora 00:11:10. Es proceso se observa en una LCD. No habrá extensión de plazo.

 */
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); //pines para conectar el lcd
int dato;
int j = 0;
int i = 0;
int on=0;
int reinicio=0;
int var = 10;
int segundero;
int minutero;
int horero=0;

void setup() {
  Serial.begin(9600);
   MsTimer2::set(250, reloj); //Configurar el timer2
  MsTimer2::start();  //inicializar el timer
  on=EEPROM.read (0);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(contar);
  Timer1.start();
}

void loop() {
  if(on==0){
  if(horero==0 && minutero==10 && segundero==50){
    Serial.print("Desactivado");
    Serial.println(reinicio);
      EEPROM.update(1,segundero);
      EEPROM.update(2,minutero);
      EEPROM.update(3,horero);
    MsTimer2::stop();
    }
  }
    if(on==1){
          if(horero==0 && minutero==11 && segundero==50){
      segundero=EEPROM.read(1);
      minutero=EEPROM.read(2);
      horero=EEPROM.read(3);
        MsTimer2::start();
  }
  
  
}
  }

void reloj(){

if(segundero<59){
  segundero++;
    lcd.setCursor(9, 1);
    lcd.print(segundero);
    lcd.setCursor(8, 1);
    lcd.print(':');
     lcd.setCursor(2,1);
    lcd.print('0');
     lcd.setCursor(5,1);
    lcd.print('0');
  }
  else{
      segundero=0;
      lcd.setCursor(9,1);
      lcd.print("   ");
     lcd.setCursor(9, 1);
    lcd.print(segundero);
    
  if(minutero<59){
  minutero++;
   lcd.setCursor(6, 1);
    lcd.print(minutero);
    lcd.setCursor(5, 1);
    lcd.print(':');
  }        
  else{
     minutero=0;
     lcd.setCursor(6,1);
      lcd.print("   ");
    lcd.setCursor(6, 1);
    lcd.print(minutero);
 
  if(horero<24){
  horero++;
    lcd.setCursor(3, 1);
    lcd.print(horero);
    lcd.setCursor(2, 1);
    lcd.print(':');
    lcd.setCursor(1,1);
    lcd.print("00");
   }
   else{
      horero=0;
      lcd.setCursor(3,1);
      lcd.print("   ");
      lcd.setCursor(3, 1);
    lcd.print(horero);
 
   
 }
    
 }
  }
}


void limpiar() {
  lcd.setCursor(0, 0);
  lcd.print(" "); lcd.setCursor(1, 0);
  lcd.print(" "); lcd.setCursor(2, 0);
  lcd.print(" "); lcd.setCursor(3, 0);
  lcd.print(" "); lcd.setCursor(4, 0);
  lcd.print(" "); lcd.setCursor(5, 0);
  lcd.print(" "); lcd.setCursor(6, 0);
  lcd.print(" "); lcd.setCursor(7, 0);
  lcd.print(" "); lcd.setCursor(8, 0);
  lcd.print(" "); lcd.setCursor(9, 0);
  lcd.print(" "); lcd.setCursor(10, 0);
  lcd.print(" "); lcd.setCursor(11, 0);
  lcd.print(" "); lcd.setCursor(12, 0);
  lcd.print(" "); lcd.setCursor(13, 0);
  lcd.print(" "); lcd.setCursor(14, 0);
  lcd.print(" "); lcd.setCursor(15, 0);
  lcd.print(" ");
}
void contar () {
  reinicio++ ;
 //Serial.println (reinicio) ;
  if (reinicio==10&&on==0) {
    wdt_enable (WDTO_1S) ;
    EEPROM.write (0,1) ;
  } else if (reinicio==10&&on==1) {
    wdt_enable (WDTO_1S) ;
    EEPROM.write (0,0) ;
     } 
  }
