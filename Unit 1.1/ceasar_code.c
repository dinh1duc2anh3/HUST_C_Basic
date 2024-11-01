#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void ma_hoa(FILE *tap_tin_nguon, FILE *tap_tin_dich, int dich_chuyen, int vong_tron) {
    char ky_tu;
    while ((ky_tu = fgetc(tap_tin_nguon)) != EOF) {
        if (isalpha(ky_tu)) {
            if (islower(ky_tu)) {
                ky_tu = 'a' + (ky_tu - 'a' + dich_chuyen) % 26;
                if (vong_tron)
                    ky_tu = ((ky_tu - 'a' + 26) % 26) + 'a';
            } else if (isupper(ky_tu)) {
                ky_tu = 'A' + (ky_tu - 'A' + dich_chuyen) % 26;
                if (vong_tron)
                    ky_tu = ((ky_tu - 'A' + 26) % 26) + 'A';
            }
        }
        fputc(ky_tu, tap_tin_dich);
    }
}

void giai_ma(FILE *tap_tin_nguon, FILE *tap_tin_dich, int dich_chuyen, int vong_tron) {
    ma_hoa(tap_tin_nguon, tap_tin_dich, -dich_chuyen, vong_tron);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Su dung: %s <tap_tin_nguon> <dich_chuyen> <tap_tin_dich>\n", argv[0]);
        return 1;
    }

    char *tap_tin_nguon = argv[1];
    int dich_chuyen = atoi(argv[2]);
    char *tap_tin_dich = argv[3];

    FILE *tập_tin_nguồn = fopen(tap_tin_nguon, "r");
    if (tập_tin_nguồn == NULL) {
        perror("Loi khi mo tap tin nguon");
        return 1;
    }

    FILE *tập_tin_dich = fopen(tap_tin_dich, "w");
    if (tập_tin_dich == NULL) {
        perror("Loi khi mo tap tin dich");
        fclose(tập_tin_nguồn);
        return 1;
    }

    if (dich_chuyen > 0) {
        ma_hoa(tập_tin_nguồn, tập_tin_dich, dich_chuyen, 1);
        printf("Ma hoa thanh cong voi dich chuyen %d\n", dich_chuyen);
    } else {
        giai_ma(tập_tin_nguồn, tập_tin_dich, -dich_chuyen, 1);
        printf("Giai ma thanh cong voi dich chuyen %d\n", -dich_chuyen);
    }

    fclose(tập_tin_nguồn);
    fclose(tập_tin_dich);

    return 0;
}