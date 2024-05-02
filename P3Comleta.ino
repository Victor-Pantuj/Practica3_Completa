// Estructura para los datos de los dulces
struct Dulce {
  String nombre;
  long cantidad;
};

// Datos de los dulces
Dulce listaDulces[5] = {
  {"POLO", 75},
  {"M&M", 50},
  {"Trident", 25},
  {"Granada", 35},
  {"Hershys", 60}
};

// Pines para los botones
#define BOTON_ADELANTE 2
#define BOTON_ATRAS 3

//Denino la funcion pausa
#define pausa delay(100)

// Variable para el dulce seleccionado
int dulceSeleccionado = 0;

#define MOSTRAR_DULCE_SELECCIONADO { \
  Serial.println("Dulce seleccionado:"); \
  Serial.println("Nombre: " + listaDulces[dulceSeleccionado].nombre); \
  Serial.println("Cantidad: " + String(listaDulces[dulceSeleccionado].cantidad)); \
   Serial.println("");\	
}

void setup() {
  Serial.begin(9600);
  pinMode(BOTON_ADELANTE, INPUT);
  pinMode(BOTON_ATRAS, INPUT);
  MOSTRAR_DULCE_SELECCIONADO;
}

void loop() {
  if (digitalRead(BOTON_ADELANTE) == HIGH) {
    dulceSeleccionado = (dulceSeleccionado + 1) % 5;
    MOSTRAR_DULCE_SELECCIONADO;
    pausa;
  }
  if (digitalRead(BOTON_ATRAS) == HIGH) {
    dulceSeleccionado = (dulceSeleccionado - 1 + 5) % 5;
    MOSTRAR_DULCE_SELECCIONADO;
    pausa;
  }
}
