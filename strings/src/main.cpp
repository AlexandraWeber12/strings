#include "./string.h"
#include "vld.h"

using namespace swe2::string_literals;

int main() {
  swe2::string ctorWithLengthAndCharacter1{ std::size_t{ 0 }, 'A' };
  swe2::string ctorWithLengthAndCharacter2{ 10, 'A' };



  /*swe2::string s1;
   swe2::string s2;
   auto         s3 { "abc"_s};
   auto         s4 {L"abc"_s};

   auto const c1 {s1 <=> s2};
   auto const c2 {s1 <   s2};*/
   // auto const c3 {s1 !=  s2};
}
