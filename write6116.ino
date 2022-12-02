


static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4};

byte frames[3][8] = {
  {
    B00111100,
    B01000010,
    B10010101,
    B10100001,
    B10100001,
    B10010101,
    B01000010,
    B00111100
  },
  {
    B00111100,
    B01000010,
    B10010101,
    B10010001,
    B10010001,
    B10010101,
    B01000010,
    B00111100
  },
  {
    B00111100,
    B01000010,
    B10100101,
    B10010001,
    B10010001,
    B10100101,
    B01000010,
    B00111100
  }
};



void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  DDRC = B00000000; // set A0-A5 to input
  DDRD = B11111111; // set D8-13 to output
  
}


// https://elektro.turanis.de/html/prj129/index.html
// https://www.arduino.cc/reference/en/
// 

//    Port D – zur Ansteuerung der digitalen Pins 0 bis 7
//    Port B – zur Ansteuerung der digitalen Pins 8 bis 13
//    Port C – zur Ansteuerung der analogen Pins 0 bis 5



void loop() {

  for (int frame=0; frame<3; frame++) {//Zeichen
    for (int dot=0; dot<8; dot++) {//Linien
      Serial.println(frames[frame][dot],BIN);
      PORTD = frames[frame][dot]; // set Pin 4 to HIGH all other to LOW
    }
    Serial.println();
    delay(750);
  }

}
