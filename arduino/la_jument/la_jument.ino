int a1, b1, c1, a2, b2, c2;
a1 = 30045.89050733355;
b1 = -110.37915299955958;
c1 = 0.31590088706991387;
a2 = 56495.65900539382;
b2 = 221.07513018008873;
c2 = -0.6533837940808938;
int fl = 700;
int fill = 15000 - 3 * 2 * fl;

boolean isNigth() {
  return TRUE;
}

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  if (isNight()) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(13, HIGH);
      delay(fl);
      digitalWrite(13, LOW);
      delay(fl);
    }
    delay(fill);
  }
}
