## Course 4. Example 6 - Object Oriented Programming (OOP)
### Class 基本架構:

``` C++
class LED{
   private:  // the members aren't accessible out of this scope
      // 不要讓人呼叫的東西就擺這裡
      /* member variables: 
         1. exist in every objects, and are independent of each objects 
         2. exist in every objects, and are independent of each objects */
      int pinLed;
      unsigned long previousTime = millis();
      // member functions:
   public:  // the members are accessible outside of this scope
      // 要提供給別人使用的東西就擺這裡
      // constructor: usually does initialization
      LED (int pin) {
          pinLed = pin;
          pinMode(pinLed, OUTPUT);
          digitalWrite(pinLed, 1); // 可改成 off();
      }
      // member variables
      // member functions:
      void blinkLed(){
        //...your code here...//
      }
      on(){
        digitalWrite(pinLed, 0);
      }
      off(){
        digitalWrite(pinLed, 1);    
      }
};
```
- **注意結尾分號!!**
- **宣告 & 呼叫:**
  - `const int pinLed1 = 3;`
  - `LED led1(pinLed1);` //物件宣告 
  - `Led1.on();` //member function 呼叫 

### 練習 6: 用物件導向寫法修改練習1
 - Please complete the class "LED"  above
 - Use the LED object rewrite 練習1


### 練習7: Please write a class name "Button" with following public functions:
  - Debounce about **20ms** either **pressing** or **releasing**
  - Function **"pressed()"** returning in **"bool"** type
    - When button is pressed return **true** else **false**
  - Function **"rising()"** returning in **"bool"** type
    - If **"rising"** return **true** else **false**
  - Function **"falling()"** returning in **"bool"** type
    - If **"falling"** return **true** else **false**
  - Hint: write a private **update()** function to refresh the state of button.
  - Notice that do not use any **delay()** when debouncing!!
  - 保持 **練習2** 的所有功能並使用 **class "Button"**。
  - 加入一個 **LED3** 並搭配 **button2** => 當按下 **button2** 則 **LED3** 亮。
