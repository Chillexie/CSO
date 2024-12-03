/**
 * CS2130 Lab 11 - Spring 2023 - Memory Errors
 *
 * Our Trivia game is fun!  But, we should have been more careful
 * with memory!  Fix the memory errors so that you, too, can play
 * a game of trivia.
 */

// Enum for possible return values when reading questions
enum { readok, nofile };

/**
 * Definition of a questionData: the text of the question, which answer is correct,
 * and 4 possible Multiple Choice options
 */
typedef struct {
    char text[300];
    char correct;
    char *answers[4];
} questionData;

/**
 * Request name: ask the users for their name and
 * return a pointer to that string
 */
void requestName(char *name);

/**
 * We want a random ordering of questions and answers for our trivia
 * game.  This function seeds our random number generator (so that it
 * gives different numbers for each run of trivia) with the current time.
 * Each time we play, the seed will be different.
 */
int seedRandomNumber();

/**
 * Shuffle pointers.  Given an array of pointers and a length n, it
 * will shuffle the pointers in a random order.  It keeps track of the
 * address stored in the first pointer (our correct answer for trivia) and
 * returns the position in the shuffled array as an offset from char 'A'.
 * That is, if the first pointer in the original list is put in the third (ptrs[2])
 * position of the shuffled list, this function will return 'C' (i.e., 'A'+2).
 */
char shufflePointers(void **ptrs, size_t n);

/**
 * Shuffle questions.  This will shuffle the array of questionData structs
 * that resides in global memory.  It follows a similar process to
 * shufflePointers, but does not return anything.
 */
void shuffleQuestions(int numQuestions);

/**
 * Read trivia questions from a file.  Given a category string and the
 * number of questions to read, this function opens the data file and
 * reads that number of questions.  It creates a struct of type questionData, 
 * then copies that struct into the global array of questions.
 */
int readTriviaQuestions(char *category, int numQuestions);


