# Step 1: Understanding the template & concept of `string`

Taken from cppreference the general structure of a template with concept:  
template <template-parameter-list> concept concept-name = constraint-expression;


```cpp
	template <typename C> concept character = std::same_as <C, char> || std::same_as <C, wchar_t>;
```

- `typename` is in a general case exchangeable with `class`.
- `std::same_as` is a method used for concepts and compares types. In this case it enforces `C` to be ether `char` or `wchar_t`.  

Following line creates a specific template:
```cpp
	template <character C = char> class string final
```

The assignment of `char` can be seen as a default parameter for the template. Results in the possibility to not always have to 
state `<char>` when using the template type.