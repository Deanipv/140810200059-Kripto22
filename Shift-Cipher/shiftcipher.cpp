#include <iostream>

namespace ShiftCipher {
    const int ASCII_CODE_LC=97;
    const int ASCII_CODE_UC=65;

    /**
     * @brief 
     * Mengecek karakter dalam range A(0) sampai Z(25)
     *  
     * @param karakter karakter sedang diperiksa
     * @param code Ascii code digunakan
     * 
     * @return true or false 
     */

    bool inRangeOfAscii(char karakter, int code) {
        return(
            (karakter-code) >= 0
            &&
            (karakter-code) <= 25
        );
    }

     /**
     * @brief 
     * Mengenkripsi teks menggunakan rumus:
     * (x + K) mod 26
     * 
     * @param text Plaintext untuk di enkripsi
     * @param key Key sudah digunakan dalam rumus
     * 
     * @return Encrypted text
     */

    std::string encrypt(std::string text="abc", int key=1){
        std::string ans=" ";

        for(char ch: text){
            if(inRangeOfAscii(ch,ASCII_CODE_LC)) { //handling buat lower case
                ch = (((ch-ASCII_CODE_LC)+key)%26)+ASCII_CODE_LC;
            }
            else if(inRangeOfAscii(ch,ASCII_CODE_UC)){ //handling for upper case
                ch = (((ch-ASCII_CODE_UC)+key)%26)+ASCII_CODE_UC;
            }
            ans.push_back(ch);
        }
        return ans;
    }

     /**
     * @brief
     * Mendeskripsikan teks menggunakan rumus:
     *  (x - K) mod 26
     * 
     * @param text text yg sudah dienkripsi buat di deskripsikan 
     * @param key Key sudah digunakan dalam rumus
     * 
     * @return Decrypted text
     */

    std::string decrypt(std::string text="abc", int key=1){
        std::string ans=" ";

        for(char ch: text) {
            if(inRangeOfAscii(ch,ASCII_CODE_LC)){ //handling for lower case
                ch -= (ASCII_CODE_LC + key);
                ch = (ch < 0 ) ? ch+26 : ch; //jika char dibawah 0,maka kan ditambahkan 26 ke nilai char
                ch = (ch%26)+ASCII_CODE_LC;
            } 
            else if(inRangeOfAscii(ch,ASCII_CODE_UC)){ //handling for upper case
                ch -= (ASCII_CODE_UC + key);
                ch = (ch < 0) ? ch+26 : ch; //jika char dibawah 0,maka kan ditambahkan 26 ke nilai char
                ch = (ch%26)+ASCII_CODE_UC;
            }
            ans.push_back(ch);
        }
        return ans;
    }
};

int main() {
    system("cls");
    bool running=true;

    while(running){
        int pilihan=1;

        //Menu
        printf("\nMENU\n");
        printf("1.  Enkripsi\n");
        printf("2.  Deskripsi\n");
        printf("3.  Keluar\n");
        std::cout << "Pilihan: "; 
        std::cin >> pilihan;
        std::cin.ignore();

        std::string plaintext=" ";
        int key=1;

        switch (pilihan)
        {
        case 1 ://enkripsi
            std::cout << "Text: " ; std::getline(std::cin,plaintext);
            std::cout << "key: "; std::cin >> key;
            std::cout << "Encryption = " << ShiftCipher::encrypt(plaintext,key) << "\n";
            break;

        case 2 ://deskripsi
            std::cout << "Text: " ; std::getline(std::cin,plaintext);
            std::cout << "key: "; std::cin >> key;
            std::cout << "Decryption = " << ShiftCipher::decrypt(plaintext,key) << "\n";
            break;

        case 3 ://keluar
            system("cls");
            printf("Sampai jumpa...\n");
            system("pause");
            running=false;
            break;
    
        default://error handling
            printf("(x) Terjadi kesalahan dalam memilih, harap coba lagi\n");
            system("pause");
            break;
        }
    }
}