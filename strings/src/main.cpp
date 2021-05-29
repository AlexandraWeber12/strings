#include "./string.h"
#include "./TestCases.h"
#include "vld.h"

using namespace swe2::string_literals;

int main() {
  swe2::testConstructor();
  swe2::testOperator();
  swe2::testAppend();
}
