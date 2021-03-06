//
//  main.cpp
//  Uva 12897 - Decoding Baby Boos
//
//  Created by S M HEMEL on 27/10/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <cstdio>
using namespace std;
char s[1048576];
int main() {
    int testcase, n;
    scanf("%d", &testcase);
    while (testcase--) {
        scanf("%s", s);
        scanf("%d", &n);
        
        char R[128], s1[10], s2[10];
        for (int i=0; i<128; i++) R[i] = i;
        for(int i=0; i<n; i++) {
            scanf("%s %s", s1,s2);
            for(int j = 'A'; j <= 'Z'; j++)
                if(R[j] == s2[0])
                    R[j] = s1[0];
        }
        
        for (int i = 0; s[i]; i++)
            putchar(R[s[i]]);
        puts("");
    }
    return 0;
}
