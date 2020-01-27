// #include <DHT.h>
// #include <ESP8266WiFi.h>
// #include <SPI.h>

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
// #include <ESPAsyncTCP.h>
// #include <ESPAsyncWebServer.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>



// #include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
// #include <ESP8266WiFiMulti.h>


//byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x01 }; // RESERVED MAC ADDRESS
//EthernetClient client;
const char* ssid = "Pieza_fondo";  // Enter SSID here
const char* password = "no se la clave";  //Enter Password here
//


#define DHTPIN 15 // SENSOR PIN
#define DHTTYPE DHT22 // SENSOR TYPE - THE ADAFRUIT LIBRARY OFFERS SUPPORT FOR MORE MODELS
DHT dht(DHTPIN, DHTTYPE);

long previousMillis = 0;
unsigned long currentMillis = 0;
long interval = 250000; // READING INTERVAL

int t = 0;	// TEMPERATURE VAR
int h = 0;	// HUMIDITY VAR

// char data;

void setup() { 

	// Serial port for debugging purposes
	Serial.begin(115200);

	// Connect to Wi-Fi
	WiFi.begin(ssid, password);
	Serial.println("Connecting to WiFi");
	while (WiFi.status() != WL_CONNECTED) {
	delay(1000);
	Serial.println(".");
	}

	// Print ESP8266 Local IP Address
	Serial.println(WiFi.localIP());


	// Serial.begin(115200);

	// if (Ethernet.begin(mac) == 0) {
	// 	Serial.println("Failed to configure Ethernet using DHCP"); 
	// }

	// dht.begin(); 
	// delay(10000); // GIVE THE SENSOR SOME TIME TO START


	dht.begin();
	delay(10000); //mio
	h = (int) dht.readHumidity(); 
	t = (int) dht.readTemperature(); 
	const char*	data = "";
}

void loop(){
	WiFiClient client

	// unsigned long currentMillis = millis();
	// if(currentMillis - previousMillis > interval) { // READ ONLY ONCE PER INTERVAL
	// 	previousMillis = currentMillis;
	// 	h = (int) dht.readHumidity();
	// 	t = (int) dht.readTemperature();
	// }
	unsigned long currentMillis = millis();
	if (currentMillis - previousMillis >= interval) {
	    // save the last time you updated the DHT values
	    previousMillis = currentMillis;
	    // Read temperature as Celsius (the default)
	    float newT = dht.readTemperature();
	    // Read temperature as Fahrenheit (isFahrenheit = true)
	    //float newT = dht.readTemperature(true);
	    // if temperature read failed, don't change t value
	}


	char data = "temp1=" + t + "&hum1=" + h;

	if (client.connect("192.168.1.30",80)) { // REPLACE WITH YOUR SERVER ADDRESS
		client.println("POST /add.php HTTP/1.1"); 
		client.println("Host: 192.168.1.30"); // SERVER ADDRESS HERE TOO
		client.println("Content-Type: application/x-www-form-urlencoded"); 
		client.print("Content-Length: "); 
		client.println(data.length()); 
		client.println(); 
		client.print(data); 
	} 

	if (client.connected()) { 
		client.stop();	// DISCONNECT FROM THE SERVER
	}

	delay(3000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN
}
