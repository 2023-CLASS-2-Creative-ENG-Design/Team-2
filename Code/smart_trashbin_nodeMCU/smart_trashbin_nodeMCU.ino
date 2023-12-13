#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#define lcdPort_TX D0
#define lcdPort_RX D1

#define servoPort_TX D2
#define servoPort_RX D3
EspSoftwareSerial::UART lcdPort;
EspSoftwareSerial::UART servoPort;
Servo myservo;

#define PORT 1000
WiFiClient client;
WiFiServer server(PORT);
String dataClient;
const char* ssid = "smart_trashbin";
const char* pass = "knucse2023";

void setup() {
  lcdPort.begin(38400, SWSERIAL_8N1, lcdPort_RX, lcdPort_TX, false);
  servoPort.begin(19200, SWSERIAL_8N1, servoPort_RX, servoPort_TX, false);
  myservo.attach(D5);
  Serial.begin(115200);
  Serial.println("test TCPIP ");
  Serial.print("Port : ");
  Serial.println(PORT); 

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
  }

  Serial.print("Point : ");
  Serial.println(ssid);
  Serial.println("Alarm IP : ");
  Serial.print(WiFi.localIP());
  delay(200);
  server.begin();
} 



void loop() {
  while(!client.connected()) {
   client = server.available();
  }
  while (client.connected()) { // TCP/IP 연결 시
    if (client.available()) { // 값이 수신되었다면
      char data = client.read(); // 수신 버퍼에서 데이터를 읽어서 저장
      dataClient += data; // 수신값 추가
      if (dataClient.equals("can")) {
        lcdPort.write('c');
        servoPort.write('c');
        dataClient = "";
      }
      if (dataClient.equals("plastic")) {
        lcdPort.write('p');
        servoPort.write('p');
        dataClient = "";
      }
      if (dataClient.equals("vinyl")) {
        lcdPort.write('v');
        servoPort.write('v');
        dataClient = "";
      }
    }
  }   
}