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
    "what\tever",
    "whatever next",
  };

  auto pfn = [](auto & tst, auto & lc) {
    std::cout << std::setw(20)
              << tst
              << ": "
              << std::boolalpha
              << lc
              << std::endl;
  };

  //  for_each()
  std::cout << "std::for_each()" << std::endl;
  for (std::string tst : tests) {
    bool lc = true;

    std::for_each(tst.begin(), tst.end(),
      [&lc](char const c_) {
        bool l_ = std::islower(c_);
        lc = lc ? l_ : lc;
//        std::cout << std::boolalpha << lc << ' ' << l_ << std::endl;
      });

    pfn(tst, lc);
  }
  std::putchar('\n');
  //  find_if()
  std::cout << "std::find_if()" << std::endl;
  for (std::string tst : tests) {
    auto fi = std::find_if(tst.begin(), tst.end(),
      [](char const c_) {
        return !std::islower(c_);
      });
    bool lc = (fi != tst.end()) ? false : true;

    pfn(tst, lc);
  }
  std::putchar('\n');

  //  find_if_not()
  std::cout << "std::find_if_not()" << std::endl;
  for (std::string tst : tests) {
    auto fi = std::find_if_not(tst.begin(), tst.end(),
      [](char const c_) {
        return std::islower(c_);
      });
    bool lc = (fi != tst.end()) ? false : true;

    pfn(tst, lc);
  }
  std::putchar('\n');

  //  all_of()
  std::cout << "std::all_of()" << std::endl;
  for (std::string tst : tests) {
    auto lc = std::all_of(tst.begin(), tst.end(),
      [](char const c_) {
        return std::islower(c_);
      });

    pfn(tst, lc);
  }
  std::putchar('\n');

  //  loop over
  std::cout << "loopy" << std::endl;
  for (std::string tst : tests) {
    bool lc = true;
    for (auto ch : tst) {
      if(!(lc = std::islower(ch))) { break; }
    }

    pfn(tst, lc);
  }
  std::putchar('\n');

  //  classic loop
  std::cout << "classic loop" << std::endl;
  for (std::string tst : tests) {
    bool lc = true;
    for (size_t c_ = 0; c_ < tst.length(); ++c_) {
      lc = std::islower(tst[c_]);
      if (!lc) { break; }
    }

    pfn(tst, lc);
  }
  std::putchar('\n');

  //  do it all with lambdas
  std::cout << "do it all with lambdas" << std::endl;
  std::for_each(tests.begin(), tests.end(), 
    [&pfn](auto tst) {
      auto fi = std::find_if(tst.begin(), tst.end(),
        [](auto c_) {
          return !std::islower(c_);
        });
      auto lc = (fi != tst.end()) ? false : true;

      pfn(tst, lc);
    });
  std::putchar('\n');

  return 0;
}
