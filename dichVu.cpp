#include "dichVu.h"

string dichVu::dinhDangTien(int i) {
    if (i < 10) {
        return "00" + to_string(i);
    } else if (i < 100 && i >= 10) {
        return "0" + to_string(i);
    } else {
        return to_string(i);
    }
}

void dichVu::nhap_dichVu() {
    int luaChon;

    cout << "\nTHEM DICH VU\n";
    cout << "---------------------------------------------------------\n";
    cout << "Do an:\t  01. " << matHang[0] << "\t  02. " << matHang[1] << "\t  03. " << matHang[2] << endl;
    cout << "\t  " << gia[0] << ".000 vnd\t  " << gia[1] << ".000 vnd\t  " << gia[2] << ".000 vnd\n\n";
    cout << "Do uong:  04. " << matHang[3] << "\t  05. " << matHang[4] << "\t  06. " << matHang[5] << endl;
    cout << "\t  " << gia[3] << ".000 vnd\t  " << gia[4] << ".000 vnd\t  " << gia[5] << ".000 vnd\n\n";
    cout << "Khac:\t  07. " << matHang[6] << "\t  08. " << matHang[7] << "\t  09. " << matHang[8] << endl;
    cout << "\t  " << gia[6] << ".000 vnd\t  " << gia[7] << ".000 vnd\t  " << gia[8] << ".000 vnd\n";
    cout << "---------------------------------------------------------\n";
    cout << "00. Hoan tat lua chon.\n";
    cout << "---------------------\n";

    do {
        cout << "Khach chon: ";
        cin >> luaChon;
        if (luaChon == 0) break;

        if (luaChon >= 1 && luaChon <= 9) {
            cout << "Nhap so luong: ";
            cin >> soLuong;
            tien[luaChon - 1] = soLuong * gia[luaChon - 1];
            tongTien += tien[luaChon - 1];

            cout << matHang[luaChon - 1] << " voi gia: ";
            if (tien[luaChon - 1] >= 1000) {
                cout << tien[luaChon - 1] / 1000 << "." << dinhDangTien(tien[luaChon - 1] % 1000) << ".000 vnd";
            } else {
                cout << tien[luaChon - 1] << ".000 vnd";
            }
            cout << " (so luong: " << soLuong << ") da duoc them vao hoa don.\n";
            cout << "---------------------\n\n";
        } else {
            cout << "Lua chon khong hop le, vui long chon lai.\n";
        }
    } while (true);
	
	cout << "---------------------\n";
    cout << "Tong so tien cac mat hang: ";
    if (tongTien >= 1000) {
        cout << tongTien / 1000 << "." << dinhDangTien(tongTien % 1000) << ".000 vnd\n";
    } else {
        cout << tongTien << ".000 vnd\n";
    }
    cout << "--------------------------------------------------\n";
}

int dichVu::get_tongTien() {
    return tongTien;
}

void dichVu::xuat_dichVu(ostream &os) {
	for (int i = 0; i < 9; i++) {
		if (tien[i] != 0) {
			os << matHang[i] << ": ";
			if (tien[i] >= 1000) {
                os << tien[i] / 1000 << "." << dinhDangTien(tien[i] % 1000) << ".000 vnd\n";
            } else {
                os << tien[i] << ".000 vnd\n";
            }
		} else {
			continue;
		}
	}
	
	if (get_tongTien() != 0) {
		os << "\nSo tien cac dich vu phat sinh: ";
		if (get_tongTien() >= 1000) {
        	os << get_tongTien() / 1000 << "." << dinhDangTien(get_tongTien() % 1000) << ".000 vnd\n";
	    } else {
	        os << get_tongTien() << ".000 vnd\n";
	    }
	    os << "---------------------\n";
	}
}

