# Lil Bugie

---

**Lil Bugie** is a lightweight, single-header logging library tailored for C/C++ projects. It offers a straightforward yet adaptable interface for logging messages across various levels, with support for custom log modes and timestamp formats, making it an ideal choice for developers seeking a minimalistic but effective logging solution.

---

## Key Features

- **Single-Header Library**: All functionality is contained in `lil_bugie.h`, simplifying inclusion and integration.
- **Multiple Log Levels**: Easily log messages at different levels—TRACE, DEBUG, INFO, WARN, ERROR, and SUCCESS.
- **Customizable Logging**: Adjust log modes and timestamp formats to fit your needs.
- **Colour-Coded Output**: Messages are colour-coded for quick identification in terminal environments.
- **Header-Only Implementation**: No need for separate compilation; just include the header file in your project.

---

## Getting Started

### 1. Including the Library

To start using Lil Bugie, simply add `lil_bugie.h` to your project directory and include it in your source files:

```c
#include "lil_bugie.h"
```

### 2. Logging Messages

Lil Bugie provides convenient macros for logging at different levels. Here's how to use them:

```c
BUGIE_LOG_INFO(stdout, "Main", "This is an info message.");
BUGIE_LOG_WARN(stdout, "Main", "This is a warning message.");
BUGIE_LOG_ERROR(stdout, "Main", "This is an error message.");
```

### 3. Customizing Logs

You can further customise your log outputs by specifying different modes or timestamp formats:

```c
BUGIE_LOG_DEBUG(stdout, "Init", "Debugging the initialization process.");
```

---

## Example

```c
#include "lil_bugie.h"

int main() {
    BUGIE_LOG_TRACE(stdout, "Main", "Starting the program...");
    BUGIE_LOG_SUCCESS(stdout, "Main", "Initialization successful.");
    BUGIE_LOG_ERROR(stdout, "Main", "An error occurred.");
    return 0;
}
```

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE.txt) file for more details.

---

## Contributing

We welcome contributions! If you encounter any issues or have ideas for improvements, please open an issue or submit a pull request.