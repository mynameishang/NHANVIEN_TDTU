#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "NhanVien.cpp"

#pragma once

using namespace std;

class ListNhanVien{
private:
    vector<NhanVien*> data;
public:
    ListNhanVien(){
    }

    vector<NhanVien*> getData(){
        return data;
    }

    void getInformation(string &maNhanVien,string &tenNhanVien,int &namSinh,float &luongNhanVien){
        fflush(stdin);
        cout << "Ma nhan vien: ";
        getline(cin,maNhanVien);
        cout << "Ten nhan vien: ";
        getline(cin,tenNhanVien);
        cout << "Nam sinh: ";
        cin >> namSinh;
        cout << "Luong nhan vien: ";
        cin >> luongNhanVien;
    }

    void nhapMangNhanVien(){
        int n;
        cout << "Nhap so nhan vien trong mang: ";
        cin >> n;
        for(int i=0;i<n;i++){
            string maNhanVien,tenNhanVien;
            int namSinh;
            float luongNhanVien;
            this->getInformation(maNhanVien,tenNhanVien,namSinh,luongNhanVien);
            NhanVien* a = new NhanVien(maNhanVien,tenNhanVien,namSinh,luongNhanVien);
            data.push_back(a);
        }
    }

    void addData(NhanVien *a) {
        this->data.push_back(a);
    }

    void xuatMangNhanVien(){
        cout << "\nDanh sach nhan vien: \n";
        for(int i=0;i<data.size();i++){
            data[i]->display();
            cout << endl;
        }
    }

    void listNamSinh(){
        vector<NhanVien*> namSinh;
        for(int i=0;i<data.size();i++){
            if(data[i]->getNamSinh()<1985){
                namSinh.push_back(data[i]);
            }
        }
        cout << "\nDanh sach nhan vien co nam sinh truoc nam 1985\n";
        for(int i=0;i<namSinh.size();i++){
            namSinh[i]->display();
            cout << endl;
        }
    }

    static bool cmp(NhanVien* a,NhanVien* b){
        return a->getLuongNhanVien() < b->getLuongNhanVien();
    }

    static vector<NhanVien*> listLuongCaoNhat(vector<NhanVien*> data){
        vector<NhanVien*> luongCao;
        //NhanVien max = *max_element(data.begin(),data.end());
        float max = (*max_element(data.begin(),data.end(),cmp))->getLuongNhanVien();
        for(int i=0;i<data.size();i++){
            if(data[i]->getLuongNhanVien() == max){
                luongCao.push_back(data[i]);
            }
        }
        return luongCao;
    }

    int tongLuong(){
        int sum = 0;
        for(int i=0;i<data.size();i++){
            sum+=data[i]->getLuongNhanVien();
        }
        return sum;
    }

    int trungBinhLuong(){
        return ListNhanVien::tongLuong() / data.size();
    }

    static bool cmpXapSep(NhanVien* a,NhanVien* b){
        return a->getLuongNhanVien() < b->getLuongNhanVien();
    }

    void sapXepLuong(){
        sort(data.begin(),data.end(),cmpXapSep);
    }
};