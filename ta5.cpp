#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* left;
    Node* right;
    Node(int n) : nilai(n), left(NULL), right(NULL) {}
};

Node* insertNode(Node* root, int nilai) {
    if (!root) return new Node(nilai);
    if (nilai < root->nilai)
        root->left = insertNode(root->left, nilai);
    else if (nilai > root->nilai)
        root->right = insertNode(root->right, nilai);
    return root;
}

void tampil(Node* root) {
    if (!root) return;
    tampil(root->left);
    cout << root->nilai << " ";
    tampil(root->right);
}

bool cari(Node* root, int nilai) {
    if (!root) return false;
    if (root->nilai == nilai) return true;
    return (nilai < root->nilai)
        ? cari(root->left, nilai)
        : cari(root->right, nilai);
}

int main() {
    Node* root = NULL;
    int pilih, nilai;

    do {
        cout << "\n=== DATA NILAI MAHASISWA (BST) ===\n";
        cout << "1. Tambah Nilai\n2. Tampilkan Semua Nilai\n3. Cari Nilai\n4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan nilai: ";
            cin >> nilai;
            root = insertNode(root, nilai);
        } 
        else if (pilih == 2) {
            cout << "Nilai mahasiswa (urutan kecil ke besar): ";
            tampil(root);
            cout << endl;
        } 
        else if (pilih == 3) {
            cout << "Masukkan nilai yang dicari: ";
            cin >> nilai;
            if (cari(root, nilai))
                cout << "Nilai ditemukan!\n";
            else
                cout << "Nilai tidak ditemukan!\n";
        }
    } while (pilih != 4);

    cout << "Program selesai.\n";
    return 0;
}
