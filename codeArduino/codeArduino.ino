// On charge les libs
#include <Ethernet.h>
#include <SPI.h>

// On déclare une constance pour corriger les approximation du capteur TMP36 - TODO : tester un autre capteur car celui-ci
// pose des problèmes quand utilisé avec un shield ethernet
#define correction 0.056
// Constante pour le temps d'attente entre chaque post
#define postingInterval 50000

// On déclare l'adresse mac du shield
byte mac[] = {0x00,0x00,0x00,0x00,0x00,0x00};

  // On déclare l'adresse du serveur où l'on va envoyer notre requete post
char server[] = "www.?????.fr"; 

// On initialise l'instance de la librairie
EthernetClient client;

  // Variable qui contient le temps en mimliseconde de la dernière connexion au serveur
unsigned long lastConnectionTime = 0;

  // Variable qui contient l'état de la connection dans la boucle 
boolean lastConnected = false;

// SETUP
void setup() {
	Serial.begin(9600);
	
  // On démarre la connexion
	Ethernet.begin(mac);
	Serial.print("My IP address: ");
	Serial.println(Ethernet.localIP());
}

// LOOP
void loop() {
  // On récuppère le voltage sur l'entré analogique
	int reading = analogRead(A0);  
	
 // On convertie le voltage et on corrige
	float voltage = reading * .004882814;
	voltage = voltage - correction;
	
 // debug voltage
	Serial.print(voltage); Serial.println(" volts");
	
 // debug temperature
 float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
 Serial.print(temperatureC); Serial.println(" degrees C");
 
 
  // Si pas de connexion on stop le client
 if (client.connected() && lastConnected) {
 	Serial.println();
 	Serial.println("disconnecting.");
 	client.stop();
 }

  // Si on est pas connecté, on se reconnecte
 if(!client.connected() && (millis() - lastConnectionTime > postingInterval)) {
 	post(temperatureC);
 }
 
  // On stocke l'état de la connexion
 lastConnected = client.connected();
 
 delay(3000);
}

// Fonction qui contient la routine pour la construction et l'émission de la requete Post
void post(float lastTemperature)
{
	char temp[10];
	String tempAsString;
	dtostrf(lastTemperature,1,2,temp);
	tempAsString = String(temp);
	
	Serial.println("connecting...");
	String PostData="name=arduino&temperature="+tempAsString; 

	Serial.println(PostData);
	if (client.connect(server,80)) {
		Serial.println("connected");
		client.println("POST /newRecord HTTP/1.1");
		client.println("Host:  home.com");
		client.println("User-Agent: Arduino/1.0");
		client.println("Connection: close");
		client.println("Content-Type: application/x-www-form-urlencoded;");
		client.print("Content-Length: ");
		client.println(PostData.length());
		client.println();
		client.println(PostData);
		
		lastConnectionTime = millis();
	} else {
     // si on ne peut pas se connecter
		Serial.println("connection failed");
		Serial.println("disconnecting.");
		client.stop();
	}
}
