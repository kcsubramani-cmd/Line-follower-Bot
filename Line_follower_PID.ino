//During callibration, find the threshold values for each of the sensors, save values for what it measures at completely white and completely black. For simplicity we assume all 
//Values are same, but we can change the code to accomodate for different cases
int white = 850;
int black = 100;
int baseSpeed = 100;
float sum,error,old_error,num,den;
sum = 0;
error = 0;
old_error = 0;

float Kp = 1;
float Kd = 0.1;
float Ki= 0.001;
void setup() {
Serial.begin(9600);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(11, OUTPUT);
// put your setup code here, to run once:
}

void loop() {
float s_mapped[5];
old_error = error;
sum = sum + error;
num = 0;
den = 0;
for(int i=0;i<5;i++){
  int raw = analogRead(i);
  s_mapped[i] = map(raw, black, white, 1000, 0);
  s_mapped[i] = constrain(s_mapped[i],0,1000);
 num = num + s_mapped[i]*(i-2);
 den = den + s_mapped[i];
}
error = num/den;
output = Kp*error + Ki*sum + Kd*(error-old_error);
int leftSpeed = baseSpeed + output;
int rightSpeed = baseSpeed - output;
leftSpeed = constrain(leftSpeed, 0, 255);
rightSpeed = constrain(rightSpeed, 0, 255);
moveForward(leftSpeed, rightSpeed);



// put your main code here, to run repeatedly:
}
void moveForward(int speed1, int speed2)
{
	digitalWrite(7, HIGH); digitalWrite(8, LOW);
	digitalWrite(9, HIGH); digitalWrite(11, LOW);
	analogWrite(5, speed1); analogWrite(6, speed2);
}
void turnRight(int speed)
{
	digitalWrite(7, HIGH); digitalWrite(8, LOW);
	digitalWrite(9, LOW); digitalWrite(11, HIGH);
	analogWrite(5, speed); analogWrite(6, speed);
}
void turnLeftt(int speed)
{
	digitalWrite(7, LOW); digitalWrite(8, HIGH);
	digitalWrite(9, HIGH); digitalWrite(11, LOW);
	analogWrite(5, speed); analogWrite(6, speed);
}
void stopMotors ()
{
	analogWrite(5, 0)
	analogWrite(6, 0)
}