#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "header.h"
//body
void body(){
	system("cls");
	printf("\t\t======================================\n");
	printf("\t\t\t   Selamat Datang\n");
	printf("\t\t======================================\n");
	char operasi;
	printf("\t\t1.Transaksi\n");
	printf("\t\t2.Cek Stok\n");
	printf("\t\t3.Laporan Keuangan\n");
	printf("\t\t4.Riwayat Transaksi\n");
	printf("\t\t5.Keluar\n");
	printf("\t\t======================================\n");
	printf("\t\tSilahkan pilih operasi dari yang ada di atas : ");scanf("%c",&operasi);
	
    switch(operasi){
    	case '1':
    		kasir();
    		break;
        case '2':
            listoperasi();
            break;
        case '3':
        	laporan();break;break;
        case '4':
        	history();break;
        case '5':
            keluar();break;
        default:
        	printf("\t\tInputan salah!");body();break;
    } 
}
void keluar(){
	system("cls");
			printf("\t\tSampai Jumpa Kembali :)\n");exit(0);
}

