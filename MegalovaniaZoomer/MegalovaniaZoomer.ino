#define BUZZER_PIN 8

// Ноты и их частоты (в Гц)
#define NOTE_D2  73
#define NOTE_D3  147
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define REST     0

// Основной риф Megalovania
int melody[] = {
  NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4, REST, NOTE_GS4, REST, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_D4, NOTE_A4, NOTE_D4, REST, NOTE_D4, NOTE_D4,
  NOTE_D5, NOTE_A4, REST, NOTE_GS4, REST, NOTE_G4, NOTE_F4, NOTE_F4,
  NOTE_D4, NOTE_A4, NOTE_D4, REST, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4,
  REST, NOTE_GS4, REST, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_A4,
  NOTE_D4, REST
};

// Длительности нот (8 = восьмая, 4 = четвертная)
int noteDurations[] = {
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8
};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int size = sizeof(noteDurations) / sizeof(int);
  
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER_PIN, melody[thisNote], noteDuration);

    // Пауза между нотами
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(BUZZER_PIN);
  }
  
  delay(2000); // Пауза перед повторением
}