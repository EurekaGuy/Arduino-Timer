/***************************************************************************************
 * This code is an example explanation for the video
 * made for a YouTube Channel - "Eureka!".
 * 
 * Author         : EurekaGuy
 * YouTube Channel: Eureka! - https://www.youtube.com/channel/UCu7SAylZELIQkBLu6gLazLA
 * YouTube Video  : https://youtu.be/t9xKb1dsuQg
****************************************************************************************/

void setup() {
  // Initializing register values to zero
  TCCR1A = 0;
  TCCR1B = 0;
  TIMSK1 = 0;

  TCCR1A |= (1 << COM1A0);                                  // Selecting toggling functionality                
  TCCR1B |= (1 << WGM12) | (1 << CS12);                     // Selecting presclar and CTC Mode

  TIMSK1 |= (1 << OCIE1A);                                  // Enabling Timer-1 Output Compare A  

  OCR1A = 0xF423;                                           // Setting OCR1A register value to get time period of 2 second

  DDRB |= (1 << 1);                                         // Setting D9 pin to output

  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
}

ISR(TIMER1_COMPA_vect){
  Serial.println(millis());                                 // Printing exactly 1 second delay
}

void loop() {
  // Regular blink functionality
  
  int  timings = map(analogRead(A0), 0, 1023, 50, 2000);
  
  digitalWrite(13, HIGH);
  delay(timings);
  digitalWrite(13, LOW);
  delay(timings);
}
