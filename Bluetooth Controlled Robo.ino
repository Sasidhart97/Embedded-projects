


int LmotorUp = 10; 
int LmotorDn = 11; 
int RmotorUp = 8;  
int RmotorDn = 9;  

void setup()
{
  Serial.begin(9600);
  pinMode(LmotorUp, OUTPUT); 
  pinMode(LmotorDn, OUTPUT); 
  pinMode(RmotorUp, OUTPUT);
  pinMode(RmotorDn, OUTPUT);
  Serial.println("<Robot name> Welcomes you"); 
  delay(1000);
}


void loop()
{
  if (Serial.available() > 0) 
  {
    int input = Serial.read(); 
    switch (input)
    {
      case 'w' : MoveF();
        break;
      case 's' : MoveB();
        break;
      case 'a' : MoveL();
        break;
      case 'd' : MoveR();
        break;
      case 'x' : Stop();
        break;
      default : break;
    }
  }
  delay(50);
}

void MoveF()
{
  Serial.println("<Robot Name> Forward");
  digitalWrite(LmotorUp, HIGH);
  digitalWrite(LmotorDn, LOW); 
  digitalWrite(RmotorUp, HIGH);
  digitalWrite(RmotorDn, LOW); 
  }

void MoveB()
{
  Serial.println("<Robot Name> Backward");
  digitalWrite(LmotorUp, LOW); //Reverse logic of above
  digitalWrite(LmotorDn, HIGH);
  digitalWrite(RmotorUp, LOW);
  digitalWrite(RmotorDn, HIGH);
}

void MoveL()
{
  Serial.println("<Robot Name> Left");
  digitalWrite(LmotorUp, LOW); 
  digitalWrite(LmotorDn, LOW);
  digitalWrite(RmotorUp, HIGH);
  digitalWrite(RmotorDn, LOW);
}

void MoveR()
{
  Serial.println("<Robot Name> Right");
  digitalWrite(LmotorUp, HIGH);
  digitalWrite(LmotorDn, LOW); 
  digitalWrite(RmotorUp, LOW);
  digitalWrite(RmotorDn, LOW);
}

void Stop()
{
  Serial.println("<Robot Name> Stop");
  digitalWrite(LmotorUp, LOW); 
  digitalWrite(LmotorDn, LOW);
  digitalWrite(RmotorUp, LOW);
  digitalWrite(RmotorDn, LOW);
}


