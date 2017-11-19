#include "DanhSachSV.h"
#include<string>
#include<iostream>
#include <fstream>
using namespace std;
void docfile() {
	SinhVien temp;
	ifstream ifs("QuanLySV.txt", ios::binary);
	ifs.read((char*)&temp, sizeof(temp));
	string demo=temp.getTenSV();
	cout << demo << endl;


}
int main() {
	DanhSachSV ds;
	int n;
	char c;
	do
	{
		cout << "\n1. Nhap danh sach sinh vien";
		cout << "\n2. Thong tin ve danh sach sinh vien";
		cout << "\n3. Chen sinh vien vao danh sach";
		cout << "\n4. Xoa sinh vien theo mot ho ten bat ky";
		cout << "\n5. Thong tin ve hoc bong cac lop";
		cout << "\n6. Sap xep danh sach sinh vien theo ho ten";
		cout << "\n7. Xoa cac sinh vien nu khoa 8 trong danh sach";
		cout << "\n8. Tim kiem sinh vien theo ten";
		cout << "\n9. Them mot sinh vien va duoc sap xep theo thu tu";
		cout << "\n10. Doc file";
		cout << "\n0. Thoat";
		cout << "\nMOI BAN CHON CONG VIEC:     " << endl;
		cin >> n;
		try {
			
			if (cin.fail()) {
				throw "ban nhap bi loi!";
				//cin >> n;
			}
		}
		catch (char* error) {
			cerr << error << endl;
			break;
		}
		switch (n)
		{
		case 1:
			ds.nhapDs();
			break;
		case 2:
			ds.xuatDS();
			break;
		case 3:
			ds.nhap();
			break;
		case 4:
			ds.xoa();
			break;
		case 5:
			ds.thongke();
			break;
		case 6:
			ds.sapXep();
			break;
		case 7:
			
			cout << "\nBan chac chan muon xoa khong(c/k)?  ";
			cin >> c;
			if(c=='c')
			ds.xoaNu08();
			break;
		case 8:

			ds.timKiemten();
			break;
		case 9:
			ds.insertSort();
			break;
		case 10:
			ds.docFile();
			break;
		default:
			cout << "\n\nBan chon sai! moi ban chon lai: \n\n";
			break;
		}
	} while (n);
	return 0;
}
