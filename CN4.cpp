//Receiver side code
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string code;
    cout << "========== RECEIVER SIDE ==========" << endl;
    cout << "Enter received Hamming code: ";
    cin >> code;
    for (char c : code)
    {
        if (c != '0' && c != '1')
        {
            cout << "Invalid input! Enter only 0 and 1." << endl;
            return 0;
        }
    }
    int n = code.length();
    int h[100] = {0};
    int j = 0;
    for (int i = n; i >= 1; i--)
    {
        h[i] = code[j] - '0';
        j++;
    }
    int r = 0;
    while ((1 << r) <= n)
    {
        r++;
    }
    cout << "\nReceived Hamming Code = " << code << endl;
    int errorPosition = 0;
    cout << "\nReceiver Parity Values:" << endl;
    for (int p = 1; p <= n; p = p * 2)
    {
        int parity = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((i & p) != 0)
            {
                parity = parity ^ h[i];
            }
        }
        cout << "R" << p << " = " << parity << endl;
        errorPosition = errorPosition + parity * p;
    }
    cout << "\nError Position = " << errorPosition << endl;
    if (errorPosition == 0)
    {
        cout << "No Error Detected!" << endl;
    }
    else
    {
        if (errorPosition > n)
        {
            cout << "Invalid Error Position!" << endl;
            return 0;
        }
        cout << "Error Detected at Position "
             << errorPosition << endl;
        h[errorPosition] = h[errorPosition] ^ 1;
    cout << "Error Corrected!" << endl;
    }
    cout << "\nCorrected Hamming Code = ";
    for (int i = n; i >= 1; i--)
    {
        cout << h[i];
    }
    cout << endl;
    cout << "\nOriginal Data Bits = ";
    for (int i = n; i >= 1; i--)
    {
        if ((i & (i - 1)) != 0)
        {
            cout << h[i];
        }
    }
    cout << endl;
    return 0;
}
//Output
========== RECEIVER SIDE ==========
Enter received Hamming code: 1001111100

Received Hamming Code = 1001111100

Receiver Parity Values:
R1 = 1
R2 = 0
R4 = 0
R8 = 1

Error Position = 9
Error Detected at Position 9
Error Corrected!

Corrected Hamming Code = 1101111100

Original Data Bits = 111111


=== Code Execution Successful ===
