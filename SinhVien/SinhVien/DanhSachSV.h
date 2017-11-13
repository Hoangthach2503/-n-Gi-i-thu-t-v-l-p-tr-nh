#pragma once
#include "SinhVien.h"
#include<string>
#include<iostream>
#include <fstream>
class DanhSachSV
{
	SV F, S;
	int dem;
public:

	DanhSachSV();
	~DanhSachSV();
	void nhapDs();
	void insertFirst();
	void insertLast();
	void xuatDS();
	void timKiemten();
	void Sort();
	void insertSort();
	void xoa();
	void thongke();
	void xoaNu08();
	int kiemTraMSSV(int , SV );
	void docFile();
};
