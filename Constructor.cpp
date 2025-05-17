#include <iostream>
#include <vector>
using namespace std;

class Buku {
    private:
        string judul;
        string penulis;
        bool dipinjam;

        public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}

    void status() {
        cout << "Buku: " << judul << " oleh " << penulis << (dipinjam ? " [Dipinjam]" : " [Tersedia]") << endl;
        }

        friend class Petugas;
    friend class Admin;

    };
    

    class Peminjam {
        private:
            int id;
            string nama;
            int totalPinjaman;

            public:
    Peminjam(int i, string n) : id(i), nama(n), totalPinjaman(0) {}

    void info() {
        cout << "ID: " << id << " | Nama: " << nama << " | Buku dipinjam: " << totalPinjaman << endl;
    }
    friend class Petugas;
    friend class Admin;

        };

class Petugas {
     private:
         int id;
                string nama;
            
    public:
        Petugas(int i, string n) : id(i), nama(n) {}
            
        void info() {
             cout << "ID Petugas: " << id << " | Nama: " << nama << endl;
            }

        void prosesPinjam(Buku* b, Peminjam* p) {
                if (!b->dipinjam) {
                    b->dipinjam = true;
                    p->totalPinjaman++;
                    cout << "Petugas '" << nama << "' memproses peminjaman buku '" << b->judul << "' untuk " << p->nama << endl;
                } else {
                    cout << "Buku '" << b->judul << "' sudah dipinjam!" << endl;
                }
            }
        
       void prosesKembali(Buku* b, Peminjam* p) {
        if (b->dipinjam) {
            b->dipinjam = false;
            p->totalPinjaman--;
            cout << "Petugas '" << nama << "' memproses pengembalian buku '" << b->judul << "' oleh " << p->nama << endl;
        } else {
            cout << "Buku '" << b->judul << "' tidak sedang dipinjam!" << endl;
        }
    }
      
};


class Admin {
    public:
        void lihatStatistikPeminjam(const vector<Peminjam>& daftarPeminjam) {
            cout << "\n[ADMIN] Statistik Peminjam:\n";
            for (const auto& p : daftarPeminjam) {
                cout << "- ID: " << p.id << " | Nama: " << p.nama << " | Buku dipinjam: " << p.totalPinjaman << endl;
            }
        }
    
        void lihatKetersediaanBuku(const vector<Buku>& daftarBuku) {
            cout << "\n[ADMIN] Ketersediaan Buku:\n";
            for (const auto& b : daftarBuku) {
                cout << "- Buku: " << b.judul << " oleh " << b.penulis << (b.dipinjam ? " [Dipinjam]" : " [Tersedia]") << endl;
            }
        }
};


int main() {
    string judulBuku, penulisBuku, namaPeminjam, namaPetugas;
    int idPeminjam, idPetugas;

    vector<Buku> daftarBuku;
    vector<Peminjam> daftarPeminjam;

    // Input buku
    cout << "Masukkan judul buku: ";
    getline(cin, judulBuku);
    cout << "Masukkan nama penulis: ";
    getline(cin, penulisBuku);
    daftarBuku.push_back(Buku(judulBuku, penulisBuku));

    // Input peminjam
    cout << "Masukkan ID peminjam: ";
    cin >> idPeminjam;
    cin.ignore();
    cout << "Masukkan nama peminjam: ";
    getline(cin, namaPeminjam);
    daftarPeminjam.push_back(Peminjam(idPeminjam, namaPeminjam));

    // Input petugas
    cout << "Masukkan ID petugas: ";
    cin >> idPetugas;
    cin.ignore();
    cout << "Masukkan nama petugas: ";
    getline(cin, namaPetugas);

    Petugas petugas1(idPetugas, namaPetugas);
    Admin admin1;

    petugas1.info();
    daftarBuku[0].status();
    daftarPeminjam[0].info();

    // Proses peminjaman buku
    petugas1.prosesPinjam(&daftarBuku[0], &daftarPeminjam[0]);

     // Admin melihat data peminjam & buku
     admin1.lihatStatistikPeminjam(daftarPeminjam);
     admin1.lihatKetersediaanBuku(daftarBuku);

     // Proses pengembalian buku
    petugas1.prosesKembali(&daftarBuku[0], &daftarPeminjam[0]);
}