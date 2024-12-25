//Proje kodları

#include <Servo.h>  // Servo kütüphanesini ekler

// Servo motor tanımlamaları
Servo servo1; // Birinci servo motor tanımlanır
Servo servo2; // İkinci servo motor tanımlanır
• const int trigPin1 = 2;// Birinci sensör için TRIG pini
• const int echoPin1 = 3; // Birinci sensör için ECHO pini
• const int trigPin2 = 11; // İkinci sensör için TRIG pini
• const int echoPin2 = 12;// İkinci sensör için ECHO pini
• const int alarm = 6;// Alarm pini
• const int kirmizi = 4; // Kırmızı LED pini
• const int yesil = 5; // Yeşil LED pini


void setup() {
// Servo motorları başlat
servo1.attach(9);  // Birinci servo motor 9. pine bağlanır
servo2.attach(10) ; // İkinci servo motor 10. pine bağlanır
pinMode(trigPin1, OUTPUT); // Birinci sensör için TRIG pini çıkış olarak ayarlanır
pinMode(echoPin1, INPUT); // Birinci sensör için ECHO pini giriş olarak ayarlanır
pinMode(trigPin2, OUTPUT); // İkinci sensör için TRIG pini çıkış olarak ayarlanır
pinMode(echoPin2, INPUT); // İkinci sensör için ECHO pini giriş olarak ayarlanır
pinMode(alarm, OUTPUT); // Alarm pini çıkış olarak ayarlanır
pinMode(kirmizi, OUTPUT); // Kırmızı LED pini çıkış olarak ayarlanır
pinMode(yesil, OUTPUT); // Yeşil LED pini çıkış olarak ayarlanır


// Başlangıçta bariyerler kapalı 0 derece
servo1.write(0); // Birinci servo motor 0 dereceye ayarlanır
servo2.write(0); // İkinci servo motor 0 dereceye ayarlanır
Serial.begin(9600); // Seri iletişim başlatılır
}

void loop() {
long sure1, mesafe1, sure2, mesafe2; // Zaman ve mesafe değişkenleri tanımlanır
// Sensör 1 için mesafe ölçümü
sure1 = mesafeOlc(trigPin1, echoPin1); // Birinci sensörün mesafesi ölçülür
mesafe1 = (sure1 / 2) / 29.1; // Birinci sensörün mesafesi cm cinsine çevrilir
// Sensör 2 için mesafe ölçümü
sure2 = mesafeOlc(trigPin2, echoPin2); // İkinci sensörün mesafesi ölçülür
mesafe2 = (sure2 / 2) / 29.1; // İkinci sensörün mesafesi cm cinsine çevrilir
// Sensör 1 için kontrol
servoKontrol1(servo1, mesafe1); // Birinci servo motorun kontrolü yapılır
// Sensör 2 için kontrol
servoKontrol2(servo2, mesafe2); // İkinci servo motorun kontrolü yapılır
delay(50); // Döngü gecikmesi
}
void servoKontrol1(Servo &servo, long mesafe) // belirli bir mesafeye göre servoyu ve LED'leri kontrol
eder
{
if (mesafe < 10) { // Mesafe 10 cm'den küçükse
servo.write(90); // Servo motor 90 dereceye ayarlanır
digitalWrite(yesil, HIGH); // Yeşil LED yakılır
digitalWrite(alarm, HIGH); // Alarm çalıştırılır
digitalWrite(kirmizi, LOW); // Kırmızı LED söndürülür
tone(alarm, 1000); // Alarm pininde 1000 HZ frekansında ses üretilir
delay(5000); // 5 saniye beklenir
noTone(alarm); // Alarm sesi durdurulur
} else {
servo.write(0); 
digitalWrite(yesil, LOW); 
digitalWrite(kirmizi, HIGH); // Servo motor 0 dereceye ayarlanır
// Yeşil LED söndürülür
// Kırmızı LED yakılır
}
}
void servoKontrol2(Servo &servo, long mesafe) //belirli bir mesafeye göre servoyu
ve LED'leri kontrol eder
{
if (mesafe < 10) { // Mesafe 10 cm'den küçükse
servo.write(90); // Servo motor 90 dereceye ayarlanır
delay(5000); // 5 saniye beklenir
} else {
servo.write(0); // Servo motor 0 dereceye ayarlanır
}
}
