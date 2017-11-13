#pragma once
#pragma once
#ifndef SINHVIEN_H
#define SINHVIEN_H
#include<string>
#include<iostream>
#include <fstream>
typedef class SinhVien * SV;
using namespace std;
class Lop {
public: int khoa;
	string tenlop;

};
class Time
{
public:
	int ngay;
	int thang;
	int nam;
};
class SinhVien
{
	int maSV;
	string hoSV;
	string tenSV;
	Time ngaySinh;
	int gioiTinh;
	Lop lopHoc;
	float diemToan;
	float diemLy;
	float diemTin;	
	SV next;
public:
	ofstream outfile;
public:

	SinhVien();
	SinhVien(int maSV, string hoSV, string tenSV, Time ngaySinh, int gioiTinh,
		Lop lopHoc, float diemToan, float diemLy, float diemTin, SV next);
	SinhVien(const SinhVien &sv);
	~SinhVien();
	void setSinhVien(int maSV, string hoSV, string tenSV, Time ngaySinh,
		int gioiTinh, Lop lopHoc, float diemToan, float diemLy, float diemTin, SV next);
	void setSinhVien(int maSV, string hoSV, string tenSV, Time ngaySinh,
		int gioiTinh, Lop lopHoc, float diemToan, float diemLy, float diemTin);
	void nextBang(SV sv1, SV sv2);
	float diemTrungBinh();
	int hocBong();
	 string toString();
	void setMaSV(int masv);
	int getMaSV();
	void setHoSV(string hosv);
	string getHoSV();
	void setTenSV(string tensv);
	string getTenSV();
	void setNgaySinh(Time ngaysinh);
	Time getNgaySinh();
	void setGioiTinh(int gioitinh);
	int getGioiTinh();
	void setLopHoc(Lop lopHoc);
	Lop getLopHoc();
	void setDiemToan(float diemtoan);
	float getDiemToan();
	void setDiemLy(float diemly);
	float getDiemLy();
	void setDiemTin(float diemtin);
	float getDiemTin();
	void setNext(SV next);
	SV getNext();
	void nhap();
};
#endif

