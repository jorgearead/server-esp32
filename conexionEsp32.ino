#include <WebServer.h>

const char* ssid = "AkyStoyClienteNombre";
const char* pass = "ClienteNombreFechaAkyStoy";

IPAddress ip(192,168,4,22);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);

WebServer server(80);

void setup() {
  Serial.begin(9600);

  WiFi.softAP(ssid, pass,10,false,1);
  WiFi.softAPConfig(ip,gateway,subnet);

  Serial.print("Nombre de la red: ");
  Serial.println(ssid);

  server.on("/", hasdleConnectionRoot);

  server.begin();
  Serial.println("Servidor http iniciado.");
  delay(150);
  
  int conexiones = WiFi.softAPgetStationNum();  //obtenemos el numero de dispositivos conextados
  Serial.printf("Stations connected to soft-AP = %d\n", conexiones);  //mostramos el numero de dispositivos conectados
}

void loop() {
  server.handleClient();
}

String answer = "<!DOCTYPE html>\ <html>\ <body>\ <h1>Mesaje de prueba</h1>\ </body>\ </html>";

void hasdleConnectionRoot(){
  server.send(200, "text/html",answer);
}
