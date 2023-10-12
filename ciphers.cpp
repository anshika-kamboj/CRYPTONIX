#include <bits/stdc++.h>
using namespace std;
unordered_map<char, char> hashMap;
string monoalphabetic_encrypt(string msg)
{
    string ciphertext;
    for (int i = 0; i < msg.size(); i++)
    {
        ciphertext.push_back(hashMap[msg[i]]);
    }

    return ciphertext;
}

string monoalphabetic_decrypt(string msg)
{
    string plaintext;
    for (int i = 0; i < msg.size(); i++)
    {
        plaintext.push_back(hashMap[msg[i]]);
    }

    return plaintext;
}

void hashFn(string a, string b)
{
    hashMap.clear();
    for (int i = 0; i < a.size(); i++)
    {
        hashMap.insert(make_pair(a[i], b[i]));
    }
}

void monoalphabetic_cipher(string text)
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string substitution = "qwertyuiopasdfghjklzxcvbnm";

    hashFn(alphabet, substitution);

    string cipher = monoalphabetic_encrypt(text);
    cout << "Encrypted Cipher Text: " << cipher << endl;
    cout << endl;
    hashFn(substitution, alphabet);
    string plain = monoalphabetic_decrypt(cipher);
    cout << "Decrypted Plain Text: " << plain << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string encrypt_cipher(string text, int s)
{
    string result = "";
    int t = 65;
    // traverse text
    for (int i = 0; i < text.length(); i++)
    {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i] + s - t) % 26 + t);

        // Encrypt Lowercase letters
        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }

    // Return the resulting string
    return result;
}
string decrypt_cipher(string text, int s)
{
    string result = "";

    // traverse text
    for (int i = 0; i < text.length(); i++)
    {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);

        // Encrypt Lowercase letters
        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }

    // Return the resulting string
    return result;
}
// Driver program to test the above function
void caesar_cipher(string text)
{
    // cout<<"enter the string tou want to encrypt using caesar cipher"<<endl;
    // string text;
    int s;
    // getline(cin,text);
    cout << "enter the shift" << endl;
    cin >> s;
    string result = encrypt_cipher(text, s);
    cout << "encrypted string : " << endl;
    cout << endl;

    cout << "Text : " << text;
    cout << endl;

    cout << "\nShift: " << s;
    cout << endl;

    cout << "\nCipher: " << result << endl;
    cout << endl;

    cout << "decrypted string : " << endl;
    cout << endl;

    cout << "Text : " << result;
    cout << endl;

    // cout << "\nShift: " << s;
    //         cout<<endl;

    cout << "\nCipher: " << decrypt_cipher(result, -s);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Vig
{
public:
    string k;
    Vig(string k)
    {
        for (int i = 0; i < k.size(); ++i)
        {
            if (k[i] >= 'A' && k[i] <= 'Z')
                this->k += k[i];
            else if (k[i] >= 'a' && k[i] <= 'z')
                this->k += k[i] + 'A' - 'a';
        }
    }
    string encryption(string t)
    {
        string output;
        for (int i = 0, j = 0; i < t.length(); ++i)
        {
            char c = t[i];
            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;
            output += (c + k[j] - 2 * 'A') % 26 + 'A'; // added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
            j = (j + 1) % k.length();
        }
        return output;
    }
    string decryption(string t)
    {
        string output;
        for (int i = 0, j = 0; i < t.length(); ++i)
        {
            char c = t[i];

            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;
            output += (c - k[j] + 26) % 26 + 'A'; // added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
            j = (j + 1) % k.length();
        }
        return output;
    }
};
void vegenere_cipher(string text)
{
    string key;
    cout << "enter the key" << endl;
    cout << endl;
    cin >> key;
    getchar();
    Vig v(key);
    string encrypt = v.encryption(text);
    string decrypt = v.decryption(encrypt);
    cout << "Original Message: " << text << endl;
    cout << endl;

    cout << "Encrypted Message: " << encrypt << endl;
    cout << endl;

    cout << "Decrypted Message: " << decrypt << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void hill_encryption(string s, int n)
{
    int x, y, i, j, k;
    cout << "Enter the key matrix\n";
    int a[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int temp = (n - s.size() % n) % n;
    for (i = 0; i < temp; i++)
    {
        s += 'x';
    }
    k = 0;
    string ans = "";
    while (k < s.size())
    {
        for (i = 0; i < n; i++)
        {
            int sum = 0;
            int temp = k;
            for (j = 0; j < n; j++)
            {
                sum += (a[i][j] % 26 * (s[temp++] - 'a') % 26) % 26;
                sum = sum % 26;
            }
            ans += (sum + 'a');
        }
        k += n;
    }
    cout << endl;
    cout << ans << '\n';
}
void hill_cipher(string text)
{
    int s;
    cout << "enter the order of matrix for hill cipher" << endl;
    cin >> s;
    cout << endl;
    hill_encryption(text, s);
}

int main() // main/driver function
{
    cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl
         << "$$$$$$$$$$$$$$$$$$$$$ CIPHERS $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl
         << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
         << endl;
    int choice, flag = 1;
    cout << "enter the string you want to encrypt using our ciphers" << endl;
    string text;
    getline(cin, text);
    cout << "enter your encryption choice among : " << endl;
    cout << endl;
    cout << "1 : monoalphabetic" << endl;
    cout << endl;
    cout << "2 : caesar" << endl;
    cout << endl;
    cout << "3 : polyalphabetic/vignere" << endl;
    cout << endl;
    cout << "4 : hill" << endl;
    cout << endl;
    cin >> choice;
    // while (flag == 1)
    // {

    switch (choice)
    {
    case 1:
        monoalphabetic_cipher(text);
        break;
    case 2:
        caesar_cipher(text);

        break;
    case 3:
        vegenere_cipher(text);
        break;
    case 4:
        hill_cipher(text);
        break;
    default:
        break;
    }
    //     cout<<"Wanna try again with different cipher??"<<endl<<"enter 1 : to continue"<<endl<<"enter 0 : to exit"<<endl;
    //     cin>>flag;
    // }
    return 0;
}