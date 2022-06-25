#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "header.h"


void simpan(){
	time_t w; 
    time(&w);
    int day,month,year;
    struct tm *local = localtime(&w);
    day = local->tm_mday;  
    month = local->tm_mon + 1;     
    year = local->tm_year + 1900;
	FILE *fp;struct riwayat pengguna={0,"",0,"",0,0,0};
    struct riwayat client;

    if ( ( fp = fopen( "Laporan.dat", "ab+" ) ) == NULL ) {
        printf( "File tidak dapat dibuka\n" );
    }
    int i;
	for(i=0;i<banyakk;i++){
	if(arr[i].jumlahbeli==0) continue;
	pengguna.kode=arr[i].kode;
	strcpy(pengguna.benda,arr[i].benda);
	pengguna.jumlahbeli=arr[i].jumlahbeli;
	strcpy(pengguna.time,ctime(&w));
	pengguna.tgl=day;
	pengguna.bln=month;
	pengguna.thn=year;
    fwrite(&pengguna,sizeof(client),1,fp);
    }
    fclose( fp );
}

void history(){
	int tgl1=0,tgl2=32,bln1=0,bln2=13,thn1=1990,thn2=3000,banyakk=10;
	while (1){
	system("cls");
	int i;
    for(i=0;i<banyakk;i++){
    	arr[i].jumlahbeli=0;
    }
	FILE *fp;
    struct riwayat pengguna={0,"",0,"",0,0,0};
	if ( ( fp = fopen( "Laporan.dat", "rb" ) ) == NULL ) {
        printf( "File tidak dapat dibuka\n" );
    }
    printf( "%-6s|%-20s|%-10s|%-25s\n", "Kode", "Nama Barang","Jumlah", "waktu");
    int penanda=0;
      while ( !feof( fp ) ) { 
         fread( &pengguna, sizeof( struct riwayat ), 1, fp );
        if(pengguna.kode==penanda) continue;
        penanda=pengguna.kode;
         if ( pengguna.kode!=0 ) {
         	if(pengguna.tgl<=tgl2&&pengguna.tgl>=tgl1&&pengguna.bln<=bln2&&pengguna.bln>=bln1&&pengguna.thn<=thn2&&pengguna.thn>=thn1){
            int i;
            for(i=0;i<banyakk;i++){
            	if(pengguna.kode==arr[i].kode){
            		arr[i].jumlahbeli+=pengguna.jumlahbeli;
            		break;
				}
			}
			printf( "%-6d|%-20s|%-10d|%-25s", pengguna.kode, pengguna.benda,pengguna.jumlahbeli,pengguna.time);
        }
         }
      }
      printf("================================================================\n");
      printf("Rekapan barang terjual : \n");printf("========================================\n");
    for(i=0;i<banyakk;i++){
    	if(arr[i].jumlahbeli!=0){
    		printf( "|%-6d|%-20s|%-10d|\n", arr[i].kode, arr[i].benda,arr[i].jumlahbeli);
		}
    }printf("========================================\n");
    fclose( fp );
    printf("\n1.Cari riwayat\n2.Kembali ke menu utama\n3.Keluar: ");printf("\nMasukkan operasi yang akan dilakukan : ");
    char suruh;scanf("%c",&suruh);
    switch (suruh){
    	case '1':
    		printf("Input awal (dd mm yyyy) : ");
			scanf("%d %d %d",&tgl1,&bln1,&thn1);
			printf("Input akhir (dd mm yyyy) : ");
			scanf("%d %d %d",&tgl2,&bln2,&thn2);
			break;break;
		case '2':
			main();break;break;
		case '3':
			keluar();exit(0);
		default:
		printf("Masukan salah!!!");break; 
	}
	}
}
