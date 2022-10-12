#include "serial_class.h"

serial_class calculadora;

void setup( void ) {

  Serial.begin ( 115200 ); // Configuración BaudRate, un sistema puede tener varios puertos seriales físicos.
  
}

void loop ( void ) {
 calculadora.get_data(); //Se manda llamar el get_data que será el encargado de ejecutar todas las funciones
}
