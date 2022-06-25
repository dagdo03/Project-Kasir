#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "header.h"

void kurangstok(){
	FILE *fp;int i;
	struct barang pengguna={0,"",0,0,0,0,0,0};
	if ( ( fp = fopen( "Master.dat", "rb+" ) ) == NULL ) {
      printf( "File tidak dapat dibuka!\n" );
   	}else{
   		for(i=0;i<banyakk;i++){
   			pengguna.kode=arr[i].kode;
   			pengguna.jual=arr[i].jual;
   			pengguna.beli=arr[i].beli;
   			strcpy(pengguna.benda,arr[i].benda);
   			pengguna.banyak=arr[i].banyak-arr[i].jumlahbeli;
   			pengguna.totalbeli=arr[i].totalbeli+arr[i].jumlahbeli;
			fseek( fp, (pengguna.kode-1) * sizeof( struct barang), SEEK_SET );                
        	fwrite( &pengguna, sizeof( struct barang ), 1, fp );
		}
	   }fclose(fp);
}
