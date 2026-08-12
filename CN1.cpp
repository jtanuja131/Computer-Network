//sender side
#include <iostream>
#include <string>
using namespace std;

int main() {
    string data;
    string result = "";
    int count = 0;

    cout << "Enter binary data: ";
    cin >> data;

    for (char bit : data) {
        result += bit;

        if (bit == '1') {
            count++;

            if (count == 5) {
                result += '0';
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    cout << "Output: " << result << endl;

    return 0;
}
//input:011011111111111111110111100
//output:011011111011111011111010111100
