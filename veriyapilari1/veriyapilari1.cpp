// veriyapilari1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include <chrono>
#include <stdlib.h>

using namespace std;

struct Node {
	int deger;
	Node* sonraki;
	
};

struct Liste {
	Node* bas;
	void olustur();
	void sonaEkle(Node*);
	void basaEkle(Node*);
	void ortayaEkle(Node*);
	void yazdir();
	void guncelle(int , int );
	void sil(int);
	void bosalt(int);
	int sayac=100;
	
};

int main()
{
	Liste* l = new Liste();


	l->olustur();
	l->yazdir();
	


	
	Node* n = new Node();
	for (int i = 1; i <= 100;i++)
	{	
		Node* n = new Node();
		n->deger = i;
		
		l->sonaEkle(n);
	}
	l->yazdir();
	

	
	l->guncelle(20, 40);
	l->yazdir();
	

	
	l->sil(2);
	l->yazdir();
	

	l->bosalt(100);
	l->yazdir();




	
	n = new Node();
	n->deger = 45;
	l->basaEkle(n);
	l->yazdir();
	



	
	n = new Node();
	n->deger = 25;
	l->ortayaEkle(n);
	l->yazdir();
	








	auto begin = std::chrono::high_resolution_clock::now();
	n = new Node();
	n->deger = 38;
	l->sonaEkle(n);
	l->yazdir();
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	cout << "100 elemanli baglantili listede sona ekleme suresi=> " << elapsed.count() << " mikro-saniye" << endl;

	



	l->yazdir();

	return 0;
}

void Liste::olustur() {
	bas = NULL;
	
}

void Liste::guncelle(int index, int deger)
{
	Node* node = new Node();
	node = bas;
	if (index == 1)
	{
		bas->deger = deger;
	}
	
	else
	{
		for (int  i = 0; i < index-1; i++)
		{
			node = node->sonraki;
		}
	}
	node->deger = deger;
}

void Liste::sil(int index)
{
	Node* node1 = new Node();
	node1 = bas;
	for (int i = 0; i < index ; i++)
	{
		node1 = node1->sonraki;
	}
	node1->sonraki->deger=	NULL;
	sayac = sayac -1;
}
	
void Liste::bosalt(int index)
{
	Node* node5 = new Node();
	node5 = bas;
	for (int i = 0; i < index; i++)
	{
		



	}
	
}


void Liste::sonaEkle(Node* n) {
	if (bas == NULL) {
		bas = n;
		return;
	}
	Node* tara;
	tara = bas;
	while (tara->sonraki) {
		tara = tara->sonraki;
	}
	tara->sonraki = n;
	sayac = sayac + 1;
}

void Liste::basaEkle(Node* n) {
	if (bas == NULL)
		bas = n;
	else {
		n->sonraki = bas;
		bas = n;
	}
	sayac = sayac+1;

}

void Liste::ortayaEkle(Node* n) {
	if (bas == NULL) {
		bas = n;
		return;
	}
	int dugumSayisi = 0;
	Node* tara;
	tara = bas;
	while (tara) {
		dugumSayisi++;
		tara = tara->sonraki;
	}
	tara = bas;
	for (int i = 0; i < dugumSayisi / 2 - 1;i++)
		tara = tara->sonraki;
	n->sonraki = tara->sonraki;
	tara->sonraki = n;
	sayac = sayac + 1;
}

void Liste::yazdir() {
	Node* tara;
	tara = bas;
	if (!tara) {
		cout << "Liste bos!!!" << endl;
		return;
	}
	while (tara) {
		cout << tara->deger << " ";
		tara = tara->sonraki;
	}
	cout << endl;
}
