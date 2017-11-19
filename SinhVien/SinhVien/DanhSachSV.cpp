#include "DanhSachSV.h"
#include"SinhVien.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
DanhSachSV::DanhSachSV()
{
	S = NULL;
	F = NULL;
}


DanhSachSV::~DanhSachSV()
{
}
int DanhSachSV::kiemTraMSSV(int mssv, SV F){
	SV p = F;
	while(p!=NULL){
		if (p->getMaSV() == mssv)
			return 1;
		p = p->getNext();
	}
	return 0;
}


void DanhSachSV::docFile() {
	ifstream infile;
	infile.open("QuanlySV.txt", ios::in);
	if (infile.fail())
	{
		std::cout << "loi mo file!" << std::endl;
		return;
	}
	else {
		delete F;
		int mssv;
		string ho;
		string tendem;
		string ten;
		int ngay;
		string time;
		int thang;
		int nam;
		int gioiTinh;
		int khoa;
		string tenLop;
		float diemToan;
		float diemLy;
		float diemTin;
		std::string line;
		while (true) {

			infile >> mssv;
			if (infile.eof())
				break;
			//std::cout << mssv << " ";
			infile >> ho;
			//std::cout << ho << " ";
			infile >> tendem;
			//std::cout << tendem << " ";
			infile >> ten;
			//std::cout << ten << " ";
			infile >> ngay;
			//std::cout << ngay << " ";
			infile >> thang;
			//std::cout << thang << " ";
			infile >> nam;
			//std::cout << nam << " ";
			infile >> gioiTinh;
			//std::cout << gioiTinh << " ";
			infile >> khoa;
			//std::cout << khoa << " ";
			infile >> tenLop;
			//std::cout << tenLop << " ";
			infile >> diemToan;
			//std::cout << diemToan << " ";
			infile >> diemLy;
			//std::cout << diemLy << " ";
			infile >> diemTin;
			//std::cout << diemTin << endl;
			Time ngaySinh;
			ngaySinh.thang = thang;
			ngaySinh.nam = nam;
			ngaySinh.ngay = ngay;
			Lop lopHoc;
			lopHoc.khoa = khoa;
			lopHoc.tenlop = tenLop;
			insertLast(mssv, ho +" "+ tendem, ten, ngaySinh, gioiTinh, lopHoc, diemToan, diemLy, diemTin);
		}
	}

}
void DanhSachSV::xuatDS() {
	//docFile();
	if(F != NULL)
	 {
		SV p = F;
		int i = 1;
	
	
		cout << "-------------------------------------------DANH SACH SINH VIEN---------------------------------------------------" << endl;
		cout << "_________________________________________________________________________________________________________________" << endl;
		while (p != NULL)
		{
			SinhVien sv = *p;
			cout << i << ".|\t";
			sv.toString();
			cout << p->toString();
	
			cout << "_________________________________________________________________________________________________________________" << endl;
			p = (*p).getNext();
			i++;
		}
	}
	else
	{
		cout << "\n\nDanh sach rong !\n" << endl;
	}
}
void DanhSachSV::timKiemten() {
	string ho; string ten;
	cout << "Nhap ho va ten dem(neu co) can tim kiem:   ";
	cin.ignore();
	getline(cin, ho);
	cout << "\nNhap ten can tim kiem:   ";
	fflush(stdin);
	cin >> ten;
	cout << endl;
	cout << "Thong tin sinh vien ban tim kiem la: " << endl;
	SV p = F;
	int i = 1;
	SV sv=NULL;
	cout << ho << " " << ten<<endl;
	cout << "-------------------------------------------DANH SACH SINH VIEN---------------------------------------------------" << endl;
	cout << "_________________________________________________________________________________________________________________" << endl;
	while (p != NULL)
	{
		if ((p->getHoSV() == ho) && ((p->getTenSV()) == ten)) {
			 sv = p;
			cout << i << ".|\t";
			cout << p->toString();

			cout << "_________________________________________________________________________________________________________________" << endl;
		}
		p = (*p).getNext();
		i++;
	}
	if (sv==NULL) {
		cout << "\n\nSinh vien " << ho << " " << ten << " ma ban tim kiem khong co trong danh sach!\n" << endl;
	}
}
void hoanVi(SinhVien *sv1, SinhVien *sv2) {
	SinhVien t;
	//gan t=sv1
	t.setDiemLy(sv1->getDiemLy());      t.setDiemTin(sv1->getDiemTin());         t.setDiemToan(sv1->getDiemToan());
	t.setGioiTinh(sv1->getGioiTinh());    t.setHoSV(sv1->getHoSV());			     t.setLopHoc(sv1->getLopHoc());
	t.setMaSV(sv1->getMaSV());          t.setNgaySinh(sv1->getNgaySinh());       t.setTenSV(sv1->getTenSV());
	//gan sv1=sv2
	sv1->setDiemLy(sv2->getDiemLy());   sv1->setDiemTin(sv2->getDiemTin());      sv1->setDiemToan(sv2->getDiemToan());
	sv1->setGioiTinh(sv2->getGioiTinh()); sv1->setHoSV(sv2->getHoSV());            sv1->setLopHoc(sv2->getLopHoc());
	sv1->setMaSV(sv2->getMaSV());       sv2->setNgaySinh(sv2->getNgaySinh());    sv1->setTenSV(sv2->getTenSV());
	//gan sv2=t;
	sv2->setDiemLy(t.getDiemLy());     sv2->setDiemTin(t.getDiemTin());          sv2->setDiemToan(t.getDiemToan());
	sv2->setGioiTinh(t.getGioiTinh());   sv2->setHoSV(t.getHoSV());                sv2->setLopHoc(t.getLopHoc());
	sv2->setMaSV(t.getMaSV());         sv2->setNgaySinh(t.getNgaySinh());        sv2->setTenSV(t.getTenSV());
}
void DanhSachSV::sapXep() {
	SV p = F;
	for (SV i = p; i !=NULL; i=i->getNext())
		for (SV j = i->getNext(); j != NULL; j=j->getNext())
		{
			if (i->getTenSV()>j->getTenSV())
			{
				hoanVi(i,j);
			}
		

		}
	xuatDS();
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
void DanhSachSV::nhap() {
	cout << "Nhap mssv:  ";
	int mssv;
	cin >> mssv;

	if (kiemTraMSSV(mssv, F)) {
		do {
			//p->nhap();
			if (kiemTraMSSV(mssv, F)) {
				cout << "\nMa so sinh vien da co! Moi ban nhap lai!\n";
				cin >> mssv;
			}

		} while (kiemTraMSSV(mssv, F) );
	}


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
	thang = (n % 1000000) / 10000;
	nam = n % 10000;
	int check = 1;
	if ((ngay < 1) || (ngay) > soNgay(thang, nam)) {
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

	Time ns = Time();
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
	getline(cin, tenLop);
	int checkLop = 1;
	if ((khoa > 17) || (khoa < 7))
	{
		checkLop = 0;
		throw"Ban nhap khong dung lop";
	}

	Lop lophoc = Lop();
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
	cout <<"\nBan co muon luu vao file khong(c/k):  " ;
	cin >> c;
	if (c == 'c') {
		insertLast(mssv, ho, ten, ns, gioiTinh, lophoc, diemToan, diemLy, diemTin);
		ofstream outfile;
		outfile.open("QuanLySV.txt", ios::app);
		outfile << mssv << " ";
		outfile << ho << " ";
		outfile << ten << " ";
		outfile << ngay << " ";
		outfile << thang << " ";
		outfile << nam << " ";
		outfile << gioiTinh << " ";
		outfile << khoa << " ";
		outfile << tenLop << " ";
		outfile << diemToan << " ";
		outfile << diemLy << " ";
		outfile << diemTin << "\n";
		outfile.close();
	}
}
void DanhSachSV::nhapDs() {

	int n;
	cout << "Nhap so sinh vien:  ";
	cin >> n;
	if (n < 1)
	{
		do {
			cout << "Ban nhap so sinh vien khong chinh xac, moi ban nhap lai:  ";
			cin >> n;
		} while (n < 1);
	}
	dem += n;
	int i = 0;
	do
	{
		try {
			nhap();
			i++;
		}
		catch (const char* msg) {
			cerr << "error" << msg << endl;
			cout << "Moi ban nhap lai!" << endl;
			nhap();
			i++;
		}
		catch (exception e) {
			cout << "Ban nhap bi loi moi ban nhap lai" << endl;
			nhap();
			i++;
		}
	} while (i<n);

}
void DanhSachSV::insertLast(int maSV, string hoSV, string tenSV, Time ngaySinh,
	int gioiTinh, Lop lopHoc, float diemToan, float diemLy, float diemTin)
{
	SV p;
	p = new SinhVien();
	(*p).setSinhVien( maSV, hoSV, tenSV, ngaySinh, gioiTinh, lopHoc,  diemToan,  diemLy,  diemTin);
	(*p).setNext(NULL);
	if (F == NULL) {
		F = p;
		dem++;
	}

	else {
		(*S).setNext(p);
		dem++;
	}

	S = p;

}
void DanhSachSV::insertSort() {
	cout << "Nhap thong tin sinh vien can chen:  \n";
	nhap();
	this->sapXep();
	xuatDS();
//	docFile();
}

void DanhSachSV::xoa() {
	SV p, q;
	int mssv;
	cout << "nhap ma sinh vien can xoa:  ";
	cin >> mssv;
	cout << "\nBan chac chan muon xoa khong(c/k)?  ";
	char c;
	cin >> c;
	if (c == 'c') {
		cin.ignore();
		if (F == NULL)
		{
			cout << "\n\nDanh sach rong !\n" << endl;
		}
		else
		{
			if ((F->getNext() == NULL) && (F->getMaSV() == mssv)) {
				p = F;
				delete p;
				dem--;
				cout << "\n\nDa xoa thanh cong\n\n";
				F = NULL;


			}
			else {
				if ((F->getNext() == NULL) && (F->getMaSV() != mssv)) {
					cout << "\n\nKhong co sinh vien ban can xoa\n" << endl;
				}
				else {
					if (F->getMaSV() == mssv)
					{
						p = F;
						F = F->getNext();
						dem--;
						delete p;
						cout << "\n\nDa xoa thanh cong\n\n";
					}
					else
					{
						q = F;
						p = (*F).getNext();
						while (p->getMaSV() != mssv)
						{
							q = p;
							p = (*p).getNext();

						}
						if (p == NULL)
						{
							cout << "\n\nKhong co sinh vien ban can xoa\n" << endl;
						}
						else
							if (p != NULL)
							{
								(*q).setNext((*p).getNext());
								dem--;
								delete p;
								cout << "\n\nDa xoa thanh cong\n\n";
							}

					}
				}

			}
		}
	}
}
void DanhSachSV::xoaNu08() {
		SV p = F;
		if (p == NULL)
		{
			cout << "\n\nDanh sach rong!\n\n";
		}
		else
		{
			SV q = NULL;
			while (p!= NULL)
			{
				if ((p->getLopHoc().khoa == 8) && (p->getGioiTinh() == 0)) {
				
					break;
				}
				q = p;
				p = p->getNext();
				
			}
			if (p== NULL)
			{
				cout << "\n\nKhong co sinh vien nu khoa 8\n\n!";
			}
			else
			{
				if (q == NULL)
				{
					SV pDel =F;
					F = F->getNext();
					pDel->setNext(NULL) ;
					delete pDel;
					pDel = NULL;
				}
				else
				{
					q->setNext(p->getNext());
					p->setNext(NULL);
					delete p;
					p = NULL;
				}
			}
		}


}

int timKiemLop(Lop lop[], Lop l, int size) {

	for (int i = 0; i < size; i++) {
		if ((l.khoa == lop[i].khoa) && (l.tenlop==lop[i].tenlop))
		{
			return 1;
		}
	}
	return 0;
}
void DanhSachSV::thongke() {
	Lop listLop[100];
	int soLop = 0;
	SV i = F, temp = F;
	double tongHocBong[100];
	int tongSinhVien[100];
	while (i != NULL) {
		if (timKiemLop(listLop, i->getLopHoc(), soLop + 1) == 0)
		{
			listLop[soLop].khoa = i->getLopHoc().khoa;
			listLop[soLop].tenlop = i->getLopHoc().tenlop;
			tongHocBong[soLop] = 0;
			tongSinhVien[soLop] = 0;
			soLop++;
		}
		i = (*i).getNext();
	}
	int j = 0;
	
	while (temp!=NULL)
	{
		for(j=0; j<soLop; j++){
		if ((listLop[j].khoa == temp->getLopHoc().khoa) && (listLop[j].tenlop == temp->getLopHoc().tenlop))
		{
			tongHocBong[j] += temp->hocBong();
			tongSinhVien[j]++;
		}
		}
		temp = (*temp).getNext();
		
	}
	cout << "-------------------------THONG KE DANH SACH HOC BONG CUA CAC LOP-----------------------" << endl;
	for (int k = 0; k < soLop; k++)
	{
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << listLop[k].khoa << listLop[k].tenlop << "\t" << tongSinhVien[k] << "\t" << tongHocBong[k] << endl;

	}
	cout << "---------------------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;
}