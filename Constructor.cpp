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
            
            
            };
            