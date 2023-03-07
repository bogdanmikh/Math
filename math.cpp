#include "math.hpp"
#include <string>
#include <assert.h>

std::string Math::sum(std::string &a, std::string &b) {
    assert(a.size() > 0 && b.size() > 0, "Incorrect data");
    if (b.size() > a.size()) {
        std::string x = a;
        a = b;
        b = x;
    }
    uint64_t remainder = 0;
    std::string ans;
    int index_a = a.size() - 1;
    int index_b = b.size() - 1;
    for (; index_a >= 0 || remainder != 0; index_a--, index_b--) {
        if (index_a < 0 && remainder != 0) {
            ans.push_back(trans_to_char(remainder % 10));
            remainder /= 10;
            continue;
        }
        if (index_b >= 0) {
            int sum = trans_to_digit(a[index_a]) + trans_to_digit(b[index_b]) + remainder;
            remainder = 0;
            if (sum > 9) {
                ans.push_back(trans_to_char(sum % 10));
                sum /= 10;
                remainder += sum;
            } else {
                ans.push_back(trans_to_char(sum));
            }
       } else {
            if (remainder <= 0) {
                ans.push_back(a[index_a]);
            } else {
                int sum = trans_to_digit(a[index_a]) + remainder;
                remainder = 0;
                ans.push_back(trans_to_char(sum % 10));
                sum /= 10;
                remainder += sum;
            }
       } 
    }
    std::string result;
    for (int i = ans.size() - 1; i >= 0; i--) result.push_back(ans[i]);
    return result;
}
// std::string Math::difference(const std::string &a, const std::string &b);
// std::string Math::multiplication(const std::string &a, const std::string &b);

inline uint64_t Math::trans_to_digit(const char &a) {
    return a - '0';
}
inline char Math::trans_to_char(const int &a) {
    return a + '0';
}