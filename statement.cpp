#include <iostream>
#include <string>

#include "input_buffer.h"
#include "meta_command.h"
#include "statement.h"

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement) {
  std::cout << "this is the statement: " << input_buffer->buffer << "\n";
  if (input_buffer->buffer.substr(0, 6) == "insert") {
    statement->type = STATEMENT_INSERT;
    return PREPARE_SUCCESS;
  }
  if (input_buffer->buffer.substr(0, 6) == "select") {
    statement->type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  }

  return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(Statement* statement) {
  switch (statement->type) {
    case (STATEMENT_INSERT):
      std::cout << "This is insert\n";
      break;
    case (STATEMENT_SELECT):
      std::cout << "This is select\n";
      break;
  }
}

