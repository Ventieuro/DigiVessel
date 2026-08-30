/*
  DigiVessel — Sketch 01: "Battito base"
  --------------------------------------
  Obiettivo di questo passo: verificare che l'ESP32 comunichi col PC via USB.
  NESSUN hardware collegato oltre all'ESP32 (niente OLED, niente pulsanti).

  Cosa fa lo sketch:
  - Tiene una variabile "fame" da 0 a 100.
  - Ogni TICK_MS millisecondi la fame cala di FAME_CALO_PER_TICK.
  - Stampa lo stato sul Serial Monitor.

  Come provarlo:
  1. Collega l'ESP32 al PC col cavo USB.
  2. Arduino IDE: seleziona la board "ESP32 Dev Module" e la porta COM giusta.
  3. Premi Upload (freccia ->).
  4. Apri il Serial Monitor e imposta la velocita' a 115200 baud.
  5. Dovresti vedere la fame scendere ogni 2 secondi.
*/

// ---- Parametri di gioco (modificabili liberamente) ----
const unsigned long TICK_MS            = 2000;   // ogni quanto aggiorniamo lo stato (ms)
const float         FAME_CALO_PER_TICK = 1.0f;   // quanta fame si perde a ogni tick
const float         FAME_MAX           = 100.0f;
const float         FAME_MIN           = 0.0f;

// ---- Stato del pet ----
float fame = FAME_MAX;

// ---- Timing non bloccante ----
// Non usiamo delay(): teniamo traccia di "quando" e' avvenuto l'ultimo tick.
unsigned long ultimoTick = 0;

void setup() {
  Serial.begin(115200);
  delay(300);                       // breve pausa: da' tempo alla seriale di agganciarsi
  Serial.println();
  Serial.println(F("=== DigiVessel avviato ==="));
  Serial.print(F("Fame iniziale: "));
  Serial.println(fame, 1);
}

void loop() {
  unsigned long ora = millis();     // millisecondi trascorsi dall'accensione

  if (ora - ultimoTick >= TICK_MS) {
    ultimoTick = ora;

    // Aggiorna lo stato
    fame -= FAME_CALO_PER_TICK;
    if (fame < FAME_MIN) fame = FAME_MIN;

    // Stampa lo stato
    Serial.print(F("[t="));
    Serial.print(ora / 1000);
    Serial.print(F("s] Fame = "));
    Serial.print(fame, 1);

    if (fame <= FAME_MIN) {
      Serial.println(F("  -> Il Digimon sta morendo di fame!"));
    } else if (fame <= 30.0f) {
      Serial.println(F("  -> Inizia ad avere fame..."));
    } else {
      Serial.println(F("  -> Sta bene"));
    }
  }

  // Qui in futuro: lettura pulsanti, aggiornamento OLED, ecc.
}
