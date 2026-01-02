Otobüs Rezervasyon Sistemi (C Programlama)
Marmara Üniversitesi Bilgisayar Programcılığı bölümü kapsamında geliştirdiğim bu proje, temel C programlama prensiplerini kullanarak çalışan bir otobüs bilet rezervasyon otomasyonudur.

Projenin Amacı
Bu çalışma; dinamik veri yönetimi, dosya işlemleri ve algoritmik düşünme becerilerini pekiştirmek amacıyla tasarlanmıştır. Kullanıcıların terminal üzerinden koltuk seçimi yapabilmesine ve bu verilerin kalıcı olarak saklanmasına olanak tanır.

Kullanılan Teknolojiler ve Yapılar
Dil: C

Dosya Yönetimi: Kayıtların rezervasyon_verileri.txt dosyası üzerinde tutulması ve okunması

Modüler Yapı: Fonksiyonların ve tanımlamaların .h (header) dosyalarıyla organize edilmesi

Algoritmalar: Koltuk doluluk kontrolü ve kullanıcı yetkilendirme mantığı

Özellikler
Otobüs seferlerini ve koltuk şemasını görüntüleme.

Boş koltuklar için yolcu kaydı oluşturma.

Mevcut rezervasyonları dosya tabanlı sistem üzerinden sorgulama ve güncelleme.

Hata yönetimi (hatalı girişleri engelleme).

Dosya Yapısı
mainim2.c: Programın ana döngüsü ve temel mantığı.

otobus_rezervasyon.h: Gerekli kütüphaneler ve fonksiyon prototipleri.

rezervasyon_verileri.txt: Verilerin kalıcı olarak saklandığı veri deposu.