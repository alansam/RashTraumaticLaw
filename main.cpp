#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cctype>

int main(int argc, char const * argv[]) {
  std::cout << "RashTraumaticLaw" << std::endl;

  std::vector<std::string> tests {
    "abCDe",
    "abcDEfG",
    "abcdef",
    "12345",
    "abc1def",
    "Whatever",
    "whatever!",
    "whatever",
  };

  for (std::string tst : tests) {
    bool lc = true;

    std::for_each(tst.begin(), tst.end(), [&lc](char const c_) {
        bool l_ = std::islower(c_);
        lc = lc ? l_ : lc;
//        std::cout << std::boolalpha << lc << ' ' << l_ << std::endl;
      });

    std::cout << std::setw(20)
              << tst
              << ": "
              << std::boolalpha
              << lc
              << std::endl;
  }
  std::putchar('\n');

  for (std::string tst : tests) {
    auto fi = std::find_if(tst.begin(), tst.end(), [](char c_) {
      return !std::islower(c_);
    });
    bool lc = (fi != tst.end()) ? false : true;

    std::cout << std::setw(20)
              << tst
              << ": "
              << std::boolalpha
              << lc
              << std::endl;
  }
  std::putchar('\n');

  return 0;
}