int motor = 11;
byte trig = 3; // transmissao
byte echo = 2; // recepcao

float cm=0.0,cmAnt=0.0, duracao; // comprimento da onda

void servo0graus();
void controlaMotor(float posicao);
float distancia();

void setup() {
  Serial.begin(9600);
  pinMode(motor, OUTPUT); 
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);    
}

void loop() {
  cm =  distancia(); 
  //Serial.print("Distancia: ");
  //Serial.print(cm);
  //Serial.print("Cm: ");
  //Serial.println();
  for(char i=0;i<100;i++) controlaMotor(cm);  
  
} 

void controlaMotor(float posicao) {
   int tempo = map(posicao, 30, 320, 600, 2400);
   Serial.print("tempo: ");
   Serial.println(tempo);

   int fator = (20000 - tempo)/tempo;
  
   digitalWrite(motor, HIGH);  
   delayMicroseconds(tempo);      
   digitalWrite(motor, LOW);   
   for(int i=0;i<fator;i++)delayMicroseconds(tempo);

}

float distancia()
{  
  digitalWrite(trig, LOW);
  delayMicroseconds(10); 
  
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10);
  
  digitalWrite(trig, LOW);
  duracao = pulseIn(echo, HIGH);
  
  float calcDistancia= (duracao/2) * 0.0343; 
  if (calcDistancia>=331){ // fora do limite do sensor
      calcDistancia=0;
  }
  return calcDistancia;  
}

