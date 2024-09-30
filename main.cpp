//Project: Phan mem quan ly khach san don gian (dung cho le tan) (console app)
#include <conio.h>
#include <cstdlib>
#include <limits>

#include "khachHang.cpp"

void themKhachHang(khachHang *&khach, int &n);
bool kiemTraThongTin(khachHang *&khach, int &n);

void nhap_duLieu(khachHang *&khach, int &n); //1
void xuat_duLieu(khachHang *&khach, int &n); //2
void sua_duLieu(khachHang *&khach, int &n); //3
void khachDoiPhong(khachHang *&khach, int &n); //4
void themDichVu(khachHang *&khach, int &n); //5 chua xong
void khachCheckIn(khachHang *&khach, int &n); //6
void khachCheckOut(khachHang *&khach, int &n); //7
void timKiem_duLieu(khachHang *&khach, int &n); //8
void xoa_duLieu(khachHang *&khach, int &n); //9

void thongTinDanhSachPhong(); //10
void baoCao(khachHang *& khach, int & n); //11 chua xong

void menu(khachHang *& khach, int & n);

int main() {
	int n = 1;
	
	khachHang *khach = new khachHang[n];
	
	menu(khach, n);
	getch();
	
	delete[] khach;
	return 0;
}

string dinhDangThoiGian(int i) {
	if (i < 10) {
        return "0" + to_string(i);
    } 
	else {
        return to_string(i);
    }
}

//tang so luong phan tu cho mang dong
void themKhachHang(khachHang *&khach, int &n) {
    khachHang *new_khach = new khachHang[n+1];
    
    for (int i = 0; i < n; i++) {
        new_khach[i] = khach[i];
    }
    
    delete[] khach;
    khach = new_khach;
    n++;
}

//Kiem tra thong tin cho cac ham ben duoi su dung lai
bool kiemTraThongTin(khachHang *&khach, int &n) { //fix ma kh
	string kiemTra;
	int dem = 0;
	
	cout << "\nNhap ma khach hang hoac CCCD: ";
	cin.ignore();
	getline(cin, kiemTra);
	cout << "--------------------------------------------------\n";
	
	for (int i=0; i<n; i++) {
		if (kiemTra == khach[i].get_cccd() || kiemTra == khach[i].maKhachHang()) { //fix
			return true;
			dem++;
		}
	}
	
	if (dem == 0) {
		return false;
	}
}

void bubbleSort(khachHang *&khach, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (khach[j].get_phongDaDat() > khach[j + 1].get_phongDaDat() ||
            
                (khach[j].get_phongDaDat() == khach[j + 1].get_phongDaDat() && 
				khach[j].get_namDatPhong() > khach[j + 1].get_namDatPhong()) ||
                
                (khach[j].get_phongDaDat() == khach[j + 1].get_phongDaDat() && 
				khach[j].get_namDatPhong() == khach[j + 1].get_namDatPhong() && 
				khach[j].get_thangDatPhong() > khach[j + 1].get_thangDatPhong()) ||
                
                (khach[j].get_phongDaDat() == khach[j + 1].get_phongDaDat() && 
				khach[j].get_namDatPhong() == khach[j + 1].get_namDatPhong() && 
				khach[j].get_thangDatPhong() == khach[j + 1].get_thangDatPhong() && 
				khach[j].get_ngayDatPhong() > khach[j + 1].get_ngayDatPhong())) {
                
                khachHang temp = khach[j];
                khach[j] = khach[j + 1];
                khach[j + 1] = temp;
            }
        }
    }
}

bool trungDatPhong(khachHang *&khach, int n) {
    bubbleSort(khach, n);
    
    for (int i = 0; i < n - 1; ++i) {
        if (khach[i].get_phongDaDat() == khach[i + 1].get_phongDaDat() &&
            khach[i].get_ngayDatPhong() == khach[i + 1].get_ngayDatPhong() &&
            khach[i].get_thangDatPhong() == khach[i + 1].get_thangDatPhong() &&
            khach[i].get_namDatPhong() == khach[i + 1].get_namDatPhong()) {
            return true;
        }
    }
    return false;
}

//01. Nhap du lieu khach hang + dat phong
//nhap du lieu vao mang, neu mang da co du lieu thi dung ham tang so luong mang dong.
//khach sau se duoc check xem co trung thong tin cac khach truoc khong, neu co nhap lai
void nhap_duLieu(khachHang *&khach, int &n) {
    cout << "\n\nNHAP THONG TIN KHACH HANG";
	cout << "\n--------------------------------------------------\n\n";

    if (n == 0 || khach[n - 1].get_phongDaDat() != 0) {
        themKhachHang(khach, n);
        cout << "khach hang: " << n << "\n---------------------\n";
        nhapLai:
        khach[n - 1].nhap_khachHang();
        
        for (int i; i<n; i++) {
        	if (trungDatPhong(khach, n) == true) {
				cout << "Phong da duoc dat, vui long cho phong khac!";
				cout << "\n---------------------\n";
				goto nhapLai;
			}
		}
    }
    else {
    	for (int i=0; i<n; i++) {
    		cout << "khach hang: " << n << "\n---------------------\n";
        	khach[i].nhap_khachHang();
		}
	}
}

//02. Xuat du lieu khach hang
//xuat toan bo du lieu ve cac khach hang
void xuat_duLieu(khachHang *&khach, int &n) { //fix ma kh
    int dem = 0;
    cout << "\n\nDANH SACH, THONG TIN KHACH HANG";
	cout << "\n--------------------------------------------------\n\n";
    for (int i = 0; i < n; i++){
    	if (khach[i].get_phongDaDat() != 0) {
    		cout << "STT: " << i + 1 << "\n---------------------\n";
    		
    		cout << "Ma khach hang: " << khach[i].maKhachHang() << endl; 
		    khach[i].xuat_khachHang(cout); 
		    khach[i].xuat_datPhong(cout);
		    khach[i].kt_tinhTrangPhong();
			dem++;
		}
    }

    if (dem == 0) {
        cout << "\n\nDANH SACH TRONG, VUI LONG NHAP DANH SACH!";
		cout << "\n--------------------------------------------------\n";
    }
    else {
        cout << "\nHET DANH SACH";
		cout << "\n--------------------------------------------------\n";
    }
}

//03. Sua du lieu
//chon khach hang, sau do chinh sua cac thong tin cua ho
void sua_duLieu(khachHang *&khach, int &n) {
	if (kiemTraThongTin(khach, n) == true) {
		for (int i=0; i<n; i++) {
			cout << "\n--------------------------------------------------";
			cout << "\nXac nhan lai thong tin cua khach hang\n";
			cout << "---------------------\n";
			khach[i].xuat_khachHang(cout);
			
			int luaChon;
			cout << "\n---------------------\n";
			cout << "01. Sua thong tin khach hang\n";
			cout << "02. Sua thong tin dat phong\n";
			cout << "03. Sua thoi gian check-in\n";
			cout << "04. Sua thoi gian check-out\n\n";
			cout << "00. Thoat chinh sua\n";
			cout << "---------------------\n";
			cout << "Nhap lua chon: ";
			cin >> luaChon;
			
			switch (luaChon) {
			    case 1:
			    	khach[i].sua_khachHang();
			    	break;
			        
			    case 2:
			        khach[i].sua_datPhong();
			        break;
			    
				case 3:	
				    khach[i].sua_checkIn();
				    break;
			        
				case 4:
					khach[i].sua_checkOut();
					break;
			    	
			    case 0:
			    	cout << "Da thoat chinh sua!";
			    	break;
			    	
			    default:
			    	cout << "Loi lua chon, vui long thu lai!";
			    	break;
			}	
		}
	} 
	else {
		cout << "\nKhong tim thay thong tin hop le!\n";
		cout << "\n--------------------------------------------------\n";
	}		
}

//04. khach muon doi phong
//doi phong cho khach hang
void khachDoiPhong(khachHang *&khach, int &n) {
	if (kiemTraThongTin(khach, n) == true) {
		for(int i=0; i<n; i++){
			cout << "Ma khach hang: " << khach[i].maKhachHang() << endl; 
			khach[i].xuat_khachHang(cout);
			khach[i].xuat_datPhong(cout);
			khach[i].nhap_doiPhong();
			
			khach[i].xacNhanLai();
			khach[i].xuat_doiPhong();
			cout << "--------------------------------------------------\n";
			break;
		}
	} 
	else {
		cout << "\nKhong tim thay thong tin hop le!\n";
		cout << "--------------------------------------------------\n";
	}
}
      
//05. khach dung them dich vu
//khach dung them cac loai hinh dich vu
void themDichVu(khachHang *&khach, int &n) {
	if (kiemTraThongTin(khach, n) == true) {
		for(int i=0; i<n; i++){
			cout << "\n\nTHONG TIN KHACH HANG" << endl;
			cout << "---------------------\n";
			cout << "Ma khach hang: " << khach[i].maKhachHang() << endl; 
			khach[i].xuat_khachHang(cout);
			
			khach[i].nhap_dichVu();
			break;
		}
	} 
	else {
		cout << "\nKhong tim thay khach hang!\n";
		cout << "--------------------------------------------------\n";
	}
}

//06. khach hang check-in
//nhap thoi gian khach nhan phong. k qua 30p so voi dat phong
void khachCheckIn(khachHang *&khach, int &n) {
	if (kiemTraThongTin(khach, n) == true) {
		for (int i = 0; i < n; i++) {
			cout << "\n\nTHONG TIN KHACH HANG" << endl;
			cout << "---------------------\n";
			cout << "Ma khach hang: " << khach[i].maKhachHang() << endl; 
			khach[i].xuat_khachHang(cout);
			khach[i].xuat_datPhong(cout);
			khach[i].nhap_checkIn();
			break;
		}
		
		for (int i = 0; i < n; i++) {
			cout << "\n\nTHONG TIN DICH VU\n";
			cout << "---------------------\n";
			khach[i].xuat_datPhong(cout);
			khach[i].xuat_checkIn(cout);
			break;
		}
	} 
	else {
		cout << "\nKhong tim thay khach hang!\n";
		cout << "--------------------------------------------------\n";
	}
}

//07. khach hang check-out
//nhap thoi gian khach tra phong. 
void khachCheckOut(khachHang *&khach, int &n) {
	if (kiemTraThongTin(khach, n) == true) {
		for (int i = 0; i < n; i++) {
			cout << "\n\nTHONG TIN KHACH HANG" << endl;
			cout << "---------------------\n";
			cout << "Ma khach hang: " << khach[i].maKhachHang() << endl; 
			khach[i].xuat_khachHang(cout);
			khach[i].xuat_datPhong(cout);
			khach[i].xuat_checkIn(cout);
			khach[i].nhap_checkOut();
			break;
		}
		
		for (int i = 0; i < n; i++) {
			cout << "\n\nTHONG TIN DICH VU\n";
			cout << "---------------------\n";
			cout << "Phong khach da dat: " << khach[i].get_phongDaDat() << endl;
			khach[i].xuat_checkIn(cout);
			khach[i].xuat_checkOut(cout);
			
			khach[i].khachThanhToan();
			khach[i].hoaDon();
			khach[i].nhap_baoCao();
			break;
		}
	}
	else {
		cout << "\nKhong tim thay khach hang!\n";
		cout << "--------------------------------------------------\n";
	}
}

//8. Tim kiem khach hang
//tim kiem khach hang theo ma khach hang hoac cac thong tin da nhap truoc do
void timKiem_duLieu(khachHang *&khach, int &n){
	int luaChon;
	string timKiem;
	int dem = 0;
	
	do {
	    cout << "\nTIM KIEM THEO:\n";
	    cout << "---------------------\n";
	    cout << "01. Ma khach hang\n";
	    cout << "02. CCCD\n";
	    cout << "03. SDT\n";
	    cout << "---------------------\n";
	    cout << "Lua chon: ";
	    cin >> luaChon;
	    cin.ignore(); 
	
	    switch (luaChon) {
	        case 1: 
	            cout << "\nNhap ma khach hang can tim: ";
	            getline(cin, timKiem);
	            cout << "--------------------------------------------------\n";
	
	            for (int i = 0; i < n; i++) {
	                if (timKiem == khach[i].maKhachHang()) {
	                    cout << "THONG TIN KHACH HANG\n";
	                    khach[i].xuat_khachHang(cout);
	                    khach[i].xuat_datPhong(cout);
	                    dem++;
	                }
	            }
	            break;
	        
	        case 2: 
	            cout << "\nNhap cccd khach hang can tim: ";
	            getline(cin, timKiem);
	            cout << "--------------------------------------------------\n";
	
	            for (int i = 0; i < n; i++) {
	                if (timKiem == khach[i].get_cccd()) {
	                    cout << "THONG TIN KHACH HANG\n";
	                    khach[i].xuat_khachHang(cout);
	                    khach[i].xuat_datPhong(cout);
	                    dem++;
	                }
	            }
	            break;
	        
	        case 3: 
	            cout << "\nNhap sdt khach hang can tim: ";
	            getline(cin, timKiem);
	            cout << "--------------------------------------------------\n";
	
	            for (int i = 0; i < n; i++) {
	                if (timKiem == khach[i].get_soDienThoai()) {
	                    cout << "THONG TIN KHACH HANG\n";
	                    khach[i].xuat_khachHang(cout);
	                    khach[i].xuat_datPhong(cout);
	                    dem++;
	                }
	            }
	            break;
	        
	        default: 
	            cout << "Vui long chon lai lua chon!\n";
	            break;
	        
	    }
	} 
	while (luaChon < 1 || luaChon > 3);
	
	if (dem == 0) {
		cout << "Khong tim thay khach hang, vui long thu lai!\n";
	}
}

//09. Xoa THONG TIN KHACH HANG
//chon khach hang va xoa toan bo thong tin
void xoa_duLieu(khachHang *&khach, int &n) {
	if (kiemTraThongTin(khach, n) == true) {
		for (int i=0; i<n; i++) {
			cout << "\n--------------------------------------------------\n";
			cout << "Xac nhan lai thong tin cua khach hang" << endl;
			cout << "---------------------\n";
			cout << "Ma khach hang: " << khach[i].maKhachHang() << endl; 
			khach[i].xuat_khachHang(cout);
			khach[i].xoa_khachHang();
			break;
		}
	} 
	else {
		cout << "\nKhong tim thay khach hang!\n";
		cout << "--------------------------------------------------\n";
	}
}

//10. Danh sach + trang thai phong
//lua chon hien thi thong tin, danh sach va trang thai cua cac phong
void thongTinDanhSachPhong() {
	danhSachPhong _dsp;
	
	int luaChon;
	cout << "\n--------------------------------------------------\n";
	cout << "01. Cap nhat thong tin tinh trang phong" << endl;
	cout << "02. Hien thi thong tin tinh trang phong" << endl;
	cout << "---------------------\n";
	cout << "Nhap lua chon: ";
	cin >> luaChon;
	
	switch (luaChon) { 
		case 1:
			cout << "\n---------------------";
			_dsp.nhap_danhSachPhong();
			cout << "--------------------------------------------------\n";
			break;
			
		case 2:
			cout << "\n---------------------";
			_dsp.xuat_danhSachPhong();
			cout << "--------------------------------------------------\n";
			break;
	}
}

//11. baoCao
//xuat bao cao theo ngay vao cac file .txt
void baoCao(khachHang *&khach, int &n) {
	int ngay, thang, nam;
	cout << "\nNhap ngay: ";
	cin >> ngay >> thang >> nam;
	
	string ten = "baoCao/" + to_string(ngay) + "_" + to_string(thang) + "_" + to_string(nam) + ".txt";
	
	for (int i = 0; i < n; i++) {
		if (ten == khach[i].tenBaoCao()) {
			cout << endl;
			khach[i].xuat_baoCao();
		} else {
			cout << "\nKhong tim thay bao cao!\n";
			cout << "--------------------------------------------------\n";
		}
	}
	
} 

//menu
//lua chon cac chuc nang duoc hien thi
void menu(khachHang *&khach, int &n) {
	int luaChon;
	
	do {
		system("cls");
		cout << "=======================<MENU>=====================\n";
		cout << "==\t  Chuong trinh quan ly khach san  \t==\n";
		cout << "==\t  ------------------------------  \t==\n";
		cout << "==\t                                  \t==\n";
		cout << "==\t01. Nhap thong tin ve khach hang  \t==\n";
		cout << "==\t02. Danh sach thong tin khach hang\t==\n";
		cout << "==\t03. Sua thong tin khach hang      \t==\n";
		cout << "==\t04. khach hang muon doi phong     \t==\n";
		cout << "==\t05. khach dung them dich vu       \t==\n";
		cout << "==\t06. khach hang check in           \t==\n";
		cout << "==\t07. khach hang check out          \t==\n";
		cout << "==\t08. Tim kiem khach hang           \t==\n";
		cout << "==\t09. Xoa thong tin khach hang      \t==\n";
		cout << "==\t----------------------------------\t==\n";
		cout << "==\t10. Danh sach, thong tin phong    \t==\n";
		cout << "==\t11. Xuat bao cao                  \t==\n";
		cout << "==\t----------------------------------\t==\n";
		cout << "==\t00. Thoat chuong trinh quan ly    \t==\n";
		cout << "==\t                                  \t==\n";
		cout << "==================================================\n";
		cout << "\t    Nhap lua chon cua ban: ";
		cin >> luaChon;
		
		while (luaChon < 0 || luaChon > 11) {
            cout << "Lua chon khong hop le, vui long nhap lai: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
		
		switch (luaChon) { 
			case 1:
				nhap_duLieu(khach, n);
				cout << "\n==\tDAT PHONG THANH CONG\t==\n\n";
				system("\nPAUSE");
				break;
				
			case 2:
				xuat_duLieu(khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 3:
				sua_duLieu(khach, n);
				cout << endl; 
				system("\nPAUSE");
				break;                                                      
				
			case 4:
				khachDoiPhong(khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 5:
				themDichVu(khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 6:
				khachCheckIn(khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 7:
				khachCheckOut(khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 8:
				timKiem_duLieu(khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 9:
				xoa_duLieu(khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
			
			case 10:
				thongTinDanhSachPhong();
				cout << endl;
				system("\nPAUSE");
				break;
				
			case 11:
				baoCao(khach, n);
				cout << endl;
				system("\nPAUSE");
				break;
			
			case 0:
				exit(0);
				break;
		}
	} 
	while (luaChon != 0);
}
