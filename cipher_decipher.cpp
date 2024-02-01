#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>

using namespace std;

int reverse(int n)
{
	if (n < 0)
		return 26 + n;
	else
		return n;
}

char inUpperCase(char c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
   
    return c;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string alphabet_inUpperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string pair_alphabet = "fghopqijklmnderabcstuxyzvw";
    string pair_alphabet_inUpperCase = "FGHOPQIJKLMNDERABCSTUXYZVW";

    int agree;
    cout << "Зашифровать или расшифровать?[1/2]\n";
    cin >> agree;

    if (agree == 1)
    {
        cout << "Введите текст для шифрования в файл Text.txt, если текст введен, то введите 1.\n";
        cin >> agree;

        if (agree == 1)
        {
            string line;

            cout << "Выберите шифр:\n1)Шифр Цезаря\n2)Шифр пар\n3)Шифр Виженера\n";
            cin >> agree;

            if (agree == 1)
            {
                int n;

                cout << "Введите длину сдвига для шифра Цезаря: ";
                cin >> n;
                cout << "\n";

                ifstream in;
                in.open("Text.txt");
                if (in.is_open())
                {
                    while (getline(in, line))
                    {
                        ofstream out;
                        out.open("Cipher.txt", ios::app);
                        if (out.is_open())
                        {
                            for (int i = 0; i < size(line); i++)
                            {
                                if (line[i] >= 'A' && line[i] <= 'Z')
                                    line[i] = alphabet_inUpperCase[(alphabet_inUpperCase.find(line[i]) + n) % size(alphabet_inUpperCase)];

                                if (line[i] >= 'a' && line[i] <= 'z')
                                    line[i] = alphabet[(alphabet.find(line[i]) + n) % size(alphabet)];
                            }
                            out << line << "\n";
                        }
                    }
                }
                in.close();
            }

            if (agree == 2)
            {
                ifstream in;
                in.open("Text.txt");
                if (in.is_open())
                {
                    while (getline(in, line))
                    {
                        ofstream out;
                        out.open("Cipher.txt", ios::app);
                        if (out.is_open())
                        {
                            for (int i = 0; i < size(line); i++)
                            {
                                if (line[i] >= 'A' && line[i] <= 'Z')
                                    line[i] = pair_alphabet_inUpperCase[(pair_alphabet_inUpperCase.find(line[i]) + 14) % size(pair_alphabet_inUpperCase)];

                                if (line[i] >= 'a' && line[i] <= 'z')
                                    line[i] = pair_alphabet[(pair_alphabet.find(line[i]) + 14) % size(pair_alphabet)];
                            }
                            out << line << "\n";
                        }
                    }
                }
                in.close();
            }

            if (agree == 3)
            {
                string key;
                cout << "Введите ключ: ";
                cin >> key;

                ifstream in;
                in.open("Text.txt");
                if (in.is_open())
                {
                    while (getline(in, line))
                    {
                        ofstream out;
                        out.open("Cipher.txt", ios::app);
                        if (out.is_open())
                        {
                            for (int i = 0, j = 0; i < size(line); i++)
                            {
                                if (j == size(key)) j = 0;
                                if (line[i] >= 'A' && line[i] <= 'Z')
                                {
                                    line[i] = alphabet_inUpperCase[(alphabet_inUpperCase.find(line[i]) + alphabet_inUpperCase.find(inUpperCase(key[j]))) % size(alphabet_inUpperCase)];
                                    j++;
                                }
                                
                                if (line[i] >= 'a' && line[i] <= 'z')
                                {
                                    line[i] = alphabet[(alphabet.find(line[i]) + alphabet.find(key[j])) % size(alphabet)];
                                    j++;
                                }
                            }
                            out << line << "\n";
                        }
                    }
                }
                in.close();
            }
                cout << "Зашифрованный текст в файле Cipher.txt.";
        }
            return 0;
    }

    if (agree == 2)
    {
        cout << "Введите текст для расшифрования в файл Cipher.txt, если текст введен, то введите 1.\n";
        cin >> agree;

        if (agree == 1)
        {
            string line;

            cout << "Выберите шифр:\n1)Шифр Цезаря\n2)Шифр пар\n3)Шифр Виженера\n";
            cin >> agree;

            if (agree == 1)
            {
                int n;
                int caesar_pos;

                cout << "Введите длину сдвига для шифра Цезаря: ";
                cin >> n;
                cout << "\n";

                ifstream in;
                in.open("Cipher.txt");
                if (in.is_open())
                {
                    while (getline(in, line))
                    {
                        ofstream out;
                        out.open("Text.txt", ios::app);
                        if (out.is_open())
                        {
                            for (int i = 0; i < size(line); i++)
                            {
                                if (line[i] >= 'A' && line[i] <= 'Z')
                                    line[i] = alphabet_inUpperCase[reverse(alphabet_inUpperCase.find(line[i]) - n) % size(alphabet_inUpperCase)];

                                if (line[i] >= 'a' && line[i] <= 'z')
                                    line[i] = alphabet[reverse(alphabet.find(line[i]) - n) % size(alphabet)];
                            }
                            out << line << "\n";
                        }
                    }
                    cout << "Расшифрованный текст в файле Text.txt.";
                }
            }

            if (agree == 2)
            {
                int pair_pos;

                ifstream in;
                in.open("Cipher.txt");
                if (in.is_open())
                {
                    while (getline(in, line))
                    {
                        ofstream out;
                        out.open("Text.txt", ios::app);
                        if (out.is_open())
                        {
                            for (int i = 0; i < size(line); i++)
                            {
                                if (line[i] >= 'A' && line[i] <= 'Z')
                                    line[i] = pair_alphabet_inUpperCase[reverse(pair_alphabet_inUpperCase.find(line[i]) - 14) % size(pair_alphabet_inUpperCase)];

                                if (line[i] >= 'a' && line[i] <= 'z')
                                    line[i] = pair_alphabet[reverse(pair_alphabet.find(line[i]) - 14) % size(pair_alphabet)];
                            }
                            out << line << "\n";
                        }
                    }
                    cout << "Расшифрованный текст в файле Text.txt.";
                }
            }

            if (agree == 3)
            {
                string key;
                cout << "Введите ключ: ";
                cin >> key;

                ifstream in;
                in.open("Cipher.txt");
                if (in.is_open())
                {
                    while (getline(in, line))
                    {
                        ofstream out;
                        out.open("Text.txt", ios::app);
                        if (out.is_open())
                        {
                            for (int i = 0, j = 0; i < size(line); i++)
                            {
                                if (j == size(key)) j = 0;
                                if (line[i] >= 'A' && line[i] <= 'Z')
                                {
                                    line[i] = alphabet_inUpperCase[reverse(alphabet_inUpperCase.find(line[i]) - alphabet_inUpperCase.find(inUpperCase(key[j]))) % size(alphabet_inUpperCase)];
                                    j++;
                                }

                                if (line[i] >= 'a' && line[i] <= 'z')
                                {
                                    line[i] = alphabet[reverse(alphabet.find(line[i]) - alphabet.find(key[j])) % size(alphabet)];
                                    j++;
                                }
                            }
                            out << line << "\n";
                        }
                    }
                    cout << "Расшифрованный текст в файле Text.txt.";
                }
            }
        }
    }
}