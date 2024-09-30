#ifndef DATPHONG_H
#define DATPHONG_H

#include <fstream>
#include <ctime>
#include "danhSachPhong.h"
#pragma once

class datPhong : public danhSachPhong {
	private:
	    struct gioPhutGiay {
	        int gio, phut, giay;
	
	        gioPhutGiay(): gio(0), phut(0), giay(0) {}
	
	        gioPhutGiay(int _gio, int _phut, int _giay) : gio(_gio), phut(_phut), giay(_giay) {}
	    } hms;
	
	    struct ngayThangNam {
	        int ngay, thang, nam;
	
	        ngayThangNam() : ngay(0), thang(0), nam(0) {}
	
	        ngayThangNam(int _ngay, int _thang, int _nam) : ngay(_ngay), thang(_thang), nam(_nam) {}
	    } dmy;
	
	    struct thongTinDatPhong {
	        int phongDaDat;
	        gioPhutGiay gioPhut;
	        ngayThangNam ngayDatPhong;
	        int phongMoi;
	        string lyDoDoi;
	
	        thongTinDatPhong() : phongDaDat(0), phongMoi(0) {}
	
	        thongTinDatPhong(int _phongDaDat, gioPhutGiay _gioPhut, ngayThangNam _ngayDatPhong, int _phongMoi, string _lyDoDoi) : phongDaDat(_phongDaDat), gioPhut(_gioPhut), ngayDatPhong(_ngayDatPhong), phongMoi(_phongMoi), lyDoDoi(_lyDoDoi) {}
	    } dp;
	
	public:
	    // DAT PHONG
	    string dinhDangThoiGian(int i) {
			if (i < 10) {
		        return "0" + to_string(i);
		    } else {
		        return to_string(i);
		    }
		}
		
		bool kt_yy(int yy) {
		    time_t now = time(0);
		    tm *ltm = localtime(&now);
		    
		    int _yy = 1900 + ltm->tm_year;
		    return yy >= _yy;
		}
		
		bool kt_mm(int yy, int mm) {
		    time_t now = time(0);
		    tm *ltm = localtime(&now);
		    
		    int _yy = 1900 + ltm->tm_year;
		    int _mm =  1+ ltm->tm_mon;
		    
		    if (yy == _yy) {
		        return mm >= _mm;
		    } else if (yy > _yy) {
		        return true;
		    }
		    return false;
		}
		
		bool kt_dd(int yy, int mm, int dd) {
		    time_t now = time(0);
		    tm *ltm = localtime(&now);
		    
		    int _yy = 1900 + ltm->tm_year;
		    int _mm = 1 + ltm->tm_mon;
		    int _dd = ltm->tm_mday;
		    
		    if (yy == _yy && mm == _mm) {
		        return dd >= _dd;
		    } else if (yy > _yy || (yy == _yy && mm > _mm)) {
		        return true;
		    }
		    return false;
		}
		
		bool kt_h(int yy, int mm, int dd, int h) {
		    time_t now = time(0);
		    tm *ltm = localtime(&now);
		    
		    int _yy = 1900 + ltm->tm_year;
		    int _mm = 1 + ltm->tm_mon ;
		    int _dd = ltm->tm_mday;
		    int _h = ltm->tm_hour;
		    
		    if (yy == _yy && mm == _mm && dd == _dd) {
		        return h >= _h;
		    } else if (yy > _yy || (yy == _yy && mm > _mm) || (yy == _yy && mm == _mm && dd > _dd)) {
		        return true;
		    }
		    return false;
		}
		
		bool kt_min(int yy, int mm, int dd, int h, int min) {
		    time_t now = time(0);
		    tm *ltm = localtime(&now);
		    
		    int _yy = 1900 + ltm->tm_year;
		    int _mm = 1 + ltm->tm_mon ;
		    int _dd = ltm->tm_mday;
		    int _h = ltm->tm_hour;
		    int _min = ltm->tm_min;
		    
		    if (yy == _yy && mm == _mm && dd == _dd && h == _h) {
		        return min >= _min;
		    } else if (yy > _yy || (yy == _yy && mm > _mm) || (yy == _yy && mm == _mm && dd > _dd) || (yy == _yy && mm == _mm && dd == _dd && h > _h)) {
		        return true;
		    }
		    return false;
		}
	
	    bool kt_datPhong(int i) {
	        return i >= 0 && i < 3 && dp.phongDaDat == get_soPhong(i);
	    }
	
	    bool kt_doiPhong(int i) {
	        return i >= 0 && i < 3 && dp.phongMoi == get_soPhong(i);
	    }
	
	    void nhap_datPhong() {
	        while (true) {
	            cout << "Phong khach muon dat: ";
	            cin >> dp.phongDaDat;
	
	            bool valid = false;
	            for (int i = 0; i < 3; ++i) {
	                if (kt_datPhong(i)) {
	                    valid = true;
	                    break;
	                }
	            }
	
	            if (valid) {
	                do {
	                    cout << "Ngay dat phong (dd mm yyyy): ";
	                    cin >> dmy.ngay >> dmy.thang >> dmy.nam;
	
	                    if (!kt_yy(dmy.nam) || !kt_mm(dmy.nam, dmy.thang) || !kt_dd(dmy.nam, dmy.thang, dmy.ngay)) {
	                        cout << "Khong hop le, vui long nhap lai!\n";
	                        cout << "---------------------\n";
	                    }
	                } while (!kt_yy(dmy.nam) || !kt_mm(dmy.nam, dmy.thang) || !kt_dd(dmy.nam, dmy.thang, dmy.ngay));
	                dp.ngayDatPhong = dmy;
	
	                do {
	                    cout << "Khung gio dat phong (h:min): ";
	                    cin >> hms.gio >> hms.phut;
	
	                    if (!kt_h(dmy.nam, dmy.thang, dmy.ngay, hms.gio) || !kt_min(dmy.nam, dmy.thang, dmy.ngay, hms.gio, hms.phut)) {
	                        cout << "Khong hop le, vui long nhap lai!\n";
	                        cout << "---------------------\n";
	                    }
	                } while (!kt_h(dmy.nam, dmy.thang, dmy.ngay, hms.gio) || !kt_min(dmy.nam, dmy.thang, dmy.ngay, hms.gio, hms.phut));
	                dp.gioPhut = hms;
	
	                cout << "---------------------\n";
	                break;
	            } else {
	                cout << "Phong khong dung, vui long nhap lai!\n";
	            }
	        }
	    }
	
	    int get_phongDaDat() {
	        return dp.phongDaDat;
	    }
	
	    void set_phongDaDat(int _phongDaDat) {
	        dp.phongDaDat = _phongDaDat;
	    }
	
	    int get_gioDatPhong() {
	        return dp.gioPhut.gio;
	    }
	
	    int get_phutDatPhong() {
	        return dp.gioPhut.phut;
	    }
	
	    int get_ngayDatPhong() {
	        return dp.ngayDatPhong.ngay;
	    }
	
	    int get_thangDatPhong() {
	        return dp.ngayDatPhong.thang;
	    }
	
	    int get_namDatPhong() {
	        return dp.ngayDatPhong.nam;
	    }
	
	    void sua_datPhong() {
	    	while (true) {
	    		int sua[6];
	            cout << "---------------------\n";
	            cout << "Phong khach muon dat: ";
	            cin >> sua[0];
	            set_phongDaDat(sua[0]);
	
	            bool valid = false;
	            for (int i = 0; i < 3; ++i) {
	                if (kt_datPhong(i)) {
	                    valid = true;
	                    break;
	                }
	            }
	
	            if (valid) {
	                do {
	                    cout << "Ngay dat phong (dd mm yyyy): ";
	                    cin >> sua[1] >> sua[2] >> sua[3];
	
	                    if (!kt_yy(sua[3]) || !kt_mm(sua[3], sua[2]) || !kt_dd(sua[3], sua[2], sua[1])) {
	                        cout << "Khong hop le, vui long nhap lai!\n";
	                        cout << "---------------------\n";
	                    }
	                } while (!kt_yy(sua[3]) || !kt_mm(sua[3], sua[2]) || !kt_dd(sua[3], sua[2], sua[1]));
	
	                do {
	                    cout << "Khung gio dat phong (h:min): ";
	                    cin >> sua[4] >> sua[5];
	
	                    if (!kt_h(sua[3], sua[2], sua[1], sua[4]) || !kt_min(sua[3], sua[2], sua[1], sua[4], sua[5])) {
	                        cout << "Khong hop le, vui long nhap lai!\n";
	                        cout << "---------------------\n";
	                    }
	                } while (!kt_h(sua[3], sua[2], sua[1], sua[4]) || !kt_min(sua[3], sua[2], sua[1], sua[4], sua[5]));
	
	                cout << "---------------------\n";
	                break;
	            } else {
	                cout << "Phong khong dung, vui long nhap lai!\n";
	            }
	        }
	    }
	
	    void xoa_datPhong() {
	        dp.phongDaDat = 0;
	        dp.gioPhut.gio = 0;
	        dp.gioPhut.phut = 0;
	        dp.ngayDatPhong.ngay = 0;
	        dp.ngayDatPhong.thang = 0;
	        dp.ngayDatPhong.nam = 0;
	    }
	
	    void xuat_datPhong(ostream &os) {
	    	string dinhDangGio = dinhDangThoiGian(dp.gioPhut.gio);
			string dinhDangPhut = dinhDangThoiGian(dp.gioPhut.phut);
			
			string dinhDangNgay = dinhDangThoiGian(dp.ngayDatPhong.ngay);
			string dinhDangThang = dinhDangThoiGian(dp.ngayDatPhong.thang);
			string dinhDangNam = to_string(dp.ngayDatPhong.nam);
	    	
	        os << "Phong duoc dat: " << dp.phongDaDat << endl;
	        os << "Ngay dat phong (dd mm yyyy): " << dinhDangNgay << "/" << dinhDangThang << "/" << dinhDangNam << endl;
	        os << "Gio dat phong (h:min): " << dinhDangGio << ":" << dinhDangPhut << endl;        
	        os << "---------------------\n";
	    }
	
	    // DOI PHONG
	    void nhap_doiPhong() {
	        while (true) {
	            cout << "Khach muon chon phong: ";
	            cin >> dp.phongMoi;
	
	            bool valid = false;
	            for (int i = 0; i < 3; ++i) {
	                if (kt_doiPhong(i)) {
	                    valid = true;
	                    break;
	                }
	            }
	
	            if (valid) {
	                if (dp.phongMoi == dp.phongDaDat) {
	                    cout << "Phong moi trung voi phong cu, vui long nhap lai!\n";
	                } else {
	                    cout << "Ly do doi phong cua khach: ";
	                    cin.ignore();
	                    getline(cin, dp.lyDoDoi);
	                    cout << endl;
	                    break;
	                }
	            } else {
	                cout << "Phong khong hop le, vui long chon lai!\n";
	            }
	        }
	    }
	
	    void xacNhanLai() {
	    	cout << "\n----------------------------------------------------\n";
		    cout << "Xac nhan lai thong tin cua khach hang:" << endl;
		    cout << "---------------------\n";
	        cout << "Khach muon chon phong: " << dp.phongMoi << endl;
	        cout << "Ly do doi phong cua khach: " << dp.lyDoDoi << endl;
	    }
	
	    void xuat_doiPhong() {
	        cout << "\nTHONG BAO\n";
	        cout << "---------------------\n";
	        cout << "Xac nhan doi phong\n";
	        cout << "01. Xac nhan\n";
	        cout << "02. Huy bo\n";
	        cout << "---------------------\n";
	
	        int luaChon;
	        cout << "Lua chon: ";
	        cin >> luaChon;
	
	        if (luaChon == 1) {
	            int x = dp.phongDaDat;
	            dp.phongDaDat = dp.phongMoi;
	            dp.phongMoi = x;
	
	            cout << "\nDa doi phong thanh cong!\n";
	            cout << "---------------------\n";
	            cout << "Phong truoc khi doi: " << dp.phongMoi << endl;
	            cout << "Phong sau khi doi: " << dp.phongDaDat << endl;
	        } else if (luaChon == 2) {
	            cout << "\n\nHuy qua trinh doi phong!\n";
	        }
	    }
};

#endif // DATPHONG_H

