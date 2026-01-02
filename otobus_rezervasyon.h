#ifndef OTOBUS_REZERVASYON_H
#define OTOBUS_REZERVASYON_H

#include <stdio.h>
#include <string.h>

// ------------------------------------
// GLOBAL DEGISKEN TANIMLARI (extern ile erisim saglanir)
// ------------------------------------

// Otobus bilgileri
extern int otobus_id[5];
extern char otobus_guzergah[5][100];
extern char otobus_tarih[5][20];
extern char otobus_saat[5][10];
extern int otobus_toplam_koltuk[5];
extern int otobus_koltuklar[5][40];
extern float otobus_fiyat[5];
extern int otobus_sayisi;

// Rezervasyon bilgileri
extern int rez_id[200];
extern char rez_yolcu[200][50];
extern char rez_telefon[200][15];
extern int rez_otobus_id[200];
extern int rez_koltuk_no[200];
extern int rez_aktif[200];
extern int rezervasyon_sayisi;

void devam_et();
void baslangic_verileri();
void otobus_listele();
void koltuk_goster(int id);
void yeni_rezervasyon();
void iptal_et();
void rezervasyon_goster();

void verileri_kaydet();
void verileri_yukle();

#endif
