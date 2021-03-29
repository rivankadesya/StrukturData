#include <iostream>
#include <malloc.h>

//menggunakan kodingan linked list melingkar 
//referensi PPT pak simon

using namespace std;
typedef int typeinfo;
typedef struct typenode *typeptr;

struct data{
	
	char goldar[3];
	char nama[100]; 
	int umur; 
	bool status;  
	
};

struct typenode{
	
	data pasien;
	int jmlhnode;
	typeptr next;
	
};


typeptr kepala;
int bykdata = 0;
typeptr awal, akhir;
string namahapus;
void balik();
void buatlist();
void sisiplist(data IB);
void cetakhasil();
void menu();
void input();
void output();
void cek();
void hapus(string IH);
int listkosong();
data pasien[1000];

int main(){ //Done
	
	buatlist();
	menu();
}

void menu(){ //Done

	int pilih;

	cout << "Unit Pelayanan Transfusi Darah" << endl
		 << endl;
	cout << "------------------------------" << endl
		 << endl;
	cout << "Daftar Menu :" << endl;
	cout << "1.Input data" << endl;
	cout << "2.Lihat data" << endl;
	cout << "3.Cek kandidat" << endl;
	cout << "4.Hapus Data" << endl;
	cout << "5.Keluar" << endl;
	cout << "------------------------------" << endl;
	cout << "Pilih : ";
	cin >> pilih;

	if (pilih == 1)
	{

		system("CLS");
		input();
	}

	else if (pilih == 2)
	{

		system("CLS");
		output();
	}

	else if (pilih == 3)
	{

		system("CLS");
		cek();
	}

	else if (pilih == 4)
	{

		system("CLS");
		cout << "Masukkan Nama yang ingin di hapus : " ; cin >> namahapus;
		hapus(namahapus);
	}

	else if (pilih == 5)
	{

		system("EXIT");
	}

	else
	{

		system("CLS");
		menu();
	}
}

void input(){ // Done
		int byk;
		cout << endl	;
		cout<<"Banyak Pendonor : "; cin>>byk;
		cout << endl	;
		
				for (int i = 0; i < byk; i++)
				{
					
				cout << endl << endl;
				cout << "Pendonor ke - " << i + 1 << endl ;
				cout << "Nama            : "; cin>>pasien[bykdata].nama;
				cout << "Umur            : "; cin>>pasien[bykdata].umur;
				cout << "Golongan darah  : "; cin>>pasien[bykdata].goldar;
				
				if(pasien[i].umur < 17 || pasien[i].umur > 60)
				
				{
					
				cout << "Status          : Tidak bisa Donor";
				cout << endl ;
				pasien[i].status=false;
				
				}
				else
				{ 
				cout << "Status          : bisa Donor";
				cout << endl ;
				pasien[i].status=true;
				}
			
				sisiplist(pasien[i]);
				}
	balik();
}

void sisiplist(data IB){
	
	typeptr NB,bantu;
	bykdata++;
	NB=(typenode *)malloc(sizeof(typenode));
	NB->pasien=IB;
	
	if(listkosong())
	{ 	
		NB->next=kepala;
		kepala->next=NB;
		kepala->jmlhnode=bykdata;
		
	}
	else
	{	
		bantu=kepala->next;
		while(bantu->next!=kepala){
			bantu=bantu->next;
		}
		
		if(bantu->next==kepala)
		{	
			NB->next=kepala;
			bantu->next=NB;
			kepala->jmlhnode=bykdata;
		}	
	}
	
}

void cek(){
	
typeptr bantu;
string cari;
char pilih;

cout << "Masukan no barang : ";
cin >> cari;
bantu=kepala->next;
while (bantu != kepala)
{
	
	if(bantu->pasien.goldar == cari){
		
		cout << endl << endl;
		cout << "Nama           : "<<bantu->pasien.nama<<endl;
		cout << "Umur           : "<<bantu->pasien.umur<<endl;
		cout << "Golongan darah : "<<bantu->pasien.goldar<<endl;
		
	}
	
	bantu = bantu->next;
};
	
	
}

void hapus(string IH){
	
	typeptr hapus, bantu;
	
	bantu = kepala->next;
	if (bantu == kepala)
	{
		cout<<"List masih kosong";
	} else {
		if (bantu->pasien.nama == IH) 
		{	
			hapus=bantu;
			kepala=bantu->next;
			free(hapus);
		}
		else
		{
			
			
			while (bantu->next->pasien.nama != IH && bantu->next!=kepala )
			{
				bantu = bantu->next;
			}
			if (bantu->next->pasien.nama == IH) 
			{
				hapus=bantu->next;
				bantu->next=hapus->next;
				free(hapus);
			
			}
		}
	}
	
	balik();
	
}

void buatlist(){ //Done

	kepala=(typenode *)malloc(sizeof(typenode));
	kepala->next=kepala;
	
}

int listkosong(){ //Done
	if (awal == NULL)
		return (true);
	else
		return (false);
}


void output(){ //Done
	
	
	typeptr bantu;
	bantu=kepala->next;
	
	if(bantu==kepala)
	{
		cout<<"data belum ada";
	}
	else
	{
		
		
		while(bantu!=kepala)
		{
			cout << endl << endl;
			cout << "Nama           : "<<bantu->pasien.nama<<endl;
			cout << "Umur           : "<<bantu->pasien.umur<<endl;
			cout << "Golongan darah : "<<bantu->pasien.goldar<<endl;
			if (bantu->pasien.status==true)
			{
				
			cout << "Status         : tidak bisa donor";
				} else 
			cout << "status         : bisa donor";
			bantu=bantu->next;
			
		}
	}
	balik();
}



void balik(){
	
	char pilih;
	cout << endl << endl << endl ;
	cout << "Kembali ke Menu(y/n)? " ;cin >> pilih;
	if (pilih== 'y') {
		
		system("CLS");
		menu();
	}
	
	else {
		system("EXIT");
	}
}

