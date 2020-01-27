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

![Nodeconectado]('./Node_conectado.jpg')