//receiver side
#include <iostream>
#include <string>
using namespace std;

int main() {
    string data, result = "";
    int count = 0;

    cout << "Enter received data: ";
    cin >> data;

    for (int i = 0; i < data.length(); i++) {
        result += data[i];

        if (data[i] == '1') {
            count++;

            if (count == 5) {
                // Skip the stuffed 0
                if (i + 1 < data.length() && data[i + 1] == '0') {
                    i++;
                }
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    cout << "Original data: " << result << endl;

    return 0;
}
//input:011011111011111011111010111100
//output:011011111111111111110111100
