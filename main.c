// Esma Tayfur
// 2420161040
// https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=Yx1h8497ax

#include <stdio.h>

int ikili_arama(int dizi[], int BOYUT, int search, int ilk_ind, int son_ind) {
    int orta_ind = (ilk_ind + son_ind) / 2;
    if (search == dizi[orta_ind]) {
        return orta_ind;
    }
    else if (search > dizi[orta_ind] && (son_ind - ilk_ind) > 0) {
        return ikili_arama(dizi, BOYUT, search, orta_ind + 1, son_ind);
    }
    else if (search < dizi[orta_ind] && (son_ind - ilk_ind) > 0) {
        return ikili_arama(dizi, BOYUT, search, ilk_ind, orta_ind - 1);
    }
    else {
        return -1;
    }
}

void dizi_yazdir(int dizi[], int BOYUT) {
    int i;
    for (i = 0; i < BOYUT; i++) {
        printf("%3d ", dizi[i]);
    }
    printf("\n");
}

void takas(int *ap, int *bp) {
    int gecici = *ap;
    *ap = *bp;
    *bp = gecici;
}

int indis_min_hesapla(int dizi[], int BOYUT, int bas_ind) {
    int i;
    int min_eleman = dizi[bas_ind];
    int min_ind = bas_ind;

    for (i = bas_ind + 1; i < BOYUT; i++) {
        if (dizi[i] < min_eleman) {
            min_eleman = dizi[i];
            min_ind = i;
        }
    }
    return min_ind;
}

void secmeli_sirala(int dizi[], int BOYUT) {
    int i;        
    int ind_min;  

    printf("\n--- Siralama Adimlari ---\n");
    for (i = 0; i < BOYUT - 1; i++) { 
        ind_min = indis_min_hesapla(dizi, BOYUT, i);
        takas(dizi + i, dizi + ind_min);
        printf("iter.%2d: ", i + 1);
        dizi_yazdir(dizi, BOYUT);
    }
    printf("-------------------------\n");
}

int main() {
    int A[] = {12, 47, 55, 8, 7, 15, 3, 99, 25, 32};
    int N = sizeof(A) / sizeof(A[0]);
    int aranan, sonuc;
    printf("Orijinal (Siralanmamis) Dizi:\n");
    dizi_yazdir(A, N);

    secmeli_sirala(A, N); 

    printf("\nSonuc (Siralanmis) Dizi:\n");
    dizi_yazdir(A, N);

    printf("\nAramak istediginiz sayi: ");
    scanf("%d", &aranan);

    sonuc = ikili_arama(A, N, aranan, 0, N - 1);

    if (sonuc == -1) {
        printf("Sonuc: Aradiginiz deger %d, dizide BULUNAMADI!\n", aranan);
    } else {
        printf("Sonuc: Aradiginiz deger %d, dizinin %d. indisinde BULUNDU!\n", aranan, sonuc);
    }

    return 0;
}
