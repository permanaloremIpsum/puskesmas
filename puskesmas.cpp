#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "xcurse.h"
#define MAX 60

using namespace std;

struct pasien{
	int id[MAX];
	string nama[MAX];
	string gender[MAX];
	string umur[MAX];
	string alamat[MAX];
	int count;
} psn;

struct queue1{
	string data_periksa[MAX];
	int awal, akhir;
}antrean_periksa;

struct queue2{
	string data_obat[MAX];
	int awal, akhir;
}antrean_obat;

// bool full_periksa(){
// 	if(antrean_periksa.akhir == MAX-1)
// 		return true;
// 	else
// 		return false;
// }

// bool empty_periksa(){
// 	if(antrean_periksa.akhir == -1)
// 		return true;
// 	else
// 		return false;
// }

void inQueue_periksa(string nama){
	antrean_periksa.data_periksa[antrean_periksa.akhir] = nama;
	antrean_periksa.akhir++;
}

void inQueue_obat(string nama){
	antrean_obat.data_obat[antrean_obat.akhir] = nama;
	antrean_obat.akhir++;
}

void add_pasien(){
	xc::color(10, 0);
	xc::xy(40,6); cout << "Masukkan Data-Data Pasien : ";
	xc::color(7, 0);
    xc::xy(40,8);  cout << "No KTP : "; cin >> psn.id[psn.count];
	xc::xy(40,9);  cout << "Nama   : "; cin >> psn.nama[psn.count];
	xc::xy(40,10); cout << "Gender : "; cin >> psn.gender[psn.count];
	xc::xy(40,11); cout << "Umur   : "; cin >> psn.umur[psn.count];
	xc::xy(40,12); cout << "Alamat : "; cin >> psn.alamat[psn.count];
	// antrean_periksa.data_periksa[antrean_periksa.akhir]
	inQueue_periksa(psn.nama[psn.count]);
	psn.count++;
}

void input_antrean(){
	xc::color(10, 0);
	xc::xy(40,6); cout << "Cari Pasien : ";
	xc::color(7, 0);
    xc::xy(40,8);  cout << "Data : "; cin >> antrean_periksa.data_periksa[antrean_periksa.akhir];

	// string nama = psn.nama[psn.count];
	// antrean_periksa.data[antrean_periksa.akhir]=psn.nama[psn.count];
	antrean_periksa.akhir++;
	// antrean_periksa.akhir++;
}

void proses_periksa(){
	int i;
	xc::xy(30,8);cout << "Pasien dengan Nama ";
	xc::color(10, 0);
	cout << "\"" << antrean_periksa.data_periksa[antrean_periksa.awal] << "\"";
	xc::color(7, 0);
	cout << " dipersilakan masuk ke ruang periksa";
	inQueue_obat(antrean_periksa.data_periksa[antrean_periksa.awal]);
	for (int i = antrean_periksa.awal; i < antrean_periksa.akhir; ++i){
		antrean_periksa.data_periksa[i] = antrean_periksa.data_periksa[i+1];
	}
	antrean_periksa.akhir--;
	// cout << "Proses Antrian";
	getch();
}

void proses_obat(){
	int i;
	xc::xy(30,8);cout << "Pasien dengan Nama ";
	xc::color(10, 0);
	cout << "\"" << antrean_obat.data_obat[antrean_obat.awal] << "\"";
	xc::color(7, 0);
	cout << " dipersilakan masuk ke ruang ambil obat";
	for (int i = antrean_obat.awal; i < antrean_obat.akhir; ++i){
		antrean_obat.data_obat[i] = antrean_obat.data_obat[i+1];
	}
	antrean_obat.akhir--;
	getch();
}

int kolom[] = {35, 40};
int baris[] = {5, 25};
int value = 16;

void show_antrean_periksa(){
	system("cls");
	xc::color(10, 0);
	xc::xy(35,3); cout << "Antrian Pasien : ";
	xc::color(7, 0);
	string header[] = {" No", " Nama Pasien"};
	for(auto r = 0; r < 2; ++r)
	{
		xc::xy(kolom[r], baris[0]);
		cout << header[r];
	}

	//perulangan yg digunakan untuk menggambar garis mendatar
	for(auto i = kolom[0]-1; i <= kolom[2] + 61; ++i){
		xc::xy(i, baris[0] - 1);
		cout << char(196);
		xc::xy(i, baris[0] + 1);
		cout << char(196);
		xc::xy(i, baris[1] - 1);
		cout << char(196);
		xc::xy(i, baris[1] + 1);
		cout << char(196);
		

		//perulangan untuk menggambar garis ke bawah di bagian tengah
		for(auto j = baris[0]-1; j <= baris[1] - 1; ++j){
			if(j==4){
				xc::xy(kolom[1]-1, j);
				cout << char(194);
				// xc::xy(kolom[2]-1, j);
				// cout << char(194);
				// xc::xy(kolom[3]-1, j);
				// cout << char(194);
				// xc::xy(kolom[4]-1, j);
				// cout << char(194);
			}
			else if(j==6){
				xc::xy(kolom[1]-1, j);
				cout << char(197);
				// xc::xy(kolom[2]-1, j);
				// cout << char(197);
				// xc::xy(kolom[3]-1, j);
				// cout << char(197);
				// xc::xy(kolom[4]-1, j);
				// cout << char(197);
			}
			else if(j==24){
				xc::xy(kolom[1]-1, j);
				cout << char(193);
				// xc::xy(kolom[2]-1, j);
				// cout << char(193);
				// xc::xy(kolom[3]-1, j);
				// cout << char(193);
				// xc::xy(kolom[4]-1, j);
				// cout << char(193);
			}
			else{
				xc::xy(kolom[1]-1, j);
				cout << char(179);
				// xc::xy(kolom[2]-1, j);
				// cout << char(179);
				// xc::xy(kolom[3]-1, j);
				// cout << char(179);
				// xc::xy(kolom[4]-1, j);
				// cout << char(179);
			}
		}

		//perulangan untuk menggambar garis ke bawah 
		//di bagian sisi kanan dan kiri
		for(auto k = baris[0]-1; k <= baris[1] + 1; ++k){
			if(k==4){
				xc::xy(kolom[0]-1, k);
				cout << char(218);
				xc::xy(kolom[4]+50, k);
				cout << char(191);
			}
			else if(k==6){
				xc::xy(kolom[0]-1, k);
				cout << char(195);
				xc::xy(kolom[4]+50, k);
				cout << char(180);
			}
			else if(k==24){
				xc::xy(kolom[0]-1, k);
				cout << char(195);
				xc::xy(kolom[4]+50, k);
				cout << char(180);
			}
			else if(k==26){
				xc::xy(kolom[0]-1, k);
				cout << char(192);
				xc::xy(kolom[4]+50, k);
				cout << char(217);
			}
			else{
				xc::xy(kolom[0]-1, k);
				cout << char(179);
				xc::xy(kolom[4]+50, k);
				cout << char(179);
			}
		}

		for (auto i = 0; i < antrean_periksa.akhir; ++i)
		{
			int nomer = 0;
			for (int j = baris[0]+2; j <= baris[1]-2; ++j)
			{
				if(antrean_periksa.data_periksa[nomer] == ""){
					xc::xy(kolom[0]+1, j);
					cout << "";
				} else {
					xc::xy(kolom[0]+1, j);
					cout << nomer+1;
					xc::xy(kolom[1], j);
					cout << antrean_periksa.data_periksa[nomer];
				}
				nomer++;
			}
			
		}
		xc::xy(36, 25);cout << "Press Any Key to Continue...";
	}
	getch();
}

void show_antrean_obat(){
	system("cls");
	xc::color(10, 0);
	xc::xy(35,3); cout << "Antrian Ambil Obat : ";
	xc::color(7, 0);
	string header[] = {" No", " Nama Pasien"};
	for(auto r = 0; r < 2; ++r)
	{
		xc::xy(kolom[r], baris[0]);
		cout << header[r];
	}

	//perulangan yg digunakan untuk menggambar garis mendatar
	for(auto i = kolom[0]-1; i <= kolom[2] + 61; ++i){
		xc::xy(i, baris[0] - 1);
		cout << char(196);
		xc::xy(i, baris[0] + 1);
		cout << char(196);
		xc::xy(i, baris[1] - 1);
		cout << char(196);
		xc::xy(i, baris[1] + 1);
		cout << char(196);
		

		//perulangan untuk menggambar garis ke bawah di bagian tengah
		for(auto j = baris[0]-1; j <= baris[1] - 1; ++j){
			if(j==4){
				xc::xy(kolom[1]-1, j);
				cout << char(194);
				// xc::xy(kolom[2]-1, j);
				// cout << char(194);
				// xc::xy(kolom[3]-1, j);
				// cout << char(194);
				// xc::xy(kolom[4]-1, j);
				// cout << char(194);
			}
			else if(j==6){
				xc::xy(kolom[1]-1, j);
				cout << char(197);
				// xc::xy(kolom[2]-1, j);
				// cout << char(197);
				// xc::xy(kolom[3]-1, j);
				// cout << char(197);
				// xc::xy(kolom[4]-1, j);
				// cout << char(197);
			}
			else if(j==24){
				xc::xy(kolom[1]-1, j);
				cout << char(193);
				// xc::xy(kolom[2]-1, j);
				// cout << char(193);
				// xc::xy(kolom[3]-1, j);
				// cout << char(193);
				// xc::xy(kolom[4]-1, j);
				// cout << char(193);
			}
			else{
				xc::xy(kolom[1]-1, j);
				cout << char(179);
				// xc::xy(kolom[2]-1, j);
				// cout << char(179);
				// xc::xy(kolom[3]-1, j);
				// cout << char(179);
				// xc::xy(kolom[4]-1, j);
				// cout << char(179);
			}
		}

		//perulangan untuk menggambar garis ke bawah 
		//di bagian sisi kanan dan kiri
		for(auto k = baris[0]-1; k <= baris[1] + 1; ++k){
			if(k==4){
				xc::xy(kolom[0]-1, k);
				cout << char(218);
				xc::xy(kolom[4]+50, k);
				cout << char(191);
			}
			else if(k==6){
				xc::xy(kolom[0]-1, k);
				cout << char(195);
				xc::xy(kolom[4]+50, k);
				cout << char(180);
			}
			else if(k==24){
				xc::xy(kolom[0]-1, k);
				cout << char(195);
				xc::xy(kolom[4]+50, k);
				cout << char(180);
			}
			else if(k==26){
				xc::xy(kolom[0]-1, k);
				cout << char(192);
				xc::xy(kolom[4]+50, k);
				cout << char(217);
			}
			else{
				xc::xy(kolom[0]-1, k);
				cout << char(179);
				xc::xy(kolom[4]+50, k);
				cout << char(179);
			}
		}

		for (auto i = 0; i < antrean_obat.akhir; ++i)
		{
			int nomer = 0;
			for (int j = baris[0]+2; j <= baris[1]-2; ++j)
			{
				if(antrean_obat.data_obat[nomer] == ""){
					xc::xy(kolom[0]+1, j);
					cout << "";
				} else {
					xc::xy(kolom[0]+1, j);
					cout << nomer+1;
					xc::xy(kolom[1], j);
					cout << antrean_obat.data_obat[nomer];
				}
				nomer++;
			}
			
		}
		xc::xy(36, 25);cout << "Press Any Key to Continue...";
	}
	getch();
}

int col[] = {25, 31, 51, 60, 72};
int row[] = {5, 25};
int isi = 7;

void show_pasien(){
	system("cls");
	xc::color(10, 0);
	xc::xy(25,3); cout << "Daftar Pasien : ";
	xc::color(7, 0);
	string header[] = {"No", "Nama Pasien", "Gender", "Umur", "Alamat"};
	for(auto i = 0; i < 5; ++i)
	{
		xc::xy(col[i], row[0]);
		cout << header[i];
	}

	//perulangan yg digunakan untuk menggambar garis mendatar
	for(auto i = col[0]-1; i <= col[4] + 20; ++i){
		xc::xy(i, row[0] - 1);
		cout << char(196);
		xc::xy(i, row[0] + 1);
		cout << char(196);
		xc::xy(i, row[1] - 1);
		cout << char(196);
		xc::xy(i, row[1] + 1);
		cout << char(196);
		

		//perulangan untuk menggambar garis ke bawah di bagian tengah
		for(auto j = row[0]-1; j <= row[1] - 1; ++j){
			if(j==4){
				xc::xy(col[1]-1, j);
				cout << char(194);
				xc::xy(col[2]-1, j);
				cout << char(194);
				xc::xy(col[3]-1, j);
				cout << char(194);
				xc::xy(col[4]-1, j);
				cout << char(194);
			}
			else if(j==6){
				xc::xy(col[1]-1, j);
				cout << char(197);
				xc::xy(col[2]-1, j);
				cout << char(197);
				xc::xy(col[3]-1, j);
				cout << char(197);
				xc::xy(col[4]-1, j);
				cout << char(197);
			}
			else if(j==24){
				xc::xy(col[1]-1, j);
				cout << char(193);
				xc::xy(col[2]-1, j);
				cout << char(193);
				xc::xy(col[3]-1, j);
				cout << char(193);
				xc::xy(col[4]-1, j);
				cout << char(193);
			}
			else{
				xc::xy(col[1]-1, j);
				cout << char(179);
				xc::xy(col[2]-1, j);
				cout << char(179);
				xc::xy(col[3]-1, j);
				cout << char(179);
				xc::xy(col[4]-1, j);
				cout << char(179);
			}
		}

		//perulangan untuk menggambar garis ke bawah 
		//di bagian sisi kanan dan kiri
		for(auto k = row[0]-1; k <= row[1] + 1; ++k){
			if(k==4){
				xc::xy(col[0]-1, k);
				cout << char(218);
				xc::xy(col[4]+20, k);
				cout << char(191);
			}
			else if(k==6){
				xc::xy(col[0]-1, k);
				cout << char(195);
				xc::xy(col[4]+20, k);
				cout << char(180);
			}
			else if(k==24){
				xc::xy(col[0]-1, k);
				cout << char(195);
				xc::xy(col[4]+20, k);
				cout << char(180);
			}
			else if(k==26){
				xc::xy(col[0]-1, k);
				cout << char(192);
				xc::xy(col[4]+20, k);
				cout << char(217);
			}
			else{
				xc::xy(col[0]-1, k);
				cout << char(179);
				xc::xy(col[4]+20, k);
				cout << char(179);
			}
		}
	}
	
	

	/*for (int i = 0; i < psn.count; ++i)
	{
		cout << "No KTP : " << psn.id[i] << endl;
		cout << "Nama   : " << psn.nama[i] << endl;
		cout << "Gender : " << psn.gender[i] << endl;
		cout << "Umur   : " << psn.umur[i] << endl;
		cout << "Alamat : " << psn.alamat[i] << endl;
	} */

	
	for (auto i = 0; i < psn.count; ++i)
	{
		// xc::xy(col[i], isi);
		// cout << nomer;
		int nomer = 0;
		for (int j = row[0]+2; j <= row[1]-2; ++j)
		{
			if(psn.id[nomer] == 0){
				xc::xy(col[0]+1, j);
				cout << "";
			} else {
				xc::xy(col[0]+1, j);
				cout << nomer+1;
				xc::xy(col[1], j);
				cout << psn.nama[nomer];
				xc::xy(col[2], j);
				cout << psn.gender[nomer];
				xc::xy(col[3], j);
				cout << psn.umur[nomer];
				xc::xy(col[4], j);
				cout << psn.alamat[nomer];
			}
			nomer++;
		}
		
	}
	xc::xy(26, 25);cout << "Press Any Key to Continue...";
	getch();
}

int colpts[] = {35, 73,};
int rowpts[] = {5, 7, 16, 18};

bool repeat = true;

void show_menu(){
	system("cls");
	// Perulangan yg digunakan untuk membuat garis yg mendatar
	for(auto i = colpts[0]; i <= colpts[1]; ++i){		
		xc::xy(i, rowpts[0]);
		cout << char(196);
		xc::xy(i, rowpts[1]);
		cout << char(196);
		xc::xy(i, rowpts[2]);
		cout << char(196);
		xc::xy(i, rowpts[3]);
		cout << char(196);

		// perulangan yg digunakan untuk membuat garis yg menurun
		for(auto j = rowpts[0]; j <= rowpts[3]; ++j){
			if(j==rowpts[0]){
				xc::xy(colpts[0], j);
				cout << char(218);
				xc::xy(colpts[1], j);
				cout << char(191);
			} else if(j==rowpts[1]){
				xc::xy(colpts[0], j);
				cout << char(195);
				xc::xy(colpts[1], j);
				cout << char(180);
			} else if(j==rowpts[2]){
				xc::xy(colpts[0], j);
				cout << char(195);
				xc::xy(colpts[1], j);
				cout << char(180);
			} else if(j==rowpts[3]){
				xc::xy(colpts[0], j);
				cout << char(192);
				xc::xy(colpts[1], j);
				cout << char(217);
			} else{
				xc::xy(colpts[0], j);
				cout << char(179);
				xc::xy(colpts[1], j);
				cout << char(179);
			}
		}
	}
}

int main(){
	int pilih;
	// init();
	do{
		show_menu();
		xc::xy(43,6); cout <<  "+ Manajemen Puskesmas +";
		xc::xy(40,8); cout <<  "| 1 |  Daftar Pasien";
		xc::xy(40,9); cout <<  "| 2 |  Lihat Pasien";
		xc::xy(40,10); cout << "| 3 |  Lihat Antrian Periksa";
		xc::xy(40,11); cout << "| 4 |  Lihat Antrian Obat";
		xc::xy(40,12); cout << "| 5 |  Masukkan Antrian";
		xc::xy(40,13); cout << "| 6 |  Proses Antrian Periksa";
		xc::xy(40,14); cout << "| 7 |  Proses Antrian Obat";
		xc::xy(40,15); cout << "| 8 |  Keluar";
		xc::xy(40,17); cout << "Masukkan Pilihan : ";
		xc::xy(60,17); cin >> pilih;
		system("cls");
		switch(pilih){
			case 1: add_pasien(); break;
			case 2: show_pasien(); break;
			case 3: show_antrean_periksa(); break;
			case 4: show_antrean_obat(); break;
			case 5: input_antrean(); break;
			case 6: proses_periksa(); break;
			case 7: proses_obat(); break;
			case 8: exit(0); break;
		}
	}
	while(pilih!=0);
	
	// show_pasien();

	return 0;
}