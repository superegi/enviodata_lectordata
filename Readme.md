# Proyecto de crear un lector de datos y enviar a una BD


Este proyecto en principio está pensado para la lectura de datos (temperatura y humedad por ahora). 


La idea inicial es que sea asequible por la web por medio de un servidor web, la 2da parte es que se pueda enviar data a un servidor y acceder a él y leer la información

## test3
Acá la 1ra parte funciona bien.
Se logra finalmente el servidor web

El puerto serial muestra el status, IP y Hum y %.

Hay que tener cuidado con los pines y el mapa. Tuve ciertos problemas al conectar, ya que los label del NodeMCU no son los mismos del código. Se debe colocar en el código lo correspondiente al pin GPIO según el mapa de pines.

También cuidado con no cargar el script con los pines conectados, ya que hay caída de tensión.

Al correr el script hay que asegurarse de desconectar-conectar el sensor, dado que la lectura se asigna con sudo cada vez que se corre. Si se desconecta y conecta.... se pierde la asignación del serial y se crea una nueva (bueno al final no funcionó....)

Para el ejemplo utilizo GND, 3v3, D8 (que corresponde a GPIO15)

![Nodeconectado]('./test3/Node_conectado.jpg')


## instalo mycopython

https://www.prometec.net/micropython-nodemcu/
http://docs.micropython.org/en/latest/esp8266/tutorial/intro.html#deploying-the-firmware


uso esto para aprender

https://www.digikey.com/en/maker/projects/micropython-basics-load-files-run-code/fb1fcedaf11e4547943abfdd8ad825ce

sigo este codigo
https://dev.to/bocajnotnef/intro-to-working-with-with-esp8266-3bno
https://dev.to/bocajnotnef/receiving-data-from-esp8266-sensors-3n5e

comando para copiar
ampy --port /dev/ttyUSB0 put main.py

screen /dev/ttyUSB0 115200

ctl+a, luego d para deattach.
screen -r para attach a esa sesion

## purbo multisocket
https://realpython.com/python-sockets/
https://github.com/realpython/materials/tree/master/python-sockets-tutorial



## finalmente me quedo con la opción 6


## ahora creo el ervicio en el pc local

https://www.dexterindustries.com/howto/run-a-program-on-your-raspberry-pi-at-startup/

metodo 4


[Unit]
Description=Servicio temp y hum por 555
After=multi-user.target

[Service]
Type=idle
ExecStart=/home/pi/termometros_py/ejecut.sh


[Install]
WantedBy=multi-user.target

