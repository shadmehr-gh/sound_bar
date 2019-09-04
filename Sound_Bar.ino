int bargraph[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

int threshold = 516; //514
int sensor_value = 0;
int abs_value = 0;
int ledCount = 10;

void setup() {
  // put your setup code here, to run once:
  for (int i = 2; i <= 11; i++){
    pinMode(i, OUTPUT);
  }
  
  Serial.begin(9600);
  
  for (int i = 2; i <= 11; i++){
    digitalWrite(i, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_value = analogRead(A0);
  
  abs_value = abs(sensor_value - threshold);
  
  int ledLevel = map(abs_value, 0, (530 - threshold), 0, ledCount); //530 is true, before it was 1024
  
  for (int i = 0; i < ledCount; i++) {
    
    // if the array element's index is less than ledLevel,
    // turn the pin for this element on:
    if (i < ledLevel) {
      digitalWrite(bargraph[i], HIGH);
      Serial.println(i);
    }
    
    // turn off all pins higher than the ledLevel:
    else{
      digitalWrite(bargraph[i], LOW);
    }
  }
}
