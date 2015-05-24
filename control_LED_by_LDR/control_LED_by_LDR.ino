//Example 06 アナログ入力に応じてLEDの点滅レートが変化

const int LED = 13; //LEDが接続されているピン
int val = 0;
const int SENSOR = 0;
int serialVal = 0;

void setup()
{
  pinMode(LED, OUTPUT); //LEDのピンを出力に設定
  //アナログピンあ自動的に入力として設定される
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(SENSOR);
  Serial.println(val);

  val = analogRead(0);
  
//  digitalWrite(13, HIGH);
//  delay(val);
  
  //example B
  analogWrite(LED, val/4);
  delay(10);
  
//  digitalWrite(13, LOW);
//  delay(val);
  delay(100);
  
}
