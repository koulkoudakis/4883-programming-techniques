// 10931 - Parity

#include <bitset>
#include <iostream>
#include <algorithm>

#define endl '\n'
using namespace std;

int main() {
  int n;

  while (cin >> n) {
    // Break the loop if n is 0
    if (!n) break;

    // Convert integer n to binary string
    std::string binary = std::bitset<128>(n).to_string();

    // Remove leading zeros from the binary string
    binary = binary.erase(0, binary.find_first_not_of('0'));

    // Output the original binary representation
    cout << "The parity of " << binary << " is ";

    // Count the number of '1's in the binary string
    int parity = std::count(binary.begin(), binary.end(), '1');

    // Output the count and the result of parity % 2
    cout << parity << " (mod 2)." << endl;
  }

  return 0;
}