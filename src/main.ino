// CÓDIGO FINAL PARA O SEU CIRCUITO QUE JÁ ESTÁ FUNCIONANDO

// Pinos definidos de acordo com a sua montagem real e funcional.
const int PINO_CONTROLE_MOTOR = 12; // Pino que controla o transistor/relé.
const int PINO_SENSOR_UMIDADE = A1; // Pino que lê o sensor.

// Limite para acionar a irrigação. Ajuste este valor se necessário.
const int UMIDADE_MINIMA = 40;

// Lógica de acionamento. Se o seu circuito liga com HIGH, está correto.
const int LIGAR_MOTOR = HIGH;
const int DESLIGAR_MOTOR = LOW;

void setup() {
  Serial.begin(9600);
  Serial.println("Sistema de Irrigacao Iniciado. (Usando configuracao funcional).");
  
  pinMode(PINO_CONTROLE_MOTOR, OUTPUT);
  
  // Garante que o motor comece desligado.
  digitalWrite(PINO_CONTROLE_MOTOR, DESLIGAR_MOTOR);
}

void loop() {
  // Lê o valor do sensor.
  int valorSensor = analogRead(PINO_SENSOR_UMIDADE);
  
  // Converte para porcentagem.
  int umidade = map(valorSensor, 1023, 0, 0, 100);

  Serial.print("Lendo pino A1 | Controle no pino 12 | Umidade: ");
  Serial.print(umidade);
  Serial.println("%");

  // Lógica de decisão para ligar ou desligar o motor.
  if (umidade < UMIDADE_MINIMA) {
    Serial.println("Status: Solo seco. Ligando motor...");
    digitalWrite(PINO_CONTROLE_MOTOR, LIGAR_MOTOR);
  } else {
    Serial.println("Status: Solo umido. Desligando motor.");
    digitalWrite(PINO_CONTROLE_MOTOR, DESLIGAR_MOTOR);
  }

  // Espera 2 segundos antes da próxima leitura.
  delay(2000);
}
