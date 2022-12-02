

// https://elektro.turanis.de/html/prj129/index.html
// https://www.arduino.cc/reference/en/
// 

static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4};

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  for (int i = 0; i < 5; i++) {
    pinMode(analog_pins[i], OUTPUT);
  }  
  
  DDRB = B00000000; // set PORTB to input
  
}

void loop() {
//byte x = 0b10101010;  // the 0b prefix indicates a binary constant
byte x = 0b11111111;  // the 0b prefix indicates a binary constant

//  Serial.println(x, BIN); // 10000000
//  bitWrite(x, 2, 0);  // write 1 to the least significant bit of x
//  Serial.println(x, BIN); // 10000001
//

    for(byte i=0; i<8; i++) {
        PINC = i;
  //      Serial.println(PIND);
        Serial.println(PIND, BIN);
        delay(250);
    }
Serial.println("------------------");

//  bitWrite(x, 2, 0);  // write 1 to the least significant bit of x

    delay(100);

}
