//Example 05 LEDフェードイン・アウト with ボタン
//ボタンを押すと明るさが変化
const int LED = 9;//LEDが接続されているピン
const int BUTTON = 7; //ボタンが接続されているピン

int val = 0;//入力ピンの状態がこの変数に記憶
int old_val = 0;//valの前の値を保存しておく変数
int state = 0;//LEDの状態フラグ(0オン、1オフ)

int brightness = 128;//明るさの値を保持
unsigned long startTime = 0;//押されたタイミング

void setup() {
  pinMode(LED, OUTPUT); //ArduinoにLEDが出力と伝える
  pinMode(BUTTON, INPUT); // BUTTONは入力に設定
}

void loop ()
{
  val = digitalRead(BUTTON); //入力をvalに格納
  
  //ボタンが押されている状態の時、stateを変更
  if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state; //オン・オフ
    startTime = millis();//millis()ボードがリセットされてからの時間をmsで返す(最後にボタンが押された時間を保持)
    delay(10);
  }
  //ボタンが押し続けられた時の処理
  if ((val == HIGH) && (old_val == HIGH)) {
    //500ms以上押されているか
    if (state == 1 && (millis() - startTime) > 500) {
      brightness++;
      delay(10);
      if (brightness > 255) {//255が最大値
        brightness = 0;
      }
    }
  }
  
  old_val = val;
  if (state == 1) {
    analogWrite(LED, brightness);
  } else {
    analogWrite(LED, 0);
  }
}
