// see https://en.cppreference.com/w/cpp/string/basic_string

#pragma once

#include <compare>
#include <concepts>
#include <iostream>

//Ausschließlich mit new und delete implementieren
//und es läuft nur über c_strings ab

namespace swe2 {

template <typename C> concept character = std::same_as <C, char> || std::same_as <C, wchar_t>;

template <character C = char> class string final {
    //public bleibt so!
   public:
      using value_type      = C;
      using const_pointer   = value_type const *;
      using const_reference = value_type const &;
      using pointer         = value_type *;
      using reference       = value_type &;
      using size_type       = std::size_t;

      static auto const npos {static_cast <size_type> (-1)}; //übergibt unendlich

      string () = default;   // default ctor

      string (size_type count, value_type chr);                 //baut einen String aus Anzahl an Charakters z.B. 10 mal A -> string{10,'A'}
      string (const_pointer);                                   //string{"hallo"}
      string (const_pointer, value_type count);                 //string{"hallo",2} -> ergibt "hal"
      string (string const &, size_type pos);                   //string{s1, 3}
      string (string const &, size_type pos, size_type count);  //string{s1, 3 ,2} -> ab dem 3. String die nächsten 2 Zeichen

      string (string const &);       // copy ctor
      string (string &&) noexcept;   // move ctor

      ~string ();   // dtor

      string & operator = (string const &);       // copy assignment -> s1 = s2
      string & operator = (string &&) noexcept;   // move assignment -> einander zuweisen -> ERSTMAL WEGLASSEN

      string & operator += (string const &);       //neue Zeichenkette -> neu allokieren -> dranhängen

      [[nodiscard]] reference       operator [] (size_type idx);        //gibt eine reference zurück -> no discard Attribut der bei dem Operator eine warnung ausgibt, wenn sie nicht weiter verwendet wird
      [[nodiscard]] const_reference operator [] (size_type idx) const;  //gibt eine konstante referenz zurück

      [[nodiscard]] reference       at    (size_type idx);      //index out of range schmeißt mit AT eine Exeption -> prüft den Index und gibt ihn dann weiter
      [[nodiscard]] const_reference at    (size_type idx) const;
      [[nodiscard]] const_pointer   c_str () const;             //pointer auf die dahinter liegende Datenstruktur -> siehe Tafel-20210430.pdf
      [[nodiscard]] pointer         data  ();                   //data macht das gleiche wie c_str
      [[nodiscard]] const_pointer   data  () const;

      string & append  (size_type count, value_type chr);       //+=
      string & append  (const_pointer);                         //
      string & append  (const_pointer, value_type count);
      string & append  (string const &);                        //+=
      string & append  (string const &, size_type pos);
      string & append  (string const &, size_type pos, size_type count);
      /* Strings vergleichen
      s1 < s2
      s1.compare(s2) <0
      //Zeichenketten miteinander vergleichen -> when this < als der String < 0, ... =0, ... >0
      GENERELL!!! (Speicher mit new und delete allokieren)
      */

      [[nodiscard]] int compare (string const &) const;                                                     //lexikographisch              
      [[nodiscard]] int compare (size_type pos, size_type count, string const &) const;                     //nur einen Substring mit einem ganzen
      [[nodiscard]] int compare (size_type posl, size_type countl, string const &, size_type posr, size_type countr = npos) const;  //zwei Substrings miteinander vergleichen -> länge muss gleich sein!
      [[nodiscard]] int compare (const_pointer) const;                                                      //vgl mit einem character array
      [[nodiscard]] int compare (size_type pos, size_type count, const_pointer) const;                      //
      [[nodiscard]] int compare (size_type posl, size_type countl, const_pointer, size_type countr) const;

                    void      clear ();                 //löscht den String
      [[nodiscard]] bool      empty () const;           //String voll oder leer
      [[nodiscard]] size_type size  () const;           //längestring
                    void      swap  (string &) noexcept;//string s1 durch s2 austauschen

      template <character T> [[nodiscard]] friend string <T> operator + (string <T> const &, string <T> const &); //außerhalb programmiert, hat aber zugriff auf private Komponenten -> hängt zwei s1 + s2 zusammen und erzeugt eine dritte

      template <character T> [[nodiscard]] friend bool                 operator ==  (string <T> const &, string <T> const &);   //vergleicht auf Gleichheit -> ungleich mitbeachten
      template <character T> [[nodiscard]] friend std::strong_ordering operator <=> (string <T> const &, string <T> const &);   //Space Ship Operator -> Strong ordering -> lExographisch alles miteinander Vergleichen
      //mit den beiden Operatoren sind alle 5 abgedeckt!

      template <character T> friend std::ostream & operator << (std::ostream &, string <T> const &);

      template <character T> friend void swap (string <T> &, string <T> &) noexcept;

      //Hilfsfunktionen kommen unter private!
   private:
      pointer   m_data {nullptr};
      size_type m_size {0};
};

}   // namespace swe2

namespace swe2::string_literals {

[[nodiscard]] string <char>    operator "" _s (char const *, std::size_t);
[[nodiscard]] string <wchar_t> operator "" _s (wchar_t const *, std::size_t);

}   // namespace swe2::string_literals

//normal alles im Headerfile implementieren -> kann nicht getrennt werden
//deshalb hier der Trick mit .inl
//das inl wird am Ende angehängt, sodass es eine Datei ist für den Compiler

#include "./string.inl"
