#ifndef INPUT_BUFFER
#define INPUT_BUFFER

class InputBuffer {
  public:
    std::string buffer;
    size_t buffer_length;
    ssize_t input_length;

    InputBuffer();
};

#endif  /* INPUT_BUFFER */
