#line 1 "c:\\Users\\usuario\\Documents\\GitHub\\Deposito\\Deposito.ino"
#include <Arduino.h>
#include <Wire.h>
#include "deposito.h"

#define I2C_ADDRESS 8
Deposito Deposito1;
bool config;
int data;

void onRequest();
void onReceive(int);

#line 13 "c:\\Users\\usuario\\Documents\\GitHub\\Deposito\\Deposito.ino"
void setup();
#line 21 "c:\\Users\\usuario\\Documents\\GitHub\\Deposito\\Deposito.ino"
void loop();
#line 39 "c:\\Users\\usuario\\Documents\\GitHub\\Deposito\\Deposito.ino"
void onReceive(int numBytes);
#line 13 "c:\\Users\\usuario\\Documents\\GitHub\\Deposito\\Deposito.ino"
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
  Wire.write(const_cast<uint8_t *>(buffer), len);
}

void onReceive(int numBytes)
{
  data = Wire.read();
}
