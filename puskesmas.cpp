#include <iostream>
#include <Windows.h>
#include "xcurse.h"

using namespace std;

int col[] = {25, 31, 51, 60, 72};
int row[] = {5, 25};

void show_pasien(){
	system("cls");
	xc::color(10, 0);
	xc::xy(25,3); cout << "Daftar Pasien : ";
	xc::color(7, 0);
	string header[] = {"No", "Nama Pasien", "Gender", "TTL", "Alamat"};
	for(auto i = 0; i < 5; ++i)
	{
		xc::xy(col[i], row[0]);
		cout << header[i];
	}

	// perulangan yg digunakan untuk menggambar garis mendatar
	for(auto i = col[0]-1; i <= col[4] + 20; ++i){
		xc::xy(i, row[0] - 1);
		cout << char(196);
		xc::xy(i, row[0] + 1);
		cout << char(196);
		xc::xy(i, row[1] - 1);
		cout << char(196);
		xc::xy(i, row[1] + 1);
		cout << char(196);
		

		// perulangan untuk menggambar garis ke bawah di bagian tengah
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

		// perulangan untuk menggambar garis ke bawah 
		// di bagian sisi kanan dan kiri
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
		// xc::xy(25, 27);cout << "Selesai";		
	}
}

int colpts[] = {35, 66,};
int rowpts[] = {5, 7, 12, 14};

bool repeat = true;

void show_menu(){
	system("cls");
	int pilih;

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

	xc::xy(40,6); cout <<  "+ Manajemen Puskesmas +";
	xc::xy(40,8); cout <<  "| 1 |    Daftar Pasien";
	xc::xy(40,9); cout <<  "| 2 |    Lihat Pasien";
	xc::xy(40,10); cout << "| 3 |    Lihat Antrian";
	xc::xy(40,11); cout << "| 4 |    Proses Antrian";
	xc::xy(40,13); cout << "Masukkan Pilihan : ";
	pilihan :
		xc::xy(60,13); cin >> pilih;

	if(pilih==1){
		cout << "Daftar Pasien";
	}else if(pilih==2){
		system("cls");
		show_pasien();
	}else if(pilih==3){
		cout << "Lihat Antrian";
	}else if(pilih==4){
		cout << "Proses Antrian";
	}else{
		xc::xy(38,2); cout << "Pilihan yang Anda Masukkan";
		xc::xy(43,3); cout << "Tidak Terdaftar!!!";
		Sleep(5000);
		xc::xy(38,2); cout << "                          ";
		xc::xy(43,3); cout << "                  ";
		goto pilihan;
	}
}

int main(){
	show_menu();
	// show_pasien();

	return 0;
}