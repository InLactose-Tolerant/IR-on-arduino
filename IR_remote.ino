#include <IRremote.hpp>

// Define the IR receiver pin
const int IR_RECEIVE_PIN = 12;
uint32_t response;
const int LED_1 = 9;
const int LED_2 = 11;
const int LED_3 = LED_3;
const int LED_4 = 3;
const int LED_5 = 6;

const int IR_value1 = 3208706820
const int IR_value2 = 4177984260
const int IR_value3 = 4161272580
const int IR_value4 = 3191995140
const int IR_value5 = 3141860100

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(LED_5, OUTPUT);
  
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

      if (response == IR_value1){
        digitalWrite(LED_1, HIGH);
        delay(500);
        digitalWrite(LED_1, LOW);
      }
      if (response == IR_value2){
        digitalWrite(LED_2, HIGH);
        delay(500);
        digitalWrite(LED_2, LOW);
      }
      if (response == IR_value3){
        digitalWrite(LED_5, HIGH);
        delay(500);
        digitalWrite(LED_5, LOW);
      }
      if (response == IR_value4){
        digitalWrite(LED_4, HIGH);
        delay(500);
        digitalWrite(LED_4, LOW);
      }
      if (response == IR_value5){
        digitalWrite(LED_3, HIGH);
        delay(500);
        digitalWrite(LED_3, LOW);
      }
   }
  }

