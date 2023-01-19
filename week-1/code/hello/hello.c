#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Declaring a max length for the name
#define MAX_NAME_LENGTH 50

/**
 * @file hello.c
 * @author Sebastien Rousseau
 * @date 2023-01-20
 *
 * @brief This program prompts the user for their name and then prints
 `hello, so-and-so`, where so-and-so is their actual name.
 * @param name The name of the user
 * @param valid A flag to check if the input is valid
 * @return hello, so-and-so where so-and-so is the user's name
 * @note The name is a string and has a maximum length of 50 characters
 * @note The valid flag is an integer
 *
 * @usage ./hello "John Doe"
 * @usage for arm64, compile with clang -lcs50 -o hello hello.c
 */
int main(void)
{
    // Declare a string variable `name`
    string name;

    // Declare an integer variable `valid` and set it to 0
    int valid = 0;

    // Loop until the input is valid
    while (!valid)
    {

        // Prompt the user for their name
        name = get_string("What is your name? ");

        // Check if the input is empty
        if (strlen(name) == 0)
        {
            printf("Error: The name cannot be empty.\n");
            continue;
        }

        // Check if the input contains any unwanted characters
        for (int i = 0, n = strlen(name); i < n; i++)
        {
            if (!isalpha(name[i]) && !isspace(name[i]))
            {
                printf("Error: The name can only contain letters and spaces.\n");
                valid = 0;
                break;
            }
            valid = 1;
        }

        // Check if the input is too long (length is managed via a constant `MAX_NAME_LENGTH`)
        if (strlen(name) >= MAX_NAME_LENGTH)
        {
            printf("Error: Name must be less than %d characters.\n", MAX_NAME_LENGTH);
            valid = 0;
        }
    }
    // Print the user's name with a greeting message (e.g. hello, John Doe)
    printf("hello, %s\n", name);
}