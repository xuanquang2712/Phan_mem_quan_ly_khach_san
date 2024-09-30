#ifndef DANHSACHPHONG_H
#define DANHSACHPHONG_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class danhSachPhong {
    protected:
        struct dacDiemPhong {
            string giuong, noiThat, wc, view;

            dacDiemPhong() {}

            dacDiemPhong(string _giuong, string _noiThat, string _wc, string _view) : giuong(_giuong), noiThat(_noiThat), wc(_wc), view(_view) {}
        };

        struct maPhong {
            int phong, tang;

            maPhong() {}

            maPhong(int _tang, int _phong) : tang(_tang), phong(_phong) {}
        };

        struct thongTinPhong {
            maPhong soPhong;
            dacDiemPhong dacDiem;
            string tinhTrang;

            thongTinPhong() {}

            thongTinPhong(maPhong _soPhong, dacDiemPhong _dacDiem, string _tinhTrang) : soPhong(_soPhong), dacDiem(_dacDiem), tinhTrang(_tinhTrang) {}
        } dsp[3];

    public:
        danhSachPhong() {
            dsp[0] = thongTinPhong(maPhong(1, 1), dacDiemPhong("Don", "Co ban", "1", "Vuon"), "Trong");
            dsp[1] = thongTinPhong(maPhong(1, 2), dacDiemPhong("Doi", "Full", "2", "Bien"), "Trong");
            dsp[2] = thongTinPhong(maPhong(2, 1), dacDiemPhong("Doi", "Full", "3", "Bien"), "Trong");
        }

        int get_soPhong(int i) {
            if (i < 0 || i >= 3) {
                return -1;
            }
            return dsp[i].soPhong.tang * 100 + dsp[i].soPhong.phong;
        }

        void nhap_danhSachPhong() {
            int i;
            cout << "\nNhap ma phong can sua(1, 2, 3): ";
            cin >> i;

            if (i <= 0 || i > 3) {
                cout << "Khong ton tai ma phong, vui long thu lai!\n";
                return;
            }

            cout << "---------------------\n";
            cout << "Tang thu: ";
            cin >> dsp[i - 1].soPhong.tang;

            cout << "Phong so: ";
            cin >> dsp[i - 1].soPhong.phong;

            cout << "Nhap thong tin giuong: ";
            cin.ignore();
            getline(cin, dsp[i - 1].dacDiem.giuong);

            cout << "Nhap thong tin noi that: ";
            getline(cin, dsp[i - 1].dacDiem.noiThat);

            cout << "Nhap thong tin WC: ";
            getline(cin, dsp[i - 1].dacDiem.wc);

            cout << "Nhap thong tin View: ";
            getline(cin, dsp[i - 1].dacDiem.view);
        }

        void xuat_danhSachPhong() {
            for(int i = 0; i < 3; i++) {
//                cout << "\nThong tin phong " << endl;
//                cout << "--------------------------------------------------\n";
//                cout << "So phong: " << setw(7) << get_soPhong(i) << setw(12) << get_soPhong(i+1) << setw(12) << get_soPhong(i+2) << endl;
//                cout << "Giuong: " << setw(9) << dsp[i].dacDiem.giuong << setw(12) << dsp[i+1].dacDiem.giuong << setw(12) << dsp[i+2].dacDiem.giuong << endl;
//                cout << "Noi that: " << setw(10) << dsp[i].dacDiem.noiThat << setw(10) << dsp[i+1].dacDiem.noiThat << setw(12) << dsp[i+2].dacDiem.noiThat << endl;
//                cout << "So WC: " << setw(9) << dsp[i].dacDiem.wc << setw(12) << dsp[i+1].dacDiem.wc << setw(12) << dsp[i+2].dacDiem.wc << endl;
//                cout << "View: " << setw(12) << dsp[i].dacDiem.view << setw(12) << dsp[i+1].dacDiem.view << setw(12) << dsp[i+2].dacDiem.view << endl;
//                cout << "Tinh trang: " << setw(7) << dsp[i].tinhTrang << setw(12) << dsp[i+1].tinhTrang << setw(12) << dsp[i+2].tinhTrang << endl;
//                break;
                
                cout << "\nDANH SACH PHONG" << endl;
                cout << "--------------------------------------------------\n";
                cout << "So phong: " << "\t" << get_soPhong(i) << "\t" << get_soPhong(i+1) << "\t" << get_soPhong(i+2) << endl;
                cout << "Giuong: " << "\t" << dsp[i].dacDiem.giuong << "\t" << dsp[i+1].dacDiem.giuong << "\t" << dsp[i+2].dacDiem.giuong << endl;
                cout << "Noi that: " << "\t" << dsp[i].dacDiem.noiThat << "\t" << dsp[i+1].dacDiem.noiThat << "\t" << dsp[i+2].dacDiem.noiThat << endl;
                cout << "So WC: " << "\t\t" << dsp[i].dacDiem.wc << "\t" << dsp[i+1].dacDiem.wc << "\t" << dsp[i+2].dacDiem.wc << endl;
                cout << "View: " << "\t\t" << dsp[i].dacDiem.view << "\t" << dsp[i+1].dacDiem.view << "\t" << dsp[i+2].dacDiem.view << endl;
                cout << "Tinh trang: " << "\t" << dsp[i].tinhTrang << "\t" << dsp[i+1].tinhTrang << "\t" << dsp[i+2].tinhTrang << endl;
                break;
            }
        }
};

#endif //DANHSACHPHONG_H

