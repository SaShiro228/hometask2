void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  Serial.begin(9600);  
}

int xx2;
int xx;
int x = 0;
int y;
int yp;
int u;
int up;
int o;
int op;
int ip;
int i;
int p;
int leds[] = {6, 7, 8, 9, 10, 11, 12, 13};
int exite = 1;

void dinamek() {
  for(i = 0;i < 1024; i++){
    tone(5, i, 1); 
  }
  delay(10);
  for(i = 1024;i > 0; i++){
    tone(5, i, 1); 
  }
}



void svetodiods (){
  for(i = 0;i < 8; i++){
    digitalWrite(leds[i], 1);
    delay(10);
  }
  for(i = 0;i<8; i++){
    digitalWrite(leds[i], 1);
    delay(10);
  }
}



void Zumer(){
  p = analogRead(A0);
  ip = map(p, 0, 1023, 0, 9);
  for(i = 0;i < ip; i++){
    digitalWrite(leds[i], 1);
  }
  delay(10);
  for(i = 0;i < ip; i++){
  digitalWrite(leds[i], 0); 
  }
}





void loop(){ 
  if (digitalRead(4) == 1){
    x = x + 1;
    delay(100);
  }
  if (digitalRead(3) == 1){
    x = x - 1;
  }
  if(x >= 4){
    x = 0;
  }
  if (x <= -1) {
    x = 7;        
  }
  if (x == 1){
    dinamek();
  }
  else if (x == 2){
    svetodiods();
  }
  else if (x == 3){
    Zumer();
  }
  Serial.println(x);
  digitalWrite(5, 0);
  
} 