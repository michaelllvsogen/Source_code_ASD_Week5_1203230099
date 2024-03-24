#include <stdio.h>

// Definisi struktur untuk menyimpan tanggal
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Fungsi untuk menentukan apakah suatu tahun adalah tahun kabisat
int leapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Tahun kabisat
    } else {
        return 0; // Bukan tahun kabisat
    }
}

// Fungsi untuk menentukan jumlah hari dalam bulan tertentu
int monthDay(int month, int year) {
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (leapYear(year)) {
                return 29; // Februari pada tahun kabisat
            } else {
                return 28; // Februari pada tahun biasa
            }
        default:
            return -1; // Input bulan tidak valid
    }
}

// Fungsi untuk menambahkan satu hari ke tanggal yang diberikan
void add_one_day(Date *date) {
    date->day++;
    if (date->day > monthDay(date->month, date->year)) {
        date->day = 1;
        date->month++;
        if (date->month > 12) {
            date->month = 1;
            date->year++;
        }
    }
}

int main() {
    // Deklarasi dan inisialisasi tanggal
    Date date = {0};

    // Input tanggal
    printf("Input tanggal (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &date.day, &date.month, &date.year);

    // Menambahkan satu hari
    add_one_day(&date);

    // Output tanggal setelah satu hari
    printf("Tanggal setelah satu hari: %d/%d/%d\n", date.day, date.month, date.year);

    return 0;
}