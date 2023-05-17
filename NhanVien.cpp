#include <iostream>

#pragma once

using namespace std;

class NhanVien{
private:
    string maNhanVien;
    string tenNhanVien;
    int namSinh;
    float luongNhanVien;
public:
    NhanVien(string maNhanVien,string tenNhanVien,int namSinh,float luongNhanVien){
        this->setMaNhanVien(maNhanVien);
        this->setTenNhanVien(tenNhanVien);
        this->setNamSinh(namSinh);
        this->setLuongNhanVien(luongNhanVien);
    }

    NhanVien():NhanVien("NA","NA",0,0){}

    void setMaNhanVien(string maNhanVien){
        while(maNhanVien.size() > 5){
            cout << "Ma nhan vien khong hop le!" << endl << "Nhap lai ma nhan vien: ";
            getline(cin,maNhanVien);
        }
        this->maNhanVien = maNhanVien;
    }

    void setTenNhanVien(string tenNhanVien){
        while(tenNhanVien.size() > 30){
            cout << "Ten nhan vien khong hop le!" << endl << "Nhap lai ten nhan vien: ";
            getline(cin,tenNhanVien);
        }
        this->tenNhanVien = tenNhanVien;
    }

    void setNamSinh(int namSinh){
        while((namSinh > 2023 || namSinh <1000) && namSinh != 0){
            cout << "Nam sinh khong hop le!" << endl << "Nhap lai nam sinh: ";
            cin >> namSinh;
        }
        this->namSinh = namSinh;
    }

    void setLuongNhanVien(float luongNhanVien){
        this->luongNhanVien = luongNhanVien;
    }

    string getMaNhanVien(){
        return maNhanVien;
    }

    string getTenNhanVien(){
        return tenNhanVien;
    }

    int getNamSinh(){
        return namSinh;
    }

    float getLuongNhanVien(){
        return luongNhanVien;
    }

    void display(){
        cout << "Ma nhan vien: " << maNhanVien << endl;
        cout << "Ten nhan vien: " << tenNhanVien << endl;
        cout << "Nam sinh: " << namSinh << endl;
        cout << "Luong nhan vien: " << luongNhanVien << endl;
    }
};