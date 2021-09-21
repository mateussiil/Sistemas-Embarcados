int MAX = 3; 
int soma = 0; 
int valorTotal = 0;

int estadoBtnEnter = 0;
int estadoBtnSoma = 0;

int pinoBotaoEnter = 9;
int pinoBotaoSoma = 10;

int countEnter = 0;
unsigned long agora=0;

void btnEnterInterrupt();
void pausa();
void showDisplay(byte soma);
void btnEnterInterrupt();
void btnSomaInterrupt();


byte seven_seg_digits[4][7] = {
  { 1,1,1,1,1,1,0 },  //DIGITO 0
  { 0,1,1,0,0,0,0 },  //DIGITO 1
  { 1,1,0,1,1,0,1 },  //DIGITO 2
  { 1,1,1,1,0,0,1 }  //DIGITO 3
};

int digito[8][3] = {
 { LOW, LOW, LOW }, // 0
 { LOW, LOW, HIGH }, // 1
 { LOW, HIGH, LOW }, // 2
 { LOW, HIGH, HIGH }, // 3
 { HIGH, LOW, LOW }, // 4
 { HIGH, LOW, HIGH }, // 5
 { HIGH, HIGH, LOW }, // 6
 { HIGH, HIGH, HIGH } // 7
};


void setup()
{
  pinMode(pinoBotaoSoma, INPUT);  
  pinMode(pinoBotaoEnter, INPUT);

  pinMode(2, OUTPUT); //PINO 2 -> SEGMENTO A  
  pinMode(3, OUTPUT); //PINO 3 -> SEGMENTO B
  pinMode(4, OUTPUT); //PINO 4 -> SEGMENTO C
  pinMode(5, OUTPUT); //PINO 5 -> SEGMENTO D
  pinMode(6, OUTPUT); //PINO 6 -> SEGMENTO E
  pinMode(7, OUTPUT); //PINO 7 -> SEGMENTO F
  pinMode(8, OUTPUT); //PINO 8 -> SEGMENTO G
  
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT); 
  pinMode(13, OUTPUT); 

  showDisplay(0);
  soma = 0;
  valorTotal =0;
}



void loop() {
  estadoBtnEnter = digitalRead(pinoBotaoEnter);  
  estadoBtnSoma = digitalRead(pinoBotaoSoma);
  
  if (estadoBtnSoma == HIGH && soma != MAX) {
    soma+=1;
    showDisplay(soma);
  }
  
  if(estadoBtnEnter == HIGH){
    valorTotal +=soma;
    soma = 0;
    countEnter++;
    if(countEnter == 2){
      showLeds(valorTotal);
    }
    else if(countEnter == 3){
      showLeds(0);
	  showDisplay(0);
      countEnter = 0;
      valorTotal= 0;
    }
  }
}


void pausa(int periodo)
{
  agora = millis();
  while(millis() < agora + periodo) {
    // Nada a fazer
  }
}

void showDisplay(byte soma)
{
  
  byte pino = 2;

  for (byte i = 0; i < 7; ++i){ 
    digitalWrite(pino, seven_seg_digits[soma][i]); 
    ++pino; 
  }
  
  pausa(0); 
}

void showLeds(byte soma)
{
  byte pino = 11;

  for (int i = 2; i >= 0; i--){ 
    digitalWrite(pino, digito[soma][i]); 
    ++pino; 
  }
  
  pausa(100); 
}



