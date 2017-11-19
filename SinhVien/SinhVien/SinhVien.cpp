#include "SinhVien.h"
#include<string>
#include<iostream>
#include <fstream>
#include <sstream>
using namespace std;
SinhVien::SinhVien()
{
	Lop lop;
	lop.khoa = 0;
	lop.tenlop = "";
	Time ngaysinh;
	ngaysinh.ngay = 1;
	ngaysinh.thang = 1;
	ngaysinh.nam = 1999;
	setSinhVien(0, "", "", ngaysinh, 0, lop, 0, 0, 0, NULL);
}
SinhVien::SinhVien(int maSV, string hoSV, string tenSV, Time ngaySinh, int gioiTinh,
	Lop lopHoc, float diemToan, float diemLy, float diemTin, SV next) {
	setSinhVien(maSV, hoSV, tenSV, ngaySinh, gioiTinh, lopHoc, diemToan, diemLy, diemTin, next);
}
SinhVien::SinhVien(const SinhVien &sv) {
	setSinhVien(sv.maSV, sv.hoSV, sv.tenSV, sv.ngaySinh, sv.gioiTinh, sv.lopHoc, sv.diemToan, sv.diemLy
		, sv.diemTin, sv.next);
}
SinhVien::~SinhVien()
{

}
void SinhVien::setSinhVien(int maSV, string hoSV, string tenSV, Time ngaySinh, int gioiTinh,
	Lop lopHoc, float diemToan, float diemLy, float diemTin, SV next) {
	this->maSV = maSV;
	this->hoSV = hoSV;
	this->tenSV = tenSV;
	this->ngaySinh.ngay = ngaySinh.ngay;
	this->ngaySinh.thang = ngaySinh.thang;
	this->ngaySinh.nam = ngaySinh.nam;
	this->gioiTinh = gioiTinh;
	this->lopHoc = lopHoc;
	this->diemToan = diemToan;
	this->diemLy = diemLy;
	this->diemTin = diemTin;
	this->next = next;
}
void SinhVien::setSinhVien(int maSV, string hoSV, string tenSV, Time ngaySinh, int gioiTinh,
	Lop lopHoc, float diemToan, float diemLy, float diemTin) {
	this->maSV = maSV;
	this->hoSV = hoSV;
	this->tenSV = tenSV;
	this->ngaySinh.ngay = ngaySinh.ngay;
	this->ngaySinh.thang = ngaySinh.thang;
	this->ngaySinh.nam = ngaySinh.nam;
	this->gioiTinh = gioiTinh;
	this->lopHoc = lopHoc;
	this->diemToan = diemToan;
	this->diemLy = diemLy;
	this->diemTin = diemTin;
}

float SinhVien::diemTrungBinh() {
	return(diemLy + diemTin + diemToan) / 3;
}
int SinhVien::hocBong() {
	if (diemTrungBinh() >= 8)
		return 200;
	if (diemTrungBinh() >= 7 && diemTrungBinh() < 8)
		return 100;
	return 0;
}
string SinhVien::toString() {
	std::ostringstream nsinh, lhoc, diem, diemtb, mssv;
	mssv << maSV;
	nsinh << ngaySinh.ngay << "/" << ngaySinh.thang << "/" << ngaySinh.nam;
	lhoc << lopHoc.khoa;
	diem << diemToan << "\t" << diemLy << "\t" << diemTin;
	diemtb << diemTrungBinh();
	string gt ;
	if (gioiTinh)
		gt = "Nam";
	else
	{
		gt = "Nu";
	}
	return  mssv.str() + "\t" + hoSV + " " + tenSV + "\t"+gt+"\t" + nsinh.str() + "\t" + lhoc.str() + lopHoc.tenlop + "\t" + diem.str() + "\t" + diemtb.str() + "\n";
}
void nextBang(SV sv1, SV sv2) {
	sv1->setSinhVien(sv1->getMaSV(), sv1->getHoSV(), sv1->getTenSV(), sv1->getNgaySinh(), sv1->getGioiTinh(),
		sv1->getLopHoc(), sv1->getDiemToan(), sv1->getDiemLy()
		, sv1->getDiemTin(), sv1->getNext());
}

Lop SinhVien::getLopHoc() {
	return lopHoc;
}
void SinhVien::setLopHoc(Lop lopHoc) {
	lopHoc = lopHoc;
}
int SinhVien::getMaSV() {
	return maSV;
}

void SinhVien::setMaSV(int maSV) {
	this->maSV = maSV;
}

string SinhVien::getHoSV() {
	return hoSV;
}

void SinhVien::setHoSV(string hoSV) {
	this->hoSV = hoSV;
}

string SinhVien::getTenSV() {
	return tenSV;
}

void SinhVien::setTenSV(string tenSV) {
	this->tenSV = tenSV;
}

Time SinhVien::getNgaySinh() {
	return ngaySinh;
}

void SinhVien::setNgaySinh(Time ngaySinh) {
	this->ngaySinh.ngay = ngaySinh.ngay;
	this->ngaySinh.thang = ngaySinh.thang;
	this->ngaySinh.nam = ngaySinh.nam;
}

int SinhVien::getGioiTinh() {
	return gioiTinh;
}

void SinhVien::setGioiTinh(int gioiTinh) {
	this->gioiTinh = gioiTinh;
}
float SinhVien::getDiemToan() {
	return diemToan;
}
void SinhVien::setDiemToan(float diemToan) {
	this->diemToan = diemToan;
}

float SinhVien::getDiemLy() {
	return diemLy;
}

void SinhVien::setDiemLy(float diemLy) {
	this->diemLy = diemLy;
}

float SinhVien::getDiemTin() {
	return diemTin;
}
void SinhVien::setDiemTin(float diemTin) {
	this->diemTin = diemTin;
}
SV SinhVien::getNext() {
	return this->next;
}
void SinhVien::setNext(SV next) {
	this->next = next;
}

