#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Node {
    int npm; string nama;
    Node* next;
};

void init(Node* table[]) { for (int i=0;i<SIZE;i++) table[i]=nullptr; }
int hashFunc(int npm) { return (npm % SIZE + SIZE) % SIZE; }

void insert(Node* table[], int npm, string nama) {
    int i = hashFunc(npm);
    Node* nodeNew = new Node{npm,nama,table[i]};
    table[i] = nodeNew;
}

Node* search(Node* table[], int npm) {
    Node* cur = table[hashFunc(npm)];
    while(cur){ if(cur->npm==npm)return cur; cur=cur->next; }
    return nullptr;
}

void remove(Node* table[], int npm) {
    int i = hashFunc(npm);
    Node *cur=table[i], *prev=nullptr;
    while(cur){
        if(cur->npm==npm){
            if(!prev)table[i]=cur->next; else prev->next=cur->next;
            delete cur;
            cout<<"Data NPM "<<npm<<" dihapus.\n";
            return;
        }
        prev=cur; cur=cur->next;
    }
    cout<<"Data tidak ditemukan.\n";
}   

void show(Node* table[]) {
    cout<<"\nIsi Hash Table:\n";
    for(int i=0;i<SIZE;i++){
        cout<<"["<<i<<"] ";
        Node* cur=table[i];
        while(cur){ cout<<"("<<cur->npm<<","<<cur->nama<<")->"; cur=cur->next; }
        cout<<"NULL\n";
    }
}

int main() {
    Node* table[SIZE]; 
    init(table);
    int pil, npm; 
    string nama;

    while (true) {
        cout<<"\nMENU HASH MAP\n";
        cout<<"1. Tambah Data\n";
        cout<<"2. Tampilkan Data\n";
        cout<<"3. Cari Data\n";
        cout<<"4. Hapus Data\n";
        cout<<"5. Keluar\n";
        cout<<"Pilih: ";
        cin>>pil;

        if (pil == 1) {
            cout<<"Masukkan NPM: "; cin>>npm;
            cout<<"Masukkan Nama: "; cin>>nama;
            insert(table,npm,nama);
        } 
        else if (pil == 2) {
            show(table);
        } 
        else if (pil == 3) {
            cout<<"Masukkan NPM yang dicari: "; cin>>npm;
            if (Node* hasil = search(table,npm)) 
                cout<<"Ditemukan: "<<hasil->nama<<endl;
            else 
                cout<<"Data tidak ditemukan.\n";
        } 
        else if (pil == 4) {
            cout<<"Masukkan NPM yang dihapus: "; cin>>npm;
            remove(table,npm);
        } 
        else if (pil == 5) {
            cout<<"program selesai.\n";
            break;
        } 
        else {
            cout<<"Pilihan tidak valid.\n";
        }
    }
}
