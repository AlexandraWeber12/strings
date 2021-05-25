#include "./string.h"
#include <assert.h>

namespace swe2 {

  template <character C> string <C>::string(size_type count, value_type chr) {
    if (count)
    {
      m_size = count + 1; // + 1 to include end of string
      m_data = new value_type[m_size];
      std::fill(m_data, m_data + count, chr);
      m_data[count] = '\0';
    }
  }

  template <character C> string <C>::string(const_pointer input) {
    createFromConstPtr(input);
  }

  template <character C> string <C>::string(const_pointer input, size_type count) {
    assert(count < swe2::MAXINT32); // ensures count value is in range of int32_t
    // string{"hallo",2} -> "hal"
    // increase count by one to accommodate the usage of count within loop instead of offset
    createFromConstPtr(input, static_cast<int32_t>(++count));
  }

  template <character C> string <C>::string(string const& input, size_type pos) {
    createFromConstPtr(input.data(), -1, pos);
  }

  template <character C> string <C>::string(string const& input, size_type pos, size_type count) {
    size_type endIndex = count + pos;
    assert(endIndex <= swe2::MAXINT32);
    // new string should end count characters after pos
    createFromConstPtr(input.data(), static_cast<int32_t>(endIndex), pos);
  }

  template <character C> void string <C>::createFromConstPtr(const_pointer input, int32_t endIndex, size_type startIndex) {
    std::vector<C> chars{};

    // increase by 1 to consider \0 being a valid position for access
    indexInValidRange(startIndex, getSizeOfCArray(input));

    for (size_type characterIndex = startIndex; input[characterIndex] != '\0' && endIndex != characterIndex; ++characterIndex)
    {
      chars.push_back(input[characterIndex]);
    }
    chars.push_back('\0');

    assignVectorDataToMembers(chars);
  }


  template <character C> typename string <C>::size_type string <C>::getSizeOfCArray(const_pointer input) const {
    size_type sizeOfArray{};
    for (sizeOfArray = 0; input[sizeOfArray] != '\0'; ++sizeOfArray)
    {
      //do nothing
    }
    return ++sizeOfArray;
  }

  template <character C> void string <C>::assignVectorDataToMembers(std::vector<C>& input) {
    m_size = input.size();
    m_data = new value_type[m_size];
    std::copy(input.begin(), input.end(), m_data);
  }

  template <character C> string <C>::string(string const& input) {
    createFromConstPtr(input.data());
  }

  template <character C> string <C>::string(string&& input) noexcept {
    m_data = input.m_data;
    m_size = input.m_size;
    input.m_data = nullptr;
    input.m_size = 0;
  }

  template <character C> string <C>::~string() {
    clear();
  }

  template <character C> string <C>& string <C>::operator = (string const& input) {

    createFromConstPtr(input.data());

    // use this if not a deep copy should be created
    //m_data = input.m_data;
    //m_size = input.m_size;
    return *this;
  }

  template <character C> string <C>& string <C>::operator = (string&& input) noexcept {
    m_data = std::move(input.m_data);
    m_size = std::move(input.m_size);
    input.m_data = nullptr;
    input.m_size = 0;
    return *this;
  }

  template <character C> string <C>& string <C>::operator += (string const& input) {
    if (empty())
    {
      createFromConstPtr(input.data());
      return *this;
    }
    std::vector<C> chars{ m_data, m_data + m_size - 1 };
    chars.insert(chars.end(), input.m_data, input.m_data + input.m_size);
    assignVectorDataToMembers(chars);
    return *this;
  }

  template <character C> typename string <C>::reference string <C>::operator [] (size_type idx) {
    indexInValidRange(idx, m_size);
    return *(m_data + idx);
  }

  template <character C> typename string <C>::const_reference string <C>::operator [] (size_type idx) const {
    indexInValidRange(idx, m_size);
    return *(m_data + idx);
  }

  template <character C> typename string <C>::reference string <C>::at(size_type idx) {
    indexInValidRange(idx, m_size);
    return this->operator[](idx);
  }

  template <character C> typename string <C>::const_reference string <C>::at(size_type idx) const {
    indexInValidRange(idx, m_size);
    return this->operator[](idx);
  }

  template <character C> void string <C>::indexInValidRange(size_type idx, size_type size) const {
    if (idx > size)
    {
      throw std::out_of_range("Index out of range.");
    }
  }

  template <character C> typename string <C>::const_pointer string <C>::c_str() const {
    return data();
  }

  template <character C> typename string <C>::pointer string <C>::data() {
    pointer pointerToData{ m_data };
    return pointerToData;
  }

  template <character C> typename string <C>::const_pointer string <C>::data() const {
    const_pointer constPointerToData{ m_data };
    return constPointerToData;
  }

  template <character C> string <C>& string <C>::append(size_type count, value_type chr) {
    const string newString{ count, chr };
    this->operator+=(newString);
    return *this;
  }

  template <character C> string <C>& string <C>::append(const_pointer input) {
    const string newString{ input };
    this->operator+=(newString);
    return *this;
  }

  template <character C> string <C>& string <C>::append(const_pointer input, size_type count) {
    const string newString{ input, count };
    this->operator+=(newString);
    return *this;
  }

  template <character C> string <C>& string <C>::append(string const& input) {
    this->operator+=(input);
    return *this;
  }

  template <character C> string <C>& string <C>::append(string const& input, size_type pos) {
    const string newString{ input, pos };
    this->operator+=(newString);
    return *this;
  }

  template <character C> string <C>& string <C>::append(string const& input, size_type pos, size_type count) {
    const string newString{ input, pos, count };
    this->operator+=(newString);
    return *this;
  }

  template <character C> int string <C>::compare(string const& rhs) const {
    return compareObjects(*this, rhs);
  }

  template <character C> int string <C>::compareObjects(string const& lhs, string const& rhs) const {
    size_type lhsLength = lhs.size();
    size_type rhsLength = rhs.size();
    size_type shorterStringLength{ lhsLength < rhsLength ? lhsLength : rhsLength };
    for (size_type i = 0; i < shorterStringLength - 1; ++i) // -1 to not compare \0
    {
      C lhsChar = lhs[i];
      C rhsChar = rhs[i];
      if (lhsChar > rhsChar)
      {
        return 1;
      }

      if (lhsChar < rhsChar)
      {
        return -1;
      }
    }

    if (lhsLength > rhsLength)
    {
      return 1;
    }
    else if (lhsLength < rhsLength)
    {
      return -1;
    }
    return 0;
  }

  template <character C> int string <C>::compare(size_type pos, size_type count, string const& input) const {
    indexInValidRange(pos, m_size);
    string subString{ *this, pos, count };
    return compareObjects(subString, input);
  }

  template <character C> int string <C>::compare(size_type posl, size_type countl, string const& input, size_type posr, size_type countr) const {
    indexInValidRange(posl, m_size);
    indexInValidRange(posr, input.size());
    string subStringL{ *this, posl, countl };
    string subStringR{ input, posr, countr };
    return compareObjects(subStringL, subStringR);
  }

  template <character C> int string <C>::compare(const_pointer input) const {
    string rhs{ input };
    return compareObjects(*this, rhs);
  }

  template <character C> int string <C>::compare(size_type pos, size_type count, const_pointer input) const {
    indexInValidRange(pos, m_size);
    string rhs{ input + pos, count };
    return compareObjects(*this, rhs);
  }

  template <character C> int string <C>::compare(size_type posl, size_type countl, const_pointer input, size_type posr, size_type countr) const {
    indexInValidRange(posl, m_size);
    indexInValidRange(posr, getSizeOfCArray(input));
    string subStringL{ *this, posl, countl };
    string subStringR{ input, posr, countr };
    return compareObjects(subStringL, subStringR);
  }

  template <character C> void string <C>::clear() {
    delete[] m_data;

    m_data = nullptr;
    m_size = 0;
  }

  template <character C> bool string <C>::empty() const {
    return m_size == 0;
  }

  template <character C> typename string <C>::size_type string <C>::size() const {
    return m_size;
  }

  template <character C> void string <C>::swap(string& input) noexcept {
    std::swap(m_data, input.m_data);
    std::swap(m_size, input.m_size);
  }

  template <character T> string <T> operator + (string <T> const& lhs, string <T> const& rhs) {
    string newString{ lhs };
    newString.append(rhs);
    return newString;
  }

  template <character T> bool operator == (string <T> const& lhs, string <T> const& rhs) {
    return lhs.compare(rhs) == 0;
  }

  template <character T> std::strong_ordering operator <=> (string <T> const& lhs, string <T> const& rhs) {

    if (&lhs == &rhs)
    {
      return std::strong_ordering::equivalent;
    }

    switch (lhs.compare(rhs))
    {
    case -1:
      return std::strong_ordering::less;
    case 1:
      return std::strong_ordering::greater;
    default:
      return std::strong_ordering::equal;
    }
  }

  template <character T> std::ostream& operator << (std::ostream& lhs, string <T> const& rhs) {
    for (size_t idx = 0; idx < rhs.m_size; ++idx)
    {
      lhs << rhs[idx];
    }
    return lhs;
  }

  template <character T> void swap(string <T>& rhs, string <T>& lhs) noexcept {
    rhs.swap(lhs);
  }

}   // namespace swe2

namespace swe2::string_literals {

  inline string <char> operator "" _s(char const*, std::size_t) {
    return {};
  }

  inline string <wchar_t> operator "" _s(wchar_t const*, std::size_t) {
    return {};
  }
}   // namespace swe2::string_literals
