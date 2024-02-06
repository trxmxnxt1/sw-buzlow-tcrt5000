const int SW1 = 2; // Connect SW1 to digital pin 2
const int SW2 = 3; // Connect SW2 to digital pin 3
const int SW3 = 4; // Connect SW3 to digital pin 4
const int SW4 = 5; // Connect SW4 to digital pin 5

const int buzzer = 5; // Buzzer

const int sensorPin = 32; // กำหนดขาที่ต่อเซ็นเซอร์
int threshold = 500; // กำหนดค่าสะสมต่ำสุดที่ถือว่าตรวจจับได้

void setup() {
  Serial.begin(9600); // Open Serial Monitor

  // Start Buzzer
  pinMode(buzzer, OUTPUT); 
  digitalWrite(buzzer,LOW);
  // END Buzzer
  
  // Start Switch
  pinMode(SW1, INPUT_PULLUP); // Set SW1 pin as input with internal pull-up resistor
  pinMode(SW2, INPUT_PULLUP); // Set SW2 pin as input with internal pull-up resistor
  pinMode(SW3, INPUT_PULLUP); // Set SW3 pin as input with internal pull-up resistor
  pinMode(SW4, INPUT_PULLUP); // Set SW4 pin as input with internal pull-up resistor
  // END Switch

}

void loop() {

  // Start Switch
  int state1 = digitalRead(SW1);
  int state2 = digitalRead(SW2);
  int state3 = digitalRead(SW3);
  int state4 = digitalRead(SW4);
  Serial.print("SW1: ");
  Serial.print(state1);
  Serial.print(" | SW2: ");
  Serial.print(state2);
  Serial.print(" | SW3: ");
  Serial.print(state3);
  Serial.print(" | SW4: ");
  Serial.println(state4);
  delay(100);
  // END Switch

  // Start TCRT5000
  int sensorValue = analogRead(sensorPin); // อ่านค่าแอนาล็อกจากเซ็นเซอร์
  Serial.println(sensorValue); // แสดงค่าทาง Serial Monitor
  // ตรวจสอบว่ามีการตรวจจับวัตถุหรือไม่
  if (sensorValue > threshold) {
    Serial.println("Not Detected: 0"); // แสดงผลเป็น 0
  } else {
    Serial.println("Detected: 1"); // แสดงผลเป็น 1
  }
  // END TCRT5000

}
