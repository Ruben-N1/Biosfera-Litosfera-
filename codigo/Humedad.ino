/*
  Práctica: Monitor de humedad del suelo
  Desarrollo Sustentable (ACD-0908) - Unidad 2: Escenario natural
  Tecnológico Nacional de México, campus Mazatlán

  Conexiones:
    Sensor VCC -> 5V
    Sensor GND -> GND
    Sensor SIG -> A0
*/

const int PIN_SENSOR = A0;   // Señal del sensor
const int PIN_LED    = 13;   // LED integrado (alerta de riego)

// Umbral: ajústalo midiendo tierra seca y mojada
const int UMBRAL_HUMEDAD = 400;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
  Serial.println("=== Monitor de humedad del suelo ===");
}

void loop() {
  int lectura = analogRead(PIN_SENSOR);              // 0 a 1023
  int porcentaje = map(lectura, 0, 876, 0, 100);     // 876 = máximo en Tinkercad
  porcentaje = constrain(porcentaje, 0, 100);

  Serial.print("Lectura: ");
  Serial.print(lectura);
  Serial.print("  |  Humedad: ");
  Serial.print(porcentaje);
  Serial.print("%  |  Estado: ");

  if (lectura < UMBRAL_HUMEDAD) {
    Serial.println("TIERRA SECA -> Se recomienda regar");
    digitalWrite(PIN_LED, HIGH);
  } else {
    Serial.println("TIERRA HUMEDA -> No necesita riego");
    digitalWrite(PIN_LED, LOW);
  }

  delay(1000);
}