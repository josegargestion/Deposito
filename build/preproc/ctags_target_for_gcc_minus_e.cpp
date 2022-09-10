# 1 "c:\\Users\\usuario\\Documents\\GitHub\\Depo\\Depo.ino"
# 2 "c:\\Users\\usuario\\Documents\\GitHub\\Depo\\Depo.ino" 2
# 3 "c:\\Users\\usuario\\Documents\\GitHub\\Depo\\Depo.ino" 2
# 4 "c:\\Users\\usuario\\Documents\\GitHub\\Depo\\Depo.ino" 2


Deposito deposito1;
int data;

void onRequest();
void onReceive(int);

void setup()
{
  Wire.begin(8);
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
