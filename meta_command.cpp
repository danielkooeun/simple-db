#include <string>

#include "input_buffer.h"
#include "meta_command.h"

MetaCommandResult do_meta_command(InputBuffer* input_buffer) {
  if (input_buffer->buffer == ".exit") {
    exit(EXIT_SUCCESS);
  } else {
    return META_UNRECOGNIZED_COMMAND;
  }
}
