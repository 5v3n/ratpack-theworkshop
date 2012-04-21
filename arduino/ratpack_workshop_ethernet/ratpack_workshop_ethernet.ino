#include <SPI.h>
#include <Ethernet.h>
#include "Config.h"

/*
* rat pack workshop result
*
* basically this is occupy ping pong with a push button replacing the infrared motion sensor,
* see https://github.com/makersandco/Occupy-Ping-Pong for details.
*
* sven kraeuter for makers & co.
*
* http://makersand.co
*
* wifly library for arduino 1.0: https://github.com/timr/WiFly-Shield
*/

byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xBA, 0xBE };

EthernetClient client;

void setup() {
  //------------------------ led setup -------------------------
  pinMode(ledPin, OUTPUT);      
  //----------------------- button setup -----------------------
  pinMode(buttonPin, INPUT);    
  // ---------------------- serial setup -----------------------
  Serial.begin(9600);
  
  // Initialize Ethernet shield
  delay(1000);
  Serial.println("Connecting to Ethernet...");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Ethernet initialization failed.");
    while (1) { /* Hang on failure */ }
  }

  connect();
}

void update_button_status(char state) {
  char http_request[255];

  Serial.println(state == '1' ? "Button pressed." : "Button NOT pressed.");

  sprintf(http_request, "PUT %s HTTP/1.1\r\nUser-Agent: %s\r\nHost: %s\r\nContent-Length: 16\r\nContent-Type: application/json\r\n\r\n{\"activated\": %c}",
    RESOURCE, USERAGENT, HOST, state);

  Serial.println(http_request);
  client.print(http_request);
  client.println();
  
  while (!client.available()) {
    delay(1);
  }
  Serial.println();
}

bool get_status_from_server() {
  char http_request[255];
  char state[1];

  Serial.println("Getting status from server...");

  sprintf(http_request, "GET %s HTTP/1.1\r\nUser-Agent: %s\r\nHost: %s\r\n", RESOURCE, USERAGENT, HOST);
  client.print(http_request);
  client.println();

  while (!client.available()) {
    delay(1);
  }
  if (client.find("\"activated\": ")) {
    client.readBytes(state, 1);
    return atoi(state) == 1;
  }    
}

void connect() {
  Serial.print("Connecting to ");
  Serial.print(HOST);
  Serial.print(":80 ...");
  if (client.connect(HOST, 80)) {
    Serial.println(" connected!");
  }
  else {
    Serial.println(" failed!");
    while (1) { /* fail */ }
  }
}

void check_connection_status() {
   if (!client.connected()) {
    Serial.println("\nDisconnected. Stopping client.");
    client.stop();
    connect();
  }
}

void loop() {
  bool led_state;

  check_connection_status();
  
  //------------------- button part ---------------------------------------
  if (digitalRead(buttonPin) == LOW) {
    update_button_status('0');
  }
  else if (digitalRead(buttonPin) == HIGH) {
    update_button_status('1');
  }
  
  //-------------------- signalling led part -------------------------------------
  led_state = get_status_from_server();
  if (led_state) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  delay(pause); 
}
