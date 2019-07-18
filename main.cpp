#include <iostream>
#include <string>

using namespace std;

string add(string& n1, string& n2) {
  int len1 = n1.size();
  int len2 = n2.size();
  int len_min = len1 < len2 ? len1 : len2;
  int len_max = len1 > len2 ? len1 : len2;
  int i = len1 - 1;
  int j = len2 - 1;
  string out = string(len_max, '0');
  unsigned char carry = '0';
  for (int k = out.size() - 1; k >= 0; --k) {
    if (i >= 0 && i < len1)
      carry += n1[i] - '0';
    if ( j >= 0 && j < len2)
      carry += n2[j] - '0';

    if (carry > 'z') {
      out[k] = carry - ('z' + 1) + '0';
      carry = '1';
    } else {
      out[k] = carry;
      carry = '0';
    }
    i--;
    j--;
  }

  if (carry != '0') {
    return string("") + (char)carry + out;
  } else
    return out;
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  string n1 = "1z", n2 = "1z";

  string ans = add(n1, n2);
  cout<<ans<<endl;
  return 0;
}