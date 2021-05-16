#include "./string.h"
#include <vector>


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
    std::vector<char> chars{};
    for (int characterIndex = 0; input[characterIndex] != '\0'; characterIndex++)
    {
      chars.push_back(input[characterIndex]);
    }
    chars.push_back('\0');

    m_size = chars.size();
    m_data = new value_type[m_size];

    for (int characterIndex = 0; characterIndex < m_size; characterIndex++)
    {
      m_data[characterIndex] = chars[characterIndex];
    }
  }

  template <character C> string <C>::string(const_pointer, size_type count) {
  }

  template <character C> string <C>::string(string const&, size_type pos) {
  }

  template <character C> string <C>::string(string const&, size_type pos, size_type count) {
  }

  template <character C> string <C>::string(string const&) {
  }

  template <character C> string <C>::string(string&&) noexcept {
  }

  template <character C> string <C>::~string() {
    clear();
  }

  template <character C> string <C>& string <C>::operator = (string const&) {
    return *this;
  }

  template <character C> string <C>& string <C>::operator = (string&&) noexcept {
    return *this;
  }

  template <character C> string <C>& string <C>::operator += (string const&) {
    return *this;
  }

  template <character C> typename string <C>::reference string <C>::operator [] (size_type idx) {
    static C t{}; return t;
  }

  template <character C> typename string <C>::const_reference string <C>::operator [] (size_type idx) const {
    static C t{}; return t;
  }

  template <character C> typename string <C>::reference string <C>::at(size_type idx) {
    static C t{}; return t;
  }

  template <character C> typename string <C>::const_reference string <C>::at(size_type idx) const {
    static C t{}; return t;
  }

  template <character C> typename string <C>::const_pointer string <C>::c_str() const {
    return nullptr;
  }

  template <character C> typename string <C>::pointer string <C>::data() {
    return nullptr;
  }

  template <character C> typename string <C>::const_pointer string <C>::data() const {
    return nullptr;
  }

  template <character C> string <C>& string <C>::append(size_type count, value_type chr) {
    return *this;
  }

  template <character C> string <C>& string <C>::append(const_pointer) {
    return *this;
  }

  template <character C> string <C>& string <C>::append(const_pointer, value_type count) {
    return *this;
  }

  template <character C> string <C>& string <C>::append(string const&) {
    return *this;
  }

  template <character C> string <C>& string <C>::append(string const&, size_type pos) {
    return *this;
  }

  template <character C> string <C>& string <C>::append(string const&, size_type pos, size_type count) {
    return *this;
  }

  template <character C> int string <C>::compare(string const&) const {
    return 0;
  }

  template <character C> int string <C>::compare(size_type pos, size_type count, string const&) const {
    return 0;
  }

  template <character C> int string <C>::compare(size_type posl, size_type countl, string const&, size_type posr, size_type countr) const {
    return 0;
  }

  template <character C> int string <C>::compare(const_pointer) const {
    return 0;
  }

  template <character C> int string <C>::compare(size_type pos, size_type count, const_pointer) const {
    return 0;
  }

  template <character C> int string <C>::compare(size_type posl, size_type countl, const_pointer, size_type countr) const {
    return 0;
  }

  template <character C> void string <C>::clear() {
    delete[] m_data;

    m_data = nullptr;
    m_size = 0;
  }

  template <character C> bool string <C>::empty() const {
    return false;
  }

  template <character C> typename string <C>::size_type string <C>::size() const {
    return 0;
  }

  template <character C> void string <C>::swap(string&) noexcept {
  }

  template <character T> string <T> operator + (string <T> const&, string <T> const&) {
    return {};
  }

  template <character T> bool operator == (string <T> const&, string <T> const&) {
    return false;
  }

  template <character T> std::strong_ordering operator <=> (string <T> const&, string <T> const&) {
    return std::strong_ordering::equal;
  }

  template <character T> std::ostream& operator << (std::ostream& lhs, string <T> const&) {
    return lhs;
  }

  template <character T> void swap(string <T>&, string <T>&) noexcept {
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
