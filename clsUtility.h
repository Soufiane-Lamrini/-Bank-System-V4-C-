#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtility
{

public:
    enum enRandomCharType {
        Lower = 1, Upper = 2, Digit = 3, MixChars = 4, Special
    };

    static void SRand()
    {
        srand((unsigned)time(NULL));
    }

    static int randomNumber(int from, int to)
    {
        int randNum = rand() % (to - from + 1) + from;
        return randNum;
    }

    static char getRandomChar(enRandomCharType charType)
    {
        if (charType == MixChars)
        {
            //Capital/Samll/Digits only
            charType = (enRandomCharType)randomNumber(1, 3);

        }

        switch (charType)
        {
        case enRandomCharType::Lower:
        {
            return char(randomNumber(97, 122));  // a-z
            break;
        }
        case enRandomCharType::Upper:
        {
            return char(randomNumber(65, 90));   // A-Z
            break;
        }

        case enRandomCharType::Special:
        {
            return char(randomNumber(33, 47));   // ! to /
            break;
        }
        case enRandomCharType::Digit:
        {
            return char(randomNumber(48, 57));   // 0-9
            break;
        }
        default:
        {
            return char(randomNumber(65, 90));
            break;
        }

        return '\0';
        }
    }


    static string generateWord(enRandomCharType charType, int length)
    {
        string word;

        for (int i = 1; i <= length; i++)
        {
            word += getRandomChar(charType);
        }
        return word;
    }

    static string generateKey(enRandomCharType CharType)
    {
        string key = "";

        key = generateWord(CharType, 4) + "-";
        key += generateWord(CharType, 4) + "-";
        key += generateWord(CharType, 4) + "-";
        key += generateWord(CharType, 4);

        return key;
    }
    static void GenerateKeys(short NumberOfKeys, enRandomCharType CharType)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "] : " << generateKey(CharType) << endl;
        }
    }

    static void Swap(int& A, int& B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(bool& A, bool& B)
    {
        bool Temp;
        Temp = A;
        A = B;
        B = Temp;
    }
    static void Swap(double& A, double& B)
    {
        double Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(char& A, char& B)
    {
        char Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(string& A, string& B)
    {
        string Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate& Date1, clsDate& Date2)
    {
        clsDate Temp;
        Temp = Date1;
        Date1 = Date2;
        Date2 = Temp;
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1,
                arrLength) - 1]);
        }
    }

    static void ShuffleArray(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1,
                arrLength) - 1]);
        }
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int from, int to)
    {

        for (int i = 0; i < arrLength; i++)
            arr[i] = randomNumber(from, to);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enRandomCharType charType, int length)
    {

        for (int i = 0; i < arrLength; i++)
            arr[i] = generateWord(charType, length);
    }

    static void FillArrayWithKeys(string arr[100], int arrLength, enRandomCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = generateKey(CharType);
        }
    }

    static string Tabs(int numTab)
    {
        string tabs = "";
        for (int i = 0; i < numTab; i++)
        {
            tabs += "\t";
            cout << tabs;
        }
        return tabs;
    }

    static  string EncryptText(string Text, short EncryptionKey = 2)
    {

        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);

        }
        return Text;
    };

    static string DecryptionText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;
    };

    static string NumberToText(int Number)
    {
        if (Number == 0)
        {
            return "";
        }
        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
       "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
         "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return arr[Number] + " ";
        }
        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }
        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    };

    
};
