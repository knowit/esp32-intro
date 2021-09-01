## Enkle analoge kretser uten mikrokontroller

Vi skal lage to enkle kretser som ikke bruker datakraften i mikrokontrolleren, men bruker den kun som strømkilde.

Hensikten er å bli kjent med bruk av breadboard og tolkning av enkle elektroniske kretser.

Hvis du har tidligere erfaring med tolkning av kretser og bruk av breadboard, kan du hoppe over disse oppgavene.

### Lampe som lyser konstant

Vi begynner først med en svært enkel krets:

![](./lyserkonstant/5V_Lampe.png)

### Du trenger

| Type          | Antall           |  Utseeende |
| ------------- | :------------- | :----: |
| LED           | 1    |  ![LED](../../img/led.png) (farge kan variere)
| Motstand 330 Ohm eller 220 ohm | 1 |  ![](../../img/330ohm.png) 	
| Breadboard (prototypebrett)	| 1 | ![](../../img/bb.png)
| ESP32 | 1 | ![](../../img/esp32-devkit.jpeg)

* ESP32 fungerer som en statisk strømkilde og mer merket ```5V``` i diagrammet
* Strømmen går fra strømkilden gjennom motstanderen og så inn i LED-en (lampen)
* Strømmen går fra LED-en tilbake til negativ side på strømforsyningen

Funksjonen til motstanden er å begrense hvor mye strøm som går gjennom LED-en slik at LED-en ikke går i stykker.

Koble opp slik:

![](./lyserkonstant/5V_Lampe_bb.png)

![](./lyserkonstant/5V_Lampe_photo.png)

### Lampe med analog knapp

Denne gangen blir det bare bittelittegranne vanskeligere. Vi legger inn en knapp for å styre lampen:

![](./analogknapp/analog_knapp.png)


### Du trenger

| Type          | Antall           |  Utseeende |
| ------------- | :------------- | :----: |
| LED           | 1    |  ![LED](../../img/led.png) (farge kan variere)
| Trykkbryter	| 1	   |    ![](../../img/button.png)
| Motstand 330 Ohm eller 220 ohm | 1 |  ![](../../img/330ohm.png) 	
| Breadboard (prototypebrett)	| 1 | ![](../../img/bb.png)
| ESP32-CAM | 1 | ![](../../img/esp32cam_small.png)


Koble opp slik:

![](./analogknapp/analog_knapp_bb.png)

![](./analogknapp/analog_knapp_bilde.png)
