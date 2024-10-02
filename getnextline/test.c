#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    // Test 1: File with multiple lines
    fd = open("testfile1.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }
    printf("Test 1 - File with multiple lines:\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);  // Remember to free the allocated line
    }
    close(fd);

    // Test 2: Empty file
    fd = open("emptyfile.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }
    printf("\nTest 2 - Empty file:\n");
    line = get_next_line(fd);
    if (!line)
        printf("Returned NULL for empty file as expected.\n");
    close(fd);

    // Test 3: File without newline characters
    fd = open("nonlfile.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }
    printf("\nTest 3 - File without newline characters:\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);

    return 0;
}