#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include <malloc.h>
#include <fstream>
#include <string.h>


using namespace std						;
typedef struct typequeue *typeptrqueue	;
typedef struct typestack *typeptrstack	;

struct typequeue{
	
    string nama,risk,barang	;
    int biaya				;
    typeptrqueue next		;
    
}							;

struct typestack{
	
    string nama,risk,barang	;
    int biaya				;
    int no_service			;
    typeptrstack next		;
    
}							;


typeptrqueue awalqueue, akhirqueue	;
typeptrstack awalstack, akhirstack	;

void push(string nama,string barang,string risk, int biaya)	;
void proses()						;
void buat_stack()					;
bool stack_kosong()					;
void pop()							;
void cetak_stack()					;
void buat_queue()					;
bool queue_kosong()					;
void enqueue()						;
void dequeue()						;
void cetak_queue()					;
void menuservice()					;
int no_service = 1000				;

ofstream tulis			;
ifstream baca			;


int main(){
buat_stack();
buat_queue();
menuservice();

}


void menuservice(){
	
	char ulang			;
	int pilih			;
	int bykjenis		;
	do
	{
		
	system("CLS")		;
	cout << "+----------------------------------+" << endl	;
	cout << "|************ TOKO HP *************|" << endl	;
	cout << "+----------------------------------+" << endl	;
	cout << "|********** MENU SERIVCE **********|" << endl	;
	cout << "+----------------------------------+" << endl	;
	cout << "| 1. Input Antrian Service         |" << endl	;
	cout << "| 2. Proses Service                |" << endl	;
	cout << "| 3. Cek Antrian Service           |" << endl	;
	cout << "| 4. Riwayat Service               |" << endl	;
	cout << "| 5. Hapus Riwayat Service         |" << endl	;
	cout << "| 6. Keluar                        |" << endl	;
	cout << "+----------------------------------+" << endl	;
	cout << " Pilih : "		; cin >> pilih					;
	if (pilih == 1)
	{	
		enqueue()			;
	}
		else if(pilih == 2)
	{
		proses()			;
	}
		else if(pilih == 3)
	{
		cetak_queue()		;
	}
		else if(pilih == 4)
	{
		cetak_stack()		;
	}
		else if(pilih == 5)
	{
		pop()				;
	}
		else if(pilih == 6)
	{
		system("CLS")		;
	}

	else 
	{
	cout << "Angka yang anda masukkan salah"	;	
	}
	cout << "kembali ke menu?(y/n): " 			; cin >> ulang;
	}while(ulang == 'y')						;
}


void proses(){

    char konfirmasi		;
	if (queue_kosong())	{
		
        cout << "Tidak ada yang harus di service!" << endl					;
        
    }
	else {  
        cout << "Nama          : " << awalqueue->nama 	<< endl				;
        cout << "Barang        : " << awalqueue->barang << endl				;
        cout << "Kerusakan     : " << awalqueue->risk 	<< endl				;
        cout << "Ingin melakukan service terhadap antrian tersebut?(y/n): "	;
        cin >> konfirmasi;

        if(tolower(konfirmasi) == 'y'){
        	
            push(awalqueue->nama,awalqueue->barang,awalqueue->risk,awalqueue->biaya);
            dequeue();
          
        }
    }
}


bool queue_kosong(){
	
    if (awalqueue == NULL){

	return true;
	
	} 
   
    else{
    	
	return false;
	
	} 
}


bool stack_kosong(){
   
    if(awalstack == NULL and akhirstack == NULL){

	return true;
	
	} 
   
    else{
    	
	return false;
	
	} 
}


void push(string nama,string barang,string risk, int biaya){  


 
    typeptrstack NS						;
    NS = new typestack					;
    NS->nama = nama						;
    NS->barang = barang					;
    NS->risk = risk						;
    NS->biaya = biaya					;
    NS->no_service = ++no_service		;


	// untuk menyimpan history data ke file 
	tulis.open("history_service.txt",ios::app) ;
	
	tulis << " | " 	<< setw(6) 	<< NS->no_service	;
	tulis << " | "	<< setw(25) << NS->nama 		;
	tulis << " | "	<<setw(25) 	<< NS->barang 		;
	tulis << " | " 	<< setw(25) << NS->risk 		;
	tulis << " | " 	<< setw(16)	<< NS->biaya 		;
	tulis << " | "  << endl							;
	
	
	tulis.close() ;
	
	
	
    if(stack_kosong()){
    	
    	awalstack = NS					;
    	
	} 
    else {
    	
    	akhirstack->next = NS			;	
    
	}

    akhirstack = NS						;
    akhirstack->next = NULL				;
    
}


void dequeue(){
	
    typeptrqueue hapus		;
    hapus = awalqueue		;
    awalqueue = hapus->next	;
    free(hapus)				;
}


void enqueue(){
	
    int biaya									;
    typeptrqueue NQ								;
    string nama , barang , risk					;

    cout << "Masukkan nama Customer       : "	;
    cin.ignore(); getline(cin,nama)				;
    cout << "Masukkan barang              : "	;
    getline(cin,barang)							;
    cout << "Masukkan Kerusakan           : "	;
    getline(cin,risk)							;
    cout << "Masukkan Biaya Service       : "	;
    cin >> biaya								;

    NQ = new typequeue							;
    NQ->nama = nama								;
    NQ->barang = barang							;
    NQ->risk = risk								;
    NQ->biaya = biaya							;

    if(queue_kosong()) {
    	
    	awalqueue = NQ		;
	}
    else {
    	
	akhirqueue->next = NQ	;
	
	}
    akhirqueue = NQ			;
    akhirqueue->next = NULL	;
}


void cetak_queue(){
    int tunggu = 0, i = 0;
    typeptrqueue bantu;

    if(queue_kosong()) cout << "Tidak Ada Antrian Service" << endl << endl;
    else {
    	
		
        bantu = awalqueue	;
		cout << "+-----+-----------------------------------------------------------------------------------+"<<endl			;
        cout << "|**********************************  DAFTAR ANTRIAN SERVICE  *****************************|"<<endl			;	
        cout << "+-----+---------------------------+---------------------------+---------------------------+"<<endl			;
        cout << "| NO  |           Nama            |           barang          |         Kerusakan         |"<<endl			;
        cout << "+-----+---------------------------+---------------------------+---------------------------+"<<endl			;
        do{
        i++		 			;
        cout << "| " 	 << setw(3) 	<< i  << " | "																		;
        cout << setw(25) << bantu->nama <<" | "<<setw(25) << bantu->barang <<" | " << setw(25) << bantu->risk <<" |" << endl 	;
        cout << "+-----+---------------------------+---------------------------+---------------------------+"<<endl			;
        bantu = bantu->next;
        } while (bantu != NULL);
        cout << endl;

        
    }
}


void cetak_stack(){
 
    char show											;
    typeptrstack buttom,bantu,top						;
    if(stack_kosong()){
    	
    	cout << "Belum ada Riwayat Service." << endl	;
    	
	} 
    else{
	         
        buttom 	= awalstack								;
        top 	= akhirstack							;
        cout << "+--------------------------------------------------------------------------------------------------------------+"<<endl	;
        cout << "|*************************************************  RIWAYAT SERVICE  ******************************************|"<<endl	;	
        cout << "+------------+---------------------+---------------------------+---------------------------+-------------------+"<<endl	;
        cout << "| NO Service |        Nama         |           barang          |         Kerusakan         |        Biaya      |"<<endl	;
        cout << "+------------+---------------------+---------------------------+---------------------------+-------------------+"<<endl	;
        
        if (buttom != top){   
            do{
                
        cout << "| " 	 << setw(10) 	<< top->no_service  	<< " | "																	;
        cout << setw(19) << top->nama 	<< " | "<<setw(25) 		<< top->barang 	<< " | "													; 
		cout << setw(25) << top->risk 	<< " |Rp."<< setw(15)	<< top->biaya 	<< " |" << endl 											;
        cout << "+------------+---------------------+---------------------------+---------------------------+-------------------+"<<endl	;
		bantu = buttom;
       	while(bantu->next != top){
       			
        	bantu = bantu->next;
        }  
        
        top = bantu;
        
        }
		while (bantu != buttom);
        }
        
        cout << "| " 	 << setw(10) 	<< buttom->no_service  	<< " | "																	;
        cout << setw(19) << top->nama 	<< " | "<<setw(25) 		<< buttom->barang 	<< " | "												; 
		cout << setw(25) << top->risk 	<< " |Rp."<< setw(15) 	<< buttom->biaya 	<< " |" << endl											;
        cout << "+------------+---------------------+---------------------------+---------------------------+-------------------+"<<endl	;
    }
}


void buat_stack(){
    // Konfigurasi awal untuk membuat stack
    typeptrstack NS;
    NS = NULL;
    awalstack = NS;
    akhirstack = NS;
}


void buat_queue(){
    awalqueue = new typequeue;
    awalqueue = NULL;
    akhirqueue = awalqueue;
}

void pop(){
    typeptrstack hapus, bantu;
    char konfirm;

     if (stack_kosong())
		{ cout << "Tidak ada Struk !\n";}
    // bantu di paling bawah stack dan hapus di puncak
    else {

        bantu = awalstack;
        hapus = akhirstack;

        cout << "+-------------+----------------------------------+" << endl;
        cout << "| No. Service |   Nama Customer  |    Biaya      |" << endl;
        cout << "+-------------+----------------------------------+" << endl;
        cout << "| " << setw(11) << hapus->no_service << " | ";
        cout << setw(16) << hapus->nama << " |";
        cout << "Rp. " << setw(10) << hapus->biaya << " |" << endl;
        cout << "+-----------+----------------------------------+" << endl;
        cout << "Ingin Mengambil Struk tersebut?(y/n): ";
        cin >> konfirm;

        if(tolower(konfirm) == 'y'){    
            // Jika hapus = paling bawah
            if(hapus == awalstack){
                awalstack = NULL;
                akhirstack = NULL;
            // Jika tidak
            } else {
                // Menggeser bantu hingga data kedua dari puncak
                while(bantu->next != akhirstack) bantu = bantu->next;
                akhirstack = bantu;
                akhirstack->next = NULL;
            }
                free(hapus);
            }
        }
}

