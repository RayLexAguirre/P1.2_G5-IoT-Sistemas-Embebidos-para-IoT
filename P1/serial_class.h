class serial_class {

 //Funciones que podrán ser llamadas fuera de la clase
public:

  void get_data( void ){ 
    if (Serial.available() > 0){ //Revisa si hay algún dato guardado que pueda utilizar 
      String Data = Serial.readStringUntil('\n'); //Revisa el string ingresado e ignora el salto de línea
      post_data(Data);
    } else {
      Serial.println("INGRESA UN NÚMERO"); //Si no recibe nada entonces pedirá el ingreso de un número
      delay(3000);
    }
}

//Funciones que no podrán ser llamadas fuera de las clases
private:

void get_max (int sig, int num) {
  uint8_t maxT8 = 0;
  uint16_t maxT16 = 0;
  uint32_t maxT32 = 0;
  uint64_t maxT64 = 0;
  int8_t imaxT8 = 0;
  int16_t imaxT16 = 0;
  int32_t imaxT32 = 0;
  int64_t imaxT64 = 0;
  if(sig == 0){
    if(num == 8){
      maxT8 = pow(2, 8) -1;
      Serial.println(maxT8);
    } else if (num == 16){
      maxT16 = pow(2, 16) -1;
      Serial.println(maxT16);
    } else if (num == 32){
      maxT32 = pow(2, 32) -1;
      Serial.println(maxT32);
    } else if (num == 64){
      maxT64 = pow(2, 64) -1;
      Serial.println(maxT64);
    }
  } else {
    if(num == 8){
      imaxT8 = pow(2, 8-1) -1;
      Serial.println(imaxT8);
    } else if (num == 16){
      imaxT16 = pow(2, 16-1) -1;
      Serial.println(imaxT16);
    } else if (num == 32){
      imaxT32 = pow(2, 32-1) -1;
      Serial.println(imaxT32);
    } else if (num == 64){
      imaxT64 = pow(2, 64-1) -1;
      Serial.println(imaxT64);
    }
  }
}

void get_min (int num) {
  int8_t iminT8 = 0;
  int16_t iminT16 = 0;
  int32_t iminT32 = 0;
  int64_t iminT64 = 0;
  
    if(num == 8){
      iminT8 = pow(2, 8-1) -1;
      Serial.println(iminT8);
    } else if (num == 16){
      iminT16 = pow(2, 16-1) -1;
      Serial.println(iminT16);
    } else if (num == 32){
      iminT32 = pow(2, 32-1) -1;
      Serial.println(iminT32);
    } else if (num == 64){
      iminT64 = pow(2, 64-1) -1;
      Serial.println(iminT64);
    }
  }

void post_data(char Data){ //Organización de los resultados de todas las funciones
  Serial.print("-----Calculando rango de ");
  Serial.print(Data);
  Serial.println("-----");
  
  switch (Data){
  case 'uint8':
  Serial.print("Rango de 0 a ");
    get_max(0, 8);
    break;
  case 'uint16':
  Serial.print("Rango de 0 a ");
    get_max(0, 16);
    break;
  case 'uint32':
  Serial.print("Rango de 0 a ");
    get_max(0, 32);
    break;
  case 'uint64':
  Serial.print("Rango de 0 a ");
    get_max(0, 64);
    break;
  case 'int8':
  Serial.print("Rango de ");
    get_min(8);
  Serial.print(" a ");
    get_max(1, 8);
    break;
  case 'int16':
  Serial.print("Rango de ");
    get_min(16);
  Serial.print(" a ");
    get_max(1, 16);
    break;
  case 'int32':
  Serial.print("Rango de ");
    get_min(32);
  Serial.print(" a ");
    get_max(1, 32);
    break;
  case 'int64':
  Serial.print("Rango de ");
    get_min(64);
  Serial.print(" a ");
    get_max(1, 64);
    break;
  default:
    Serial.println("Variable no valida");
    break;
  }
}
};
