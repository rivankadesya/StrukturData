#include <iostream> 	//Rivanka Desya Fawwaz Assyiraaj//
#define max 12		   // 123190018 Prak.Strukdat (D)  //
#define true 1
#define false 0

using std::cout;
using std::endl;

typedef struct{
	
int info	; 
int next	; 

}typenode	;

typenode elemen[max];

int list,akhirlist,kosong,akhirkosong	;
int listkosong()						;
void buatlist()							;
void sisipnode(int IB)					;
void hapusnode(int IH)					;
void hapusnodeblkg(int IH)				;
void hapusnodetgh(int IH)				;
void cetaklist()						;

int main()
{ 
buatlist()					;
cetaklist()					;
sisipnode(7)				;
cout << "\n\n Sisip 7 \n\n"	;
cetaklist()					;
sisipnode(30)				;
cout << "\n\n sisip 30 \n\n";
cetaklist()					;
hapusnode(7)				;
cout << "\n\n hapus 7 \n\n"	;
cetaklist()					;
hapusnodeblkg(60)			;
cout << "\n\n hapus 60 \n\n";
cetaklist()					;
hapusnodetgh(25)			;
cout << "\n\n hapus 25 \n\n";
cetaklist()					;
}


void buatlist(){ 

	list		=5		;
	kosong		=3		;
	akhirlist	=10		;
	akhirkosong	=4		;
	elemen[1].info=25	; elemen[1].next=8;
	elemen[2].info=0 	; elemen[2].next=9;
	elemen[3].info=0	; elemen[3].next=6;
	elemen[4].info=0	; elemen[4].next=0;
	elemen[5].info=10	; elemen[5].next=7;
	elemen[6].info=0	; elemen[6].next=2;
	elemen[7].info=15	; elemen[7].next=1;
	elemen[8].info=40	; elemen[8].next=10;
	elemen[9].info=0	; elemen[9].next=4;
	elemen[10].info=60	; elemen[10].next=0;
	
}


int listkosong(){
	
	if (list==0)
	return(true)	;
	
	else
	return(false)	;

}


void sisipnode(int IB){ 

	int listbaru,k,m,n,x;
	
	if(IB<elemen[list].info){				//-------------------------- sisip di awal
		
	listbaru				= kosong				;
	kosong					= elemen[kosong].next	;
	elemen[listbaru].info	= IB					;
	elemen[listbaru].next	= list					;
	list					= listbaru				;
	
	}
	else if(IB>elemen[akhirlist].info){ 	//-------------------------sisip di akhir
	
	listbaru				= kosong				;
	kosong					= elemen[kosong].next	;
	elemen[listbaru].info	= IB					;
	elemen[listbaru].next	= 0						;
	elemen[akhirlist].next	= listbaru				;
	akhirlist				= listbaru				;
	
	}
	else{									//--------------------------sisip di tengah
	
	n	= list				;
	x	= elemen[n].info	;
	
	while(IB>x)
	{
		m	= n					;
		n	= elemen[n].next	;
		x	= elemen[n].info	;
	
	}	
	
	k					= elemen[kosong].next	;
	elemen[m].next		= kosong				;
	elemen[kosong].info	= IB					;
	elemen[kosong].next	= n						;
	kosong				= k						;
}
}



void cetaklist(){ 

	int n,m					;
	n=list					;
	m=kosong				;
	cout << "isi list : \n"	;
	
	do{
		
		cout << elemen[n].info << " "	;
		n=elemen[n].next				;
	
	}
	while (elemen[n].next!=0);
	
	cout << " "<< elemen[akhirlist].info << endl	;
	cout << "\nIndex tempat-tempat kosong: \n"		;
	
	do{
		
		cout << m << " ";
		m=elemen[m].next;
	
	
	}
	while(elemen[m].next!=0);
	
	cout << " " << akhirkosong;

}

void hapusnode(int IH) //------------------------ hapus di awal
{
	
	int listbaru,k;
	
	if(IH == elemen[list].info){
		
		listbaru			= elemen[list].next	; 
		k					= kosong			; 
		kosong				= list				; 
		list				= listbaru			;
		elemen[kosong].next	= k					;
		
	}

}

void hapusnodeblkg(int IH) //------------------------ hapus di akhir
{
	
	if(IH == elemen[akhirlist].info){
		
		
		elemen[akhirlist].next	= kosong	; 
		kosong					= akhirlist	; 
		  
		int listbaru=list;
		
		while(elemen[listbaru].next!=akhirlist){
			
		  listbaru = elemen[listbaru].next	;
		  
		}

	  if(elemen[listbaru].next == akhirlist){
	  	
		elemen[listbaru].next 	= 0			;
		akhirlist				= listbaru	;
		
		}
		
  	}
  
}

void hapusnodetgh(int IH){ //------------------------ hapus di tengah
	
	int index_tengah, next_tengah	;
		int listbaru=list			;
		
		while(elemen[listbaru].info!= IH /* && elemen[listbaru].next!=0 */){   //fungsi yang di bintang jika program di jalankan secara dinamis agar tidak eror namun jika dipakaipun tetap bisa di jalankan//
			
			listbaru = elemen[listbaru].next;
		
		}  
		
		if(elemen[listbaru].info== IH){
			
			index_tengah			= listbaru				;
			next_tengah 			= elemen[listbaru].next	;
			elemen[listbaru].next	= kosong				;
			kosong					= listbaru				;
			listbaru 				= list					;
			
			while(elemen[listbaru].next!=index_tengah){
				
				listbaru			= elemen[listbaru].next	;
				
			}
			
			elemen[listbaru].next	= next_tengah			;
		}
}
