#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *overflow_me = "overflow me : ";
void func(int key){
    char overflowme[32];
    printf("%s", overflow_me);
    fgets(overflowme, 200, stdin);    // smash me!
    if(key == 0xcafebabe){
        system("/bin/sh");
    }
    else{
        printf("Nah..\n");
    }
}

int main(int argc, char* argv[]){
    func(0xdeadbeef);
    return 0;
}

