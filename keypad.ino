//se povrzuva obratno od to so pisuva na konektoro
// od digi pin 2 na arduinoto se vrzuva so 8 na konektoro na keypad i taka natamu za site 8


#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8,9}; //connect to the column pinouts of the keypad
char password[11] = {0,0,0,0,0,0,0,0,0,0,0};
int count = 0;
bool flag = 0;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  Serial.println("enter new 8 char password");
}
  
void loop(){
  char key = keypad.getKey();
    if(count<8){
      if(key){
        password[count]=key;
        count++;
        if(count==8){ flag=1; }
        }
      }
    if(count==8 && flag==1){
        Serial.println(password);
        flag=0;
      }
   if(count == 8 && key=='D'){
    count=0;
    Serial.println("enter new 8 char password");
    }
      
    // just print the pressed key
 
  
//  // this checkes if 4 is pressed, then do something. Here  we print the text but you can control something.
  if (key =='4'){
    Serial.println("Key 4 is pressed");
    Serial.println(password);
  }
}
