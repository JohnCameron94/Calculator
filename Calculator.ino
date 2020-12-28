#include <Key.h>
#include <Keypad.h>
#include <Keypad.h>
#include   <LiquidCrystal.h>

LiquidCrystal LCD(0, 1, 2, 3, 4, 5);
const byte ROWS = 4;//rows
const byte COLS = 4;//columns

char keys [ROWS] [COLS] = {
  //Keypad Layout
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};
byte rowPins[ROWS] = {13,12,11,10};
byte colPins[COLS] = {9,8,7,6};
//init keypad
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

boolean presentValue = false;
boolean next = false;
boolean final = false;
String num1, num2;
int answer;
char op;

void setup()
{
  LCD.begin(16,2);
  LCD.setCursor(0,0);
  LCD.print("Electronic Calc");
  LCD.setCursor(0,1);
  LCD.print("   Calculator");
  delay(3000);
  LCD.clear();
  LCD.setCursor(0,0);
  LCD.print("    Like And");
  LCD.setCursor(0,1);
  LCD.print("  Subscribe Us"    );
  delay(3000);
  LCD.clear();
}

void loop(){

  char key = myKeypad.getKey();

  if (key != NO_KEY && (key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'||key=='0'))
  {
    if (presentValue != true)
    {
      num1 = num1 + key;
      int numLength = num1.length();
      LCD.setCursor(15 - numLength, 0); //to adjust one whitespace for operator
      LCD.print(num1);
    }
    else 
    {
      num2 = num2 + key;
      int numLength = num2.length();
      LCD.setCursor(15 - numLength, 1);
      LCD.print(num2);
      final = true;
    }
  }

  else if (presentValue == false && key != NO_KEY && (key == '/' || key == '*' || key == '-' || key == '+'))
  {
    if (presentValue == false)
    {
      presentValue = true;
      op = key;
      LCD.setCursor(15,0);
      LCD.print(op);
    }
  }

  else if (final == true && key != NO_KEY && key == '='){
    if (op == '+'){
      answer = num1.toInt() + num2.toInt();
    }
    else if (op == '-'){
      answer = num1.toInt() - num2.toInt();
    }
    else if (op == '*'){
      answer = num1.toInt() * num2.toInt();
    }
    else if (op == '/'){
      answer = num1.toInt() / num2.toInt();
    }    
      LCD.clear();
      LCD.setCursor(15,0);
      LCD.autoscroll();
      LCD.print(answer);
      LCD.noAutoscroll();
  }
  else if (key != NO_KEY && key == 'C'){
    LCD.clear();
    presentValue = false;
    final = false;
    num1 = "";
    num2 = "";
    answer = 0;
    op = ' ';
  }
}

/*

      © Techtronic Harsh
 
*/
