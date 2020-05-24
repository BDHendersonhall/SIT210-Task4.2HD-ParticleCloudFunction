/**************************************************************
 * 
 *  Particle Cloud Function - Toggle LEDs
 * 
 **************************************************************/

int led1 = D4; // red
int led2 = D5; // green
int led3 = D6; // blue

void setup() 
{
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    
    Particle.function("led",ledToggle);
    Particle.function("led_off",ledsOff);
    
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);    
}

void loop() 
{

    
}

// Finally, we will write out our ledToggle function, which is referenced by the Particle.function() called "led"

int ledToggle(String led_colour) 
{

    if (led_colour == "red") 
    {
        digitalWrite(led1,HIGH);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        return 1;
    }
    else if (led_colour == "green") 
    {
        digitalWrite(led1,LOW);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,LOW);
        return 2;
    }
    else if (led_colour == "blue") 
    {
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,HIGH);
        return 3;
    }
    else 
    {
        return 0;
    }
}

int ledsOff(String command)
{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW); 
    return 1;
}