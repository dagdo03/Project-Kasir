#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "header.h"

void listoperasi(){
	system("cls");
	char opt[10];
	printf("1.Tambah Barang\n2.Tampilkan Stok\n3.Kembali ke Menu Utama\n4.Exit\n");
	printf("Masukkan operasi yang diinginkan : ");scanf("%s",opt);
	if(strcmp(opt,"1")==0) masukan();
	else if(strcmp(opt,"2")==0) keluaran();
	else if(strcmp(opt,"3")==0){
		system("cls");body();
		
	} 
	else if(strcmp(opt,"4")==0){
		system("cls");
		printf("\t\tSampai Jumpa Kembali :)\n");exit(0);
	}
	
}
void masukan(){
	int i;
	system("cls");
	FILE *fp;
	struct barang pengguna={0,"",0,0,0,0,0,0};
	if ((fp = fopen( "Master.dat", "rb+" ) ) == NULL ) {
        printf( "File tidak dapat dibuka\n" );exit(0);
    }
	 while ( 1 ) { 
        printf( "Masukkan kode barang(0 untuk kembali ke menu utama) :  " );scanf( "%d", &pengguna.kode );
        if(pengguna.kode == 0){
        	printf("\nBarang sukses ditambahkan!");fclose( fp );main();
		} 
        printf( "Masukkan nama barang : " );scanf( "%s", pengguna.benda);
        printf("Masukkan harga beli barang : ");scanf("%lf",&pengguna.beli);
        printf("Masukkan harga jual barang : ");scanf("%lf",&pengguna.jual);
        printf("Masukkan banyak barang : ");scanf("%d",&pengguna.banyak);
        fseek( fp, (pengguna.kode-1) * sizeof( struct barang), SEEK_SET );                
        fwrite( &pengguna, sizeof( struct barang ), 1, fp );
    }
    fclose( fp );
}
void keluaran(){
	system("cls");
	FILE *fp; /* credit.dat file pointer */
   	struct barang pengguna={0,"",0,0,0,0,0,0};
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
         }
     	}
    }printf("==============================================================================");
      fclose( fp );char ahir;printf("\n1.Hapus\n2.Tambah\n3.Kembali\n4.Keluar\nMasukkan operasi yang diinginkan : ");getchar();scanf("%c",&ahir);
      switch(ahir){
      	case '1':
      		hapus();break;
      	case '2':
      		masukan();break;
      	case '3':
      		listoperasi();break;
      	case '4':
      		keluar();exit(0);
      	default:
      		printf("\nMasukkan salah!");break;
	  }
}

