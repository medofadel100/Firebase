#include <Firebase.h>
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>


const char* ssid = "Ahmed  Fadel";
const char* password = "Girl181997";



#define FIREBASE_HOST "test-57917.firebaseio.com"
#define FIREBASE_AUTH "rbE6dWoyNaP8udHaFx0kZtIygVtX3h5dHU3b0YZg"


int ledpin = 5 ;
void setup() {

 Serial.begin(9600);
 
  WiFi.begin(ssid, password);
 
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  
  Firebase.begin(FIREBASE_HOST , FIREBASE_AUTH );
   pinMode(ledpin,OUTPUT);
}

void loop() {
  


  int ledStatus = Firebase.getInt("Ahmed/ledStatus");
  Serial.println(ledStatus);
  if(ledStatus==1){
    digitalWrite(ledpin,HIGH);
  }
  else {
    digitalWrite(ledpin,LOW);
  }
}
