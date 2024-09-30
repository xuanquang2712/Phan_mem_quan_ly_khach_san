#ifndef DICHVU_H
#define DICHVU_H

#include <iostream>
#include <string>

using namespace std;

class dichVu {
	private:
		int soLuong, tongTien = 0;
		int tien[9] = {0};
		
		string matHang[9] = {
	        "Mi", "Com rang", "Hoa qua",
	        "Nuoc cam", "Coca", "Bia",
	        "Ban chai", "Khan tam", "Dau goi"
	    };
	
	    int gia[9] = {
	        10, 50, 100,
	        20, 20, 30,
	        30, 50, 20
	    };
	
	public:
		string dinhDangTien(int i);
		
	    void nhap_dichVu();
	    int get_tongTien();
	    void xuat_dichVu(ostream &os);
	    
	    friend class thanhToan;
};

#endif //DICHVU_H

