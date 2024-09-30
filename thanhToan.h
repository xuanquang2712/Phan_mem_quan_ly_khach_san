#ifndef THANHTOAN_H
#define THANHTOAN_H

#include "datPhong.h"
#include "checkIn.h"
#include "checkOut.h"
#include "dichVu.h"

#pragma once

class thanhToan : public virtual datPhong, public virtual checkIn, public virtual checkOut, public virtual dichVu {
    private:
        double thanhTien;
        double giaNgayVip = 4000, giaGioVip = 250;
        double giaNgayThuong = 2500, giaGioThuong = 150;
        
        double chuyenDoiThoiGian();

    public:
        thanhToan();
        string dinhDangTien(int i);
        void khachThanhToan();
        double get_thanhTien();
        void xuat_thanhToan(ostream &os);
        
        friend class khachHang;
};

#endif // THANHTOAN_H

