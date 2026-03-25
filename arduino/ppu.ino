const char PPU[] = {3,4,5,6,7,8};
#define ALE 9
#define INTR 10
uint8_t incomingByte;
int arrayLength = sizeof(PPU) / sizeof(PPU[0]);

void setup() {
  // put your setup code here, to run once:
  for (int n=0; n < 6; n++){
    pinMode(PPU[n], INPUT);
  }
  pinMode(ALE, INPUT);
  pinMode(INTR, INPUT);
  Serial.begin(57600);
}

void loop() {
  if (Serial.available() > 0) {

    // read the incoming byte:

    incomingByte = Serial.read();
    if (incomingByte == 0)
      clearPPU();
    else if (incomingByte == 255){
      pinMode(INTR, OUTPUT);
      digitalWrite(INTR, HIGH);
    }
    else
      displayPPU(incomingByte);
  }
}

void displayPPU(uint8_t data){
  uint8_t modData = data % 64;
  for (int n=0; n < arrayLength; n++){
    pinMode(PPU[n], OUTPUT);
    digitalWrite(PPU[n], ((2^n) & modData));
  }
}

void clearPPU(){
  for(int n=0; n<arrayLength; n++){
    digitalWrite(PPU[n], LOW);
    pinMode(PPU[n], INPUT);
  }
  digitalWrite(INTR, LOW);
  pinMode(INTR, INPUT);
}