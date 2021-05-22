// see https://en.cppreference.com/w/cpp/string/basic_string

#pragma once

#include <compare>
#include <concepts>
#include <iostream>

namespace swe2 {

template <typename C> concept character = std::same_as <C, char> || std::same_as <C, wchar_t>;

template <character C = char> class string final {
   public:
      using value_type      = C;
      using const_pointer   = value_type const *;
      using const_reference = value_type const &;
      using pointer         = value_type *;
      using reference       = value_type &;
      using size_type       = std::size_t;

      static auto const npos {static_cast <size_type> (-1)};

      string () = default;   // default ctor

      string (size_type count, value_type chr);
      string (const_pointer);
      string (const_pointer, size_type count);
      string (string const &, size_type pos);
      string (string const &, size_type pos, size_type count);

      string (string const &);       // copy ctor
      string (string &&) noexcept;   // move ctor

      ~string ();   // dtor

      string & operator = (string const &);       // copy assignment
      string & operator = (string &&) noexcept;   // move assignment

      string & operator += (string const &);

      [[nodiscard]] reference       operator [] (size_type idx);
      [[nodiscard]] const_reference operator [] (size_type idx) const;

      [[nodiscard]] reference       at    (size_type idx);
      [[nodiscard]] const_reference at    (size_type idx) const;
      [[nodiscard]] const_pointer   c_str () const;
      [[nodiscard]] pointer         data  ();
      [[nodiscard]] const_pointer   data  () const;

      string & append  (size_type count, value_type chr);
      string & append  (const_pointer);
      string & append  (const_pointer, size_type count);
      string & append  (string const &);
      string & append  (string const &, size_type pos);
      string & append  (string const &, size_type pos, size_type count);

      [[nodiscard]] int compare (string const &) const;
      [[nodiscard]] int compare (size_type pos, size_type count, string const &) const;
      [[nodiscard]] int compare (size_type posl, size_type countl, string const &, size_type posr, size_type countr = npos) const;
      [[nodiscard]] int compare (const_pointer) const;
      [[nodiscard]] int compare (size_type pos, size_type count, const_pointer) const;
      [[nodiscard]] int compare (size_type posl, size_type countl, const_pointer, size_type countr) const;

                    void      clear ();
      [[nodiscard]] bool      empty () const;
      [[nodiscard]] size_type size  () const;
                    void      swap  (string &) noexcept;

      template <character T> [[nodiscard]] friend string <T> operator + (string <T> const &, string <T> const &);

      template <character T> [[nodiscard]] friend bool                 operator ==  (string <T> const &, string <T> const &);
      template <character T> [[nodiscard]] friend std::strong_ordering operator <=> (string <T> const &, string <T> const &);

      template <character T> friend std::ostream & operator << (std::ostream &, string <T> const &);

      template <character T> friend void swap (string <T> &, string <T> &) noexcept;

   private:
      pointer   m_data {nullptr};
      size_type m_size {0};
      void createFromConstPtr(const_pointer, int count = -1);
};

}   // namespace swe2

namespace swe2::string_literals {

[[nodiscard]] string <char>    operator "" _s (char const *, std::size_t);
[[nodiscard]] string <wchar_t> operator "" _s (wchar_t const *, std::size_t);

}   // namespace swe2::string_literals

#include "./string.inl"
