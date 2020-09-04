#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float avg_Letters(int length, int words);
int calc_Letters(int length, string text);
int calc_words(string text, int length);
float calc_l(int letter, int words);
int calc_sentences(int length, string text);
float calc_S(int sentences, int words);

int main(void) {
    string text = get_string("Enter reading text? ");
    int length = strlen(text);
    int words = calc_words(text, length);
    int letters = calc_Letters(length,text);
    float L = calc_l(letters, words);
    int sentences = calc_sentences(length, text);
    float S = calc_S(sentences, words);

    printf("%i\n", (int) roundf( 0.0588 * L - 0.296 * S - 15.8));
}

float calc_l(int letter, int words) {
    return (float) letter / (float) words * (float) 100;
}

int calc_Letters(int length,string text) {
    int sum = 0;
    for(int i = 0; i < length; i++) {
        char letter = tolower(text[i]);
        if( letter >= 'a' && letter <= 'z') {
            sum++;
        }
    }
    return sum;
}

int calc_words(string text, int length) {
    int sum = 0;
    for(int i = 0; i < length; i++) {
        char letter = tolower(text[i]);
        if(letter == ' ') {
            sum++;
        }
    }
    return sum + 1;
}

float avg_Letters(int length, int words) {
    return (float) length / words * 100;
}

int calc_sentences(int length, string text) {
    int sum = 0;
    for(int i = 0; i < length; i++) {
        char letter = tolower(text[i]);
        if(letter == '?' || letter == '!' || letter == '.') {
            sum++;
        }
    }
    return sum;
}

float calc_S(int sentences, int words) {
    return (float) sentences / words * 100;
}