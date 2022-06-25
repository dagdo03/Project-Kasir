#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "header.h"

void laporan(){
	system("cls");int modal=0,pendapatan=0,banyakk=0,i,laba=0;
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
            modal+=(arr[banyakk].banyak+arr[banyakk].totalbeli)*arr[banyakk].beli;
            pendapatan+=arr[banyakk].totalbeli*arr[banyakk].jual;
            laba=pendapatan-modal;
            
            banyakk++;
         }
     	}
	}printf("==============================================================================");fclose( fp );
	printf("\nModal = Rp %d",modal);
    printf("\nPendapatan = Rp %d",pendapatan);
    printf("\nlaba : %d",laba);
    if(laba<modal) printf("\nStatus : RUGI!!\n");
	else printf("\nUntung!!");
	printf("\n1.Kembali ke menu utama\n2.Keluar");getchar();printf("\nMasukkan operasi yang akan dilakukan : ");
	char opkeuangan;scanf("%c",&opkeuangan);
	switch(opkeuangan){
		case '1':
			main();break;
		case '2':
			keluar();break;
	}  
}
  
            
        
    

