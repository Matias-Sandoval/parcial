#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    int i = 0;
    int length = 0;
    while(s[i] != '\0') {
        length++;
        i++;
    }

    return length;
}



bool fstring_eq(fixstring s1, fixstring s2) {
    int i = 0;
    bool result = true;

    if(fstring_length(s1) ==  fstring_length(s2)) {
        while(s1[i] != '\0' && s2[i] != '\0') { //en realidad basta con que uno de ellos sea != de \0 ya que al entrar al if sabemos que tienen la misma longitud
            if (s1[i] != s2[i] ) {
                result = false;
                break;
            }
            i++;
        }
    } else {
        result = false;
    }

    return result;
}



/*
//hecho por el profe
bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int length_s1 = fstring_length(s1);
    unsigned int length_s2 = fstring_length(s2);
    
    bool result = (length_s1 == length_s2);
    unsigned int i = 0;
    
    while(result && i < length_s1) {
        result = result && (s1[i] == s2[i])
        i++;
    }
    
    return result;
}
*/

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool result = false;
    bool alm = false;
    int i = 0;
    while(s1[i] != '\0') {
        if (s1[i] < s2[i]) {
            result = true;
            break;
        } else if (s1[i] > s2[i]) {
            result = false;
            alm = true;
            break;
        } else if (s1[i] == s2[i]) {
        }
        i++;
    }
    
    
    if(!alm) {
        result = true;
    }
        
    return result;
}


/* p
//hecho por el profe
bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int length_s1 = fstring_length(s1);
    unsigned int length_s2 = fstring_length(s2);
    
    unsigned min_length = (length_s1 <= length_s2) ? length_s1 : length_s2;
    unsigned int i = 0;
    while (i < min_length && (s1[i] == s2[i])) {
        i++;
    }
    
    result = (i== min_length && length_s1 <= length_s2) || 
            (min_length > 0 && s1[i] < s2[i]);
    
    return result;
    
    //4 == 4 && 4<= 9
    
    
*/

