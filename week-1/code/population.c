#include "cs50.h"
#include <stdio.h>

/**
 * @file population.c
 * @author Sebastien Rousseau
 * @date 2023-01-20
 *
 * @brief This program calculates the number of years until a llama population reaches a certain size.
 * @details The population size is calculated as follows:
 *    - Each year, n / 3 new born llamas are added to the population
 *    - Each year, n / 4 llamas die
 *    - The population size is an integer
 * @param startingPopulation The starting population size (greater than 9)
 * @param endingPopulation The ending population size (greater than the starting population)
 * @return The number of years until the population reaches the ending size
 * @note The population size is an integer
 * @usage ./population
 * @usage ./population 100 200
 * @usage for arm64: clang -lcs50 -o population population.c
 */
int main(void)
{
    // Prompt the user for the starting population size (greater than 9)
    int startingPopulation;
    do
    {
        startingPopulation = get_int("Choose a starting population greater than 9: ");
    } while (startingPopulation < 9);

    printf("Start size: %i\n", startingPopulation);

    // Prompt the user for the ending population size (greater than the starting population size)
    int endingPopulation;
    do
    {
        endingPopulation = get_int("Choose a ending population greater than your starting size: ");
    } while (startingPopulation > endingPopulation);

    printf("End size: %i\n", endingPopulation);

    // Calculate the number of years until we reach the threshold (as an integer)
    int years = 0;
    do
    {
        startingPopulation = startingPopulation + (startingPopulation / 3) - (startingPopulation / 4);
        years++;
    } while (startingPopulation < endingPopulation);

    // Print the number of years (as an integer)
    printf("Years: %i\n", years);
}
