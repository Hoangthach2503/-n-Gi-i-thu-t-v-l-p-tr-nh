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
int namNhuan(int n) {
	if (((n % 4 == 0) && n % 100 != 0) || (n % 400 == 0))
		return 1;
	return 0;
}
int soNgay(int thang, int nam)
{
	int ngay[12] = { 31, 28, 31, 30, 31, 30 , 31, 31, 30, 31, 30, 31 };
	if (namNhuan(nam))
	{
		ngay[1] = 29;
	}
	return ngay[thang - 1];
}
void SinhVien::nhap() {
	cout << "Nhap mssv:  ";
	int mssv;
	cin >> mssv;
	cout << "Nhap ho va ten dem(neu co):  ";
	//fflush(stdin);
	cin.ignore();
	string ho;
	getline(cin, ho);
	cout << endl;
	cout << "Nhap Ten:  ";
	//cin.ignore();
	fflush(stdin);
	string ten;
	getline(cin, ten);
	cout << endl;
	cout << "Nhap Ngay sinh(ngaythangnam):  ";
//	cin.ignore();
	//fflush(stdin);
	int n;
	cin >> n;
	int ngay;
	int thang;
	int nam;
	if (cin.fail()) {
		throw "Ban nhap bi loi!";
	}
	ngay = n / 1000000;
	thang = (n % 100000) / 10000;
	nam = n % 10000;
	int check = 1;
	if ((ngay < 1) || (ngay) > soNgay(thang,nam)) {
		throw"Ban phai nhap dung ngay! ";
		check = 0;
	}
	if ((thang < 1) || (thang) > 12) {
		check = 0;
		throw"Ban phai nhap dung thang 1->12";
	}
	if ((nam < 1957) || (nam) > 2002) {
		check = 0;
		throw"Ban phai nhap dung ngay";
	}
	
	Time ns= Time();
	ns.nam = nam;
	ns.thang = thang;
	ns.ngay = ngay;
	
	cout << "Nhap gioi tinh nam(1)/nu(0): ";
	cin.ignore();
	//fflush(stdin);
	int  gioiTinh;
	cin >> gioiTinh;
	if ((gioiTinh != 0) && (gioiTinh != 1))
	{
		throw"Ban nhap loi ve gioi tinh (1, 0)!";
	}
	cout << "Nhap lop:  ";
	int khoa;
	cin >> khoa;
	//cin.ignore();
	fflush(stdin);
	string tenLop;
	getline(cin,tenLop);
	int checkLop=1;
	if ((khoa > 17) || (khoa < 7))
	{
		checkLop = 0;
		throw"Ban nhap khong dung lop";
	}

		Lop lophoc= Lop();
		lophoc.khoa = khoa;
		lophoc.tenlop = tenLop;
	
	cout << endl;
	cout << "Nhap diem toan:  ";
	float diemToan;
	cin >> diemToan;
	if ((diemToan < 0) || (diemToan > 10)) {
		throw"Ban nhap diem khong dung";
	}
	
	cout << endl;
	cout << "Nhap diem ly:  ";
	float diemLy;
	cin >> diemLy;
	if ((diemLy < 0) || (diemLy > 10)) {
		throw"Ban nhap diem khong dung";
	}
	
	cout << endl;
	cout << "Nhap diem tin:  ";

	fflush(stdin);
	float diemTin;
	cin >> diemTin;
	if ((diemTin < 0) || (diemTin > 10)) {
		throw"Ban nhap diem khong dung";
	}
	char c ;
	cout <<"\nBan co muon luu vao file khong(y/n):  " ;
	cin >> c;
	if (c == 'y') {
		outfile.open("QuanLySV.txt", ios::app);
		setSinhVien(mssv, ho, ten, ns, gioiTinh, lophoc, diemToan, diemLy, diemTin);
		outfile << mssv <<" ";
		outfile << ho <<" ";
		outfile << ten <<" ";
		outfile << ngay << " ";
		outfile <<thang << " ";
		outfile << nam << " ";
		outfile << gioiTinh<<" ";
		outfile << khoa<<" ";
		outfile << tenLop << " ";
		outfile << diemToan << " ";
		outfile << diemLy << " ";
		outfile << diemTin <<"\n";
	}
	outfile.close();

}