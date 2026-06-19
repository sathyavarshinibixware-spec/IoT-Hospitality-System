#include <WiFi.h>

// ---------------- WIFI DETAILS ----------------
const char* ssid = "BWT CBE_5G";
const char* password = "Bwtpl@2@26";

// ---------------- NEXTION SERIAL ----------------
HardwareSerial nextion(2);   // UART2

String receivedData = "";

void setup()
{
    // Serial Monitor
    Serial.begin(9600);

    // Nextion Serial
    nextion.begin(9600, SERIAL_8N1, 16,17);

    // WiFi Connection
    WiFi.begin(ssid, password);

    Serial.println("Connecting to WiFi...");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    Serial.println("Hotel Service System Ready");
}

void loop()
{
    while (nextion.available())
    {
        char c = nextion.read();

        // Ignore Nextion ending bytes
        if (c != 255)
        {
            receivedData += c;
        }

        // Small delay to complete message
        delay(10);
    }

    // If data received
    if (receivedData.length() > 0)
    {
        Serial.print("Service Requested: ");
        Serial.println(receivedData);

        // -------- SERVICE DETECTION --------

        if (receivedData == "Food")
        {
            Serial.println("Food order Requested");
        }

        else if (receivedData == "Water")
        {
            Serial.println("Water Requested");
        }

        else if (receivedData == "Laundry")
        {
            Serial.println("Laundry Requested");
        }

        else if (receivedData == "Cleaning")
        {
            Serial.println("Cleaning Requested");
        }

        else if (receivedData == "Wi-Fi")
        {
            Serial.println("Wi-Fi Support Requested");
        }

        else if (receivedData == "Help")
        {
            Serial.println("Help Requested");
        }

        else if (receivedData == "Taxi")
        {
            Serial.println("Taxi Requested");
        }

        else if (receivedData == "Do not disturb")
        {
            Serial.println("Do not disturb enabled");
        }

        else if (receivedData == "Tea/Coffee")
        {
            Serial.println("Tea/Coffee Requested");
        }

        else if (receivedData == "Towel")
        {
            Serial.println("Towel Requested");
        }

        else if (receivedData == "Bill")
        {
            Serial.println("Bill Requested");
        }

        else if (receivedData == "Checkout")
        {
            Serial.println("Checkout Requested");
        }

        // Clear buffer
        receivedData = "";
    }
}