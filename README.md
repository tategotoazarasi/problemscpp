# problemscpp

A collection of competitive programming solutions written in C++. This repository serves as a personal log of solved problems from various platforms like LeetCode, LintCode, and AcWing.

## Project Structure

The project is organized by platform, with source and header files for each.

- `CMakeLists.txt`: The main build configuration file for the project.
- `Doxyfile`: The configuration file for the Doxygen documentation generator.
- `main.cpp`: The entry point for running the Google Test suite.
- `acwing.cpp`, `leetcode.cpp`, etc.: Implementation files containing solutions for problems from the respective platforms.
- `acwing.h`, `leetcode.h`, etc.: Header files declaring the classes and functions for each platform's solutions.
- `*_test.cpp`: Test files containing unit tests for the solutions, organized by platform.
- `templates/`: Contains reusable code and data structures, such as a `BigInt` class.

## Getting Started

### Prerequisites

- A C++20 compatible compiler (e.g., GCC, Clang, MSVC).
- CMake (version 3.21 or newer).
- Doxygen (for generating documentation).

### Build

This project uses CMake for building. Google Test is managed via `FetchContent` and will be downloaded automatically if not found on your system.

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/tategotoazarasi/problemscpp.git
    cd problemscpp
    ```

2.  **Configure the build using CMake:**
    ```bash
    cmake -B build
    ```

3.  **Build the project:**
    ```bash
    cmake --build build
    ```
    This will compile the source code and create an executable in the `build` directory.

## Testing

The project uses Google Test for unit testing. The tests are discovered automatically by CMake.

To run all tests, execute the binary built in the previous step:

```bash
./build/problemscpp
```

Alternatively, you can use `ctest` from within the build directory:

```bash
cd build
ctest
```

## Documentation

The project uses Doxygen to automatically generate API documentation from the comments in the source code.

1.  **Install Doxygen:**
    Ensure you have Doxygen installed. You can typically install it through your system's package manager (e.g., `sudo apt-get install doxygen`) or from the [official website](https://www.doxygen.nl/download.html).

2.  **Generate the documentation:**
    Navigate to the project's root directory and run Doxygen:
    ```bash
    doxygen Doxyfile
    ```

3.  **View the documentation:**
    The documentation will be generated in the directory specified by `OUTPUT_DIRECTORY` and `HTML_OUTPUT` in the `Doxyfile` (currently `./`). Open the `index.html` file in your web browser to view the documentation.
