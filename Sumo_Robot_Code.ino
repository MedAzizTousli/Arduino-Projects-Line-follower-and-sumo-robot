#include <PS2X_lib.h>                         /* PS2 Controller Library */

PS2X ps2x;                                    /* create PS2 Controller Class*/

byte Type = 0;
byte vibrate = 0;
int RX=0,RY=0,LX=0,LY=0;
int IN1=5,IN2=2,IN3=3,IN4=4;

void setup(){

   pinMode(IN1,OUTPUT);
   pinMode(IN2,OUTPUT);
   pinMode(IN3,OUTPUT);
   pinMode(IN4,OUTPUT);
   Serial.begin(9600);
   ps2x.config_gamepad(13,11,10,12, true, true); /* setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error*/
   Type = ps2x.readType();                       /* Reading type of the PS2 Ccontroller */
   
}

void loop(){
   
   ps2x.read_gamepad(false, vibrate);   /* read controller and set large motor to spin at 'vibrate' speed */
   
   LY = ps2x.Analog(PSS_LY);          /* Reading Left stick Y axis */
   LX = ps2x.Analog(PSS_LX);          /* Reading Left stick X axis */
   RY = ps2x.Analog(PSS_RY);          /* Reading Right stick Y axis */
   RX = ps2x.Analog(PSS_RX);          /* Reading Right stick X axis */
   
   if((LY <= 9))                      /* standardize to 3 digit by checking less than 10 */
      Serial.print("00");                /* eg: if LY= 5 then it display as "005" in Serial */
   if((LY >= 9 &&LY <= 99))           /* standardize to 3 digit by checking between 10-99 */
      Serial.print("0");                 /* eg: if LY= 55 then it display as "055" in Serial */     
   Serial.print(LY,DEC);                 /* display left analog stick Y axis */
   Serial.print(",");                    /* separate values using comma */
   if((LX <= 9))                      /* standardize to 3 digit by checking less than 10 */
      Serial.print("00");                /* eg: if LX= 5 then it display as "005" in Serial */
   if((LX >= 9 && LX<=99))            /* standardize to 3 digit by checking between 10-99 */
      Serial.print("0");                 /* eg: if LX= 55 then it display as "055" in Serial */  
   Serial.print(LX,DEC);                 /* display left analog stick X axis */
   Serial.print(",");                    /* separate values using comma */
   if((RY <= 9))                      /* standardize to 3 digit by checking less than 10 */
      Serial.print("00");                /* eg: if RY= 5 then it display as "005" in Serial */
   if((RY >= 9 &&RY<=99))             /* standardize to 3 digit by checking between 10-99 */
      Serial.print("0");                 /* eg: if RY= 55 then it display as "055" in Serial */  
   Serial.print(RY,DEC);                 /* display Right analog stick Y axis               */
   Serial.print(",");                    /* separate values using comma */
   if((RX <= 9))                      /* standardize to 3 digit by checking less than 10 */
      Serial.print("00");                /* eg: if RX= 5 then it display as "005" in Serial */
   if((RX >= 9 &&RX <= 99))           /* standardize to 3 digit by checking between 10-99 */
      Serial.print("0");                 /* eg: if RX= 55 then it display as "055" in Serial */  
   Serial.print(RX,DEC);                 /* display Right analog stick X axis          */
   Serial.print(" ");
   
   if(ps2x.NewButtonState()) {        /* will be TRUE if any button changes state  */
      if(ps2x.ButtonPressed(PSB_PAD_UP))             /* will be TRUE as long as UP button is pressed */
         forward();
      if(ps2x.ButtonReleased(PSB_PAD_UP))
         stopp();
      if(ps2x.ButtonPressed(PSB_PAD_RIGHT))          /* will be TRUE as long as RIGHT  button is pressed */
         right();
      if(ps2x.ButtonReleased(PSB_PAD_RIGHT))
         stopp();
      if(ps2x.ButtonPressed(PSB_PAD_LEFT))           /* will be TRUE as long as LEFT button is pressed */
         left();
      if(ps2x.ButtonReleased(PSB_PAD_LEFT))
         stopp();
      if(ps2x.ButtonPressed(PSB_PAD_DOWN))           /* will be TRUE as long as DOWN button is pressed */
         backward();
      if(ps2x.ButtonReleased(PSB_PAD_DOWN))
         stopp();
   }
   
}

void backward()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void forward()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void left()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void right()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void stopp()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
