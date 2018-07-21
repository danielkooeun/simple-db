#include <iostream>
#include <cstdlib>
#include <string>

#include "input_buffer.h"
#include "db_io.h"
#include "meta_command.h"
#include "statement.h"

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

    // Commands starting with '.' are 'meta-commands' (non-SQL)
    if (input_buffer->buffer[0] == '.') {
      switch (do_meta_command(input_buffer)) {
        case (META_SUCCESS_COMMAND):
          continue;
        case (META_UNRECOGNIZED_COMMAND):
          std::cout << "Unrecognized command '" << input_buffer->buffer << "'.\n";
          continue;
      }
    }
    
    Statement statement;
    switch (prepare_statement(input_buffer, &statement)) {
      case(PREPARE_SUCCESS):
        break;
      case(PREPARE_UNRECOGNIZED_STATEMENT):
        std::cout << "Unrecognized keywords at start of '" << input_buffer->buffer << "'.\n";
        continue;
    }

    execute_statement(&statement);
    std::cout << "Executed.\n";
  }
  
}
