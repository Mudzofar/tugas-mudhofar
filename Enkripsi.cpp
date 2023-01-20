#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

main(int argc, char *argv[]){

    FILE *Fin, *Fout;
    char p,c;
    string k;
    int i;

    // Membuka file
    Fin = fopen(argv[1], "rb");
    if(Fin == NULL) {
        cout << "Berkas " << argv[1] << " tidak ada " << endl;
        exit(0);
    }

    // membuka file
    Fout = fopen(argv[2] , "wb");
    cout << "Kata kunci : "; cin >> k;
    cout << "Deskripsi " << argv[2] << " 
	menjadi " << "....";

    i = 0;
    while(!feof(Fin)) {
        p = getc(Fin);
        c = p ^ k[i]; // operasi XOR
        putc(c, Fout);
        i = (i + 1) % k.length();
    }

    // Menutup File
    fclose(Fin);
    fclose(Fout);
    
}
