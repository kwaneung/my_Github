#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

char *ssid = "paperget_315_24";
char *password = "paperget**";

int RELAY_pin = 5;

ESP8266WebServer server(80);

void handleON() {
  server.send(200, "text/plane", "Turned ON !!");
  Serial.println("RELAY is ON !!");
  pinMode(RELAY_pin, OUTPUT);
  digitalWrite(RELAY_pin, LOW);
}

 void handleOFF() {
  server.send(200, "text/plane", "Turned OFF!!");
  Serial.println("RELAY is OFF !!");
  pinMode(RELAY_pin, INPUT);
}

 void setup(void) {
  Serial.begin(115200);

  Serial.print("Connecting to \'");
  Serial.print(ssid);
  Serial.println("\'");

  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("WiFi connected.");

  Serial.print("Server IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/on", handleON);
  server.on("/off", handleOFF);

  server.begin();
  Serial.println("HTTP server started");

  pinMode(RELAY_pin, INPUT);
  digitalWrite(RELAY_pin, LOW);
}

void loop(void) {
  server.handleClient();
}
