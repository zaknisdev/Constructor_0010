#include <iostream>
using namespace std;

class Mahasiswa{
    private:
        static int jumlahMhs;
    
    public:
        string nama;
        Mahasiswa(string pNama){
            nama = pNama;
            ++jumlahMhs;
            cout << "Mahasiswa dibuat " << nama << endl;
        }
        ~Mahasiswa(){
            --jumlahMhs;
            cout << "Nama Terhapus " << nama << endl;
        }
        static void setJumlah(int pJumlah){
            jumlahMhs = pJumlah;
        }
        static int getJumlahMhs(){
            return jumlahMhs;
        }
};

int Mahasiswa::jumlahMhs = 0;

int main(){
    cout << "Jumlah Mahasiswa:" << Mahasiswa::getJumlahMhs() << endl;

    Mahasiswa mhs1("Tono");
    Mahasiswa mhs2("Agus");
    cout << "Jumlah Mahasiswa:" << Mahasiswa::getJumlahMhs() << endl;
    Mahasiswa::setJumlah(5);
    {
        Mahasiswa mhs3("Sulis");
         cout << "Jumlah Mahasiswa: " << Mahasiswa::getJumlahMhs() << endl;
    }

    cout << "Jumlah Mahasiswa: " << Mahasiswa::getJumlahMhs() << endl;
    return 0;
}