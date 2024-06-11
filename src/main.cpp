#include <Arduino.h>
#include <WiFi.h>
#include <SPIFFS.h>
#include <vector>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>

// Configuration WiFi
const char *ssid = "Iphone de Guillaume";
const char *password = "aga78420";

// Configuration serveur web
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

// Définir les broches GPIO pour les LED
const int yellowLED = 14;
const int blueLED = 27;
const int redLED = 16;
const int greenLED = 17;

// Variables pour le jeu Simon Says
std::vector<int> sequence; // La séquence de LEDs à suivre
std::vector<int> playerInput; // Les réponses du joueur
int currentStep = 0; // Étape actuelle de la séquence
bool gameActive = false; // Indicateur de l'état du jeu
int blinkDelay = 500; // Délai initial pour le clignotement des LEDs

void blinkLED(int led, int delayTime);
void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);
void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
void generateNextSequence();
void playSequence();
void checkPlayerInput();
void resetGame();
void turnOnAllLEDs();
void turnOffAllLEDs();

void setup() {
    Serial.begin(115200);
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(blueLED, OUTPUT);

    if (!SPIFFS.begin(true)) {
        Serial.println("An error has occurred while mounting SPIFFS");
        return;
    }

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
    
    Serial.print("Adresse IP : ");
    Serial.println(WiFi.localIP());

    // Serve les fichiers HTML
    server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");

    // Configure WebSocket
    ws.onEvent(onEvent);
    server.addHandler(&ws);

    server.begin();
    Serial.println("HTTP server started");
}

void loop() {
    ws.cleanupClients();
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
    AwsFrameInfo *info = (AwsFrameInfo*)arg;
    if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
        data[len] = 0;
        String msg = (char*)data;

        if (msg == "start") {
            resetGame();
            generateNextSequence();
            playSequence();
            ws.textAll("Game Started");
            ws.textAll("showButtons");
        } else if (msg.startsWith("response")) {
            String color = msg.substring(9); // "response:color"
            int led = -1;
            if (color == "red") {
                led = redLED;
                playerInput.push_back(redLED);
            } else if (color == "green") {
                led = greenLED;
                playerInput.push_back(greenLED);
            } else if (color == "yellow") {
                led = yellowLED;
                playerInput.push_back(yellowLED);
            } else if (color == "blue") {
                led = blueLED;
                playerInput.push_back(blueLED);
            }
            if (led != -1) {
                blinkLED(led, 400); // Blink LED for 0.4 seconds
                checkPlayerInput();
            }
            ws.textAll("Response Received");
        }
    }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
    if (type == WS_EVT_CONNECT) {
        Serial.println("WebSocket client connected");
    } else if (type == WS_EVT_DISCONNECT) {
        Serial.println("WebSocket client disconnected");
    } else if (type == WS_EVT_DATA) {
        handleWebSocketMessage(arg, data, len);
    }
}

void blinkLED(int led, int delayTime) {
    digitalWrite(led, HIGH);
    delay(delayTime);
    digitalWrite(led, LOW);
}

void generateNextSequence() {
    int randomLED = random(0, 4);
    switch (randomLED) {
        case 0:
            sequence.push_back(redLED);
            break;
        case 1:
            sequence.push_back(greenLED);
            break;
        case 2:
            sequence.push_back(yellowLED);
            break;
        case 3:
            sequence.push_back(blueLED);
            break;
    }
}

void playSequence() {
    gameActive = false;
    for (int led : sequence) {
        blinkLED(led, blinkDelay);
        delay(blinkDelay);
    }
    gameActive = true;
    currentStep = 0;
    playerInput.clear();
}

void checkPlayerInput() {
    if (playerInput[currentStep] != sequence[currentStep]) {
        // Défaite - recharger la page
        turnOnAllLEDs();
        delay(1000);
        turnOffAllLEDs();
        ws.textAll("alert('Game Over'); setTimeout(function(){ location.reload(); }, 100);");
        resetGame();
        return;
    }
    currentStep++;
    if (currentStep >= sequence.size()) {
        ws.textAll("Round Complete! Starting next round...");
        delay(2000);
        generateNextSequence();
        blinkDelay = max(100, blinkDelay - 50); // Diminuer le délai à chaque tour, sans descendre en dessous de 100ms
        playSequence();
    }
}

void resetGame() {
    sequence.clear();
    playerInput.clear();
    currentStep = 0;
    gameActive = false;
    blinkDelay = 500; // Réinitialiser le délai au début du jeu
}

void turnOnAllLEDs() {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(blueLED, HIGH);
}

void turnOffAllLEDs() {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(blueLED, LOW);
}