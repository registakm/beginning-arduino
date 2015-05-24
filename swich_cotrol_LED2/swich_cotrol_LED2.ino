//Example 03 ボタンが押すと、LEDが点灯
//ボタンを離しても点灯したままにする。

const int LED = 13; //LEDが接続されているピン
const int BUTTON = 7; //ボタンが接続されているピン

int val = 0;//入力ピンの状態がこの変数に記憶
int old_val = 0;//valの前の値を保存しておく変数
int state = 0;//LEDの状態フラグ(0オン、1オフ)

void setup() {
  pinMode(LED, OUTPUT); //ArduinoにLEDが出力と伝える
  pinMode(BUTTON, INPUT); // BUTTONは入力に設定
}

void loop() 
{
  val = digitalRead(BUTTON); //入力をvalに格納
  
  //ボタンが押されている状態の時、stateを変更
  if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state;
    delay(10);
  }
  old_val = val;
  //LEDび点灯制御
  if (state == 1) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
