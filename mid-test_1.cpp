/*
Author 		: M Reza Atthariq Kori 
NPM 		: 140810180060
Kelas		: B
Tanggal		: 24 April 2019
Deskripsi	: Program Mengentri dan mengupdate data pada single Linked List
*/
#include<iostream>
using namespace std;

struct ElemList{
	int nomor;
	char makanan[30];
	char harga[10];
	int jumlah;
	ElemList* next;
};

typedef ElemList* pointer;
typedef pointer List;

void createList(List& First){
    First=NULL;
}

void createElement(pointer& pBaru){
    pBaru=new ElemList;
    cout<<"Masukkan Nomor daftar : ";cin>>pBaru->nomor;
    cout<<"Masukkan Nama Makanan : ";cin.ignore();cin.getline(pBaru->makanan,30);
    cout<<"Masukkan Harga satuan : ";cin>>pBaru->harga;
    pBaru->jumlah=0;
    pBaru->next=NULL;
}

void insertLast(List& First, pointer pBaru){
    pointer last;
    if(First==NULL){
        First=pBaru;
    }
    else{
        last=First;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=pBaru;
    }
}

void traversal(List First){
	cin.ignore();
    pointer pBantu;
    if(First==NULL){
        cout<<"List Kosong"<<endl;
    }
    else{
        pBantu=First;
        do{
            cout<<pBantu->nomor<<"\t"<<
            pBantu->makanan<<"\t\t"<<pBantu->jumlah<<"\t"<<pBantu->harga<<endl;
            pBantu=pBantu->next;
        }
        while(pBantu!=NULL);
    }
}

void sorting(List& First, pointer pBaru);

void update(List& First){
    pointer pBantu;
    pBantu=First;
    while(pBantu!=NULL){
        cout<<"Update jumlah pesanan "<<pBantu->makanan<<" : ";cin>>pBantu->jumlah;
        pBantu=pBantu->next;
    }
}

int main(){
    List l;
    pointer p;
    int n;
    char nama[15];
    
    cout<<"Masukkan nama pemesan : "; cin.ignore();cin.getline(nama,15);
    cout<<"Masukkan banyak jenis makanan : ";cin>>n;
	cout<<"\n";    
    
    createList(l);
    for(int i=0;i<n;i++){
        cout<<"Makanan ke-"<<i+1<<endl;
        createElement(p);
        insertLast(l,p);
        cout<<endl;
    }
    cout<<"PESANAN "<<endl;
    cout<<"Nama Pemesan : "<<nama<<endl;
    cout<<"No\tNama\t\t\tJumlah\tHarga Satuan"<<endl;
    traversal(l);
    cout<<endl;    
    cout<<"\nUpdate Jumlah Makanan\n\n";
    update(l);
    cout<<"\nHasil Update"<<endl<<endl;
    cout<<"No\tNama\t\t\tJumlah\tHarga Satuan"<<endl;
    traversal(l);
}

