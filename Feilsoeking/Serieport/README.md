## Feilsøking: Serieport

Hvis du får en feilmelding med teksten ```Resource busy: '/dev/cu.usbserial-XXX``` eller liknende, gjør du følgende:

### Mac:

* Velg meny: **Terminal -> Run Task ... -> PlatformIO -> PlatformIO: Devices**
  
Forhåpentligvis ser du en serieport som heter ```/dev/cu.SLAB_USBtoUART``` i teksten som vises:

```
/dev/cu.SLAB_USBtoUART
----------------------
Hardware ID: USB VID:PID=10C4:EA60 SER=02130EC1 LOCATION=20-2
Description: CP2104 USB to UART Bridge Controller - CP2104 USB to UART Bridge Controller
```

* Åpne filen ```platform.io```
* Legg til disse to linjene:
```
upload_port = /dev/cu.SLAB_USBtoUART
monitor_port = /dev/cu.SLAB_USBtoUART
```

Seksjonen ```[env:esp32dev]``` skal nå se ca. slik ut:

```
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
upload_port = /dev/cu.SLAB_USBtoUART
monitor_port = /dev/cu.SLAB_USBtoUART
```


