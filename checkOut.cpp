#include "checkOut.h"

string checkOut::dinhDangThoiGian(int i) {
	if (i < 10) {
        return "0" + to_string(i);
    } else {
        return to_string(i);
    }
}

void checkOut::nhap_checkOut() {
	if (checkIn::get_ngayVao() == 0) {
		cout << "\nKhach chua check-in, vui long nhap check-in truoc!/n";
	} else {
		int luaChon;
		time_t now = time(0);
		tm *ltm = localtime(&now);
		
	    do {
	    	cout << "\n\nKHACH HANG CHECK-OUT";
	        cout << "\n---------------------";
	        cout << "\nThoi gian: " << dinhDangThoiGian(ltm->tm_hour) << ":" << dinhDangThoiGian(ltm->tm_min) << " " << dinhDangThoiGian(ltm->tm_mday) << "/" << dinhDangThoiGian(1 + ltm->tm_mon) << "/" << dinhDangThoiGian(1900 + ltm->tm_year);
	        cout << "\n---------------------";
	        cout << "\n01. Dong y";
	        cout << "\n02. Chinh sua";
	        cout << "\n03. Huy bo";
	        cout << "\n---------------------";
	        cout << "\nNhap lua chon: ";
	        cin >> luaChon;
		    
		    switch (luaChon) {
		    	case 1:
				    dmy.ngay = ltm->tm_mday;
				    dmy.thang = 1 + ltm->tm_mon;
				    dmy.nam = 1900 + ltm->tm_year;
				    co.ngayRa = dmy;
				    
				    hms.gio = ltm->tm_hour;
				    hms.phut = ltm->tm_min;
				    co.gioRa = hms;
				    break;
				    
				case 2:
			    sua_checkOut();
			    break;
			    
				case 3:
					cout << "Da huy thoi gian check-in!";
					break;
			}
		} while (luaChon <= 0 && luaChon > 2);
	}
    
}

int checkOut::get_gioRa() {
    return co.gioRa.gio;
}

void checkOut::set_gioRa(int _gioRa) {
	co.gioRa.gio = _gioRa;
}

int checkOut::get_phutRa() {
    return co.gioRa.phut;
}

void checkOut::set_phutRa(int _phutRa) {
    co.gioRa.phut = _phutRa;
}

int checkOut::get_ngayRa() {
	return co.ngayRa.ngay;
}

void checkOut::set_ngayRa(int _ngayRa) {
	co.ngayRa.ngay = _ngayRa;
}

int checkOut::get_thangRa() {
	return co.ngayRa.thang;
}

void checkOut::set_thangRa(int _thangRa){
	co.ngayRa.thang = _thangRa;
}

int checkOut::get_namRa() {
	return co.ngayRa.nam;
}

void checkOut::set_namRa(int _namRa){
	co.ngayRa.nam = _namRa;
}

void checkOut::sua_checkOut() {
	int luaChon, sua[5];
	
	cout << "\n\nSUA THOI GIAN CHECK-OUT\n";
	cout << "---------------------\n";
    cout << "Nhap gio:phut: ";
    cin.ignore();
	cin >> sua[0] >> sua[1];
    set_gioRa(sua[0]);
    set_phutRa(sua[1]);
    
    cout << "Nhap ngay/thang/nam: ";
	cin >> sua[2] >> sua[3] >> sua[4];
    set_ngayRa(sua[2]);
    set_thangRa(sua[3]);
    set_namRa(sua[4]);
    cout << "---------------------\n";
}

void checkOut::xoa_checkOut() {
    co.gioRa.gio = 0;
    co.gioRa.phut = 0;
    co.ngayRa.ngay = 0;
    co.ngayRa.thang = 0;
    co.ngayRa.nam = 0;
}

void checkOut::xuat_checkOut(ostream &os) {
	string dinhDangGio = dinhDangThoiGian(co.gioRa.gio);
	string dinhDangPhut = dinhDangThoiGian(co.gioRa.phut);
	
	string dinhDangNgay = dinhDangThoiGian(co.ngayRa.ngay);
	string dinhDangThang = dinhDangThoiGian(co.ngayRa.thang);
	string dinhDangNam = to_string(co.ngayRa.nam);
	
    os << "Ngay check-out: " << dinhDangNgay << "/" << dinhDangThang << "/" << dinhDangNam << endl;
    os << "Gio check-out: " << dinhDangGio << ":" << dinhDangPhut << endl;
    os << "---------------------\n";
}

