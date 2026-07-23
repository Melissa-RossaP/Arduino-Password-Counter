#include "arduino_secrets.h"

#include <Adafruit_BusIO_Register.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
Adafruit_SSD1306 display(128, 64);
int senha = 0;
#define botaoUp 2
#define botaoDown 3
#define buzzer 4

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0X3C);
  pinMode(botaoUp, INPUT_PULLUP);
  pinMode(botaoDown, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  display.setTextColor(1);
}

void loop() {
  display.drawRoundRect(0, 10, 128, 47, 10, WHITE);
  display.setCursor(18,0);
  display.setTextSize(1);
  display.print("MANU MARI & MEL");

  display.setCursor(35, 15);
  display.setTextSize(2);
  display.print("SENHA");

  display.setCursor(48, 35);
  if (senha < 10){
    display.print(String("0") + senha);
  }
  if ((senha > 9) && (senha <100)){
    display. print(senha);
  }
  if(digitalRead(botaoUp) == 0){
    senha+= 1;
    if (senha >99){
      senha = 99;
    }
    tone (buzzer, 262, 250);
    delay(250);
    tone(buzzer, 2093, 400);
    delay(400);
  }

  if(digitalRead(botaoDown)== 0){
    senha += -1;
    if (senha < 0) {
      senha = 0;
    }
    tone(buzzer, 350, 250);
    delay(250);
    tone(buzzer, 2093, 400);
    delay(400);
  }

  display.setCursor(20, 57);
  display.print("Obrigado(a)!");

  display.display();
  display.clearDisplay();
}
