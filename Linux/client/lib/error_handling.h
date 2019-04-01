#ifndef _ERROR_HANDLING_H_
#define _ERROR_HANDLING_H_

#include <stdio.h>
#include <stdlib.h>

void error_handling(const char *message)
{
	fputs(message, stderr);
    fputc('\n', stderr);
	exit(EXIT_FAILURE);
}

#endif