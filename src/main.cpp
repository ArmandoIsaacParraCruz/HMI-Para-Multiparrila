#include <Arduino.h>
#include "HMI.h"

uint8_t opcion;

void setup() 
{   
    inicializar_HMI();
	Serial.begin(115200);
}

void loop()
{
    opcion = menu_principal();
    if(opcion == 1)
		configurar_agitacion_y_calentamiento();
  	else if(opcion == 2)
		monitorear_agitacion_y_temperatura();
  	else if(opcion == 3)
    	mostrar_el_estado_del_enlace();
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


uint8_t mac_multiparrilla[] = {0x40, 0x91, 0x51, 0xAB , 0x1B, 0xC0};
uint8_t mac_HMI[] = {0x0C, 0xB8, 0x15, 0xC1, 0x9A, 0xD4};

uint8_t num;



void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nEstatus del último Paquete enviado\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_MODE_STA);
    ESPNow.set_mac(mac_HMI);
    WiFi.disconnect();
    ESPNow.init();
    ESPNow.reg_send_cb(OnDataSent);
    ESPNow.add_peer(mac_multiparrilla);
    num = 33;
}

void loop() {
    uint8_t a[] = {'C','a', 'r','a','c','t','e','r',':',' ', (char)num};
    delay(100);
    ESPNow.send_message(mac_multiparrilla, a, sizeof(a));
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

uint8_t mac_multiparrilla[] = {0x40, 0x91, 0x51, 0xAB , 0x1B, 0xC0};
uint8_t mac_HMI[] = {0x0C, 0xB8, 0x15, 0xC1, 0x9A, 0xD4};

void confirmarRecepcion(){
    uint8_t recibido[] = {'R','E', 'C','I','B','I','D','O'};
    ESPNow.send_message(mac_HMI, recibido, sizeof(recibido));
}

void onRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) {
    Serial.print("Last Packet Recv Data: ");
    // if it could be a string, print as one
    if (data[data_len - 1] == 0)
        Serial.printf("%c\n", data);
    // additionally print as hex
    for (int i = 0; i < data_len; i++) {
        Serial.printf("%c", data[i]);
    }
    Serial.println(" ");
    confirmarRecepcion();
}

void setup() {
    Serial.begin(115200);
    Serial.println("ESPNow receiver Demo");
    WiFi.mode(WIFI_MODE_STA);
    ESPNow.set_mac(mac_multiparrilla);
    WiFi.disconnect();
    ESPNow.init();
    ESPNow.reg_recv_cb(onRecv);
    ESPNow.add_peer(mac_HMI);
}

void loop() {}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

