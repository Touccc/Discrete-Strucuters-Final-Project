#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int generateKey(char c);
char encrypt(char c, int rshift);
char decrypt(char c, int rshift);
string encryptText(string str, string key);
string decryptText(string str, string key);


int main()                                                    //create menu and take inputs from the user
{
    int choice;

    cout << "Choose an option\n" <<
        "---------------------------------\n" <<
        " 1. Encrypt\n" <<
        " 2. Decrypt\n" <<
        " 3. Cancel\n" <<
        "---------------------------------\n";
    cin >> choice;
    cin.ignore();


    switch (choice)
    {
    case 1: {
        string str, key, result;
        cout << "Enter text to encrypt: ";
        getline(cin, str);

        cout << "Enter a key: ";
        getline(cin, key);

        result = encryptText(str, key);
        cout << " Your message is: " << result;
        return 0;
        break;
    }

    case 2: {
        string str, key, result;
        cout << " Enter text to decrypt: ";
        getline(cin, str);

        cout << " Enter a key: ";
        getline(cin, key);

        result = decryptText(str, key);
        cout << " Your message is: " << result;
        return 0;
        break;
    }

    case 3: {
        cout << " Returning to menu.";
        return 0;
    }





    }
}

int generateKey(char c)                                               //shifted value
{

    if (isupper(c)) {
        return (int)c - (int)'A';
    }

    else {
        return (int)c - (int)'a';
    }

}

//Encryption
char encrypt(char c, int rshift)
{
    char shifted;

    if (isalpha(c))                                                      //check if it is a letter
    {

        if (isupper(c))
        {
            shifted = ((int)c + rshift - 'A') % 26 + 'A';                       //int is str[i] and rshifted is from generate key
        }
        else
        {
            shifted = ((int)c + rshift - 'a') % 26 + 'a';
        }
        return shifted;
    }
    else
    {
        return c;
    }
}

string encryptText(string str, string key)                            //assembles encrypted message
{

    char encrypted;
    string vigenere;
    int ciphercount = 0;

    for (int i = 0; i < str.length(); ++i)
    {

        if (isalpha(str[i]))
        {
            encrypted = encrypt(str[i], generateKey(key[ciphercount]));        //calls function to calculate
            vigenere += encrypted;                                             //adds to the string
            ciphercount++;
        }
        else
        {
            vigenere += str[i];                                              //adds to the string
        }
        ciphercount = ciphercount % key.length();                          //loop the key until it goes through the entire
                                                                           // plain text
    }
    return vigenere;
}

//Decryption
char decrypt(char c, int rshift)
{
    char shifted;

    if (isalpha(c))                                                      //check if it is a letter
    {

        if (isupper(c))
        {
            shifted = ((int)c - rshift + 26 - 'A') % 26 + 'A';                //came from decryption equation
        }
        else
        {
            shifted = ((int)c - rshift + 26 - 'a') % 26 + 'a';
        }
        return shifted;
    }
    else
    {
        return c;
    }
}

string decryptText(string str, string key)                              //assembles decrypted message
{

    char decrypted;
    string vigenere;
    int ciphercount = 0;

    for (int i = 0; i < str.length(); ++i)
    {

        if (isalpha(str[i]))
        {
            decrypted = decrypt(str[i], generateKey(key[ciphercount]));
            vigenere += decrypted;
            ciphercount++;
        }
        else
        {
            vigenere += str[i];
        }
        ciphercount = ciphercount % key.length();
    }
    return vigenere;
}