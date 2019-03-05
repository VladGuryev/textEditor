#include "test_runner.h"
#include "profile.h"
#include "tests.cpp"
#include <experimental/string_view>
using namespace std;
using namespace std::experimental;

int main()
{
  TestRunner tr;
  LOG_DURATION("Total tests duration");
//  RUN_TEST(tr, TestEditing);
//  RUN_TEST(tr, TestReverse);
//  RUN_TEST(tr, TestNoText);
//  RUN_TEST(tr, TestEmptyBuffer);

  string* t = new string("AAAAAAAAAaaaa");
  string_view sv(*t);
  delete t;
  for (int i = 0; i < 10000; i++) {
    string* p = new string("123456789");
    p->at(1);
  }
  cout << sv << endl;

  return 0;
}
