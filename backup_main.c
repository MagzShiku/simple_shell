#include "main.h"

int main()
{

char *mj_c_prompt;
char *mj_input; /* a pointer to buffer input from stdin*/
size_t size;/*stores allocated memory in bytes*/
	
size = 256;
mj_c_prompt = "mjshell$";

printf("%s", mj_c_prompt);
fflush(stdout); /* Ensure the prompt is printed before reading input */

mj_input = malloc(sizeof(char) * 256); /* Allocate memory for input buffer */


if (mj_input == NULL) {
    fprintf(stderr, "Failed to allocate memory\n");
    return 1; /* Return with error code */
}

if (fgets(mj_input, size, stdin) == NULL) {
    fprintf(stderr, "Failed to read input\n");
    free(mj_input);
    return 1; /* Return with error code */
}

printf("%s\n", mj_input);
/*CHECK TO USE scanf here*/
free(mj_input);
return 0;
}
