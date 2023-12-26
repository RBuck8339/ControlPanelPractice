// Set up button pins
const int BUTTON_ONE = 2;
const int BUTTON_TWO = 4;
const int BUTTON_THREE = 6;
const int BUTTON_FOUR = 8;
const int BUTTON_FIVE = 10;

int buttonStates[5]; // Can be expanded for more states
bool bchangeOfState = false; // 

void setup() {
  Serial.begin(9600); // Set up serial for output

  // Initialize the pushbutton pin as a pull-up input
  pinMode(BUTTON_ONE, INPUT_PULLUP);
  pinMode(BUTTON_TWO, INPUT_PULLUP);
  pinMode(BUTTON_THREE, INPUT_PULLUP);
  pinMode(BUTTON_FOUR, INPUT_PULLUP);
  pinMode(BUTTON_FIVE, INPUT_PULLUP);
} // End setup()

void loop() {
  // Read the state of each switch/button
  buttonStates[0] = digitalRead(BUTTON_ONE);
  buttonStates[1] = digitalRead(BUTTON_TWO);
  buttonStates[2] = digitalRead(BUTTON_THREE);
  buttonStates[3] = digitalRead(BUTTON_FOUR);
  buttonStates[4] = digitalRead(BUTTON_FIVE);

  // Want to make a conditional that disables one button if another is pressed

  // If any button returns one, a change of state has occurred and should be sent to csv
  for(int i = 0; i < 5; i++){
    if(buttonStates[i] == 1){
      bchangeOfState = true;
    }
  }

  // Display button states, separated by commas
  if(bchangeOfState){
    Serial.print(buttonStates[0]);
    Serial.print(",");
    Serial.print(buttonStates[1]);
    Serial.print(",");
    Serial.print(buttonStates[2]);
    Serial.print(",");
    Serial.print(buttonStates[3]);
    Serial.print(",");
    Serial.println(buttonStates[4]); // Adds a newline character for formatting
    bchangeOfState = false;
  }

  delay(500); // Stops repeated inputs
} // End loop()
