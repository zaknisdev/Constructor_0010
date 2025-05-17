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
    