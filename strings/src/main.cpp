#include "./string.h"
#include "vld.h"

using namespace swe2::string_literals;

int main() {
  //swe2::string ctorWithLengthAndCharacter1{ 0ull , 'A' };
  //swe2::string ctorWithLengthAndCharacter2{ 10, 'A' };

  //swe2::string ctorWithLengthAndCharacter2{"Test"};
  //swe2::string ctorWithLengthAndCharacter2{ "Test", 2 };
  //swe2::string ctorWithLengthAndCharacter2{ "Test", 0 };

  /*const swe2::string ctorWithLengthAndCharacter1{ "Test" };
  char const* test{ ctorWithLengthAndCharacter1.data() };*/
  /* swe2::string ctorWithLengthAndCharacter1{ "Test" };
   char* test{ ctorWithLengthAndCharacter1.data() };*/
   /*swe2::string ctorWithLengthAndCharacter1{ "Test" };
   swe2::string ctorWithLengthAndCharacter2{ ctorWithLengthAndCharacter1, 2 };*/
   /*swe2::string ctorWithLengthAndCharacter1{ "TestOneMore" };
   swe2::string ctorWithLengthAndCharacter2{ ctorWithLengthAndCharacter1, 2 , 5};*/
   /*swe2::string ctorWithLengthAndCharacter1{ "Test" };
 swe2::string ctorWithLengthAndCharacter2{ ctorWithLengthAndCharacter1 };*/
 /*swe2::string ctorWithLengthAndCharacter1{ "Test" };
 swe2::string ctorWithLengthAndCharacter2{ std::move(ctorWithLengthAndCharacter1) };*/
 /*swe2::string ctorWithLengthAndCharacter1{ "Test" };
 swe2::string ctorWithLengthAndCharacter2{};
 ctorWithLengthAndCharacter2 = ctorWithLengthAndCharacter1;*/
 /*swe2::string ctorWithLengthAndCharacter1{ "Test" };
 swe2::string ctorWithLengthAndCharacter2{};
 ctorWithLengthAndCharacter2 = std::move(ctorWithLengthAndCharacter1);*/
 /*swe2::string ctorWithLengthAndCharacter1{ "Te" };
 swe2::string ctorWithLengthAndCharacter2{ "st" };
 ctorWithLengthAndCharacter1 += ctorWithLengthAndCharacter2;*/
 /*swe2::string ctorWithLengthAndCharacter1{ "Test" };
 char& characterRef = ctorWithLengthAndCharacter1[2];
 characterRef = 'A';*/
 //const swe2::string ctorWithLengthAndCharacter1{ "Test" };
 //const char& characterRef = ctorWithLengthAndCharacter1[2];
 /*swe2::string ctorWithLengthAndCharacter1{ "Test" };
 char& test = ctorWithLengthAndCharacter1.at(2);*/
 /*const swe2::string ctorWithLengthAndCharacter1{ "Test" };
 try
 {
   const char& test = ctorWithLengthAndCharacter1.at(10);
 }
 catch (const std::out_of_range& ex)
 {
   std::cout << ex.what() << "\n";
 }
 */
 /*swe2::string ctorWithLengthAndCharacter1{ "Test" };
  ctorWithLengthAndCharacter1.append(3, 'A');*/
  /*swe2::string ctorWithLengthAndCharacter1{ "Test" };
ctorWithLengthAndCharacter1.append("Test", 2);*/
/*swe2::string ctorWithLengthAndCharacter1{ "Test" };
swe2::string ctorWithLengthAndCharacter2{ "Test" };
ctorWithLengthAndCharacter1.append(ctorWithLengthAndCharacter2);*/
/*swe2::string ctorWithLengthAndCharacter1{ "Test" };
swe2::string ctorWithLengthAndCharacter2{ "AnotherTestString" };
ctorWithLengthAndCharacter1.append(ctorWithLengthAndCharacter2, 1, 2);*/
/*swe2::string AA{ "green apple1" };
swe2::string AB{ "apple" };
std::cout << AA.compare(6, 5, AB) << "\n";
std::string A{ "green apple1" };
std::string B{ "apple" };
std::cout << A.compare(6, 5, B) << "\n";*/
//swe2::string AA{ "green apple" };
//swe2::string AB{ "red apple1" };
//std::cout << AA.compare(6, 5, AB, 4, 5) << "\n";
//std::string A{ "green apple" };
//std::string B{ "red apple1" };
//std::cout << A.compare(6, 5, B, 4, 5) << "\n";
//swe2::string AA{ "green apple" };
//std::cout << AA.compare(0, 5, "apple green", 6, 5) << "\n";
//std::string A{ "green apple" };
//std::cout << A.compare(0, 5, "apple green", 6, 5) << "\n";
/*swe2::string A{ "green apple" };
swe2::string B{ "lol" };
A.swap(B);*/
/*swe2::string A{ "green apple" };
swe2::string B{ "lol" };
swe2::swap(A, B);*/
  //swe2::string A{ "green apple" };
  //swe2::string B{ "lol" };
  //swe2::string C = A + B;
 /* swe2::string A{ "green apple" };
  swe2::string B{ "green apple" };
  std::strong_ordering res = A <=> B;*/
  /*swe2::string A{ "green apple" };
  std::cout << A << '\n';*/


  /*std::string B{ "green apple" };
  std::strong_ordering res1 = B <=> B;*/

  /*swe2::string s1;
   swe2::string s2;
   auto         s3 { "abc"_s};
   auto         s4 {L"abc"_s};

   auto const c1 {s1 <=> s2};
   auto const c2 {s1 <   s2};*/
   // auto const c3 {s1 !=  s2};
}
