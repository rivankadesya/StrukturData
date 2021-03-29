#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include <malloc.h>
#include <string.h>

using namespace std;
 
// Konfigurasi untuk Stack dan Queue menggunakan Linked List
typedef struct typequeue *typeptrqueue;
typedef struct typestack *typeptrstack;

struct typequeue{
    string nama,warna	;
    int jumlah			;
    typeptrqueue next	;
};
struct typestack{
    string warna		;
    typeptrstack next	;
};

typeptrqueue awaltamu, akhirtamu, awalantri, akhirantri		;
typeptrstack awalmeja, akhirmeja, awalkardus, akhirkardus	;
void menu()													;
void buat_stack()											;
void buat_queue()											;
void entamu(string nama , int jumlah , string warna)		;
void enantrian(string nama , int jumlah , string warna)		;
void cetak_tamu()											;
void cetak_antri()											;
void detamu()												;
void deantri()												;
bool tamu_kosong()											;
bool antri_kosong()											;
bool meja_kosong()											;
void keluar()												;
void pushmeja(string warna)									;
void pushkardus(string warna)								;
void popmeja()												;				
int kuota = 5												;
int kuotasouvenir = 3										;
bool konfirm												;
void souvenir()												;

main(){
	
	string warna_temp									;
	buat_stack()										;
	buat_queue()										;
	//karena diketerangan soal sudah statis di dalamnya
	warna_temp = "hijau"								;
	pushmeja(warna_temp)								;
	warna_temp = "kuning"								;
	pushmeja(warna_temp)								;
	warna_temp = "merah"								;
	pushmeja(warna_temp)								;
	//mengisi di kardus
	for(int i=0;i<4;i++){
	
	warna_temp = "merah"								;
	pushkardus(warna_temp)								;
	warna_temp = "kuning"								;
	pushkardus(warna_temp)								;
	warna_temp = "hijau"								;
	pushkardus(warna_temp)								;
	}
	
	menu();
	
}

void buat_stack(){
    // Konfigurasi awal untuk membuat stack
    typeptrstack NM										;
    NM = NULL											;
    awalmeja = NM										;
    akhirmeja = NM										;
    typeptrstack NK										;
    NK = NULL											;
    awalkardus = NK										;
    akhirkardus = NK									;
}

void buat_queue(){
    awaltamu = new typequeue							;
    awaltamu = NULL										;
    akhirtamu = awaltamu								;
    awalantri = new typequeue							;
    awalantri = NULL									;
    akhirantri = awalantri								;
}

void menu(){
	
	int pilih, jumlah												;
	string nama														;
	cout << "===========================================" 	<< endl	;
	cout << " sisa orang yang boleh masuk:" <<	kuota		<< endl	;
	cout << " Tumpukan souvenir:" << kuotasouvenir			<< endl	;
	cout << "==========================================="	<< endl	;
	cout << " Menu :"										<< endl	;
	cout << " 1. Masuk"										<< endl	;
	cout << " 2. Tamu yang masuk"							<< endl	;
	cout << " 3. Antrian"									<< endl	;
	cout << " 4. Tamu keluar"								<< endl	;
	cout << " 5. Souvenir"									<< endl	;
	cout << " 0. Exit"										<< endl	;
	cout << " Pilih: ";cin >> pilih									;
	
	if (pilih == 1){
		if(kuotasouvenir > 0){
		
		cout << "Nama yang di undang : " 									;
		cin.ignore(); getline(cin,nama)										;
		do{	
			cout << "Jumlah orang yang datang : " 	; 	cin >> jumlah		;
			if(jumlah > 2){
				cout << " Maksimal 2 Orang"									;
				cout << endl 												;
				konfirm = true												;
			}
			else {
				konfirm = false												;
			}
		}while (konfirm)													;
		
		
		if (jumlah <= kuota )
		{
			cout << "Atas nama " << nama << " Boleh langsung masuk"			;
			kuota = kuota - jumlah 											;
			entamu(nama,jumlah,akhirmeja->warna)							;
			popmeja()														;
		} 
		else if (jumlah > kuota)
		{
			cout << "Atas nama " << nama << " silahkan antri terlebih dahulu"	;
			enantrian(nama,jumlah,akhirmeja->warna)								;
			popmeja()															;
		}

		cout << endl << endl													;
		kuotasouvenir--;
		menu()																	;
		
		
	}	
	else {
	
		cout << "Tambahkan souvenir terlebih dahulu" << endl << endl			;
		menu()																	;
		}
	}
	else if (pilih == 2){
		cetak_tamu()															;
		cout << endl << endl													;
		menu()																	;
	}
	else if (pilih == 3){
		cetak_antri()															;
		cout << endl << endl													;
		menu()																	;
	}
	else if (pilih == 4){
		keluar()																;
		cout << endl << endl													;
		menu()																	;
	}
	else if (pilih == 5){
		souvenir()																;
		cout << endl << endl													;
		menu()																	;
	}
	else if (pilih == 0){
		cout << endl << endl													;
		system("EXIT")															;
	}
}

void entamu(string nama , int jumlah, string warna){
	
	typeptrqueue NT								;
    NT = new typequeue							;
    NT->nama = nama								;
    NT->jumlah = jumlah							;
	NT->warna = warna							;

    if(tamu_kosong()) {
    	
    	awaltamu = NT							;
	}
    else {
    	
	akhirtamu->next = NT						;
	
	}
    akhirtamu = NT								;
    akhirtamu->next = NULL						;
}

void enantrian(string nama , int jumlah , string warna){
	
    typeptrqueue NA								;
    NA = new typequeue							;
    NA->nama = nama								;
    NA->jumlah = jumlah							;
	NA->warna = warna							;

    if(antri_kosong()) {
    	
    	awalantri = NA							;
	}
    else {
    	
	akhirantri->next = NA						;
	
	}
    akhirantri = NA								;
    akhirantri->next = NULL						;
}

bool tamu_kosong(){
	
    if (awaltamu == NULL){

	return true;
	
	} 
   
    else{
    	
	return false;
	
	} 
}

bool antri_kosong(){
	
    if (awalantri == NULL){

	return true;
	
	} 
   
    else{
    	
	return false;
	
	} 
}

void cetak_tamu(){
	
    typeptrqueue bantu											;
    if(tamu_kosong()) cout << "Tidak Ada Tamu" << endl << endl	;
    else {
    	
		int i = 0																												;
        bantu = awaltamu																										;
		cout << "+-----------------------------------------------------------------------------------------+"<<endl				;
        cout << "|**********************************  DAFTAR TAMU DI DALAM  *******************************|"<<endl				;	
        cout << "+-----+---------------------------+---------------------------+---------------------------+"<<endl				;
        cout << "| NO  |           Nama            |      banyak orang         |          Souvenir         |"<<endl				;
        cout << "+-----+---------------------------+---------------------------+---------------------------+"<<endl				;
        do
		{
        i++		 																												;
        cout << "| " 	 << setw(3) 	<< i  << " | "																			;
        cout << setw(25) << bantu->nama <<" | "<<setw(25) << bantu->jumlah <<" | " << setw(25) << bantu->warna <<" |" << endl 	;
        cout << "+-----+---------------------------+---------------------------+---------------------------+"<<endl				;
        bantu = bantu->next																										;
        } 
		while (bantu != NULL)																									;
        cout << endl																											;

        
    }
}

void cetak_antri(){
    typeptrqueue bantu;
    if(antri_kosong()) cout << "Tidak Ada Antrian" << endl << endl;
    else {
    	
		int i = 0			;
        bantu = awalantri	;
		cout << "+-----------------------------------------------------------------------------------------+"<<endl				;
        cout << "|*************************************  DAFTAR ANTRIAN  **********************************|"<<endl				;	
        cout << "+-----+---------------------------+---------------------------+---------------------------+"<<endl				;
        cout << "| NO  |           Nama            |      banyak orang         |          Souvenir         |"<<endl				;
        cout << "+-----+---------------------------+---------------------------+---------------------------+"<<endl				;
        do{
        i++		 			;
        cout << "| " 	 << setw(3) 	<< i  << " | "																			;
        cout << setw(25) << bantu->nama <<" | "<<setw(25) << bantu->jumlah <<" | " << setw(25) << bantu->warna <<" |" << endl 	;
        cout << "+-----+---------------------------+---------------------------+---------------------------+"<<endl				;
        bantu = bantu->next;
        } while (bantu != NULL);
        cout << endl;

        
    }
}

void keluar(){
	if(awaltamu != NULL){
	
	kuota = kuota + awaltamu->jumlah							;
	detamu()													;
	
	
	if (awalantri == NULL){
	cout << "Tidak ada antrian lagi untuk masuk"				;
	menu();
	}
	
	if(kuota >= awalantri->jumlah  ){
	
	
	entamu(awalantri->nama,awalantri->jumlah,awalantri->warna)	;
	deantri()													;
	
	}
}
else{
	

cout << "Didalam Ruangan masih kosong" ;
}
}

void detamu(){
	
    typeptrqueue hapus		;
    hapus = awaltamu		;
    awaltamu = hapus->next	;
    free(hapus)				;
}

void deantri(){
	
    typeptrqueue hapus		;
    hapus = awalantri		;
    awalantri = hapus->next	;
    free(hapus)				;
}

void pushmeja(string warna){   
 
    typeptrstack NM						;
    NM = new typestack					;
    NM->warna = warna					;
  

    if(meja_kosong()){
    	
    	awalmeja = NM					;
    	
	} 
    else {
    	
    	akhirmeja->next = NM			;	
    
	}

    akhirmeja = NM						;
    akhirmeja->next = NULL				;
    
}

bool meja_kosong(){
    // Jika awal dan akhir NULL
    if(awalmeja == NULL and akhirmeja == NULL) return true;
    // Jika tidak
    else return false;
}

bool kardus_kosong(){
    // Jika awal dan akhir NULL
    if(awalkardus == NULL and akhirkardus == NULL) return true;
    // Jika tidak
    else return false;
}

void popmeja(){
    typeptrstack hapus, bantu;

     if (meja_kosong())
		{ 
		cout << "Tidak ada souvenir souvenir"						;
		}
    // bantu di paling bawah stack dan hapus di puncak
    else {

        bantu = awalmeja											;
        hapus = akhirmeja											;

			
		 
            // Jika hapus = paling bawah
            if(hapus == awalmeja){
                awalmeja = NULL										;
                akhirmeja = NULL									;
            // Jika tidak
            } else {
                // Menggeser bantu hingga data kedua dari puncak
                while(bantu->next != akhirmeja) bantu = bantu->next	;
                akhirmeja = bantu									;
                akhirmeja->next = NULL								;
            }
                free(hapus)											;
            
        }
}

void pushkardus(string warna){   
 
    typeptrstack NK						;
    NK = new typestack					;
    NK->warna = warna					;
  

    if(kardus_kosong()){
    	
    	awalkardus = NK					;
    	
	} 
    else {
    	
    	akhirkardus->next = NK			;	
    
	}

    akhirkardus = NK					;
    akhirkardus->next = NULL			;
    
}

void popkardus(){
    typeptrstack hapus, bantu;

     if (kardus_kosong())
		{ 
		cout << "Tidak ada souvenir lagi"								;
		}
    // bantu di paling bawah stack dan hapus di puncak
    else {

        bantu = awalkardus												;
        hapus = akhirkardus												;

			
            // Jika hapus = paling bawah
            if(hapus == awalkardus){
                awalkardus = NULL										;
                akhirkardus = NULL										;
            // Jika tidak
            } else {
                // Menggeser bantu hingga data kedua dari puncak
                while(bantu->next != akhirkardus) bantu = bantu->next	;
                akhirkardus = bantu										;
                akhirkardus->next = NULL								;
            }
                free(hapus)												;
            
        }
}

void souvenir(){
	if (kuotasouvenir < 3){
	
	kuotasouvenir++										;
	pushmeja(akhirkardus->warna)						;
	popkardus()											;
	cout << endl << "souvenir berhasil ditambahkan"		;
	}
	else
	{
	
	cout << "Maksimal souvenir 3 diatas meja"			;
	
	}
}


