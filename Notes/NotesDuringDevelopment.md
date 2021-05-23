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

# Step 2: ctors

Is there a way to replace the following two lines of code with a single line initialization?
```cpp
	m_data = new value_type[m_size];
    std::fill(m_data, m_data + count, chr);
```

Is it possible for the ctor stated below to get the content of the std::vector 'moved' to m_data?
It was tried to std::move(vector.data()).
```cpp
	string(const_pointer input)
```
# ++ pre/post increment

Post increment requires saving the current value, pre does not need that. Prefere pre over post in most cases when the return value of the ++-operator is not required.

# r-value reference
The r-value reference was used for the move ctor. It seemed like that the r-value reference of the "object-to-be-moved-from" enables the access to private member variables.

# Copy assignment operator
Why can private members accessed in these functions when passed as const&? Same was done before with && references.
What is the usual behavior of a copy assignment operator? Does this make a deep copy of the assigned members?
Should pointer type members only be assigned, should container type members be recreated? 
Should a check be added for self assignment?