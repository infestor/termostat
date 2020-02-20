
### Termostat do horního pokoje:
--------------------------------

- Měření teploty pokoje a podlahy
- Musí umět regulovat výkon cca 500W 220V AC do topné fólie a držet přednastavenou teplotu (pomocí PID)
- Je limitace na teplotu fólie - nesmí překročit 27 stupňů  
- Budeme řídit pomalou pwm - aby perioda přibližně odpovídala 10ti vlnám AC (tzn. 20 půlvln, 200ms) a budeme to prostě hala bala nastavovat po 10ms (= 5% výkonu) až do 200ms (= 100% výkonu). Obvod s detekcí průchodu nulou pořeší ostatní za nás. V podstatě řekneme kolik (1-20) půlvln ze 20ti chceme mít sepnuto.
- ovládání dvěma tlačítkama
- teplota nastavitelná asi od 15 - 25 stupňů (asi můžem po 0.5 stupních) (a hele to se hodí jako hodnoty uint8_t 150 - 250 :)
- zřejmě nějakej manuální mód - prostě přednastavená teplota nafurt bez ohledu na hodiny
- mód total off, třeb na léto apod
- možná nějaký počítání procentohodin?? - Kumulace jak dlouho bylo zapnuto a na kolik procent..

- pokud se implementuje časový rozvrh:
  - bude asi stačit rozdělit den na 3 úseky,
  - separátně pracovní dny + víkend
  - myslim že nemusíme nastavovat po minutách ale po čtvrthodinách

__Nastavení úseků__ - první vždycky začína na 00:00 a poslední končí zase o půlnoci, takže je potřeba nastavit akorát začátek a konec prostředního úseku a na to bude separátní obrazovka, což znamená i okrajové časy pro první a třetí úsek.  
Úseky v pracovních dnech jsou označené jako PD1 .. PD3, víkendové jako VK1 .. VK3

--------------------------------
### Funkce tlačítek:
Tbd





--------------------------------
### Displej bude ukazovat:


__pohotovostní zobrazení:__
```
/----------------\
|22.1  [AUT 23.0]|
|26.5| OFF |11:56|
\----------------/

Aktuální teplota vzduchu | [ AUT/MAN nastavená teplota] nebo [VYPNUTO] pro total off
aktuální teplota podlahy | aktuální výkon 95% (nebo OFF) | Hodiny
```
  
__Nastavení zacatku a konce prostredniho useku:__  
Prvni hodnota (zacatek useku) jde cyklovat asi mezi 0:15 - 23:30, ta druha se pak prispusobi a nepujde dát níž než začátek a vždycky může končit na 23:45
```
/----------------\
|Pracovni dny    |
|08:00      22:00|
\----------------/
/----------------\
|Vikendy         |
|08:00      22:00|
\----------------/
```
  
__Nastavení teplot pro jednotlivé úseky:__
```
/----------------\
|PD1  00:00|08:15|
|Teplota:  19.5'C|
\----------------/
/----------------\
|PD2  08:15|18:00|
|Teplota:  23.0'C|
\----------------/
/----------------\
|PD3  18:00|23:59|
|Teplota:  18.0'C|
\----------------/
/----------------\
|VK3  18:00|23:59|
|Teplota:  18.0'C|
\----------------/
```

__Nastavení hodin:__
```
/----------------\
|Nastaveni casu  |
|    12 : 36     |
\----------------/

 1234567890123456
/----------------\
|                |
|                |
\----------------/
```

Součástky:
----------------------
Arduino Nano  
Displej 2x16 znaků  
MOC3043 (MOC3063) řídicí optotriak se zero crossing (5mA Ion)  
BTA16 výkonovej triak  
2x DS18B20 teplotní čidlo 1wire  
Stabilizovaný napájení 220AC -> 5V DC  
(RTC obvod - DS3231 (https://arduino-shop.cz/arduino/1261-rtc-hodiny-realneho-casu-ds3231-at24c32-iic-pametovy-modul-pro-arduino.html) )  
R 39 ohm  
R 330 ohm  
R 360 ohm  
C 0.01 uF na 400V  
