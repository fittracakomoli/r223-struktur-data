#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct tree *pohon;
/* Deklarasi dari tree dengan menggunakan linked list */
struct tree{
 char info;
 pohon kiri;
 pohon kanan;
}; 

/* Fungsi untuk membuat simpul yang pertama */
pohon baru(char hrf)
{
 pohon br;
 br=(pohon)malloc(sizeof(struct tree));
 br->info=hrf;
 br->kiri=NULL;
 br->kanan=NULL;
 return (br);
} 

/*
Fungsi untuk menyisipkan simpul pada tree yang sudah dibangun
*/
void sisip (pohon ph, pohon sp)
{
 pohon P,Q;
 P = ph;
 Q = ph;
 while((sp->info != ph->info)&&(Q!=NULL))
 {
 P = Q;
 if (sp->info < P->info)
 Q = P->kiri;
 else
 Q = P->kanan;
 }
 if(sp->info == P->info)
 printf("Sudah ada");
 else
 if(sp->info < P->info)
 P->kiri=sp;
 else
 P->kanan=sp;
} 

/*
Fungsi-fungsi untuk metode traversal secara rekursif
*/
void preorder(pohon ph)
{
 if (ph != NULL)
 {
 printf("%c ", ph->info);
 preorder(ph->kiri);
 preorder(ph->kanan);
 }
}
void inorder(pohon ph)
{
 if (ph != NULL)
 {
 inorder(ph->kiri);
 printf("%c ", ph->info);
 inorder(ph->kanan);
 }
}
void postorder(pohon ph)
{
 if (ph != NULL)
 {
 postorder(ph->kiri);
 postorder(ph->kanan);
 printf("%c ", ph->info);
 }
} 


int main(){
    int j=0;char input,jawab[2];
    pohon br, ssp;

    while(true){
        printf("\nKetikkan huruf :");scanf("%c",&input);
        fflush(stdin);
        if (j==0){ 
            br = baru(input); 
        } else {
        ssp = baru(input);
        sisip(br,ssp);
        }
        printf("Ada data lagi(y/t):"); scanf("%s",&jawab);
        fflush(stdin);


        if((strcmp(jawab,"Y")==0)||(strcmp(jawab,"y")==0)){
            j++;continue;
        } else if((strcmp(jawab,"Y")==0)||(strcmp(jawab,"y")==0)){
            break;
        }
        preorder(br); printf("\n");
        inorder(br); printf("\n");
        postorder(br); 
    }           
           
           
           
    return 0;
}