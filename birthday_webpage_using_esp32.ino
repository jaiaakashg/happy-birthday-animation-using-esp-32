#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "your ssid";
const char* password = "your password";

WebServer server(80);

const char* htmlContent = "<html><body><h1>Happy Birthday</h1></body></html>";

void handleRoot() {
  server.send(200, "text/html", htmlContent);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}

