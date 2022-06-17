// the setup function runs once when you press reset or power the board
#define led1 5
#define led2 3
#define led3 4


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600); // Begen listening on port 9600 for serial
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  
}
// the loop function runs over and over again forever
void loop() {
   if(Serial.available() > 0) // Read from serial port
    {
      char ReaderFromNode; // Store current character
      ReaderFromNode = (char) Serial.read();
      convertToState(ReaderFromNode); // Convert character to state
    }
  delay(1000);
}
void convertToState(char chr) {
  if(chr=='a'){
    digitalWrite(led1, HIGH);
    
  }
  if(chr=='b'){
    digitalWrite(led2, HIGH);
  } 
  if(chr=='c'){
    digitalWrite(led3, HIGH);
  }
  if(chr=='d'){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } 

}
