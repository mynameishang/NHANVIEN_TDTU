#include <iostream>
#include "NhanVien.cpp"
#include "ListNhanVien.cpp"

using namespace std;

int main(){
    // NhanVien a("21110290","Diem Hang",2003,0);
    ListNhanVien list;
    NhanVien *b = new NhanVien("1","Hang",2003,10);
    NhanVien *c = new NhanVien("2","Ngan",1800,5);
    // list.nhapMangNhanVien();
    // list.xuatMangNhanVien();
    list.addData(b);
    list.addData(c);
    list.listNamSinh();

    vector<NhanVien*> luongCao;
    luongCao = ListNhanVien::listLuongCaoNhat(list.getData());
    cout << "Nhan vien co luong cao nhat: " << endl;
    for(int i=0;i<luongCao.size();i++){
        luongCao[i]->display();
    }

    cout << "\nTong luong nhan vien: " << list.tongLuong() << endl;

    list.sapXepLuong();
    list.xuatMangNhanVien();
    return 0;
}