const int on = LOW;
const int off = HIGH;

int pinLed1 = 3;
int pinLed2 = 4;
int pinButton = 2;

class LED{
  
  private:
    int pinLed;
    unsigned long previousTime = millis();
    
  public:
    LED(int pin){
      pinLed = pin;  
      pinMode(pinLed, OUTPUT);
      off();
    }
    void blinkLed(){        
      unsigned long currentTime = millis();
      if((currentTime - previousTime) >= 500) {
        digitalWrite(pinLed, !digitalRead(pinLed));
        previousTime = currentTime;
      }  
    }
    void on(){
      digitalWrite(pinLed, 0);
    }
    void off(){
      digitalWrite(pinLed, 1);
    }
};

class Button{
  private:
    int state;
    int pin;
    unsigned long preTime;
    const int debounceTime = 20;
    
    void updateButton(){
      unsigned long currentTime = millis();
      
      if(currentTime - preTime > debounceTime){
        int newState = digitalRead(pin);
        if(newState != state){
          state = newState;
          preTime = currentTime;
        }
      }      
    }
  public:
    
    Button(int _pin){
      pin = _pin;
      state = digitalRead(pin);
      preTime = millis();
    }
    
    bool pressed(){
      updateButton();
      return state == 0;
    }
    bool rising(){
      int preState = state;
      updateButton();
      if(state - preState == -1) return true;
      else return false;
    }
    bool falling(){
      int preState = state;
      updateButton();
      if(state - preState == 1) return true;
      else return false;
    }
     
};


void setup(){
  // initialize LED digital pin as an output.
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinButton, INPUT);
  Serial.begin(9600);
  delay(100);
  digitalWrite(pinLed1, off);  
}
void loop() {
  // put your main code here, to run repeatedly:
   
  static LED led1(pinLed1);  
  led1.blinkLed();
  led2();
}
void led2(){
  static Button button1(pinButton); 
  static LED led2(pinLed2);
  static int state = 0;  
  switch(state){
    case 0: //waiting for first pressed
      led2.off();
      if(button1.rising()) state++;
      break;
    case 1: // waiting for first released
      led2.on();
      if(button1.rising()) state++;
      break;
    case 2: // waiting for second pressed
      led2.blinkLed();
      if(button1.rising()) state = 0;
      break;    
  }  
}
