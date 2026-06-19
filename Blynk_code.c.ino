#define BLYNK_TEMPLATE_ID "TMPL3wU61d1qx"
#define BLYNK_TEMPLATE_NAME "Smart Hospitality System"
#define BLYNK_AUTH_TOKEN "1RtGp2_AO2ixXCijM8IDK6tQrf6OBtJA"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include "time.h"

char ssid[] = "Sathya's S24";
char pass[] = "varshu@13";

const char* ntpServer = "time.google.com";
const long gmtOffset_sec = 19800;
const int daylightOffset_sec = 0;

HardwareSerial nextion(2);

String receivedData = "";

String getTime()
{
  struct tm timeinfo;

  if(!getLocalTime(&timeinfo))
  {
    return "Time Error";
  }

  char timeStringBuff[30];

  strftime(timeStringBuff,
           sizeof(timeStringBuff),
           "%I:%M:%S %p",
           &timeinfo);

  return String(timeStringBuff);
}

// =========================
// STAFF ACCEPT BUTTON
// =========================

BLYNK_WRITE(V5)
{
  int buttonState = param.asInt();

  if(buttonState == 1)
  {
    Serial.println("Request Accepted");

    Blynk.virtualWrite(V4, "Accepted");

    Blynk.logEvent("service_request", "Staff Accepted Request");

    Blynk.virtualWrite(V5, 0);
  }
}

// =========================
// STAFF COMPLETED BUTTON
// =========================
BLYNK_WRITE(V6)
{
  int buttonState = param.asInt();

  if(buttonState == 1)
  {
    Serial.println("Service Completed");

    Blynk.virtualWrite(V4, "Completed");

    Blynk.logEvent("service_request", "Service Completed");

    Blynk.virtualWrite(V6, 0);
  }
}

String lastService = "";

void setup()
{
  Serial.begin(115200);

  // Nextion UART
  nextion.begin(9600, SERIAL_8N1, 16, 17);      
  Serial.println("System Starting");

  // WiFi Connection
  WiFi.begin(ssid, pass);

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected");
  
  // Time configuration
  configTime(19800, 0, "time.google.com");
  struct tm timeinfo;

  if(getLocalTime(&timeinfo))
 {
  Serial.println("Time Obtained");
 }
  else
 {
  Serial.println("Time Failed");
 }

  Serial.println(getTime());        

  // Blynk Connection
  Blynk.config(BLYNK_AUTH_TOKEN);

  if(Blynk.connect())
  {
    Serial.println("Blynk Connected");
  }
  else
  {
    Serial.println("Blynk Failed");
  }
}

void loop()
{
  Blynk.run();

  while(nextion.available())
  {
    char c = nextion.read();

    if(c != 255)
    {
      receivedData += c;
    }

    delay(5);
  }

  if(receivedData.length() > 0)
  {
    Serial.print("Received: ");
    Serial.println(receivedData);

    // Soap SERVICE
    if(receivedData.indexOf("Soap") >= 0)
    {
      Serial.println("Soap Requested");
      Serial.println("Sending To Blynk");

      // PUSH NOTIFICATION
      Blynk.logEvent("soap_request", "Soap Requested for Room 101");
      delay(100);

      // Send to Blynk Cloud
      Blynk.virtualWrite(V0, "Soap Requested");
      Blynk.virtualWrite(V1, "101");
      Blynk.virtualWrite(V2, "Hari");
      Blynk.virtualWrite(V3, getTime());
      Blynk.virtualWrite(V4, "Pending");

    }

       // Dental SERVICE
    else if(receivedData.indexOf("Dental") >= 0)
    {
      Serial.println("Dental Requested");
      Serial.println("Sending To Blynk");

      // PUSH NOTIFICATION
      Blynk.logEvent("dental_request", "Dental Requested for Room 102");
      delay(100);

      // Send to Blynk Cloud
      Blynk.virtualWrite(V0, "Dental Requested");
      Blynk.virtualWrite(V1, "102");
      Blynk.virtualWrite(V2, "Jai");
      Blynk.virtualWrite(V3, getTime());
      Blynk.virtualWrite(V4, "Pending");

      }

       // Hanger SERVICE
    else if(receivedData.indexOf("Hanger") >= 0)
    {
      Serial.println("Hanger Requested");
      Serial.println("Sending To Blynk");

      // PUSH NOTIFICATION
      Blynk.logEvent("hanger_request", "Hanger Requested for Room 103");
      delay(100);

      // Send to Blynk Cloud
      Blynk.virtualWrite(V0, "Hanger Requested");
      Blynk.virtualWrite(V1, "103");
      Blynk.virtualWrite(V2, "Sreeram");
      Blynk.virtualWrite(V3, getTime());
      Blynk.virtualWrite(V4, "Pending");

    }

      // Towel SERVICE
    else if(receivedData.indexOf("Towel") >= 0)
    {
      Serial.println("Towel Requested");
      Serial.println("Sending To Blynk");

      // PUSH NOTIFICATION
      Blynk.logEvent("towel_request", "Towel Requested for Room 104");
      delay(100);

      // Send to Blynk Cloud
      Blynk.virtualWrite(V0, "Towel Requested");
      Blynk.virtualWrite(V1, "104");
      Blynk.virtualWrite(V2, "Gowtham");
      Blynk.virtualWrite(V3, getTime());
      Blynk.virtualWrite(V4, "Pending");

    }

      // Iron box SERVICE
    else if(receivedData.indexOf("Iron box") >= 0)
    {
      Serial.println("Iron box Requested");
      Serial.println("Sending To Blynk");

      // PUSH NOTIFICATION
      Blynk.logEvent("iron_box_request", "Iron box Requested for Room 105");
      delay(100);

      // Send to Blynk Cloud
      Blynk.virtualWrite(V0, "Iron box Requested");
      Blynk.virtualWrite(V1, "105");
      Blynk.virtualWrite(V2, "Prince");
      Blynk.virtualWrite(V3, getTime());
      Blynk.virtualWrite(V4, "Pending");

    }
      
      // Water refill SERVICE
    else if(receivedData.indexOf("Water Refill") >= 0)
    {
      Serial.println("Water Refill Requested");
      Serial.println("Sending To Blynk");

       // PUSH NOTIFICATION
      Blynk.logEvent("water_refill_request", "Water refill Requested for Room 106");
      delay(100);

      // Send to Blynk Cloud
      Blynk.virtualWrite(V0, "Water refill Requested");
      Blynk.virtualWrite(V1, "106");
      Blynk.virtualWrite(V2, "Aravindh");
      Blynk.virtualWrite(V3, getTime());
      Blynk.virtualWrite(V4, "Pending");

    }

       // Mini bar refill SERVICE
    else if(receivedData.indexOf("Mini Bar Refill") >= 0)
    {
      Serial.println("Mini Bar Refill Requested");
      Serial.println("Sending To Blynk");

       // PUSH NOTIFICATION
      Blynk.logEvent("minibar_refill_request", "Mini Bar refill Requested for Room 107");
      delay(100);

      // Send to Blynk Cloud
      Blynk.virtualWrite(V0, "Mini Bar Refill Requested");
      Blynk.virtualWrite(V1, "107");
      Blynk.virtualWrite(V2, "Mithun");
      Blynk.virtualWrite(V3, getTime());
      Blynk.virtualWrite(V4, "Pending");

    }

      //  Do not Disturb SERVICE
    else if(receivedData.indexOf("Do not Disturb") >= 0)
    {
      Serial.println("dnd Requested");
      Serial.println("Sending To Blynk");

      // PUSH NOTIFICATION
      Blynk.logEvent("dnd_request", "DND Requested for Room 108");
      delay(100);

      // Send to Blynk Cloud
      Blynk.virtualWrite(V0, "dnd Requested");
      Blynk.virtualWrite(V1, "108");
      Blynk.virtualWrite(V2, "Tharshini");
      Blynk.virtualWrite(V3, getTime());
      Blynk.virtualWrite(V4, "Pending");

    }
     
     //  Extra pillows SERVICE
    else if(receivedData.indexOf("Extra Pillows") >= 0)
    {
      Serial.println("extra pillows Requested");
      Serial.println("Sending To Blynk");

      // PUSH NOTIFICATION
      Blynk.logEvent("extra_pillows_request", "extra pillows Requested for Room 109");
      delay(100);

      // Send to Blynk Cloud
      Blynk.virtualWrite(V0, "extra pillows Requested");
      Blynk.virtualWrite(V1, "109");
      Blynk.virtualWrite(V2, "Vidya");
      Blynk.virtualWrite(V3, getTime());
      Blynk.virtualWrite(V4, "Pending");

    }
       
       // Laundry SERVICE
    else if(receivedData.indexOf("Laundry") >= 0)
    {
      Serial.println("laundry Requested");
      Serial.println("Sending To Blynk");

             // PUSH NOTIFICATION
      Blynk.logEvent("laundry_request", "laundry requested for Room 110");
      delay(100);

      // Send to Blynk Cloud
      Blynk.virtualWrite(V0, "laundry requested");
      Blynk.virtualWrite(V1, "110");
      Blynk.virtualWrite(V2, "Swetha");
      Blynk.virtualWrite(V3, getTime());
      Blynk.virtualWrite(V4, "Pending");

    }
       
       // Luggage SERVICE
    else if(receivedData.indexOf("Luggage") >= 0)
    {
      Serial.println("luggage assistance Requested");
      Serial.println("Sending To Blynk");

      // PUSH NOTIFICATION
      Blynk.logEvent("luggage_assistance_request", "Luggage assistance Requested for Room 111");
      delay(100);

      // Send to Blynk Cloud
      Blynk.virtualWrite(V0, "Luggage assistance Requested");
      Blynk.virtualWrite(V1, "111");
      Blynk.virtualWrite(V2, "Subha");
      Blynk.virtualWrite(V3, getTime());
      Blynk.virtualWrite(V4, "Pending");

    }
      
       // Cleaning SERVICE
    else if(receivedData.indexOf("Cleaning") >= 0)
    {
      Serial.println("cleaning requested");
      Serial.println("Sending To Blynk");

      // PUSH NOTIFICATION
      Blynk.logEvent("cleaning_request", "Cleaning Requested for Room 112");
      delay(100);

      // Send to Blynk Cloud
      Blynk.virtualWrite(V0, "cleaning requested");
      Blynk.virtualWrite(V1, "112");
      Blynk.virtualWrite(V2, "Premalatha");
      Blynk.virtualWrite(V3, getTime());
      Blynk.virtualWrite(V4, "Pending");

    }


    receivedData = "";
  }
}