/*
 * UNIVERSIDAD TÉCNICA DEL NORTE 
 * FICA-CIERCOM 
 * SISTEMAS MICROPROCESADOS 
 * Nombre: Macas Christofer 
 * Realizar una validación de placa de vehículo donde indique: *La provincia *si ha registrado los 4 dígitos necesarios. 
 * *si no tiene números en la parte de las letras.
 * El arduino uno no tiene tanta capacidad de memoria por lo que no se pude ingresar todas las provinchias en el programa 
 */

String dato;  //Declaramos la variable de ingreso por comunicacion serial
String letras; // Declaramos la variable donde almacenaremos el vector
String numeros; 
char l1;       // Asisgnamos la variable para la primera letra de la placa
char l2;      // Asisgnamos la variable para la segunda letra de la placa
char l3;      // Asisgnamos la variable para la tercera letra de la placa
char n1;      // Asisgnamos la variable para el primer numero de la placa
char n2;      // Asisgnamos la variable para el segundo numero de la placa
char n3;     // Asisgnamos la variable para el tercer numero de la placa
char n4;     // Asisgnamos la variable para el cuarto numero de la placa

void setup() {
Serial.begin(9600);                 //Iniciamos la comunicacion serial en 9600
Serial.println("Ingrese la placa");  // Pregunta inicial

}

void loop() {
if (Serial.available() > 0) {      // se valida la comunicacion serial 
    dato = Serial.readString();
     letras=dato.substring(0,dato.indexOf("-")); //Agrupamos la parte de las letras en un vector
    numeros=dato.substring(dato.indexOf("-")+1,dato.length()); //Agrupamos la parte de los numeros en un vector
  l1 = letras.charAt(0);                                      // Asignamos las posciones del vector para los numeros
  l2 = letras.charAt(1);
  l3 = letras.charAt(2);

  n1 = numeros.charAt(0);                                     //Asignamos las posiciones del vector para los numeros
  n2 = numeros.charAt(1);
  n3 = numeros.charAt(2);
  n4 = numeros.charAt(3);
  if(numeros.length() == 4){                                   //Condicionamos que sean solo 4 numeros por placa 
  if(letras.length() == 3){                                    // Condicionamos que solo sean 3 letras por placa
   if (l1 == 'A') {                                            //Para saber de que provincia pertenece el vehiculo se toma como referencia la primera letra de la placa
    if(l2 == 'A'){                                             // Para saber que tipo de vehiculo es se toma como referencia la segunda letra de la placa 
    Serial.println("LA PLACA ES DE AZUAY Y ES UN VEHICULO COMERCIAL"); // Indicamos de que provincia es el vehiculo y el tipo 
    }else{
      Serial.println("LA PLACA ES DE AZUAY Y ES UN VEHICULO PARTICULAR");
        }
           }
              
    if (l1 == 'B') {
    if(l2 == 'A'){
    Serial.println("LA PLACA ES DE BOLIVAR Y ES UN VEHICULO COMERCIAL");
    }else{
      Serial.println("LA PLACA ES DE BOLIVAR Y ES UN VEHICULO PARTICULAR");
    }
      }
    if (l1 == 'U') {
    if(l2 == 'A'){
    Serial.println("LA PLACA ES DE CAÑAR Y ES UN VEHICULO COMERCIAL");
    }else{
      Serial.println("LA PLACA ES DE CAÑAR Y ES UN VEHICULO PARTICULAR");
    }
      }
    if (l1 == 'C') {
    if(l2 == 'A'){
    Serial.println("LA PLACA ES DE CARCHI Y ES UN VEHICULO COMERCIAL");
    }else{
      Serial.println("LA PLACA ES DE CARCHI Y ES UN VEHICULO PARTICULAR");
    }
      }
    if (l1 == 'H') {
    if(l2 == 'A'){
    Serial.println("LA PLACA ES DE CHIMBORAZO Y ES UN VEHICULO COMERCIAL");
    }else{
      Serial.println("LA PLACA ES DE CHIMBORAZO Y ES UN VEHICULO PARTICULAR");
    }
      }
    if (l1 == 'X') {
    if(l2 == 'A'){
    Serial.println("LA PLACA ES DE COTOPAXI Y ES UN VEHICULO COMERCIAL");
    }else{
      Serial.println("LA PLACA ES DE COTOPAXI Y ES UN VEHICULO PARTICULAR");
    }
      }
//    if (l1 == 'O') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE EL ORO Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE EL ORO Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'E') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE ESMERALDAS Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE ESMERALDAS Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'W') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE GALAPAGOS Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE GALAPAGOS Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//     if (l1 == 'G') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DEL GUAYAS Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DEL GUAYAS Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'I') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE IMBABURA Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE IMBABURA Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'L') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE LOJA Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE LOJA Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'R') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE LOS RIOS Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE LOS RIOS Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'M') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE MANABI Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE MANABI Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//     if (l1 == 'V') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE MORONA SANTIAGO Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE MORONA SANTIAGO Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'N') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE NAPO Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE NAPO Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'Q') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE ORELLANA Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE ORELLANA Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'S') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE PASTAZA Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE PASTAZA Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'P') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE PICHINCHA Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE PICHINCHA Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'Y') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE SANTA ELENA Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE SANTA ELENA Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'J') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE SANTO DOMINGO DE LOS TSACHILAS Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE SANTO DOMINGO DE LOS TSACHILAS Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'K') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE SUCUMBIOS Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE SUCUMBIOS Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'T') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE TUNGURAHUA Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE TUNGURAHUA Y ES UN VEHICULO PARTICULAR");
//    }
//      }
//    if (l1 == 'Z') {
//    if(l2 == 'A'){
//    Serial.println("LA PLACA ES DE ZAMORA CHINCHIPE Y ES UN VEHICULO COMERCIAL");
//    }else{
//      Serial.println("LA PLACA ES DE ZAMORA CHINCHIPE Y ES UN VEHICULO PARTICULAR");
//    }
//      }
      
    }
  }else{
        Serial.println("Placa no valida");                                 // Error si se ingresa mal la placa  
                                                         
      }
        }
          } 
