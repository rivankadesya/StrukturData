#include <iostream>
#include <string.h>

using namespace std;

typedef struct{
	
	string nama, agama, darah		; 
	string alamat, ttl				;
	int nik							;
	
	
}data_ktp				;

data_ktp ktp[999]		;
void input()			;
void output()			;
int i ,bykdata, baru	;


int main(){
	
	int pilih			;
	char ulang = 'y'	;
	while (ulang='y')	{
		system("CLS")							;
		cout << "Pilih Pilihan Anda"	<< endl ;
		cout << "1.Input Data"			<< endl ;
		cout << "2.Lihat Data"			<< endl ;
		cout << "3.Keluar"				<< endl ;
		cout << "Masukkan Pilihan Anda = "		; cin >> pilih	;
		
		if 		(pilih == 1){
			
			system("CLS")	;
			input()			;
			
			
		}
		else if (pilih == 2){
			
			system("CLS")	;
			output()		;
			
			
		}
		else if (pilih == 3){
			
			system("CLS")	;
			break			;
			system("EXIT")	;
			
		}
		else				{
			
			system("CLS")	;
			main()			;
			
		}
		cout<<"Kembali ke Menu? (y/t) : ";cin>>ulang;
	}


}



void input()			{
	
	cout << "Banyak data yang akan di input : " ;cin >> baru ;
	for( i=0;i <baru; i++){
		cout << "Data Ke - " << bykdata+1 << endl << endl									;
		cout << "NIK			: "			; cin >> ktp[bykdata].nik						;	
		cout << "Nama			: "			; cin.ignore();getline(cin,ktp[bykdata].nama)	;
		cout << "Alamat			: "			; getline(cin,ktp[bykdata].alamat)				;
		cout << "Tempat, Tanggal Lahir	: "	; getline(cin,ktp[bykdata].ttl)					;
		cout << "Agama			: "			; getline(cin,ktp[bykdata].agama)				;
		cout << "Golongan Darah		: "		; getline(cin,ktp[bykdata].darah)				;
		cout << endl << endl	;
		bykdata++				;
		
	}
	

}

void output()			{
	
		for( i=0;i < bykdata; i++){
		cout << "Data Ke - " << i+1 << endl 	<< endl					;
		cout << "NIK			: " 			<< ktp[i].nik << endl	;	
		cout << "Nama			: " 			<< ktp[i].nama << endl	;
		cout << "Alamat			: " 			<< ktp[i].alamat<< endl	;
		cout << "Tempat, Tanggal Lahir	: "		<< ktp[i].ttl<< endl	;
		cout << "Agama			: " 			<< ktp[i].agama<< endl	;
		cout << "Golongan Darah		: " 		<< ktp[i].darah<< endl	;
		cout << endl << endl	;
	}
	
}
