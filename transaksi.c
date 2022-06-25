#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "header.h"

void kasir(){
	int jumlah,i,total=0,banrang=0,bayar=0,kembalian=0;
	FILE *fp;
	struct barang pengguna={0,"",0,0,0,0,0,0};
	if ( ( fp = fopen( "Master.dat", "rb" ) ) == NULL ) {
      printf( "File tidak dapat dibuka!\n" );
   	}else{
   		while(1){
		   	setok();int kodebeli;
		   	printf("\n1.Masukkan kode barang yang ingin dibeli (-1 untuk mengahiri input barang) : ");scanf("%d",&kodebeli);
   			if(kodebeli==-1){
   				fclose(fp);
   				break;
			   }
   		else{
   			int indeks;
   			for(i=0;i<banyakk;i++){
   			if(arr[i].kode==kodebeli){
   				indeks=i;break;
			}
		   }
			printf("\nMasukkan jumlah barang : ");scanf("%d",&arr[indeks].jumlahbeli);
   			total+=arr[indeks].jual*arr[indeks].jumlahbeli;
		}
	}
	while(1){
		printf("\nTotal pembelanjaan adalah Rp %d",total);
		printf("\nMasukkan uang pembayaran : ");scanf("%d",&bayar);
		kembalian=bayar-total;
		if(bayar<total){
			printf("Uang tidak cukup!");continue;
		}
		printf("\nUang kembalian sebesar Rp %d",kembalian);break;
	}
	}fclose(fp);kurangstok();simpan();
		char satudua;printf("\nTekan 1 untuk kembali ke menu utama\nTekan 2 untuk cetak struk\nTekan 3 untuk keluar\nMasukkan operasi : ");
		getchar();scanf("%c",&satudua);
		switch(satudua){
			case '1':
				main();break;break;
			case '2':
				struk(total,bayar,kembalian);;break;
			case '3':
				keluar();break;
			default:
				printf("Inputan Salah!!");break;
	}
	
}



