#include "thanhToan.h"

thanhToan::thanhToan() {}

string thanhToan::dinhDangTien(int i) {
    if (i < 10) {
        return "00" + to_string(i);
    } else if (i < 100 && i >= 10) {
        return "0" + to_string(i);
    } else {
        return to_string(i);
    }
}

double thanhToan::chuyenDoiThoiGian() {
    tm a = {};
    a.tm_year = get_namVao() - 1900;
    a.tm_mon = get_thangVao() - 1;
    a.tm_mday = get_ngayVao();
    a.tm_hour = get_gioVao();
    a.tm_min = get_phutVao();
    a.tm_sec = 0;
	
    tm b = {};
    b.tm_year = get_namRa() - 1900;
    b.tm_mon = get_thangRa() - 1;
    b.tm_mday = get_ngayRa();
    b.tm_hour = get_gioRa();
    b.tm_min = get_phutRa();
    b.tm_sec = 0;

    time_t timeIn = mktime(&a);
    time_t timeOut = mktime(&b);

    return difftime(timeOut, timeIn);
}

void thanhToan::khachThanhToan() {
    double thoiGian = chuyenDoiThoiGian();
    double soPhut = thoiGian / 60;
    double soGio = thoiGian / 3600;
    double soNgay = thoiGian / (3600 * 24);

    int ngay = static_cast<int>(soNgay);
    int gio = static_cast<int>(soGio) - static_cast<int>(soNgay) * 24;
    int phut = static_cast<int>(soPhut) - static_cast<int>(soGio) * 60;

    cout << "\n\nHOA DON\n";
    cout << "---------------------\n";
    cout << "Thong tin thanh toan:\n\n";
    
    int giaNgay, giaGio;
    if (datPhong::get_phongDaDat() == 102 || datPhong::get_phongDaDat() == 201) {
    	giaNgay = giaNgayVip;
		giaGio = giaGioVip;
	} else {
		giaNgay = giaNgayThuong;
		giaGio = giaGioThuong;
	}
	
    if (soGio >= 24) {
        if (phut >= 0 && phut < 30) {
            thanhTien = ngay * giaNgay + gio * giaGio;
            cout << "Tong thoi gian thue: " << ngay << " ngay, " << gio << " gio." << endl;
        } else {
            thanhTien = ngay * giaNgay + gio * giaGio + 70;
            cout << "Tong thoi gian thue: " << ngay << " ngay, " << gio << " gio, " << phut << " phut." << endl;
        }
    } else {
        if (phut >= 0 && phut < 30) {
            thanhTien = gio * giaGio;
            cout << "Tong thoi gian thue: " << gio << " gio." << endl;
        } else {
            thanhTien = gio * giaGio + 70;
            cout << "Tong thoi gian thue: " << gio << " gio, " << phut << " phut." << endl;
        }
    }
	
	thanhTien += (double)dichVu::get_tongTien();
	
	int tien = static_cast<int>(thanhTien);
	if (tien >= 1000) {
		cout << "Thanh tien: " << tien / 1000 << "." << dinhDangTien(tien % 1000) << ".000 vnd" << endl;
	} else {
		cout << "Thanh tien: " << tien << ".000 vnd" << endl;
	}
    

    int luaChon;
    cout << "---------------------\n";
    cout << "Phuong thuc thanh toan:\n\n";
    cout << "01. Tien mat\n";
    cout << "02. Chuyen khoan\n";
    cout << "---------------------\n";

    while (true) {
        cout << "Khach chon: ";
        cin >> luaChon;

        if (luaChon == 1) {
            cout << "\n\nXAC NHAN PHUONG THUC: Tien mat\n";
            break;
        } else if (luaChon == 2) {
            cout << "\n\nXAC NHAN PHUONG THUC: Chuyen khoan\n";
            break;
        } else {
            cout << "Loi nhap, vui long thu lai!\n";
        }
    }
    cout << "----------------------------------------------------\n";
}

double thanhToan::get_thanhTien() {
	return thanhTien;
}

void thanhToan::xuat_thanhToan(ostream &os) {
	double thoiGian = chuyenDoiThoiGian();
    double soPhut = thoiGian / 60;
    double soGio = thoiGian / 3600;
    double soNgay = thoiGian / (3600 * 24);

    int ngay = static_cast<int>(soNgay);
    int gio = static_cast<int>(soGio) - static_cast<int>(soNgay) * 24;
    int phut = static_cast<int>(soPhut) - static_cast<int>(soGio) * 60;
	
	if (soGio >= 24) {
        if (phut >= 0 && phut < 30) {
            os << "Tong thoi gian thue: " << ngay << " ngay, " << gio << " gio." << endl;
        } else {
            os << "Tong thoi gian thue: " << ngay << " ngay, " << gio << " gio, " << phut << " phut." << endl;
        }
    } else {
        if (phut >= 0 && phut < 30) {
            os << "Tong thoi gian thue: " << gio << " gio." << endl;
        } else {
            os << "Tong thoi gian thue: " << gio << " gio, " << phut << " phut." << endl;
        }
    }
    
    int tien = static_cast<int>(get_thanhTien());
	if (tien >= 1000) {
		os << "Tong so tien: " << tien / 1000 << "." << dinhDangTien(tien % 1000) << ".000 vnd" << endl;
	} else {
		os << "Tong so tien: " << tien << ".000 vnd" << endl;
	}
}

