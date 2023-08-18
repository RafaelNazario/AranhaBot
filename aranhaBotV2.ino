#define BLYNK_TEMPLATE_ID "**********" // INSIRA ID DO TEMPLATE AQUI
#define BLYNK_TEMPLATE_NAME "*********"  // INSIRA NOME DO TEMPLATE BLYNK
#define BLYNK_AUTH_TOKEN "*********" // INSIRA TOKEN DE AUTETENTICAÇAO BLYNK AQUI

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define ENA 14
#define ENB 12
#define IN1 5
#define IN2 4
#define IN3 0
#define IN4 2

#define echo 13
#define trigger 15



char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "*******";    // INSIRA A SSID DA REDE WIFI
char pass[] = "*******";    // INSIRA PASSWORD DA REDE WIFI
int velAranha = 400;

void frente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velAranha);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, velAranha);
}

void tras() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, velAranha);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velAranha);
}

void direita() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, velAranha);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, velAranha);
}

void esquerda() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velAranha);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velAranha);
  
}

void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, LOW);
}



void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  digitalWrite(trigger, LOW);
  digitalWrite(echo, LOW);

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}

// Função de callback para o botão V1 (frente)
BLYNK_WRITE(V0) {
  int estado = param.asInt();
  if (estado == HIGH) {
    frente();
  } else {
    parar();
  }
}

// Função de callback para o botão V1 (trás)
BLYNK_WRITE(V1) {
  int estado = param.asInt();
  if (estado == HIGH) {
    tras();
  } else {
    parar();
  }
}

// Função de callback para o botão V2 (esquerda)
BLYNK_WRITE(V2) {
  int estado = param.asInt();
  if (estado == HIGH) {
    esquerda();
  } else {
    parar();
  }
}

// Função de callback para o botão V3 (direita)
BLYNK_WRITE(V3) {
  int estado = param.asInt();
  if (estado == HIGH) {
    direita();
  } else {
    parar();
  }
}
