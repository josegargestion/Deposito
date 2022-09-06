#include <Arduino.h>
#include <Wire.h>
#include "deposito.h"

#define I2C_ADDRESS 8
Deposito Deposito1;
bool config;
int data;

void onRequest();
void onReceive(int);

void setup()
{
  Wire.begin(I2C_ADDRESS);
  Wire.onRequest(onRequest);
  Wire.onReceive(onReceive);
  Deposito1.begin();
}

void loop()
{

Deposito1.Control();
if (config == true)
{
  Deposito1.configDeposito;
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