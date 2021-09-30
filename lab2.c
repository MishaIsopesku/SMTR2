#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char vowels[] = "aeiouy"; /* голосні - 6 */
char consonants[] = "bcdfghjklmnpqrstvwxz"; /* приголосні букви - 20 */

const int SIZE = 1024;

/* визначимо, чи буква голосна */
int is_vowel(const char c)
{
for(int x = 0; x < 6; x++)
if (tolower(c) == vowels[x]) return 1;
return 0;
}

/* визначимо,чи буква приголосна */
int is_consonant(const char c)
{
for(int x = 0; x < 20; x++)
if (tolower(c) == consonants[x]) return 1;
return 0;
}

/* підрахунок кількості голосних у слові */
int count_vowels(const char * word, const int len)
{
int count = 0;
for(int x = 0; x < len; x++)
if( is_vowel(word[x]) ) count++;
return count;
}

/* підрахунок кількості приголосних в слові */
int count_consonants(const char * word, const int len)
{
int count = 0;
for(int x = 0; x < len; x++)
if( is_consonant(word[x]) ) count++;
return count;
}

/* для зберігання слів і інформації про них */
struct words
{
char * word; /* слово */
int len; /* довжина слова */
int volwes; /* кількість голосних в слові */
int consonants; /* кількість приголосних в слові */
} ;

int main()
{
    printf("Введіть:");
char str[SIZE]; /* рядок для ввода */
char c;
int i = 0;
while( ( (c = getchar()) != '\n') && i < SIZE - 1 )
{
str[i] = c;
i++;
}
str[i] = '\0';

struct words w[SIZE]; /* сховище слів */
int count_of_words = 0; /* лічильник слів */
int len_str = strlen(str); /* довжина введеного рядка */

/* розбиваємо рядок на слова*/
for(int x = 0; x < len_str;)
{
w[count_of_words].word = (char *) malloc(SIZE); /* виділяємо пам'ять під слово */
w[count_of_words].len = 0;
w[count_of_words].volwes = 0;
w[count_of_words].consonants = 0;
while( ( is_vowel(str[x]) || is_consonant(str[x]) ) && x < len_str )
{
if( is_vowel(str[x]) ) w[count_of_words].volwes++;
else if ( is_consonant(str[x]) ) w[count_of_words].consonants++;
w[count_of_words].word[w[count_of_words].len] = str[x];
w[count_of_words].len++;
x++;
}
w[count_of_words].word[w[count_of_words].len] = '\0';
count_of_words++;
/*пропустити знаки, пробіли */
while( !( is_vowel(str[x]) || is_consonant(str[x]) ) && x < len_str ) x++;
}

/* а) */
int odinak = 0; /* кількість слів, які містять однакову кількість голосних і приголосних літер */
for(int x = 0; x < count_of_words; x++)
if(w[x].volwes == w[x].consonants) odinak++;
printf("Кількість слів з однаковою кількістю голосних і приголосних -- %d.\r\n", odinak);

/* б) */
int i_max_len = 0; /* виводить найдовше слово */
for(int x = 1; x < count_of_words; x++)
if( w[x].len > w[i_max_len].len ) i_max_len = x;
printf("Саме найдовше слово -- %s.\r\n", w[i_max_len].word);

/* очищаем память */
for(int x = 0; x < count_of_words; x++)
{
if(!w[x].word)
{
w[x].word[0] = ' ';
w[x].word[1] = '\0';
}
free(w[x].word);
w[x].word[0] = '\0';
w[x].len = 0;
w[x].volwes = 0;
w[x].consonants = 0;
}

return 0;
}





