#ifndef CHECKIN_H
#define CHECKIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class checkIn {
	protected:
		struct gioPhutGiay {
	        int gio, phut, giay;
	
	        gioPhutGiay() {}
	
	        gioPhutGiay(int _gio, int _phut, int _giay) : gio(_gio), phut(_phut), giay(_giay) {}
	    } hms;
		
	    struct ngayThangNam {
	        int ngay, thang, nam;
	
	        ngayThangNam() {}
	        ngayThangNam (int _ngay, int _thang, int _nam) : ngay (_ngay), thang (_thang), nam (_nam) {}
	    } dmy;
	
	    struct thoiGianCI {
	        ngayThangNam ngayVao;
	        gioPhutGiay gioVao;
	
	        thoiGianCI() {}
	        thoiGianCI(ngayThangNam _ngayVao, gioPhutGiay _gioVao) : ngayVao(_ngayVao), gioVao(_gioVao) {}
	    } ci;
	
	public:
		string dinhDangThoiGian(int i);
		
	    void nhap_checkIn();
	    
	    int get_gioVao();
	    void set_gioVao(int _gioVao);
	    
		int get_phutVao();
		void set_phutVao(int _phutVao);
		
		int get_ngayVao();
		void set_ngayVao(int _ngayVao);
		
		int get_thangVao();
		void set_thangVao(int _thangVao);
		
		int get_namVao();
		void set_namVao(int _namVao);
		
	    void sua_checkIn();
	    void xoa_checkIn();
	    void xuat_checkIn(ostream &os);
	    
	    friend class thanhToan;
};

#endif //CHECKIN_H

