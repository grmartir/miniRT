#include "minirt.h"

void    error_exit(int code)
{
    if (code == -1)
        write(STDERR_FILENO, "Error: Can't allocate memmory for new element\n", 46);
    exit(code);
}
