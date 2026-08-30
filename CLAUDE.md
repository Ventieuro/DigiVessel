# DigiVessel

Virtual pet fisico a tema Digimon (stile Tamagotchi / Digivice), basato su ESP32.
Questo file da' a Claude Code il contesto del progetto su qualsiasi macchina. Tenerlo aggiornato e committarlo.

## Contesto sviluppatore

- Parte da zero su elettronica ed embedded. Spiegare in modo semplice.
- Procedere per **piccoli passi verificabili**, un pezzo alla volta, non tutto insieme.
- Dare i comandi da terminale **uno alla volta** quando serve interazione.
- Lingua: italiano.

## Ambiente

Sviluppo su **due macchine**: un PC Windows 11 e un Mac.
- Il codice e' Arduino/C++ puro: nessuna dipendenza dal sistema operativo.
- Unica differenza pratica: nome della porta seriale.
  - Windows: `COM3` (o simile)
  - Mac: `/dev/cu.SLAB_USBtoUART` (o simile)

### Sincronizzazione tra le due macchine

GitHub e' il punto di incontro: https://github.com/Ventieuro/DigiVessel

- A inizio sessione: `git pull`
- A fine sessione: `git add -A` -> `git commit` -> `git push`
- Non lavorare sull'altra macchina senza aver pushato prima e pullato dopo.

La cronologia chat e la memoria locale di Claude Code **non** si sincronizzano tra macchine:
il contesto condiviso vive in questo file, nei commit e in `docs/`.

## Hardware

- ESP32 DevKit (chip USB CP2102)
- OLED 0.96" I2C, driver **SSD1306**, 128x64 px (pin VCC / GND / SCL / SDA)
- Breadboard, jumper maschio-femmina
- Pulsanti tattili 6x6 mm

Stato: hardware ordinato, arrivo previsto ~2026-09-01. Fino ad allora si puo' solo
compilare (Verify), non caricare/testare su device.

## Struttura repo

```
firmware/
  DigiVessel/
    DigiVessel.ino      sketch principale (la cartella DEVE avere lo stesso nome del .ino)
    ...                  futuri moduli .h/.cpp accanto al .ino
  README.md
docs/                    note di progetto, decisioni
assets/sprites/          grafica per l'OLED
```

## Toolchain

- Arduino IDE 2.x
- Board: **ESP32 Dev Module** (pacchetto "esp32 by Espressif Systems")
- Librerie (dallo sketch 02 in poi, con OLED collegato):
  - `Adafruit SSD1306`
  - `Adafruit GFX Library`
- Serial Monitor: **115200 baud**

Aprire il progetto: Arduino IDE -> File -> Open -> `firmware/DigiVessel/DigiVessel.ino`

## Convenzioni di codice

- Timing **non bloccante** con `millis()`, mai `delay()` nel loop principale
  (devono convivere lettura pulsanti + aggiornamento display + logica pet).
- Stringhe letterali con `F("...")` per risparmiare RAM.
- Parametri di gioco come costanti nominate in cima al file, facili da ritoccare.
- Codice e commenti in italiano.

## Roadmap

1. [in corso] Installare Arduino IDE + supporto ESP32 + librerie OLED.
   - [FATTO] Arduino IDE 2.3.10 installato (Windows, via winget `ArduinoSA.IDE.stable`).
   - [DA FARE] Boards Manager: pacchetto "esp32 by Espressif Systems".
   - [DA FARE] Library Manager: `Adafruit SSD1306` + `Adafruit GFX Library`.
   - [DA FARE] Verify dello sketch 01 (compila senza hardware collegato).
2. [FATTO, da testare su device il ~2026-09-01] Sketch 01: variabile `fame` che cala
   nel tempo, stampata sul Serial Monitor. Nessun hardware oltre all'ESP32.
3. Disegnare sull'OLED reale una volta collegato.
4. Refactor in moduli: `PetState`, `Display`, `Input` (file separati nella cartella dello sketch).
   Poi, in ordine: interazione pulsanti (mangia / gioca / pulisci), sistema di evoluzione,
   piu' avanti eventualmente WiFi per comunicazione tra dispositivi.
