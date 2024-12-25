# Sensorlu-Bariyer-Sistemi
Batman Üniversitesi Sensörler ve Dönüştürücüler Proje Ödevi 2024

# Çalışma mantığı

HC-sr04(ultrasonik mesafe sensörü) sensörünün gelen araçları ses dalgaları sayesinde algılayıp kontrolere uyarı gönderir, kontrolörde servo motordan uygun açı değerine göre hareket etmesini ister ve bariyer açılıp 5 saniyelik bir geçiş süresi tanır ardındanda tekrar kapanır bariyer açık olduğunda sesli uyarı verilir ve yeşil ışık yanar kapalı olduğunda ise kırmızı ışık yanar

# KULANILAN MALZEMELER 

- HC-sr04 sensörü
- Direnç
- Led lambalar
- Bağlantı kabloları(jumper kablo)
- Buzzer
- Breadboard
- Servo-sg90 motor

# MALZEME DETAYLARI

**HC-sensörü**

**Ses dalgası yayılır=** Sensör trig pininden 40 khz frekansına ses dalgaları yayar

**Dalgalar nesneye çarpışır=** Ses dalgaları nesneye çarpıp geri döner
Dalgalar iade edilir=sensör echo pininden geri dönüş süresini ölçer

**Mesafe hesaplanır=** Sesin havadaki hızı ve dönüş süresi kulanılarak mesafe hesaplanır

**Buzzer=** Ses üreten bir sinyal cihazıdır bu projede bariyer açık olduğu anda sesli uyarı verir 

**Led lambalar=** Adından da anlaşılacağı üzere akımın yanlızca bir yönden geçmesini sağlayan bir diyot türüdür

**Servo sg90 motor=** Bu motor 0 ile 180 derece arasında hareket edebilir ve hasas komutlandırma gerektiren uygulamalarda tercih edilir robotik ve otomasyon projelerinde sıkça tercih edilir
