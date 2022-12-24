#include <stdio.h>
#define LINE 256
#define WORD 30

///-----Calculate the size of a given string-----
int getStrLen(char *str){
    int len = 0 ;
    //-----While current character not equals the null character, promote the pointer to the next char-----
    //-----and increase len by 1---------------------------------------------------------------------------
    while(*str != 0){
        len++ ;
        str += 1 ;
    }
    return len ;
}

///-----Reading from the standard input a line (a sequence of characters without newLine character between)-----
int getLine(char s[]){
    int i = 0 ;
    char c = 0 ;

    //-----While c is not equals EOF keep going-----
    while(scanf("%c", &c) != -1){
        //-----If new line character has been scanned, insert null character to the end of the line and-----
        //-----return the line size-------------------------------------------------------------------------
        if(c == '\n'){
            s[i] = 0 ;
            return i;
        }else{
            //-----If the char holds the ascii value of 13, skip on it, else add the char to the line and-----
            //-----increase the index by 1--------------------------------------------------------------------
            if(c != 13) {
                s[i] = c;
                i++ ;
            }
        }
    }
    return -1 ;
}

///-----Reading from the standard input a word (a sequence of characters without whitespaces between)-----
int getWord(char w[]){
    int i = 0 ;
    char c = 0 ;

    //-----While c is not equals EOF keep going-----
    while(scanf("%c", &c) != -1){

        //-----If c is a whitespace char, return the word scanned until this point, else add the char to the word-----
        //-----and increase the index by 1----------------------------------------------------------------------------
        if(c == '\n' || c == 32 || c == '\t' || c == 13){
            w[i] = 0 ;
            return i ;
        }else{
            w[i] = c ;
            i++ ;
        }
    }
    return -1 ;
}

///-----Given two strings (str1 and str2) check if str1 contains str2 within it, if yes return 1, else return 0-----
int substring(char *str1, char *str2){

    //-----Get the length of the given strings-----
    int len1 = getStrLen(str1) ;
    int len2 = getStrLen(str2) ;

    //-----For each index i of (len1 - len2), compare str1[i, ..., i + len2] to str2[0, ..., len2]-----
    for(int i = 0 ; i <= len1 - len2; i++){
        int j = 0 ;
        while(str1[i+j] == str2[j] && j < len2){
            j++ ;
        }
        if(j == len2){
            return 1 ;
        }
    }
    return 0 ;
}

///-----Given two strings (str1, str2), and integer n, check if str2 can be reached from str1 by dropping-----
///-----at most n characters, if it can, return 1, else return 0----------------------------------------------
int similar(char *str1, char *str2, int n){

    //-----Get the length of the given strings-----
    int len1 = getStrLen(str1) ;
    int len2 = getStrLen(str2) ;

    //-----skipped - the number of skipped characters till this point-----
    int skipped = 0 ;

    //-----i is the index of the current char being checked at str2-----
    int i = 0 ;

    //-----If len1 - n > len2, str2 cannot be reached from str1 because str1 is two long-----
    //-----If len1 < len2, a trivial case, str1 is not equal to str2, and dropping chars from it will not help-----
    if(len1 - n > len2 || len1 < len2){
        return 0 ;
    }else{

        //-----If skipped characters number + current index >= length(str1), the algorithm passed on all of str1,-----
        //-----and match has not been found, so exit------------------------------------------------------------------
        //-----If skipped > n(allowed skips number), match has not been found, exit-----
        while(skipped <= n && i + skipped < len1){

            //-----If the current char on str1 equals the current char on str2, increase current char index by 1-----
            //-----else, skip the current char on str1 by increasing skipped-----------------------------------------
            if(str1[i + skipped] == str2[i]){
                i++ ;
            }else{
                skipped++ ;
            }
        }

        //-----If the current index of str2 equals the length of str2, the words are similar, else they are not-----
        if(i == len2){
            return 1 ;
        }else{
            return 0 ;
        }
    }
}

///-----Scan each line of the given input, and check if it contains the string given at the func signature-----
void print_lines(char *str){
    char line[LINE] = {0} ;

    //-----While getting input, getLine() != -1, keep going until the end of the given input-----
    while(getLine(line) != -1){
        if(substring(line, str)) {
            printf("%s\n", line);
        }
    }
}

///-----Scan each word of the given input, and check if it is similar to the word given at the func signature-----
void print_similar_words(char *word){
    char currentWord[WORD] = {0} ;

    //-----While getting input, getWord() != -1, keep going until the end of the input-----
    while(getWord(currentWord) != -1){
        if(similar(currentWord, word, 1)) {
            printf("%s\n", currentWord);
        }
    }
}

