# Lil Bugie

Lil Bugie is a lightweight, single-header logging library designed to be easily integrated into your C/C++ projects. It provides a simple yet flexible interface for logging messages with different log levels, including support for custom log modes and timestamp formats.

## Features

- Single-Header Library: All functionality is contained in a single header file (lil_bugie.h), making it easy to include in your projects.
- Multiple Log Levels: Support for various log levels such as TRACE, DEBUG, INFO, WARN, ERROR, and SUCCESS.
- Customizable Output: Customize log modes and timestamp formats.
- Color-Coded Output: Log messages are color-coded for easy identification in the terminal.
- Header-Only: No need for separate compilation; just include the header file.

## Usage

### 1. Including the Library

Simply drop the lil_bugie.h file into your project and include it in your source files:

```c
#include "lil_bugie.h"
```

### 2. Basic Logging

You can log messages using the provided macros for different log levels:

```c
BUGIE_LOG_INFO(stdout, "Main", "This is an info message.");
BUGIE_LOG_WARN(stdout, "Main", "This is a warning message.");
BUGIE_LOG_ERROR(stdout, "Main", "This is an error message.");
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE.txt) file for details.

## Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request.