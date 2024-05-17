# Big Number Container

The Big Number Container is a C++ project designed to handle and process very large numbers that exceed the limits of standard data types. This project implements a class that stores huge numbers in a vector and overloads major operators for comparison and arithmetic operations.

## Features

- **Huge Number Storage**: Stores large numbers in a vector to manage their digits.
- **Operator Overloading**: Supports major operators including:
  - Arithmetic: `+`, `-`, `*`, `/`
  - Comparison: `==`, `!=`, `<`, `<=`, `>`, `>=`
- **Efficiency**: Designed to handle operations on very large numbers efficiently.

## Examples

Here are some example operations you can perform with the Huge Number Container:

1. **Addition**:

    ```cpp
    HugeNumber a("12345678901234567890");
    HugeNumber b("98765432109876543210");
    HugeNumber result = a + b;
    std::cout << "Sum: " << result << std::endl;
    ```

2. **Subtraction**:

    ```cpp
    HugeNumber a("98765432109876543210");
    HugeNumber b("12345678901234567890");
    HugeNumber result = a - b;
    std::cout << "Difference: " << result << std::endl;
    ```

3. **Multiplication**:

    ```cpp
    HugeNumber a("12345678901234567890");
    HugeNumber b("2");
    HugeNumber result = a * b;
    std::cout << "Product: " << result << std::endl;
    ```

4. **Comparison**:

    ```cpp
    HugeNumber a("12345678901234567890");
    HugeNumber b("98765432109876543210");
    if (a < b) {
        std::cout << a << " is less than " << b << std::endl;
    }
    ```

Thank you for using the Huge Number Container!
