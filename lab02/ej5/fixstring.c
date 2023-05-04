#include <stdbool.h>
#include <assert.h>

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
        while(s1[i] != '\0' && s2[i] != '\0') {
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




void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux,s1);
    fstring_set(s1,s2);
    fstring_set(s2,aux);
    
}


