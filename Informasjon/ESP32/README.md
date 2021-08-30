# Om ESP32

ESP32 er en serie billige, mikrobrikkere med integrert Wi-Fi og Bluetooth.
De bruker lite strøm og tar liten plass.

![ESP32](../../img/esp32-devkit.jpeg)

ESP32 er designet av Espressif Systems, et Shanghai-basert kinesisk selskap, og er produsert av TSMC ved bruk av deres 40 nm-prosess. Den er en etterfølger til ESP8266 mikrokontrolleren.

ESP32 og ESP8266 er veldig populære til prototyping på grunn av deres lave pris, enkelhet i bruk, dokumentasjon og tilgjengelighet til informasjon på nettet.

## Funksjoner
* CPU: Xtensa dual-core (eller single-core) 32-bit LX6 microprocessor, på 160 eller 240 MHz.
* Ultra low power (ULP) co-processor
* Minne: 320 KiB RAM, 448 KiB ROM og mulighet for å bruke ekstra minne.
* Wi-Fi: 802.11 b/g/n
* Bluetooth: v4.2 BR/EDR og BLE (deler radio med Wi-Fi)
* Integrerte enheter, bl.a
    * 34 × programmerbare GPIOs (innganger og utganger)
    * 12-bit ADC på opptil 18 kanaler (analoge innganger)
    * 2 × 8-bit DACs (analoge utganger)
    * 10 × touch sensorer (kapasitive sensorer)
    * 4 × SPI (serieporter for tilkobling av eksterne enheter)
    * 2 × I²S interfaces (grensesnitt for digital lyd)
    * 2 × I²C interfaces (serieporter for tilkobling av eksterne enheter)
    * 3 × UART (enheter for seriell kommunikasjon)
    * SD/SDIO/CE-ATA/MMC/eMMC host controller (for tilkobling av minnenheter)
    * Ethernet MAC interface
    * CAN bus 2.0
    * PWM for styring av motorer og LEDs
* Integrerte sikkerhetmekaniser, bl.a. 
    * IEEE 802.11 standard inkludert WPA, WPA2, WPA3 og WAPI
    * Sikker boot
    * Kryptering av flash
    * Hardwareaksellerert kryptering: AES, SHA-2, RSA, m.m.
* Støtte for lavt strømforbruk

![ESP32 Pinout](./esp32-devkitc-v4-broche-gpio-pinout-2021-1024x553.jpeg)

Kilde: [diyprojects.io](https://diyprojects.io/)
