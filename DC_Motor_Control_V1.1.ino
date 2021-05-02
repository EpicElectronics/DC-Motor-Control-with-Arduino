/********************************************************************************************
*Project:              DC Motor Control with Arduino                                        *
*Author:               Epic Electronics                                                     *
*Youtube channel:      https://www.youtube.com/channel/UCUvW5tOMS4KRXxMFt33XYvg/featured    *
*Programming Date:     01.05.2021                                                           *
*Version:              V1.1                                                                 *
*Last Update:          02.05.2021                                                           *
*Video from project:   https://youtu.be/yY58GM1gHbo                                         *
*                                                                                           *
*About:   The program controls a DC Motor with a h-Bridge. There goes 3 wires from the      *
*         Arduino to the h-Bridge. The first one for Enable the Motor and the other 2 for   *
*         the direction of the Motor. With a Pulse Signal there is a startramp programmed.  *
********************************************************************************************/

// ++++++++++++ Outputs +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int In1 = 7;
int In2 = 8;
int En = 9;

// ++++++++++++ Variables +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int speed1 = 0; //variable for motorspeed

// ++++++++++++ Setup start ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void setup() {

  //set PinModes
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(En, OUTPUT);  
}

// ++++++++++++ loop start ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void loop() {
  
  //set direction of the motor
  digitalWrite(In1, HIGH);                        
  digitalWrite(In2, LOW);

  // Enable motor
  // Motor startramp
for( int i = 0; i < 255; i++){           // for Loop => repeats until variable "i" reached the value 255
  analogWrite(En, speed1);               // generate Analog Output Signal => 0 to 255 
  speed1++;
  delay(20);
}
  delay(2000);
  speed1 = 0;                            
  analogWrite(En, speed1);               // set the Speed to 0
  delay(1000);


  //without startramp
  /*
  digitalWrite(En, HIGH);
  delay(3000);
  digitalWrite(En, LOW);
  delay(1000);
  */
}
