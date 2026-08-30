# assets/sprites/

Grafica per l'OLED SSD1306 (128x64, monocromatico).

Gli sprite vanno convertiti in bitmap C (array `PROGMEM`) per essere disegnati
con `display.drawBitmap()` della libreria Adafruit GFX. Strumento comodo:
image2cpp (https://javl.github.io/image2cpp/), formato "Arduino code, single bitmap".

Tenere qui sia il sorgente (PNG) sia l'header generato.
