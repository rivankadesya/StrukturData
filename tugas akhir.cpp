#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;
//typedata queue
typedef struct typequeue *typeptrqueue	;
//typedata stack
typedef struct typestack *typeptrstack	;

//struct queue
struct typequeue{
	
    string nama,risk,barang	;
    int biaya				;
    typeptrqueue next		;
    
}							;

//struct stack
struct typestack{
	
    string nama,risk,barang	;
    int biaya				;
    int no_service			;
    typeptrstack next		;
    
}							;

//pendklarasian variabel awal dan akhir queue
typeptrqueue awalqueue, akhirqueue	;

//pendklarasian variabel awal dan akhir stack
typeptrstack awalstack, akhirstack	;

typedef struct{
	
	string nama,   pekerjaan		; 
	string alamat, jenis_kelamin	;
	int nopgw						;
	
	
}data_pegawai			;


typedef struct{
	
	int id				;
	string password		;
	
}data_akun				;

struct pabrik{
	string tglmasuk		;
	int kode			;
	string namabrg		;
	int stok, lokerbrg	;
};


pabrik data[999]		;
data_pegawai datap[999]	;
data_akun akun[50] 		;
ofstream tulis			;
ifstream baca			;
ofstream tulispabrik	;
ifstream bacapabrik		;

void awal()							;
void login()						;
void buat_akun()					;
void ambil_data_akun(int *)			;
void menu()							;
void pegawai()						;
void barang()						;
void input(int *)					;
void contoh()						;
void outputpgw()					;
void ambildatapgw(int *)			;
void sorting_bubble(int)			;
void sorting_selection()			;
void sorting_shell()				;
void shell_urut(int)				;
void caripgw()						;
void binary()						;
void sequential()					;
void output_cari(int *)				;
void sorting_selection()			;
void back_menu()					;
void cari_alamat()					;
void cari_jeniskelamin()			;
void cari_bagian()					;
void inputdata(int *)				;
void outputdata()					;
void caridata(int)					;
void ambildata(int *)				;
void insertionsorting(int n)		;

//void stack dan queue
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


int main()							{
	buat_stack();
	buat_queue();
	awal()		;
	
}

void awal()							{
	
	char pilihmenu	;
	int bykinput	;
	cout << "========================================================================" << endl ;
	cout << "======================= LOGIN DATABASE PABRIK ==========================" << endl ;
	cout << "========================================================================" << endl << endl << endl ;
	
	cout << "	1.Login akun" 	<< endl 	;
	cout << "	2.Buat akun"	<< endl 	;
	cout << "	3.Keluar"		<< endl 	;
	cout << endl << endl					;
	cout << "Masukkan Pilihan Anda : " 		; cin >> pilihmenu ;
	
	if 		(pilihmenu == '1')	{
	
		system ("CLS")		;
		login ()			;
		
	}
	
	else if (pilihmenu == '2')	{
		
		system ("CLS")		;
		buat_akun ()		;
	}
	
	else if (pilihmenu == '3')	{
		
		system ("CLS")		;
		exit(0)				;
		
	}
	else 						{
		
		system("CLS")		;
		awal()				; 
		
	}
	
}

void login()						{
		
		int id 			;
		string password ;
		int length		;
		int login = 0	;
		
		cout << "======================== LOGIN =======================================" 	 << endl   << endl 	; 
		cout << "ID			 : " 		 				; cin >> id									  			;cin.ignore() ;
		cout << "PASSWORD\t	 : "		 				; getline(cin,password)						  			;
		
		ambil_data_akun(&length) ;
		
		for (int i = 0 ; i < length ; i++){
		
			if( id == akun[i].id && password == akun[i].password ) 		{
			
				login = 1		;
				system("CLS") 	;
				menu()		  	;
			
			
			}
		
	
}

		if( login != 1 ) 		{
			
			cout << endl << endl 										 ;
			cout << " akun yang anda masukkan salah "	 		 << endl ;
			cout << " Tekan enter untuk kembali ke menu awal "	 << endl ;
			cout << endl << endl ;
			system ("PAUSE") 	 ;
			system ("CLS")	 	 ;
			awal()			 	 ;
			
		}
		

}

void buat_akun()					{
	
		cout << endl << endl ;
		cout << "=======================CONTOH PENGISIAN =======================" 	 << endl ;
		cout << "ID			 : 20001 (5 digit awali dengan angka 2)" 		 		 << endl ; 
		cout << "PASSWORD\t	 : rumahktp (tanpa spasi)"				 		 		 << endl ; 
		cout << endl << endl ;	
		
		tulis.open("Data_akun.txt",ios::app) ;
		for (int i =0 ; i < 1 ; i++){
		
		
		cout << endl << endl ;
		cout << "===============================================================" 	 << endl; 
		cout << "ID			 : "  					; cin >> akun[i].id 				    ; cin.ignore() ; 
		cout << "PASSWORD\t	 : "				    ; getline(cin,akun[i].password)			;
		cout << "===============================================================" 	 << endl;
		
		cout << endl << endl ;	
			
		tulis <<  akun[i].id				<< endl  ;
		tulis <<  akun[i].password	 		<< endl  ;
		
	
		tulis.close() ;
		}
		cout << " Akun berhasil dibuat " 				;
		cout << " Tekan Enter untuk kembali ke menu " 	;
		cout << endl << endl ;
		system("PAUSE") ;
		system("CLS")	;
		awal()			;
}

void ambil_data_akun(int *n)		{
	int i = 0									;
		
		baca.open("Data_akun.txt")				;
		while(true){
		baca >> akun[i].id						;
		if (baca.eof())
		{
			break;
		}
		baca.ignore();
		getline(baca, akun[i].password)	 		 ;	
		
		
		i++;
	}
	*n = i 		;
	baca.close();
}

void menu()							{
	
	char pilih ;
	cout << "========================================================================" 	<< endl ;
	cout << "============================ DATABASE PABRIK ===========================" 	<< endl ;
	cout << "========================================================================" 	<< endl << endl << endl ;
	cout << "	1.Pegawai "																<< endl ;
	cout << "	2.Barang "																<< endl ;
	cout << "	3.Logout "																<< endl << endl;
	cout << "	Masukkan Pilihan anda : " 														; cin >> pilih ;
	
	if (pilih == '1')		{
		
		system("CLS")	;
		pegawai()		;
		
	}
	else if (pilih == '2')	{
		system("CLS")	;
		barang()		;
	}
	
	else if (pilih == '3')	{
		system("CLS")	;
		awal()			;
	}
	else 					{
		
		cout << endl << endl 	;
		cout << " input yang anda masukkan salah tekan enter untuk mengulang " << endl << endl ;
		system("PAUSE")			;
		system("CLS")			;
		menu()					;
		
	}
	
}

void pegawai()						{
	
	system("CLS")	;
	char pilihmenu	;
	int bykinput	;
	
	cout << "======================================================================================" << endl ;
	cout << "================================ MENU DATABASE PEGAWAI ===============================" << endl ;
	cout << "======================================================================================" << endl << endl << endl ;
	cout << " 	1.Input Data Pegawai Baru "			<< endl ;
	cout << " 	2.Lihat data Pegawai "	 			<< endl ;
	cout << " 	3.Cari Data pegawai "		 		<< endl ;
	cout << " 	4.kembali ke menu awal "			<< endl ;
	cout << endl << endl 						 			;
	cout << " 	Pilih : "						 			; cin >> pilihmenu ;
	
	if ( pilihmenu == '1')
	{
		system("CLS") 		;
		cout << " Banyak Pegawai baru yang akan di input : " ; cin >> bykinput;
		
		input ( &bykinput ) ;
		system("CLS")		;
		pegawai()			;
			
	}
	else if ( pilihmenu == '2' )
	{
		outputpgw()			;
		cout << " Tekan enter untuk kembali ke menu " << endl << endl ;
		system("PAUSE")		;
		system("CLS")		;
		pegawai()			;
	}
	else if ( pilihmenu == '3' )
	{
		system("CLS") 		;
		caripgw()			;
	}	
	else if ( pilihmenu == '4' )
	{
		system("CLS")		;
		menu()				;	
	}
	else
	{
		system("CLS")		;
		pegawai()			;
	}
	
}

void input ( int *bykinput )		{ // void input menggunakan pointer //
	
	system("CLS")						;
	contoh()							;
	tulis.open("Data_pegawai.txt",ios::app) ;
	for  (int i = 0 ; i < *bykinput;i++) {
		
		cout << endl ;
		cout << "==================================================================================" << endl ;
		cout << "	No Pegawai          : " ; cin >> datap[i].nopgw										 ; cin.ignore() ;
		cout << "	Nama                : " ; getline(cin,datap[i].nama)	 							 ; 
		cout << "	Alamat              : " ; getline(cin,datap[i].alamat)								 ; 
		cout << "	Jenis Kelamin       : " ; getline(cin,datap[i].jenis_kelamin) 			 			 ;
		cout << "	Bagian              : " ; getline(cin,datap[i].pekerjaan)							 ;
		cout << "==================================================================================" << endl ;
		cout << endl ;
			
		tulis <<  datap[i].nopgw					<< endl  ;
		tulis <<  datap[i].nama	 					<< endl  ;
		tulis <<  datap[i].alamat					<< endl  ;
		tulis <<  datap[i].jenis_kelamin			<< endl  ;
		tulis <<  datap[i].pekerjaan				<< endl  ;
		
		
	}
	tulis.close() ;
	
	cout << " Tekan enter untuk kembali kemenu pegawai" << endl << endl << endl ;
	system("PAUSE")	;
	system("CLS")	;
	
}

void contoh()						{
	
		cout << endl ;
		cout << "==================================================================================" 	 << endl ;
		cout << "========================CONTOH PENGISIAN DATA=====================================" 	 << endl ;
		cout << "=================================================================================="	 << endl ;
		cout << "	No Pegawai          : 1004 (4 DIGIT DIAWALI ANGKA 1)"								 << endl ;
		cout << "	Nama                : ROBERT JOHNSON (HURUF KAPITAL)" 								 << endl ;
		cout << "	Alamat              : BANTUL,JL.SENOPATI NO 32 (HURUF KAPITAL)" 					 << endl ;
		cout << "	Jenis Kelamin       : LAKI-LAKI (HURUF KAPITAL)" 									 << endl ;
		cout << "	Bagian              : PEMASARAN (HURUF KAPITAL)" 									 << endl ;
		cout << "==================================================================================" 	 << endl ;
		cout << endl << endl ;
	
}

int outputpgw2(int i,int length)	{ // FUNGSI REKURSIF//


		
	if(i==length){
		cout << endl << endl << "tekan enter untuk kembali ke menu "	;
		cout << endl << endl											;
		system ("PAUSE")												;
		system ("CLS")													;
		pegawai()														;
	}
	else
	{
		cout << "Data Ke - " << i+1 << endl ;
		cout << "==================================================================================" << endl ;
		cout << "	No Pegawai          : " << datap[i].nopgw								 << endl ;
		cout << "	Nama                : " << datap[i].nama 								 << endl ;
		cout << "	Alamat              : " << datap[i].alamat					 		   	 << endl ;
		cout << "	Jenis Kelamin       : " << datap[i].jenis_kelamin						 << endl ;
		cout << "	Bagian              : " << datap[i].pekerjaan							 << endl ;
		cout << "==================================================================================" << endl ;
		cout << endl 				;
	}
	cout<<endl						;
	return outputpgw2(i+1,length)	;
	
}

void outputpgw()					{  
	
	int length;
	system("CLS")																							;
	cout << "==================================================================================" << endl 	;
	cout << "====================== SEMUA DATA TERSORTING BY NO PEGAWAI =======================" << endl 	;
	cout << "==================================================================================" << endl 	;
	cout << endl << endl 																					;
	ambildatapgw ( &length )	 																			; // mengambil data file dan menggunakan fungsi pointer //
	sorting_bubble (length)																					; // sorting //
	cout << endl << endl 																					;
	cout << "Banyak Pegawai : "  << length << endl << endl													;
	outputpgw2 (0,length)																					; //Fungsi rekursif//
	system ("PAUSE")																						;
}

void ambildatapgw (int *n) 			{
	int i = 0							;
	baca.open("Data_pegawai.txt")		;
	while(true){
		baca >> datap[i].nopgw			;
		if (baca.eof())
		{
			break;
		}
		baca.ignore();
		getline(baca, datap[i].nama)			;	
		getline(baca, datap[i].alamat)			;
		getline(baca, datap[i].jenis_kelamin) 	;
		getline(baca, datap[i].pekerjaan) 		;
		
		i++;
	}
	baca.close();
	*n = i;
}

void sorting_bubble ( int bykdata )	{ //sorting menggunakan bubble sort //
	data_pegawai sementara;
	for( int current = 0 ; current < bykdata ; current++ )
	{
		for( int j= current + 1 ; j < bykdata ; j++ )
		{
			if( datap[current].nopgw > datap[j].nopgw )
			{
				sementara 		= datap[current];
				datap[current] 	= datap[j]		;
				datap[j] 		= sementara		;
			}
		}
	}
}

void caripgw()						{


	int pilih			;
	system("CLS")		;
	cout << "===============================================================" << endl ;
	cout << "======================= CARI DATA =============================" << endl ;
	cout << "===============================================================" << endl ;
	cout << endl << endl 								;
	cout << "	Cari Berdasarkan : "			<< endl ;
	cout << "	1.  Nomer Pegawai(Binary)"		<< endl ;	
	cout << "	2.  Nama(Sequential)"			<< endl ;
	cout << "	3.  Alamat"						<< endl ;
	cout << "	4.  Jenis Kelamin"				<< endl ;
	cout << "	5.  Bagian"						<< endl ;
	cout << "	6. kembali ke menu pegawai"		<< endl ;
	cout << "	Pilih : "								;
	cin  >> pilih		;
	

		
	if(pilih==1){
		system("CLS")				;
		binary()					;
		back_menu()					;
		system("PAUSE")				;
		caripgw()					;
	}
	
		if(pilih==2){
		system("CLS")				;
		sequential()				;
		back_menu()					;
		system("PAUSE")				;
		caripgw()					;
	}
	
	if(pilih==3){
		system("CLS")				;
		cari_alamat()				;
		back_menu()					;
		system("PAUSE")				;
		caripgw()					;
	}
	
	if(pilih==4){
		system("CLS")				;
		cari_jeniskelamin()			;
		back_menu()					;
		system("PAUSE")				;
		caripgw()					;
	}
	if(pilih==5){
		system("CLS")				;
		cari_bagian()				;
		back_menu()					;
		system("PAUSE")				;
		caripgw()					;
		
	}
	if(pilih==6){
		system("CLS")				;
		pegawai()					;
		
	}
	else {
		system("CLS")				;
		caripgw()					;
	}
}

void binary()						{
	
	int length					;
	ambildatapgw ( &length ) 	;
	sorting_selection()			;
	int awal,nilaiCari,akhir,x	;
	bool found		;
	found = false	;
	awal = 0		;
	akhir = length	;
	cout << "==================================================================================" << endl ;
	cout << "================================ CARI NO PEGAWAI =================================" << endl ;
	cout << "==================================================================================" << endl ;
	cout << endl << endl 														  ;
   cout << "	Nomer pegawai yang dicari : "	; cin >> nilaiCari;
   
   while((!found) && (awal <= akhir))
   {
      x= (awal + akhir) / 2;
      if( nilaiCari == datap[x].nopgw ){
      	
      			output_cari(&x)	;
				found = true	;
	  }
         
      else
      {
         if( nilaiCari < datap[x].nopgw )
            akhir = x - 1 ;  
         else
            awal  = x + 1 ;  
      }
   }
   if(!found)
      	{
			cout<<"Nomer Pegawai Tidak ditemukan" << endl << endl ;	
		}
   
     
}

void output_cari(int *n)			{
			int i	;
			i = *n	;
	
			cout << endl 	;
			cout << "==================================================================================" << endl ;
			cout << "	No Pegawai          : " << datap[i].nopgw								 << endl ;
			cout << "	Nama                : " << datap[i].nama 								 << endl ;
			cout << "	Alamat              : " << datap[i].alamat					 		   	 << endl ;
			cout << "	Jenis Kelamin       : " << datap[i].jenis_kelamin						 << endl ;
			cout << "	Bagian              : " << datap[i].pekerjaan							 << endl ;
			cout << "==================================================================================" << endl ;
			cout << endl 	;
	
}

void sorting_selection()			{
	int length					;
	ambildatapgw ( &length ) 	;
	data_pegawai temp;
    for(int i=0; i<length; i++) 
	{
      for(int j=i+1; j<length; j++) 
	{	
         if(datap[i].nopgw > datap[j].nopgw) 
         {
            temp 	= datap[i]	;
            datap[i] = datap[j]	;
            datap[j] = temp		;
         }
     }
   }    
}	

void shell_urut(int length)			{
			
	ambildatapgw(&length)	;
	int i, j, k				;
	data_pegawai sementara	;
	
	for(i = length/2; i > 0; i = i/2)
	{
		for(j = i; j < length; j++)
		{
			for(k = j-i; k >= 0; k = k-i)
			{
				
				if(datap[k+i].nopgw >= datap[k].nopgw )
				break;
				
				else
				{
					sementara		= datap[k]		;
					datap[k] 		= datap[k+i]	;
					datap[k+i] 		= sementara		;
				}
			}
		}
	}
}

void sorting_shell()				{
	
	int length					;
	ambildatapgw ( &length ) 	; // mengambil data file dan menggunakan fungsi pointer //
	shell_urut( length )		;
	
	
}

void sequential()					{
	int length					;
	ambildatapgw ( &length )	; // mengambil data file dan menggunakan fungsi pointer //
	sorting_shell ()			;
	int i						;
	string search 				;
	bool found					;
	found=false					;
	cin.ignore()				;
	cout << "==================================================================================" << endl ;
	cout << "================================= CARI NAMA ======================================" << endl ;
	cout << "==================================================================================" << endl ;
	cout << endl << endl 														  ;
	cout<<"Masukkan nama yang dicari : "; getline(cin,search);
	for(i = 0; i < length; i++)
	{
		
			if(search == datap[i].nama )
			{
				
				output_cari(&i)	;
				found = true	;
			}
		}
	
	if(!found)
	cout << "Data tidak di temukan" << endl;
	
}

void back_menu()					{
	
	cout << endl << endl << " Tekan Enter Untuk kembali ke menu cari " << endl << endl ;
}

void cari_alamat()					{
	
	int length					;
	ambildatapgw ( &length ) 	;
	int hasil = 0				;
	string cari					;
	cin.ignore()				;
	cout << "==================================================================================" << endl ;
	cout << "=================================== CARI ALAMAT ==================================" << endl ;
	cout << "==================================================================================" << endl ;
	cout << endl << endl 														  ;
	cout << "Masukkan Alamat (SESUAI INPUT KAPITAL) : " ; getline(cin,cari) ;
	
	for (int i = 0 ; i < length ; i++){
		
		if (cari == datap[i].alamat) {
			
				output_cari(&i)	;
				hasil = 1		;
			
		}
		
	}
	if(hasil==0){
	
	cout << "Data tidak di temukan" << endl << endl << endl ;
	
	}
	else 
	{
		cout << endl ;
	}	
	
}
	
void cari_jeniskelamin()			{
	int length					;
	ambildatapgw ( &length ) 	;
	int hasil = 0				;
	string cari					;
	cin.ignore()				;
	cout << "==================================================================================" << endl ;
	cout << "================================ CARI JENIS KELAMIN ==============================" << endl ;
	cout << "==================================================================================" << endl ;
	cout << endl << endl ;
	
	cout << "Masukkan Jenis Kelamin	(SESUAI INPUT KAPITAL) : " ; getline(cin,cari) ;
	
	for (int i = 0 ; i < length ; i++){
		
		if (cari == datap[i].jenis_kelamin) {
			
				output_cari(&i)	;
				hasil = 1		;
			
		}
		
	}
	if(hasil==0){
	
	cout << "Data tidak di temukan" << endl << endl << endl ;
	
	}
	else 
	{
		cout << endl ;
			}	
}
	
void cari_bagian()					{
	int length					;
	ambildatapgw ( &length ) 	;
	int hasil = 0				;
	string cari					;
	cin.ignore()				;
	cout << "==================================================================================" << endl ;
	cout << "=============================== CARI BAGIAN PEKERJAAN ============================" << endl ;
	cout << "==================================================================================" << endl ;
	cout << endl << endl ;
	
	cout << "Masukkan Bagian Pekerjaan	(SESUAI INPUT KAPITAL) : " ; getline(cin,cari) ;
	
	for (int i = 0 ; i < length ; i++){
		
		if (cari == datap[i].pekerjaan) {
			
				output_cari(&i)	;
				hasil = 1		;
			
		}
		
	}
	if(hasil==0){
	
	cout << "Data tidak di temukan" << endl << endl << endl ;
	
	}
	else 
	{
		cout << endl ;
			}	
}

void barang()						{	

	char pilih2	;
	do
	{
	int bykbrg	;
	int pilih	;	
	cout << " ______________________________________________________ \n";
	cout << "|                                                      |\n";
	cout << "|               Database Barang Pabrik                 |\n";
	cout << "|______________________________________________________|\n";
	cout << "|      Silahkan Dipilih :                              |\n";
	cout << "|                         1. Input Data                |\n";
	cout << "|                         2. Lihat Data                |\n";
	cout << "|                         3. Cari Data                 |\n";
	cout << "|                         4. Perbaikan                 |\n";
	cout << "|                         5. Kembali ke menu awal      |\n";
	cout << "|______________________________________________________|\n";
	cout << "                 PILIH : "; cin >> pilih					;
	if (pilih==1)
	{
		cout << "Banyak Data Barang Yang akan Diinput : "				; cin >> bykbrg ;
		inputdata (&bykbrg)												;
		cout << "\nApakah Anda Mau Kembali Ke Menu Pilihan ? [Y/N] : "	; cin >> pilih2 ;
		system ("CLS")													;
	}
	else if (pilih==2)
	{
		outputdata()													;
		cout << "\nApakah Anda Mau Kembali Ke Menu Pilihan ? [Y/N] : "	; cin >> pilih2 ;
		system ("PAUSE")												;
		system ("CLS")													;
		
	}
	else if (pilih==3)
	{
		system ("cls")		;
		caridata (bykbrg)	;
		barang ()			;
	}
	else if (pilih==4)
	{
		system ("CLS")		;
		menuservice ()		;
	}
		else if (pilih==5)
	{
		system ("CLS")		;
		menu ()				;
	}
	else 
	{
		cout << "Pilihan tidak ada"									;
		cout << "\n\n\nTekan Enter Untuk Kembali Ke Menu . . . !\n"	;
		system ("cls")												;
		barang ()													;
	}
	}
	while ( pilih2 == 'y' || pilih2 == 'Y' ) 						;
	
}

int outputbrg(int i,int length)		{
		
	if( i == length )
	{
		system ("PAUSE")	;
		system ("CLS")		;
		 barang()			;
	}
	else
	{
	cout << "Tanggal Masuk           : " << data[i].tglmasuk<<endl			;
	cout << "Kode Barang             : " << data[i].kode<<endl				;
	cout << "---------------------------------------------------------\n"	;
	cout << "Nama Barang             : " << data[i].namabrg<<endl			;
	cout << "Stok Barang             : " << data[i].stok<<endl				;
	cout << "Letak Loker (1/2/3/4/5) : " << data[i].lokerbrg<<endl			;
	cout << "=========================================================\n"	;
	cout << endl 															;
	}
	
	cout << endl					;
	return outputbrg (i+1,length)	;
	
}

void inputdata (int *n)				{
	
	
	tulispabrik.open("DataBarangPabrik.txt", ios::app);
	cout << "=========================================================\n"				;
	cout << "|                      DATA INPUT                       |\n"				;
	cout << "|                  STOK BARANG PABRIK                   |\n"				;
	cout << "=========================================================\n"				;
	
	for ( int i = 0 ; i < *n ; i++ )
	{
		cin.ignore()																	;
		cout << "Tanggal Masuk           : " ; getline(cin, data[i].tglmasuk)			;
		cout << "Kode Barang (8 digit mulai angka 2): " ; cin >> data[i].kode			;
		cout << "---------------------------------------------------------\n"			;
		cout << "Nama Barang             : " ; cin.ignore();getline(cin,data[i].namabrg);
		cout << "Stok Barang             : " ; cin >> data[i].stok						;
		cout << "Letak Loker (1/2/3/4/5) : " ; cin >> data[i].lokerbrg					;
		cout << "=========================================================\n"			;
		cout << endl																	;
		tulispabrik << data[i].tglmasuk		<<endl										;
		tulispabrik << data[i].kode			<<endl										;
		tulispabrik << data[i].namabrg		<<endl										;
		tulispabrik << data[i].stok			<<endl										;
		tulispabrik << data[i].lokerbrg		<<endl										;
	}
	tulispabrik.close()																	;	
}

void outputdata()					{
	
	int pjg																	;	
	system ("cls")															;
	ambildata ( &pjg )														;
	insertionsorting (pjg)													;
	cout << endl << endl													;
	cout << "Banyak Data : " << pjg << endl << endl 						;
	outputbrg (0,pjg)														;
	cout << "=========================================================\n"	;
	cout << "|                      DATA INPUT                       |\n"	;
	cout << "|                  STOK BARANG PABRIK                   |\n"	;
	cout << "=========================================================\n"	;
	system ("pause")														;	
	
}

void ambildata(int *n) 				{
	
	int i = 0							;
	
	baca.open("DataBarangPabrik.txt")	;
	while(true ){
		baca.ignore()					;
		getline(baca,data[i].tglmasuk)	;	
		if (baca.eof())
		{
			
			break;
		}
		baca >> data[i].kode			;
		baca.ignore()					;
		getline(baca,data[i].namabrg)	;
		baca >> data[i].stok			;
		baca >> data[i].lokerbrg		;	
		i++								;
	}
	baca.close()						;
	*n = i								;
	
}

void insertionsorting(int n)		{
	
	pabrik temp								;
	for (int coba = 1 ; coba < n ; coba++ )
	{
		int j=coba							;
		while(data[j].kode < data[j-1].kode)
		{
			temp		= data[j]			;
			data[j]		= data[j-1]			;
			data[j-1]	= temp				;			
			
			j--								;
		}
	}
}

void caridata(int pjg2)				{
	
	
	bool found													;
	int cari, x 												;
	system ("cls")												;
	ambildata(&pjg2)											;
	insertionsorting (pjg2)										;
	cout << "\n\t==CARI DATA BERDASARKAN KODE BARANG==\n"		;
	cout << "Masukan Kode Barang yang ingin dicari : "			; cin >> cari ;
	
	found = false							;
	int i=0									;
	int j=pjg2								;
		while((!found) & (i <= j ) ) {
			
			x = ( i + j ) / 2 				;
			if( cari == data[x].kode )
			found = true					;
			else
			{
				if( cari < data[x].kode )
					j = x - 1 				;
				else
					i = x + 1				;
			}
		}

	if (found) {
	cout << "========================================================="		<< endl	;
	cout << "|                      DATA INPUT                       |"		<< endl	;
	cout << "|                  STOK BARANG PABRIK                   |" 	<< endl	;
	cout << "=========================================================" 	<< endl	;
	cout << "Tanggal Masuk           : " << data[x].tglmasuk				<< endl	;
	cout << "Kode Barang             : " << cari							<< endl	;
	cout << "---------------------------------------------------------" 	<< endl	;
	cout << "Nama Barang             : " << data[x].namabrg					<< endl	;
	cout << "Stok Barang             : " << data[x].stok					<< endl	;
	cout << "Letak Loker (1/2/3/4/5) : " << data[x].lokerbrg				<< endl	;
	cout << "=========================================================" 	<< endl	;
	cout << endl																	;
	}
	else
	{
		cout << "Kode Barang Yang Anda Cari Tidak Ditemukan Dalam Data "	<<endl 	;
	}
}

//materi semester 3



void menuservice(){  // menu perbaikan
	
	char ulang			;
	int pilih			;
	int bykjenis		;
	do
	{
		
	system("CLS")		;
	cout << "+----------------------------------+" << endl	;
	cout << "|******** DATABASE PABRIK *********|" << endl	;
	cout << "+----------------------------------+" << endl	;
	cout << "|********* MENU PERBAIKAN *********|" << endl	;
	cout << "+----------------------------------+" << endl	;
	cout << "| 1. Input Antrian Perbaikan       |" << endl	;
	cout << "| 2. Proses Perbaikan              |" << endl	;
	cout << "| 3. Cek Antrian Perbaikan         |" << endl	;
	cout << "| 4. Riwayat Perbaikan             |" << endl	;
	cout << "| 5. Hapus Riwayat Perbaikan       |" << endl	;
	cout << "| 6. Kembali ke menu barang        |" << endl	;
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
		barang()			;
	}

	else 
	{
	cout << "Angka yang anda masukkan salah"	;	
	}
	cout << "kembali ke menu?(y/n): " 			; cin >> ulang;
	}while(ulang == 'y')						;
}


void proses(){ //memproses antrian terjadinya dequeue atau menghilangkan antrian pertama

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
    int tunggu = 0, i = 0	;
    typeptrqueue bantu		;

    if(queue_kosong()) cout << "Tidak Ada Antrian Perbaikan" << endl << endl;
    else {
    	
		
        bantu = awalqueue	;
		cout << "+-----+-----------------------------------------------------------------------------------+"<<endl			;
        cout << "|*********************************  DAFTAR ANTRIAN PERBAIKAN  ****************************|"<<endl			;	
        cout << "+-----+---------------------------+---------------------------+---------------------------+"<<endl			;
        cout << "| NO  |           Nama            |           barang          |         Kerusakan         |"<<endl			;
        cout << "+-----+---------------------------+---------------------------+---------------------------+"<<endl			;
        do{
        i++		 			;
        cout << "| " 	 << setw(3) 	<< i  << " | "																		;
        cout << setw(25) << bantu->nama <<" | "<<setw(25) << bantu->barang <<" | " << setw(25) << bantu->risk <<" |" << endl;
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
    	
    	cout << "Belum ada Riwayat Perbaikan." << endl	;
    	
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

void pop(){ //menghapus stack/history perbaikan last in first out (dari data paling terbaru)
    typeptrstack hapus, bantu			;
    char konfirm						;

     if (stack_kosong())
		{ cout << "Tidak ada Riwayat Perbaikan !\n";}
    // bantu di paling bawah stack dan hapus di puncak
    else {

        bantu = awalstack				;
        hapus = akhirstack				;

        cout << "+-------------+----------------------------------+" << endl;
        cout << "| No. Service |   Nama Customer  |    Biaya      |" << endl;
        cout << "+-------------+------------------+---------------+" << endl;
        cout << "| " << setw(11) << hapus->no_service << " | ";
        cout << setw(16) << hapus->nama << " |";
        cout << "Rp. " << setw(10) << hapus->biaya << " |" << endl;
        cout << "+-------------+------------------+---------------+" << endl;
        cout << "Ingin Menghapus Riwayat tersebut?(y/n): ";
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

