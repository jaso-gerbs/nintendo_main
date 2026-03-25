const char DATA[]={2,3,4,5,6,7,8,9};

void setup() {
  // put your setup code here, to run once:
  for (int n = 0; n < 8; n += 1){
    pinMode(DATA[n], OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(2), interrupt, RISING);
  Serial.begin(57600);
}

void interrupt(){
  char bits [8];
  unsigned int data = 0;

  for (int n = 0; n < 8; n += 1){
    int bit = digitalRead(DATA[n]) ? 1 : 0;
    Serial.print(bit);
    data = (data << 1) + bit;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
