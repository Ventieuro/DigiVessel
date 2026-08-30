# Firmware DigiVessel

## Struttura

Arduino richiede che ogni sketch stia in una cartella con lo **stesso nome** del file `.ino`:

```
firmware/
  DigiVessel/
    DigiVessel.ino   <- sketch principale
    (in futuro: PetState.h/.cpp, Display.h/.cpp, Input.h/.cpp)
```

Tutti i file `.h`/`.cpp` dei moduli andranno dentro `firmware/DigiVessel/` accanto al `.ino`:
l'IDE Arduino li compila automaticamente se sono nella stessa cartella dello sketch.

## Aprire il progetto

Arduino IDE -> File -> Open... -> `firmware/DigiVessel/DigiVessel.ino`

Funziona identico su Windows e su Mac: il codice e' Arduino/C++ puro, nessuna dipendenza dal sistema operativo.

## Board e librerie

- Board: **ESP32 Dev Module** (pacchetto "esp32 by Espressif Systems")
- Librerie (servono dallo sketch 02 in poi, con OLED collegato):
  - `Adafruit SSD1306`
  - `Adafruit GFX Library`

## Sketch attuali

| Sketch | Stato | Descrizione |
|--------|-------|-------------|
| 01 — Battito base | in test | La variabile `fame` cala nel tempo e viene stampata sul Serial Monitor. Nessun hardware oltre all'ESP32. |
