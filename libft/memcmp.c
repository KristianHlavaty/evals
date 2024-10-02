#include <stdio.h>
#include <string.h> 

// memcmp function

int main()
{
	// Test 1: Identical strings
    char str1[] = "abcdef";
    char str2[] = "abcdef";
    printf("Test 1: %d (expected 0)\n", ft_memcmp(str1, str2, 6));

    // Test 2: Different strings
    char str3[] = "abcdeg";
    printf("Test 2: %d (expected non-zero)\n", ft_memcmp(NULL, str3, 6));

    // Test 3: Different strings, comparing first few characters
    printf("Test 3: %d (expected 0)\n", ft_memcmp(str1, NULL, 5));

    // Test 4: Comparing empty strings
    printf("Test 4: %d (expected 0)\n", ft_memcmp(NULL, NULL, 0));

    // Test 5: Original memcmp comparison
    printf("Original memcmp result: %d\n", memcmp(str1, str3, 6));
    
    return 0;
}
