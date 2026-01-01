#include <iostream>
#include <map>
using namespace std;

class Kutuphane {
private:
    string kitapAdi;
    string yazarAdi;
    int rafNo;

public:

    // VARSAYILAN KURUCU
    Kutuphane() : kitapAdi(""), yazarAdi(""), rafNo(0) {}

    Kutuphane(string kitap, string yazar,int no){
        kitapAdi = kitap;
        yazarAdi = yazar;
        rafNo = no;
    }

    string getKitapAdi() const {return kitapAdi;}
    string getYazarAdi() const {return yazarAdi;}
    int raf_No() const {return rafNo;}
};

std::ostream& operator<<(std::ostream& os, const Kutuphane& k) {
    os << "\nKitap: " << k.getKitapAdi()
       << ", Yazar: " << k.getYazarAdi()
       << ", Raf No: " << k.raf_No() << endl;
    return os;
}

int main()
{

    string kitap, yazar;
    int no, id;

        //id, kitap bilgileri
    map<int, Kutuphane> mKitaplar;


    int secim = 0, idYaz;

    do {
        cout << "\n---Kütüphane Yönetim Sistemine Hoşgeldiniz---\n";

        cout << "\nYapmak istediğiniz işlemi seçiniz:\n";

        cout << "1- Kitap Ekleme\n";
        cout << "2- Kitap Bilgilerini Görüntüleme\n";
        cout << "3- Kitap Silme\n";
        cout << "4- Tüm Kitapları Listeleme\n";
        cout << "5- Çıkış\n";

        cin >> secim;


        switch (secim) {
        case 1: //Kitap Ekleme
            cout << "kitap id: ";
            cin >> id;
            cin.ignore();

            cout << "kitap adı: ";
            getline(cin,kitap);

            cout << "yazar adı: ";
            getline(cin,yazar);

            cout << "raf no: ";
            cin >> no;

            mKitaplar[id] = Kutuphane(kitap,yazar,no);
            cout << "Kitap başarıyla eklendi..";
            break;

        case 2:{
            cout << "Bilgilerini görüntülemek istediğiniz kitap id: ";
            cin >> idYaz;

            auto it = mKitaplar.find(idYaz); // boş nesne oluşturulmasını engelledik.
            if (it != mKitaplar.end()) {
                cout << idYaz << " id numaralı kitap bilgileri: " << it->second << endl;
            } else {
                cout << "Kitap bulunamadı!" << endl;
            }
            break;}

        case 3: //Kitap Silme
            cout << "Silmek istediğiniz kitap Id: ";
            cin >> idYaz;

            if(mKitaplar.find(idYaz) != mKitaplar.end()){
                mKitaplar.erase(idYaz);
                cout << "Kitap Silindi" << endl;
            }
            else{cout << "Kitap bulunamadı..\n";}
            break;

        case 4: //Tüm Kitapları Listeleme
            cout << "\n---Kayıtlı Kitap Listesi---\n\n";

            for(const auto& kitap : mKitaplar){
                cout << "Kitap id: " << kitap.first << " , Kitap Bilgileri: " << kitap.second << endl;
            }
            break;

        case 5:
            cout << "Çıkış yapılıyor...";
            break;

        default:
            break;
        }




    } while(secim != 5);


    return 0;
}
