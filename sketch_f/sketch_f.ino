#include <WiFi.h>
#include <WebServer.h>

// MOTOR PINS (L293D)
#define IN1 26
#define IN2 27
#define IN3 14
#define IN4 12

// OPTIONAL SPEED CONTROL (PWM ENABLE PINS)
#define ENA 25
#define ENB 33

// RELAY FOR WATER PUMP
#define PUMP_RELAY 2

// WiFi Access Point Credentials
const char* ssid = "POCO M4 Pro";
const char* password = "ashupathak";

WebServer server(80);

// -------------------- MOTOR FUNCTIONS ----------------------
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void moveLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopBot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// -------------------- WEB PAGE ----------------------
String htmlPage() {
  String page = "<html><head>";
  page += "<style>";
  page += "button{width:120px;height:60px;font-size:20px;margin:10px;}";
  page += "body{text-align:center;font-family:Arial;}";
  page += "</style>";
  page += "</head><body><h1>Floor Cleaner Bot</h1>";

  page += "<h2>Movement</h2>";
  page += "<a href='/forward'><button>Forward</button></a><br>";
  page += "<a href='/left'><button>Left</button></a>";
  page += "<a href='/stop'><button>Stop</button></a>";
  page += "<a href='/right'><button>Right</button></a><br>";
  page += "<a href='/backward'><button>Backward</button></a><br><br>";

  page += "<h2>Water Pump</h2>";
  page += "<a href='/pump_on'><button>PUMP ON</button></a>";
  page += "<a href='/pump_off'><button>PUMP OFF</button></a>";

  page += "</body></html>";
  return page;
}

// -------------------- HTTP HANDLERS ----------------------
void handleRoot() { server.send(200, "text/html", htmlPage()); }

void handleForward() { moveForward(); server.send(200, "text/html", htmlPage()); }
void handleBackward() { moveBackward(); server.send(200, "text/html", htmlPage()); }
void handleLeft() { moveLeft(); server.send(200, "text/html", htmlPage()); }
void handleRight() { moveRight(); server.send(200, "text/html", htmlPage()); }
void handleStop() { stopBot(); server.send(200, "text/html", htmlPage()); }

void handlePumpOn() {
  digitalWrite(PUMP_RELAY, LOW); // LOW = ON for most relay modules
  server.send(200, "text/html", htmlPage());
}

void handlePumpOff() {
  digitalWrite(PUMP_RELAY, HIGH); // HIGH = OFF
  server.send(200, "text/html", htmlPage());
}

// -------------------- SETUP ----------------------
void setup() {
  Serial.begin(115200);

  // Motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  // Relay pin
  pinMode(PUMP_RELAY, OUTPUT);
  digitalWrite(PUMP_RELAY, HIGH); // pump off by default

  // Start Access Point
  WiFi.softAP(ssid, password);
  Serial.print("WiFi AP started. Connect to: "); Serial.println(ssid);
  Serial.println("Open http://192.168.4.1");

  // Route control
  server.on("/", handleRoot);
  server.on("/forward", handleForward);
  server.on("/backward", handleBackward);
  server.on("/left", handleLeft);
  server.on("/right", handleRight);
  server.on("/stop", handleStop);
  server.on("/pump_on", handlePumpOn);
  server.on("/pump_off", handlePumpOff);

  server.begin();
}

// -------------------- LOOP ----------------------
void loop() {
  server.handleClient();
}