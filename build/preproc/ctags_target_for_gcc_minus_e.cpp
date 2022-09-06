# 1 "c:\\Users\\usuario\\Documents\\GitHub\\Deposito\\Deposito.ino"
# 2 "c:\\Users\\usuario\\Documents\\GitHub\\Deposito\\Deposito.ino" 2
# 3 "c:\\Users\\usuario\\Documents\\GitHub\\Deposito\\Deposito.ino" 2
# 4 "c:\\Users\\usuario\\Documents\\GitHub\\Deposito\\Deposito.ino" 2


Deposito Deposito1;
bool config;
int data;

void onRequest();
void onReceive(int);

void setup()
{
  Wire.begin(8);
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
