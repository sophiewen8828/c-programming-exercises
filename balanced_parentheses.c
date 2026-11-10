#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

int main(void)
{
    char line[MAXLEN + 2];
    char stack[MAXLEN + 1];
    int top = 0;
    int ok = 1;
    int i;

    if (fgets(line, sizeof line, stdin) == NULL)
        return 0;

    for (i = 0; line[i] != '\0' && line[i] != '\n' && line[i] != '\r'; i++) {
        char c = line[i];

        if (c == '(' || c == '[' || c == '{') {
            stack[top++] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            char want = (c == ')') ? '(' : (c == ']') ? '[' : '{';

            if (top == 0 || stack[top - 1] != want) {
                ok = 0;
                break;
            }
            top--;
        } else {
            /* Unexpected character: not part of a valid sequence. */
            ok = 0;
            break;
        }
    }

    if (top != 0)
        ok = 0;

    printf("%s\n", ok ? "Valid" : "Invalid");

    return 0;
}
