/*Universidad Tecnica del Norte
 * FICA-CIERCOM
 * SISTEMAS MICROPROCESADOS
 * TIMER 1
 * Realizar un programa de seguridad domótica que permita encender las luces de un domicilio de 5 habitaciones de forma aleatoria 
*  solo en horario nocturno. El sistema se activa al ingresar una contraseña por comunicación serial.
*/

#include <MsTimer2.h> //Declaramos las librerias 
#include <TimerOne.h>
#include <EEPROM.h>
String pswd;          //Variable para la validacion de contraseñas
boolean validar;
int cont=0;           //Variables para encender las luces aletoriamente
int contador=0;
int on=0;
int i=0;
int segundero;
int minutero;
int horero;


void setup() {
Serial.begin(9600);          // Iniciamos la comunicacion serial 
Timer1.initialize(1000000);  //Iniciamos el timer en 1 segundo 
Timer1.attachInterrupt(conteo);  //Le acoplamos a un direccion 
pinMode(8,OUTPUT);               //Pines de salida para las luces
pinMode(9,OUTPUT); 
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT); 
MsTimer2::set(100,reloj);      //Por cuestion de simulacion ajustamos el tiempo del reloj a la mitad 
MsTimer2::start();
Serial.println("Ingrese la contrasenia");  //Mensaje inicial 
Timer1.stop();
segundero=EEPROM.read(0);      //Guardamos los datos del reloj en EEPROM
minutero=EEPROM.read(1);
horero=EEPROM.read(2);

}

void loop() {
    if(Serial.available()>0){           //Metodo para validar la contraseña
      pswd=Serial.readString();
      if(pswd.length()!=4){
         }else{
        validar=pswd.equals("1234");
        if(validar==true){
         Serial.println("PSWD VALIDO");
         Serial.println("Sistema encendido");
         Serial.println("Luces apagadas"); //apagamos las luces en caso de ser denoche se encienden 
             digitalWrite(8,LOW);
             digitalWrite(9,LOW);
             digitalWrite(11,LOW);
             digitalWrite(10,LOW);
             digitalWrite(12,LOW);
         on=1;
         Timer1.stop();
    
        }else{
      Serial.println("PSWD INVALIDO");
          delay(1000);     
        }
      }
    }
     if(minutero == 6 && segundero ==0){
      if(on==1){
        delay(100);
        Timer1.stop();
      Serial.println("Horario matutino"); //En el horario matutino apagamos las luces
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);
    contador=0;
            }
    
     } if(minutero == 19 && segundero ==0){   //En el hoario nocturno empieza a prender luces aletoriamente
         delay(100);
         Timer1.start();
        Serial.println("Horario nocturno");
    }
   }
 
 void conteo(){                     //Metodo para el encendido de luces aletorio
  contador++;
  if(contador==1)digitalWrite(8,HIGH);
  if(contador==5)digitalWrite(9,HIGH);
  if(contador==6)digitalWrite(8,LOW);
  if(contador==8)digitalWrite(10,HIGH);
  if(contador==10)digitalWrite(11,HIGH);
    if(contador==12)digitalWrite(9,LOW);
  if(contador==16)digitalWrite(12,HIGH);
  if(contador==18)digitalWrite(10,LOW);
  if(contador==20)digitalWrite(11,LOW);
  if(contador==25)digitalWrite(8,HIGH);
  if(contador==25){
       contador=0;
    }

}     
void reloj(){                      //Metodo del reloj 
  
if(segundero<30){
  segundero++;
  }
  else{
  segundero=0;
  if(minutero<24){
  minutero++;
  }        
  else{
  minutero=0;
  if(horero<24){
  horero++;
   }
   else{
   horero=0;
  }
    
 }
  
}
}
   
