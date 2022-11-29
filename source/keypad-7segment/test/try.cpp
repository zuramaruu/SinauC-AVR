int PIR = 4;
int statusPin = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(PIR, INPUT);
}

void loop()
{
    statusPin = digitalRead(PIR);
    if (statusPin == HIGH)
    {
        Serial.print("Gerakan Terdeteksi");
    }
    else
    {
        Serial.print("Tidak ada Gerakan");
    }
}