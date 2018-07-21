#include <iostream>
#include <cstdlib>
#include <string>
#include "input_buffer.h"
#include "db_io.h"

int main(int argc, char* argv[]) {
  InputBuffer* input_buffer = new InputBuffer();
  
  // infinite loop to retrieve user input
  while (true) {
    print_prompt();
    std::getline(std::cin, input_buffer->buffer);
    if (input_buffer->buffer.length() <= 0) {
      std::cout << "Error reading input\n";
      exit(EXIT_FAILURE);
    }
    if (input_buffer->buffer == ".exit") {
      exit(EXIT_SUCCESS);
    } else {
      std::cout << "Unrecognized command '" << input_buffer->buffer << "'.\n";
    }
  }
  
}
