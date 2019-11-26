#include<bits/stdc++.h>
using namespace std;

void string2hex(const string str, string& hexstr, bool capital = true) {
    hexstr.resize((str.size() * 2));
    const size_t a = capital ? 'A' - 1 : 'a' - 1;
    for (size_t i = 0, c = str[0] & 0xFF; i < hexstr.size(); c = str[i / 2] & 0xFF) {
        hexstr[i++] = c > 0x9F ? (c / 16 - 9) | a : c / 16 | '0';
        hexstr[i++] = (c & 0xF) > 9 ? (c % 16 - 9) | a : c % 16 | '0';
    }
}

int main(){
    string s = "Your lips are smoother than vaseline";
    cout << "\n\tOriginal String: " << s << '\n';
    string2hex(s, s);
    s = s + "0D0A";
    cout << "\n\tHexadecimal Format: " << s << "\n\n";
    return 0;
}


/*NEXT:-  PC 18*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    // string K = "133457799BBCDFF1";
    string K;
    cout << "\n\n\tEnter The Hexadecimal String : ";
    cin >> K;
    int PC1[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};

    int KPlus[56];

    string hex[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

    string bits[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

    string bin[(sizeof(K) / sizeof(K[0]))];

    for (int i = 0; i < (sizeof(K) / sizeof(K[0])); i++) 
{
        if (K[i] == '0') bin[i] = bits[0];
        if (K[i] == '1') bin[i] = bits[1];
        if (K[i] == '2') bin[i] = bits[2];
        if (K[i] == '3') bin[i] = bits[3];
        if (K[i] == '4') bin[i] = bits[4];
        if (K[i] == '5') bin[i] = bits[5];
        if (K[i] == '6') bin[i] = bits[6];
        if (K[i] == '7') bin[i] = bits[7];
        if (K[i] == '8') bin[i] = bits[8];
        if (K[i] == '9') bin[i] = bits[9];
        if (K[i] == 'A') bin[i] = bits[10];
        if (K[i] == 'B') bin[i] = bits[11];
        if (K[i] == 'C') bin[i] = bits[12];
        if (K[i] == 'D') bin[i] = bits[13];
        if (K[i] == 'E') bin[i] = bits[14];
        if (K[i] == 'F') bin[i] = bits[15];
    }
    cout << "\n\n\tK (Hexa Str) : " << K;

    cout << "\n\n\tK (64 bits)  : ";
    for (int l = 0; l < sizeof(K) / sizeof(K[0]); l++) cout << bin[l] << " ";

    for (int kp = 0; kp < 56; kp++) 
{
        KPlus[kp] = int(bin[PC1[kp] / 4][PC1[kp] % 4]) - 48;
    }

    cout << "\n\n\tK+ (56 bits) : ";

    for (int u = 0; u < 56; u++) 
{
        if ((u+1) % 4 != 0) cout << KPlus[u];
        else {
            cout << KPlus[u] << " ";
        }
    }
    cout << "\n\n";

    return 0;

/*NEXT:-*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int KPlus[56] = {1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0};
    int C0[28], D0[28];
    int itr[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

    cout << "\n\n\tK+ (56-bits)  : ";
    for (int i = 0; i < 56; i++) 
   {
        if ((i + 1) % 4 != 0) cout << KPlus[i];
        else cout << KPlus[i] << " ";
    }
    cout << endl;
    int it = 0;
    for (int cd = 0; cd < 28; cd++) 
   {
        C0[cd] = KPlus[it++];
    }
    for (int cd = 0; cd < 28; cd++)
    {
        D0[cd] = KPlus[it++];
    }
    int C[16][28], D[16][28];

    for (int iter = 0; iter < 16; iter++) 
    {
        int z1 = 0;
        int z2 = 0;
        if (iter == 0) {
            for (int x = itr[iter]; x < 28; x++) 
           {
                C[iter][z1++] = C0[x];
                D[iter][z2++] = D0[x];
            }
            for (int y = 0; y < itr[iter]; y++) 
           {
                C[iter][z1++] = C0[y];
                D[iter][z2++] = D0[y];
            }
        }
        else {
            for (int x = itr[iter]; x < 28; x++) 
            {
                C[iter][z1++] = C[iter - 1][x];
                D[iter][z2++] = D[iter - 1][x];
            }
            for (int y = 0; y < itr[iter]; y++) 
            {
                C[iter][z1++] = C[iter - 1][y];
                D[iter][z2++] = D[iter - 1][y];
            }
        }
    }

    cout << "\n\tC0 (28-bits)  : ";
    for (int c = 0; c < 28; c++) 
    {
        if ((c + 1) % 4 != 0) cout << C0[c];
        else cout << C0[c] << " ";
    }
    cout << "\n\tD0 (28-bits)  : ";
    for (int d = 0; d < 28; d++) 
    {
        if ((d + 1) % 4 != 0) cout << D0[d];
        else cout << D0[d] << " ";
    }
    cout << endl;

    for (int i = 0; i < 16; i++) 
   {

        if (i + 1 <= 9) cout << "\n\tC" << i + 1 << " (28-bits)  : ";
        else cout << "\n\tC" << i + 1 << " (28-bits) : ";
        for (int x = 0; x < 28; x++) 
       {
            if ((x + 1) % 4 != 0) cout << C[i][x];
            else cout << C[i][x] << " ";
        }
        if (i + 1 <= 9) cout << "\n\tD" << i + 1 << " (28-bits)  : ";
        else cout << "\n\tD" << i + 1 << " (28-bits) : ";
        for (int y = 0; y < 28; y++) 
       {
            if ((y + 1) % 4 != 0) cout << D[i][y];
            else cout << D[i][y] << " ";
        }
        cout << "\n";   }
    cout << endl << endl;
    return 0;
}
}


/*NEXT:-*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int KPlus[56] = {1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0};
    int PC2[48] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};
    int itr[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

    // 1. Generating C1, C2, ......., C16 & D1, D2, ...... D16 from K+

    // 1.1. Creating C0 & D0 from K+
    int C0[28], D0[28];
    int it = 0;
    for (int cd = 0; cd < 28; cd++) 
   {
        C0[cd] = KPlus[it++];
    }
    for (int cd = 0; cd < 28; cd++) 
   {
        D0[cd] = KPlus[it++];
    }

    // 1.2. Creating C1, C2, ......., C16 & D1, D2, ...... D16 from C0 & D0
    int C[16][28], D[16][28];

    for (int iter = 0; iter < 16; iter++) 
    {
        int z1 = 0;
        int z2 = 0;
        if (iter == 0) {
            for (int x = itr[iter]; x < 28; x++) 
            {
                C[iter][z1++] = C0[x];
                D[iter][z2++] = D0[x];
            }
            for (int y = 0; y < itr[iter]; y++) 
           {
                C[iter][z1++] = C0[y];
                D[iter][z2++] = D0[y];
            }
        }
        else {
            for (int x = itr[iter]; x < 28; x++) 
           {
                C[iter][z1++] = C[iter - 1][x];
                D[iter][z2++] = D[iter - 1][x];
            }
            for (int y = 0; y < itr[iter]; y++) 
           {
                C[iter][z1++] = C[iter - 1][y];
                D[iter][z2++] = D[iter - 1][y];
            }
        }
    }

    // 2. Generating K1, K2, ......., K16 in 56 bit format from C1, C2, ......., C16 & D1, D2, ...... D16
    int K_56[16][56];
    for (int w = 0; w < 16; w++) 
     {
        int out = 0;
        for (int w1 = 0; w1 < 28; w1++) 
        {
            K_56[w][out++] = C[w][w1];
        }
        for (int w2 = 0; w2 < 28; w2++) 
       {
            K_56[w][out++] = D[w][w2];
        }
    }

    // 3. Generating K1, K2, ......., K16 in 48 bit format from K1, K2, ......., K16 in 56 bit format using PC-2
    int K_48[16][48];

    for (int i = 0; i < 16; i++) 
    {
        for (int j = 0; j < 48; j++) 
       {
            K_48[i][j] = K_56[i][PC2[j]];
        }
    }

    // Printing The Final Outputs :

    cout << "\n\n\tK+ (56-bits)  : ";
    for (int i = 0; i < 56; i++) 
   {
        if ((i + 1) % 4 != 0) cout << KPlus[i];
        else cout << KPlus[i] << " ";
    }
    cout << "\n\tC0 (28-bits)  : ";
    for (int c = 0; c < 28; c++) 
    {
        if ((c + 1) % 4 != 0) cout << C0[c];
        else cout << C0[c] << " ";
    }
    cout << "\n\tD0 (28-bits)  : ";
    for (int d = 0; d < 28; d++) 
    {
        if ((d + 1) % 4 != 0) cout << D0[d];
        else cout << D0[d] << " ";
    }

    cout << "\n";
    for (int i = 0; i < 16; i++) 
      {

        if (i + 1 <= 9) cout << "\n\tC" << i + 1 << " (28-bits)  : ";
        else cout << "\n\tC" << i + 1 << " (28-bits) : ";
        for (int x = 0; x < 28; x++) 
        {
            if ((x + 1) % 4 != 0) cout << C[i][x];
            else cout << C[i][x] << " ";
        }
        if (i + 1 <= 9) cout << "\n\tD" << i + 1 << " (28-bits)  : ";
        else cout << "\n\tD" << i + 1 << " (28-bits) : ";
        for (int y = 0; y < 28; y++) 
        {
            if ((y + 1) % 4 != 0) cout << D[i][y];
            else cout << D[i][y] << " ";
        }

        if (i + 1 <= 9) cout << "\n\tK" << i + 1 << " (56-bits)  : ";
        else cout << "\n\tK" << i + 1 << " (56-bits) : ";
        for (int j = 0; j < 56; j++) 
       {
            if ((j + 1) % 4 != 0) cout << K_56[i][j];
            else cout << K_56[i][i] << " ";
        }
        if (i + 1 <= 9) cout << "\n\tK" << i + 1 << " (48-bits)  : ";
        else cout << "\n\tK" << i + 1 << " (48-bits) : ";
        for (int k = 0; k < 48; k++) 
       {
            if ((k + 1) % 4 != 0) cout << K_48[i][k];
            else cout << K_48[i][k] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n\n";

    return 0;
}
  OUTPUT:



