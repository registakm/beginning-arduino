//Example 02 ボタンが押されている間、LEDが点灯

const int LED = 13; //LEDが接続されているピン
const int BUTTON = 7; //ボタンが接続されているピン

int val = 0;//入力ピンの状態がこの変数に記憶

void setup() {
  pinMode(LED, OUTPUT); //ArduinoにLEDが出力と伝える
  pinMode(BUTTON, INPUT); // BUTTONは入力に設定
}

void loop() {
  val = digitalRead(BUTTON); //入力をvalに格納
  //ボタンが押されている状態=HIGの時、点灯
  if (val == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
