#include <Arduino.h>     // General de Arduino
#include <Wire.h>        // Libreria I2C
#include "estructuras.h" // Estructuras de datos comunes
#include "deposito.h"    // Biblioteca de control de depositos.
#include "hardware.h"    // Biblioteca de contol del hardware.

#define I2C_ADDRESS 8

Deposito deposito1;
Hardware Sistema1;

int data;

void onRequest();
void onReceive(int);

void setup()
{
  Wire.begin(I2C_ADDRESS);
  Wire.onRequest(onRequest);
  Wire.onReceive(onReceive);
  Sistema1.begin();
  deposito1.begin();
}

void loop()
{
  Sistema1.Control();
  deposito1.Control();
  if (data == 1)
  {
    deposito1.configDeposito;
  }
}

volatile byte buffer[3];
volatile byte len = 1;

void onRequest()
{
  // Envio de respuesta
  Wire.write(const_cast<uint8_t *>(buffer), len);
}

void onReceive(int numBytes)
{
  data = Wire.read();
}