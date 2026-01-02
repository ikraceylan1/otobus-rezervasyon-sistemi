#include "otobus_rezervasyon.h"

// Otobus bilgileri
int otobus_id[5];
char otobus_guzergah[5][100];
char otobus_tarih[5][20];
char otobus_saat[5][10];
int otobus_toplam_koltuk[5];
int otobus_koltuklar[5][40];
float otobus_fiyat[5];
int otobus_sayisi = 0;

// Rezervasyon bilgileri
int rez_id[200];
char rez_yolcu[200][50];
char rez_telefon[200][15];
int rez_otobus_id[200];
int rez_koltuk_no[200];
int rez_aktif[200];
int rezervasyon_sayisi = 0;

void devam_et() {
    printf("\nDevam etmek icin Enter'a basin...");
    getchar();
    getchar();
}

void baslangic_verileri() {
    int i;
    
    // 1. Otobus
    otobus_id[0] = 1;
    strcpy(otobus_guzergah[0], "Istanbul - Ankara");
    strcpy(otobus_tarih[0], "10.12.2024");
    strcpy(otobus_saat[0], "09:00");
    otobus_toplam_koltuk[0] = 40;
    otobus_fiyat[0] = 450.0;
    for(i = 0; i < 40; i++) {
        otobus_koltuklar[0][i] = 0;
    }
    
    // 2. Otobus
    otobus_id[1] = 2;
    strcpy(otobus_guzergah[1], "Istanbul - Izmir");
    strcpy(otobus_tarih[1], "10.12.2024");
    strcpy(otobus_saat[1], "10:30");
    otobus_toplam_koltuk[1] = 40;
    otobus_fiyat[1] = 500.0;
    for(i = 0; i < 40; i++) {
        otobus_koltuklar[1][i] = 0;
    }
    
    // 3. Otobus
    otobus_id[2] = 3;
    strcpy(otobus_guzergah[2], "Ankara - Antalya");
    strcpy(otobus_tarih[2], "11.12.2024");
    strcpy(otobus_saat[2], "14:00");
    otobus_toplam_koltuk[2] = 40;
    otobus_fiyat[2] = 380.0;
    for(i = 0; i < 40; i++) {
        otobus_koltuklar[2][i] = 0;
    }
    
    // 4. Otobus
    otobus_id[3] = 4;
    strcpy(otobus_guzergah[3], "Istanbul - Bursa");
    strcpy(otobus_tarih[3], "11.12.2024");
    strcpy(otobus_saat[3], "08:00");
    otobus_toplam_koltuk[3] = 40;
    otobus_fiyat[3] = 180.0;
    for(i = 0; i < 40; i++) {
        otobus_koltuklar[3][i] = 0;
    }
    
    // 5. Otobus
    otobus_id[4] = 5;
    strcpy(otobus_guzergah[4], "Ankara - Izmir");
    strcpy(otobus_tarih[4], "12.12.2024");
    strcpy(otobus_saat[4], "11:00");
    otobus_toplam_koltuk[4] = 40;
    otobus_fiyat[4] = 420.0;
    for(i = 0; i < 40; i++) {
        otobus_koltuklar[4][i] = 0;
    }
    
    otobus_sayisi = 5;
}

void otobus_listele() {
    int i, j;
    int dolu, bos;
    
    printf("\n\n");
    printf("=================================================================\n");
    printf("                   OTOBUS SEFERLERI                        \n");
    printf("=================================================================\n\n");
    
    printf("%-5s %-25s %-12s %-8s %-10s %-10s\n", 
           "ID", "GUZERGAH", "TARIH", "SAAT", "BOS/TOP", "FIYAT");
    printf("-----------------------------------------------------------------\n");
    
    for(i = 0; i < otobus_sayisi; i++) {
        dolu = 0;
        for(j = 0; j < otobus_toplam_koltuk[i]; j++) {
            if(otobus_koltuklar[i][j] != 0) {
                dolu++;
            }
        }
        bos = otobus_toplam_koltuk[i] - dolu;
        
        printf("%-5d %-25s %-12s %-8s %d/%-9d %.2f TL\n", 
               otobus_id[i],
               otobus_guzergah[i],
               otobus_tarih[i],
               otobus_saat[i],
               bos,
               otobus_toplam_koltuk[i],
               otobus_fiyat[i]);
    }
}

void koltuk_goster(int id) {
    int i, bulundu = -1;
    
    for(i = 0; i < otobus_sayisi; i++) {
        if(otobus_id[i] == id) {
            bulundu = i;
            break;
        }
    }
    
    if(bulundu == -1) {
        printf("\nOtobus bulunamadi!\n");
        return;
    }
    
    printf("\n\n=================================================================\n");
    printf("                      KOLTUK DUZENI                          \n");
    printf("=================================================================\n");
    printf("  %s - %s %s\n", 
           otobus_guzergah[bulundu], 
           otobus_tarih[bulundu], 
           otobus_saat[bulundu]);
    printf("=================================================================\n\n");
    
    printf("                  [SOFOR]\n\n");
    
    for(i = 0; i < otobus_toplam_koltuk[bulundu]; i++) {
        if(i % 4 == 0 && i != 0) {
            printf("\n");
        }
        if(i % 4 == 2) {
            printf("  ");
        }
        
        if(otobus_koltuklar[bulundu][i] == 0) {
            printf(" [%2d] ", i + 1);
        } else {
            printf(" [XX] ");
        }
    }
    
    printf("\n\n  [ ] Bos Koltuk    [XX] Dolu Koltuk\n");
}

void yeni_rezervasyon() {
    int id, koltuk_no;
    char yolcu[50], telefon[15];
    int i, otobus_index = -1;
    
    printf("\n\n");
    otobus_listele();
    
    printf("\n\n=================================================================\n");
    printf("                    REZERVASYON YAP                          \n");
    printf("=================================================================\n");
    
    printf("\nOtobus ID: ");
    scanf("%d", &id);
    
    for(i = 0; i < otobus_sayisi; i++) {
        if(otobus_id[i] == id) {
            otobus_index = i;
            break;
        }
    }
    
    if(otobus_index == -1) {
        printf("\nHatali otobus ID!\n");
        devam_et();
        return;
    }
    
    koltuk_goster(id);
    
    printf("\n\nKoltuk No (1-%d): ", otobus_toplam_koltuk[otobus_index]);
    scanf("%d", &koltuk_no);
    
    if(koltuk_no < 1 || koltuk_no > otobus_toplam_koltuk[otobus_index]) {
        printf("\nHatali koltuk numarasi!\n");
        devam_et();
        return;
    }
    
    if(otobus_koltuklar[otobus_index][koltuk_no - 1] != 0) {
        printf("\nBu koltuk dolu!\n");
        devam_et();
        return;
    }
    
    printf("Yolcu Adi: ");
    scanf(" %[^\n]", yolcu);
    printf("Telefon: ");
    scanf("%s", telefon);
    
    rez_id[rezervasyon_sayisi] = rezervasyon_sayisi + 1;
    strcpy(rez_yolcu[rezervasyon_sayisi], yolcu);
    strcpy(rez_telefon[rezervasyon_sayisi], telefon);
    rez_otobus_id[rezervasyon_sayisi] = id;
    rez_koltuk_no[rezervasyon_sayisi] = koltuk_no;
    rez_aktif[rezervasyon_sayisi] = 1;
    
    otobus_koltuklar[otobus_index][koltuk_no - 1] = rez_id[rezervasyon_sayisi];
    rezervasyon_sayisi++;
    
    printf("\n\n=================================================================\n");
    printf("               REZERVASYON BASARILI!                         \n");
    printf("=================================================================\n");
    printf("\n  Rezervasyon No: %d\n", rez_id[rezervasyon_sayisi - 1]);
    printf("  Yolcu: %s\n", yolcu);
    printf("  Guzergah: %s\n", otobus_guzergah[otobus_index]);
    printf("  Tarih/Saat: %s %s\n", otobus_tarih[otobus_index], otobus_saat[otobus_index]);
    printf("  Koltuk: %d\n", koltuk_no);
    printf("  Tutar: %.2f TL\n", otobus_fiyat[otobus_index]);
    
    devam_et();
}

void iptal_et() {
    int id, i, j;
    int rez_index = -1;
    
    printf("\n\n");
    printf("=================================================================\n");
    printf("                  REZERVASYON IPTAL                          \n");
    printf("=================================================================\n");
    
    printf("\nRezervasyon No: ");
    scanf("%d", &id);
    
    for(i = 0; i < rezervasyon_sayisi; i++) {
        if(rez_id[i] == id && rez_aktif[i] == 1) {
            rez_index = i;
            break;
        }
    }
    
    if(rez_index == -1) {
        printf("\nRezervasyon bulunamadi!\n");
        devam_et();
        return;
    }
    
    for(i = 0; i < otobus_sayisi; i++) {
        if(otobus_id[i] == rez_otobus_id[rez_index]) {
            otobus_koltuklar[i][rez_koltuk_no[rez_index] - 1] = 0;
            break;
        }
    }
    
    rez_aktif[rez_index] = 0;
    
    printf("\nRezervasyon iptal edildi!\n");
    devam_et();
}

void rezervasyon_goster() {
    int i, j;
    int var_mi = 0;
    
    printf("\n\n");
    printf("=================================================================\n");
    printf("                  AKTIF REZERVASYONLAR                       \n");
    printf("=================================================================\n\n");
    
    printf("%-5s %-20s %-15s %-25s %-8s\n", 
           "NO", "YOLCU", "TELEFON", "GUZERGAH", "KOLTUK");
    printf("-----------------------------------------------------------------\n");
    
    for(i = 0; i < rezervasyon_sayisi; i++) {
        if(rez_aktif[i] == 1) {
            var_mi = 1;
            for(j = 0; j < otobus_sayisi; j++) {
                if(otobus_id[j] == rez_otobus_id[i]) {
                    printf("%-5d %-20s %-15s %-25s %-8d\n",
                           rez_id[i],
                           rez_yolcu[i],
                           rez_telefon[i],
                           otobus_guzergah[j],
                           rez_koltuk_no[i]);
                    break;
                }
            }
        }
    }
    
    if(var_mi == 0) {
        printf("\nHic rezervasyon yok.\n");
    }
    
    devam_et();
}

void verileri_kaydet() {
    FILE *dosya;
    int i, j;
    
    dosya = fopen("rezervasyon_verileri.txt", "w");
    
    if(dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }
    
    fprintf(dosya, "%d\n", rezervasyon_sayisi);
    
    for(i = 0; i < rezervasyon_sayisi; i++) {
        fprintf(dosya, "%d\n", rez_id[i]);
        fprintf(dosya, "%s\n", rez_yolcu[i]);
        fprintf(dosya, "%s\n", rez_telefon[i]);
        fprintf(dosya, "%d\n", rez_otobus_id[i]);
        fprintf(dosya, "%d\n", rez_koltuk_no[i]);
        fprintf(dosya, "%d\n", rez_aktif[i]);
    }
    
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 40; j++) {
            fprintf(dosya, "%d ", otobus_koltuklar[i][j]);
        }
        fprintf(dosya, "\n");
    }
    
    fclose(dosya);
}

void verileri_yukle() {
    FILE *dosya;
    int i, j;
    
    dosya = fopen("rezervasyon_verileri.txt", "r");
    
    if(dosya == NULL) {
        return;
    }
    
    fscanf(dosya, "%d", &rezervasyon_sayisi);
    
    for(i = 0; i < rezervasyon_sayisi; i++) {
        fscanf(dosya, "%d", &rez_id[i]);
        fscanf(dosya, " %[^\n]", rez_yolcu[i]);
        fscanf(dosya, "%s", rez_telefon[i]);
        fscanf(dosya, "%d", &rez_otobus_id[i]);
        fscanf(dosya, "%d", &rez_koltuk_no[i]);
        fscanf(dosya, "%d", &rez_aktif[i]);
    }
    
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 40; j++) {
            fscanf(dosya, "%d", &otobus_koltuklar[i][j]);
        }
    }
    
    fclose(dosya);
}

int main() {
    int secim;
    int id;
    
    baslangic_verileri();
    verileri_yukle();
    
    while(1) {
        printf("\n\n\n");
        printf("=================================================================\n");
        printf("              OTOBUS REZERVASYON SISTEMI                     \n");
        printf("=================================================================\n");
        printf("                                                                 \n");
        printf("    1. Otobusleri Goster                                        \n");
        printf("    2. Koltuk Durumunu Goster                                   \n");
        printf("    3. Rezervasyon Yap                                          \n");
        printf("    4. Rezervasyon Iptal Et                                     \n");
        printf("    5. Rezervasyonlari Goster                                   \n");
        printf("    0. Cikis                                                    \n");
        printf("                                                                 \n");
        printf("=================================================================\n");
        printf("\n  Seciminiz: ");
        scanf("%d", &secim);
        
        if(secim == 1) {
            otobus_listele();
            devam_et();
        } 
        else if(secim == 2) {
            otobus_listele();
            printf("\n\nOtobus ID: ");
            scanf("%d", &id);
            koltuk_goster(id);
            devam_et();
        } 
        else if(secim == 3) {
            yeni_rezervasyon();
            verileri_kaydet();
        } 
        else if(secim == 4) {
            iptal_et();
            verileri_kaydet();
        } 
        else if(secim == 5) {
            rezervasyon_goster();
        } 
        else if(secim == 0) {
            verileri_kaydet();
            printf("\n\n  Veriler kaydedildi. Programdan cikiliyor...\n\n");
            break;
        } 
        else {
            printf("\nHatali secim!\n");
            devam_et();
        }
    }
    
    return 0;
}
