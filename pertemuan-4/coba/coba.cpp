#include<stdio.h>
#include<string.h>
struct dtnilai
{
	char nrp[10];
	char nama[20];
	double nilai;
	dtnilai *next;
};
struct dtnilai *ujung, *tampung,*cur;

void sisip_awal_LIFO()
{
	//dtnilai *tampung;
	int j=0;char jawab[2];
	while(1)
	{
		ujung=new dtnilai();
		fflush(stdin);
		printf("NRP :");scanf("%s",&ujung->nrp);
		printf("Nama :");scanf("%s",&ujung->nama);
		printf("Nilai Test :");scanf("%lf",&ujung->nilai);
		if(j==0)
		{
			ujung->next=NULL;
			tampung=ujung;
		}
		else
		{
			ujung->next=tampung;
			tampung=ujung;
		}
		printf("Ada data lagi(y/t):"); scanf("%s",&jawab);
		if((strcmp(jawab,"Y")==0)||(strcmp(jawab,"y")==0))
		{
			j++;continue;
		}
		else if ((strcmp(jawab,"T")==0)||(strcmp(jawab,"t")==0))
		break;
	}

}
void cetak_data(){
	cur=ujung;
	while (cur != NULL){
	printf("===============\n");
	printf("NRP : %s\n",cur->nrp);
	printf("Nama : %s\n",cur->nama);
	printf("Nilai Test : %lf\n",cur->nilai);
	cur=cur->next;
}
}
int main(){
	sisip_awal_LIFO();
	cetak_data();
}