#line 1 "c:\\Users\\usuario\\Documents\\GitHub\\Depo\\Depo.ino"
#include <Arduino.h>
#include <Wire.h>
#include "deposito.h"

#define I2C_ADDRESS 8
Deposito deposito1;
int data;

void onRequest();
void onReceive(int);

#line 12 "c:\\Users\\usuario\\Documents\\GitHub\\Depo\\Depo.ino"
void setup();
#line 20 "c:\\Users\\usuario\\Documents\\GitHub\\Depo\\Depo.ino"
void loop();
#line 39 "c:\\Users\\usuario\\Documents\\GitHub\\Depo\\Depo.ino"
void onReceive(int numBytes);
#line 12 "c:\\Users\\usuario\\Documents\\GitHub\\Depo\\Depo.ino"
void setup()
{
  Wire.begin(I2C_ADDRESS);
  Wire.onRequest(onRequest);
  Wire.onReceive(onReceive);
  deposito1.begin();
}

void loop()
{

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
