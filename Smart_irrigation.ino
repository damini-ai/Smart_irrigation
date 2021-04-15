void setup() {

pinMode(A0,INPUT_PULLUP);// soil moisture sensor
pinMode(8,OUTPUT);// buzzer
pinMode(7,OUTPUT);//pump

Serial.begin(9600);

  // put your setup code here, to run once:

}

void loop()
{char Incoming_value = 0;
int m=analogRead(A0); // to measure moisture in the soil
Serial.println(m);  //to print the value of moisture
delay(1000);

if(m<=900)
{

Incoming_value = Serial.read();      //Read the incoming data and store it into variable Incoming_value
    Serial.print(Incoming_value);        //Print Value of Incoming_value in Serial monitor
    Serial.print("\n");        //New line 
    if(Incoming_value == 'a')            //Checks whether value of Incoming_value is equal to a
     { digitalWrite(7, HIGH);  //If value is a then pump turns ON
      digitalWrite(8,HIGH);  // buzzer beeps for 2 seconds
      delay(2000);
      digitalWrite(8,LOW);}  
    else if(Incoming_value == '0')       //Checks whether value of Incoming_value is equal to 0
      {digitalWrite(7, LOW);   //If value is 0 then pump turns OFF
       digitalWrite(8,LOW);}   //buzzer also turns off

}
else                    
  {
    Incoming_value = Serial.read();      //Read the incoming data and store it into variable Incoming_value
    Serial.print(Incoming_value);        //Print Value of Incoming_value in Serial monitor
    Serial.print("\n");        
   
    
    if(Incoming_value == '1')            //Checks whether value of Incoming_value is equal to 1 
     { digitalWrite(7, HIGH);  //If value is 1 then pump turns ON
      digitalWrite(8,HIGH);
      delay(500);
      digitalWrite(8,LOW);
      }
     else if(Incoming_value == 'a')       //Checks whether value of Incoming_value is equal to 0
      {
       digitalWrite(7, HIGH);             //If value is 0 then pump turns OFF
       digitalWrite(8,HIGH);
       delay(1000);
       digitalWrite(8,LOW);
       }
   


    else if(Incoming_value == '0')       //Checks whether value of Incoming_value is equal to 0
      {
        digitalWrite(7, LOW);            //If value is 0 then pump turns OFF
       digitalWrite(8,LOW);
       }
   
       

  }                           
}
