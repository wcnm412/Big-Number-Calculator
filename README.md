# Big-Number-Calculator

C++ Calculator with 3 functions:
  1. Exponentiation
  2. Factorial
  3. Change working number

<br>

Known issues:
  - Exponentiation of a negative integer immediately falls back to a double due to current implementation of overflow detection

<br>

To add:
  - Make this a general-purpose calculator with add, subtract, multiplication, division, logarithm, etc.
  - Include a GUI
  - Split into multiple files for better readability
  - Browse history, including past *base* numbers and the result of operations on them
  - Allow multiple operations and numbers to be chained together, e.g. a * b + c / d
    - Ask user to enter a string, and interpret string as a series of numbers and operations
