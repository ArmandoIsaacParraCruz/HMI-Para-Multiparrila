#include <Arduino.h>
#include "HMI.h"

uint8_t opcion = 0;

void setup() { 
  
	inicializaHMI();
	Serial.begin(115200);
}

void loop() 
{
  opcion = menuPrincipal();
  Serial.println(opcion);
}

/*

EL CÓDGIDO COMENTADO A CONTINUACIÓN SE UTILIZARÁ COMO BASE PARA ESTABLECER LA COMUNICACIÓN ENTRE EL HMI Y LA MULTIPPARRILLA AGITADORA


#include <esp_wifi.h>
#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
void setup() {
	Serial.begin(115200); Serial.println();Serial.println();
	Serial.print("AP MAC: "); Serial.println(WiFi.softAPmacAddress());
	Serial.print("STA MAC: "); Serial.println(WiFi.macAddress());
}

void loop() {}
*/

/*
//////////////////////////////////////////////TRANSMISOR///////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include <WiFi.h>
#include "ESPNowW.h"
#include "PantallaTecladoComunicacion.h"

uint8_t receiver_mac[] = {0x40, 0x91, 0x51, 0xAB , 0x1B, 0xC0};
uint8_t num;
void setup() {
    Serial.begin(115200);
    Serial.println("ESPNow sender Demo");
#ifdef ESP8266
    WiFi.mode(WIFI_STA); // MUST NOT BE WIFI_MODE_NULL
#elif ESP32
    WiFi.mode(WIFI_MODE_STA);
#endif
    WiFi.disconnect();
    ESPNow.init();
    ESPNow.add_peer(receiver_mac);
    num = 33;
}

void loop() {
    uint8_t a[] = {'C','a', 'r','a','c','t','e','r',':',' ', (char)num};
    delay(100);
    ESPNow.send_message(receiver_mac, a, sizeof(a));
    for(int i = 0; i < sizeof(a); ++i)
        Serial.printf("%c",a[i]);
    Serial.print("  ");Serial.println(num);
    num++;
    if(num > 126)
        num = 33;
}

*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
//////////////////////////////////////////////RECEPTOR///////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#ifdef ESP8266
#include <ESP8266WiFi.h>
#elif ESP32
#include <WiFi.h>
#endif
#include "ESPNowW.h"

uint8_t mac[] = {0x36, 0x33, 0x33, 0x33, 0x33, 0x33};

void onRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) {
    char macStr[18];
    snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
             mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4],
             mac_addr[5]);
    Serial.print("Last Packet Recv from: ");
    Serial.println(macStr);
    Serial.print("Last Packet Recv Data: ");
    // if it could be a string, print as one
    if (data[data_len - 1] == 0)
        Serial.printf("%c\n", data);
    // additionally print as hex
    for (int i = 0; i < data_len; i++) {
        Serial.printf("%c", data[i]);
    }
}

void setup() {
    Serial.begin(115200);
    Serial.println("ESPNow receiver Demo");
#ifdef ESP8266
    WiFi.mode(WIFI_STA); // MUST NOT BE WIFI_MODE_NULL
#elif ESP32
    WiFi.mode(WIFI_MODE_STA);
#endif
    ESPNow.set_mac(mac);
    WiFi.disconnect();
    ESPNow.init();
    ESPNow.reg_recv_cb(onRecv);
}

void loop() {}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

*/