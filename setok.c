#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "header.h"

void setok(){
system("cls");
	FILE *fp; /* credit.dat file pointer */
   	struct barang pengguna={0,"",0,0,0,0,0,0};banyakk=0;
   	if ( ( fp = fopen( "Master.dat", "rb" ) ) == NULL ) {
      printf( "File tidak dapat dibuka!\n" );
   	}else { 
   		printf("|\t\t\t          DAFTAR BARANG\t\t\t             |\n");printf("==============================================================================\n");
   		printf( "|%-6s  |%-16s|%-16s   |%-16s   |%-10s|\n", " Kode", "  Nama Barang", "  Harga Beli", "  Harga Jual","  Stok");
   		int penanda=0;
      while ( !feof( fp ) ){ 
        fread( &pengguna, sizeof( struct barang ), 1, fp );
        if(pengguna.kode==penanda) continue;
        penanda=pengguna.kode;
		if (pengguna.kode != 0 ) {
            printf( "|  %-6d|%-16s|Rp %-16.2lf|Rp %-16.2lf|%-10d|\n", pengguna.kode,pengguna.benda,pengguna.beli,pengguna.jual,pengguna.banyak);
            arr[banyakk].kode=pengguna.kode;
            arr[banyakk].beli=pengguna.beli;
            arr[banyakk].jual=pengguna.jual;
            arr[banyakk].banyak=pengguna.banyak;
            arr[banyakk].totalbeli=pengguna.totalbeli;
            strcpy(arr[banyakk].benda,pengguna.benda);
            banyakk++;
         }
     	}
    }printf("==============================================================================");
      fclose( fp );
}

void hapus(){
	int i;
	system("cls");
	FILE *fp;
	struct barang pengguna={0,"",0,0,0,0,0,0};
	if ((fp = fopen( "Master.dat", "rb+" ) ) == NULL ) {
        printf( "File tidak dapat dibuka\n" );exit(0);
    }
	 while ( 1 ){ 
        printf( "Masukkan kode barang yang ingin dihapus (-1 untuk kembali ke menu utama) :  " );scanf( "%d", &pengguna.kode );
		if(pengguna.kode==-1){
			fclose(fp);main();break;
		} 
        fseek( fp, (pengguna.kode-1) * sizeof( struct barang), SEEK_SET );
		pengguna.kode=0;
        pengguna.beli=0;
        pengguna.jual=0;
        pengguna.banyak=0;
        strcpy(pengguna.benda,"");            
        fwrite( &pengguna, sizeof( struct barang ), 1, fp );
    }
    fclose( fp );
}
