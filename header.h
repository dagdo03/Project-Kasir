#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int banyakk;
struct barang{
	int kode;
	char benda[25];
	double beli;
	double jual;
	double modal;
	int banyak;
	int jumlahbeli;
	int totalbeli;
};
struct riwayat{
	int kode;
	char benda[25];
	int jumlahbeli;
	char time[30];
	int tgl;
	int bln;
	int thn;
};
struct barang arr[100];
void history();
void hapus();
void laporan();
void pilih();
void keluar();
void body();
void listoperasi();
void masukan();
void keluaran();
void kasir();
void setok();
void kurangstok();
void struk();
