#include <iostream> //Ambil dari PPT 
#include <malloc.h> // Rivanka Desya Fawwaz Assyiraaj
#define true 1 		//Praktikum struktur data D
#define false 0 

using namespace std				;
typedef int typeinfo			; 
typedef struct typenode *typeptr;
int node[9999]					;
struct typenode
	{
		
	typeinfo info; 		 
	typeptr next;
	
	}							; 
typeptr awal,akhir				; 

void buatlistbaru()				; 	
void sisipnode(typeinfo IB)		; 
void bacamaju()					; 
void bacamundur()				;
int listkosong()				;


int main() 
{ 	

	char ulang='y'				;
	int i=0						;
	buatlistbaru()				; 
		
	while(ulang=='y')
	{
	cout << endl << "masukan node yang akan disisip"	;
	cout << endl << "node : " 							; cin >> node[i] ;
	sisipnode(node[i])									;
	i++													;	
	cout << endl << "Ulang?(y/n) : "					; cin>>ulang	;	
	}
	system("CLS")										;
	cout << "========= HASIL SISIP =======" << endl		;
	bacamaju()											; 
	return 0											;
}

void buatlistbaru() //prototype untuk membuat list baru
{ 
	typeptr list		; 
	list	= NULL		; 
	awal	= list		; 
	akhir	= list		;
}


int listkosong() 
{  
	if(awal == NULL)     
	return(true)		;  
	else     
	return(false)		; 
}


void sisipnode(typeinfo IB) 
{ 
	typeptr NB, bantu						; //NB = Nilai Baru
	NB=(typenode *) malloc(sizeof(typenode)); 
	NB->info=IB								;
	 NB->next=NULL							; 
	 if ( listkosong() ) 
	 {  awal	= NB						;    
		akhir	= NB						; 
	 }
	  
	 else if (IB <= awal->info) // Sisip depan
	 { 
		 NB->next	= awal					;   
		 awal		= NB					; 
	 } 
	 else 
	 { 
	 
		bantu=awal							;
		while (bantu->next!=NULL && IB > bantu->next->info) 
	    bantu	= bantu->next				;   
	    NB->next=bantu->next				;// Sisip di tengah atau di belakang   
	    bantu->next = NB					; 
	    if (IB>akhir->info) 
	    akhir=NB							;
	} 
} 
 
 
 void bacamaju() 
 { 
	 typeptr bantu							; 
	 bantu=awal								; 
	 while (bantu!=NULL) 
	 { 
		 cout << " " << bantu->info 		; 
		 bantu = bantu->next				; 
	 } 
 }
