#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "header.h"

void struk(int total,int bayar,int kembalian){
	time_t w;int i; 
    time(&w);
	FILE *ptr;
    ptr=fopen("Struk.txt","w");
	fprintf(ptr,"||==========================================================||\n");
	fprintf(ptr,"||                                                          ||\n");
	fprintf(ptr,"||		      TERIMA KASIH	                    ||\n");
	fprintf(ptr,"||                                                          ||\n");
	fprintf(ptr,"||==========================================================||\n");
	fprintf(ptr,"||Nama                |    Banyak barang      |    Total    ||\n");
	for(i=0;i<banyakk;i++){
        if(arr[i].jumlahbeli==0) continue;
        fprintf(ptr,"||%-20s|          %-10d   | Rp %.2lf||\n",arr[i].benda,arr[i].jumlahbeli,arr[i].jual*arr[i].jumlahbeli);
    }
    fprintf(ptr,"||==========================================================||\n");
    fprintf(ptr,"||Total   : Rp %d\t\t\t\t\t    ||\n",total);
    fprintf(ptr,"||Uang    : Rp %d\t\t\t\t\t    ||\n",bayar);
    fprintf(ptr,"||Kembali : Rp %d\t\t\t\t\t    ||\n",kembalian);
    fprintf(ptr,"||==========================================================||\n");
    fprintf(ptr,"||    		%s",ctime(&w));fprintf(ptr,"||\n");
    fprintf(ptr,"||                                                          ||\n");
    fprintf(ptr,"||==========================================================||\n");
    fclose(ptr);printf("Struk berhasil dicetak!");printf("\ntekan enter untuk kembali ke menu utama ");getchar();main();
}
