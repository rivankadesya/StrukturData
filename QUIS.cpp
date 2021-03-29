#include <iostream>
#include <malloc.h>

using namespace std;


typedef struct node *typeptr;

struct pasien{
	  char goldar[20];
	  char nama[1000]; //nim goldar
	  int umur,uas; 
	  bool status;  
};

struct node{
	pasien psn;
	int jmlhnode;
	typeptr next;
};

typeptr kepala;
void sisipnode(pasien IB);
void buatlist();
bool listkosong();
void outputdata();
void hapuslist(string IH);
int bykdata=0;

int main(){
	
	pasien psn[999];
	int pilih;
	int jml;
	string nama;  
	buatlist();
	
	do
	{
		cout<<"\n\n1. input data pasien \n";
		cout<<"2. lihat data pasien \n";
		cout<<"3. cek data pasien\n";
		cout<<"4. hapus data pasien\n";
		cout<<"pilih : "; cin>>pilih;
		
		switch (pilih)
		{
			case 1:
				cout<<"\nmasukan jumlah yang diinput : "; cin>>jml;
				for (int i = 0; i < jml; i++)
				{
				cout<<"nama\t\t: "; cin>>psn[i].nama;
				cout<<"umur\t\t: "; cin>>psn[i].umur;
				cout<<"golongan darah\t: "; cin>>psn[i].goldar;
				if(psn[i].umur>17 && psn[i].umur<=60)
				{
						cout<<"status\t\t: bisa donor\n";
						psn[i].status=true;
				
				}
				else
				{ 
					cout<<"status\t\t: tidak bisa donor\n";
					psn[i].status=false;
				}
			
				sisipnode(psn[i]);
				}
				
			break;
			
			case 2: 
				outputdata();
			break;
			case 3 : 
				cout<<"\ncek kandidat pendonor\n";
					

					outputdata();
				break;
				
			
			case 4: 
				cout<<"masukan nama data yang mau di hapus : "; cin>>nama;
				hapuslist(nama);
				outputdata();
			break;
		}
	}while(true);
}


void buatlist(){
	kepala=(node *)malloc(sizeof(node));
	kepala->next=kepala;
}
	
bool listkosong(){
	if(kepala->next==kepala){
		return true;
	}
	else{
		return false;
	}
}

void sisipnode(pasien IB){
	
	typeptr NB,bantu;
	bykdata++;
	NB=(node *)malloc(sizeof(node));
	NB->psn=IB;
	
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
	
void outputdata()
{
	typeptr bantu;
	bantu=kepala->next;
	
	if(bantu==kepala)
	{
		cout<<"data belum ada";
	}
	else
	{
		//int i=0;
		
		while(bantu!=kepala)
		{
			
			cout<<"\n\nnama : "<<bantu->psn.nama<<endl;
			cout<<"umur : "<<bantu->psn.umur<<endl;
			cout<<"golongan darah: "<<bantu->psn.goldar<<endl;
			if (bantu->psn.status==true)
			{
				cout<<"status\t: bisa donor";
				} else cout<<"status \t: tidak bisa donor";
			bantu=bantu->next;
			
		}
	}
}


void hapuslist(string IH)
{
	typeptr hapus, bantu;
	
	bantu = kepala->next;
	if (bantu == kepala)
	{
		cout<<"List masih kosong";
	} else {
		if (bantu->psn.nama == IH) //Hapus awal list
		{	
			hapus=bantu;
			kepala=bantu->next;
			free(hapus);
		}
		else
		{
			
			//bantu=awal;// cari list yang akan dihapus
			while (bantu->next->psn.nama != IH && bantu->next!=kepala )
			{
				bantu = bantu->next;
			}
			if (bantu->next->psn.nama == IH) //kalo nimnya ketemu
			{
				hapus=bantu->next;
				bantu->next=hapus->next;
				free(hapus);
				//printf("List tidak ditemukan\n");
			}
		}
	}
}
