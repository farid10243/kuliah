#include <iostream>
using namespace std;

struct sampul {
    int angka;
    struct sampul *next;
} *baru, *awal = NULL, *akhir = NULL, *current, *hapus;

void btBaru(){
    cout << "Tambah Data" << endl;
    baru = (sampul*)malloc(sizeof(sampul));
    cout << "Input Angka : ";
    cin >> baru->angka;
    baru->next = NULL;
}

void tambahDepan(){
    btBaru();
    if (awal == NULL){
        awal = baru;
        akhir = baru;
        akhir->next = NULL;
    }else {
        baru->next = awal;
        awal = baru;
    }
}

void tambahBelakang(){
    btBaru();
    if (awal == NULL){
        awal = baru;
    }else {
        akhir->next = baru;
    }
    akhir = baru;
    akhir->next = NULL;
}

void tampil(){
    if (awal == NULL){
        cout << "Data Kosong" << endl;
    }else{
        current = awal;
        while (current != NULL){
            cout << current->angka << " ";
            current = current->next;
        }
        cout << endl;
    }
}   

void hapusDepan(){
    if (awal == NULL){
        cout << "Data Kosong" << endl;
    }else{
        current = awal;
        awal = awal->next;
        free(current);
    }
}

void hapusBelakang(){
    current = awal;
    while (current){
        if (current->next == akhir){
            hapus = akhir;
            akhir = current;
            akhir->next = NULL;
            delete hapus;
            break;
        }
        current = current->next;
    }
}

void pilih(){
    int pilih;
    bool con = true;
    while (con)
    {
        cout << "Pilih Menu : " << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampilkan" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilih;
        cout<<"\n\n";
        switch (pilih)
        {
        case 1 : tambahDepan();
            break;
        case 2 : tambahBelakang();
            break;
        case 3 : hapusDepan();
            break;
        case 4 : hapusBelakang();
            break;
        case 5 : tampil();
            break;
        case 6 : con = false;
            break;
        default : cout << "Pilihan tidak ada" << endl;
        }
    }
    
}
int main(){
    pilih ();
    return 0;
}