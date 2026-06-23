#include <IRremote.hpp>

// Define the IR receiver pin
const int IR_RECEIVE_PIN = 12;
uint32_t response;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  
  Serial.println("Starting IR-receiver");

  // Initialize the modern IR receiver instance
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  Serial.println("IR-receiver active");
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  // Check if a signal was received without passing parameters
  if (IrReceiver.decode()) {
    
    response = IrReceiver.decodedIRData.decodedRawData;
    
    // Print the decoded data using the new structure
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    Serial.println(response);
    // Resume receiving for the next signal
    IrReceiver.resume();

      if (response == 3208706820){
        digitalWrite(9, HIGH);
        delay(500);
        digitalWrite(9, LOW);
      }
      if (response == 4177984260){
        digitalWrite(11, HIGH);
        delay(500);
        digitalWrite(11, LOW);
      }
      if (response == 4161272580){
        digitalWrite(6, HIGH);
        delay(500);
        digitalWrite(6, LOW);
      }
      if (response == 3191995140){
        digitalWrite(3, HIGH);
        delay(500);
        digitalWrite(3, LOW);
      }
      if (response == 3141860100){
        digitalWrite(2, HIGH);
        delay(500);
        digitalWrite(2, LOW);
      }
   }
  }

