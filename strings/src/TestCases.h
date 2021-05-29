#pragma once

#include "./string.h"
#include <iostream>

namespace swe2 {
  void printResultStrings(swe2::string<char>& swe2String, std::string& stdString) {
    std::cout << "std::string: " << stdString << "\n";
    std::cout << "swe2::string: " << swe2String << "\n";
    std::cout << "std::string.size: " << stdString.size() << "\n";
    std::cout << "swe2::string.size: " << swe2String.size() << "\n\n";
  }

  void ctorTestCase1() {
    std::cout << "Ctor with char const*:" << "\n";
    const std::string stdString{ "Test" };
    const string swe2String{ "Test" };
    std::cout << "std::string: " << stdString.data() << "\n";
    std::cout << "swe2::string: " << swe2String.data() << "\n";
    std::cout << "std::string.size: " << stdString.size()<< "\n";
    std::cout << "swe2::string.size: " << swe2String.size() << "\n\n";
  }

  void ctorTestCase2() {
    std::cout << "Ctor with object pos and length:" << "\n";
    swe2::string swe2String{ "TestOneMore" };
    swe2::string swe2String1{ swe2String, 2, 5 };
    std::string stdString{ "TestOneMore" };
    std::string stdString1{ stdString, 2, 5 };
    printResultStrings(swe2String1, stdString1);
  }

  void ctorTestCase3() {
    std::cout << "Ctor with empty string:" << "\n";
    swe2::string swe2String{ "" };
    std::string stdString{ "" };
    printResultStrings(swe2String, stdString);
  }

  void testConstructor() {
    // swe2::string ctorWithLengthAndCharacter1{ 0ull, 'A' };
    std::cout << "Constructor tests start:" << "\n";
    ctorTestCase1();
    ctorTestCase2();
    ctorTestCase3();
    std::cout << "Constructor tests end" << "\n\n";
  }

  void operatorTestCase1() {
    std::cout << "+= operator:" << "\n";
    swe2::string swe2StringA{ "Te" };
    swe2::string swe2StringB{ "st" };
    std::string stdStringA{ "Te" };
    std::string stdStringB{ "st" };
    printResultStrings(swe2StringA += swe2StringB, stdStringA += stdStringB);
  }

  void operatorTestCase2() {
    std::cout << "at/[] operator:" << "\n";
    swe2::string swe2String{ "Test" };
    std::string stdString{ "Test" };
    std::cout << "std::string: " << stdString.at(2) << "\n";
    std::cout << "swe2::string: " << swe2String.at(2) << "\n";
  }

  void testOperator() {
    std::cout << "Operator tests start:" << "\n";
    operatorTestCase1(); 
    operatorTestCase2();
    std::cout << "Operator tests end" << "\n\n";
  }

  void appendTestCase1() {
    swe2::string swe2StringA{ "Te" };
    swe2::string swe2StringB{ "st" };
    swe2::string swe2StringC{ "Test" };
    swe2StringA.append(swe2StringB, 0, 1);
    std::cout << (swe2StringC.compare(0, 3, swe2StringA) == 0 ? "Strings are equal" : "Strings are not equal") << "\n";
  }

  void testAppend() {
    std::cout << "Append tests start:" << "\n";
    appendTestCase1();
    std::cout << "Append tests end" << "\n\n";
  }
}