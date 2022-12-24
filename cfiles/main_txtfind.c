#include <stdio.h>
#include "../hdrs/txtfind.h"
#define WORD 30
int main(){
    char option = 0 ;
    char word[WORD] = {0} ;
    //-----Read the first word from the input stream-----
    getWord(word) ;

    //-----Read the chosen option (a\b) from the input stream-----
    scanf("%c", &option) ;

    //-----If option == 'a' print the lines contains the given word-------
    //-----if option == 'b' print the similar words found in the text-----
    //-----else, option is not valid, return -1---------------------------
    if(option == 'a') {
        print_lines(word) ;
    }else if(option == 'b') {
        print_similar_words(word);
    }else{
        return -1 ;
    }
    return 0 ;
}
