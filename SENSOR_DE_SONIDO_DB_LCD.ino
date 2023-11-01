const int PinSensor = A0; //pino Anlógico de Entrada 0
const int PinDigital = 0;
//int Estado = 0;
int ValorSensor = 0;
int valorMayor = 0;
float sensado = 0;
int dB = 0;
int cont = 0;

/*#include <LiquidCrystal.h> //libreria pantalla LCD 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Parametros de inicializacion*/
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);   // inicializa la interfaz I2C del LCD 16x2
void setup()
{
Serial.begin(9600);
/*pinMode(0, INPUT);  //Modo de pin 0 como entrada
lcd.begin(16,2); //Inicializa LCD 
lcd.clear();   //Limpia la pantalla LCD
lcd.setCursor(0,0); //El cursor se posiciona en la linea 0 columna 0  
lcd.print("iNTENCIDAD: ");  //Imprime el mensjade en la pantalla LCD
lcd.setCursor(10,1);  //Posiciona el cursor en la linea 10 y en la columna 1 para imprimir el siguiente mensaje 
lcd.print("dB");  //Se imprime el mensaje en la pantalla LCD*/
pinMode(13, OUTPUT);               //Salida por el pin 13
lcd.init();                         // Se inicializa el LCD 16x2
lcd.backlight();                           
lcd.clear();
lcd.print("INTENCIDAD: ");  //Imprime el mensjade en la pantalla LCD 
lcd.setCursor(10,1);  //Posiciona el cursor en la linea 10 y en la columna 1 para imprimir el siguiente mensaje 
lcd.print("dB");  //Se imprime el mensaje en la pantalla LCD
}
void loop()
{
lcd.setCursor(3,1); //Posiciona el cursor en la linea 3 columna 1
while(cont < 10000) //Se inicia un ciclo while 
{
ValorSensor = analogRead(PinSensor); // La variable ValorSensor guarda el valor analogo de PinSensor
if(ValorSensor > valorMayor)  //Inica una condicional if para hacer las lecturas  
{
valorMayor = ValorSensor;
}
cont++;
}
cont = 0;
sensado = valorMayor/1023.0*4.53;
//dB = 103.1*sensado - 115,4;
dB = 87.1*sensado - 290,0; //dB = 87.1*sensado - 75,4;
if(dB < 0)
{
dB = 0;
}
lcd.print("");
lcd.setCursor(3,1);
lcd.print(dB);
Serial.print("Sensado: ");
Serial.print(sensado);
Serial.println(" V");
Serial.print("Intensidad: ");
Serial.print(dB);
Serial.println(" dB");
valorMayor = 0;
delay(100);
}
