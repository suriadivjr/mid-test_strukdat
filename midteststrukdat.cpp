/*
Author    		: SURIADI VAJRAKARUNA
NPM		        : 140810180038
Deskripsi	    : Mid-term test 
Tahun           : 2019
*/

#include <iostream>
using namespace std;

struct Order
{
	char nama[30];
	int jumlah;
	int harga;
	Order* next;
};

typedef Order* pointer;
typedef pointer List;

void createList (List& First)
{
	First=NULL;
}

void createElmnt (List& First, pointer& pBaru)
{
	pBaru=new Order;
	cout << "Nama Makanan: "; cin.ignore(); cin.getline(pBaru->nama,30);
	cout << "Jumlah Pesanan: "; cin >> pBaru->jumlah;
	cout << "Harga Satuan: "; cin >> pBaru->harga;
	pBaru->next=NULL;
}

void insertLast (List& First, pointer pBaru)
{
	pointer last;
	if (First==NULL) First=pBaru;
	else 
	{
		last=First;
		while (last->next!=NULL)
		{
			last=last->next;
		}
		last->next=pBaru;
	}
}

void traversal (List First)
{
	pointer pBantu=First;
	int i=1;
	while (pBantu!=NULL)
	{
		cout << "Nomor: " << i << endl;
		cout << "\tNama Makanan: " << pBantu->nama << endl;
		cout << "\tJumlah Pesanan: " << pBantu->jumlah << endl;
		cout << "\tHarga Satuan: " << pBantu->harga << endl;
		i++;
		pBantu=pBantu->next; 
	}
}

void update (List& First, pointer& pToUpdate)
{
	pToUpdate=First;
	int i=1;
	while (pToUpdate!=NULL)
	{
		cout << "UPDATE Nomor: " << i << endl;
		cout << "\tNama Makanan: " << pToUpdate->nama << endl;
		cout << "\tHarga Satuan: " << pToUpdate->harga << endl;
		cout << "\tJumlah Pesanan Baru: "; cin >> pToUpdate->jumlah;
		i++;
		pToUpdate=pToUpdate->next; 
	}	
}

void swap(pointer& a, pointer& b)
{
	int temp=a->jumlah;
	a->jumlah=b->jumlah;
	b->jumlah=temp;
}

void sorting (List& First)
{
	int swapped;
	pointer p1;
	pointer p2=NULL;
	
	if (First==NULL)
	{
		return;
	}

	do
	{
		swapped=0;
		p1=First;
		while (p1->next!=p2)
		{
			if (p1->jumlah<p1->next->jumlah)
			{
				swap(p1,p1->next);
				swapped=1;
			}
			p1=p1->next;
		}
		p2=p1;	
	}
	while (swapped);
}

int main(int argc, char** argv) 
{
	List x;
	pointer p,pToUpdate;
	int n;
	char pemesan[30];
	
	createList(x);
	
	cout << "Nama Pemesan: "; cin.ignore(); cin.getline(pemesan,30);
	cout << "Banyak menu yang ingin dimasukkan: "; cin >> n;
	for (int i=0; i<n; i++)
	{
		createElmnt(x,p);
		insertLast(x,p);
	}
	cout << endl;
	cout << "Nama Pemesan: " << pemesan << endl;
	traversal(x);
	cout << endl;
	update(x,pToUpdate);
	cout << "Nama Pemesan: " << pemesan << endl;
	sorting(x);
	traversal(x);
	
	
	
	return 0;
}
