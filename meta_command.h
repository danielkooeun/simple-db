#ifndef META_COMMAND
#define META_COMMAND

typedef enum {
  META_SUCCESS_COMMAND,
  META_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum {
  PREPARE_SUCCESS,
  PREPARE_SYNTAX_ERROR,
  PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum {
  EXECUTE_SUCCESS,
  EXECUTE_TABLE_FULL
} ExecuteResult;

MetaCommandResult do_meta_command(InputBuffer* input_buffer);

#endif  /* META_COMMAND */
