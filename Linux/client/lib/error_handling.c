#include <lib/error_handling.h>

#include <stdio.h>
#include <stdlib.h>

void error_handling(const char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(EXIT_FAILURE);
}
