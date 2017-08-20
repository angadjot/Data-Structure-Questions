#include <stdio.h>
#include <map>
using namespace std;

char* CrossCommon(char* str1,char *str2){

    map<char,bool> hashmap;

    for(int i=0;str1[i] != '\0';i++)
        hashmap[str1[i]] = true;

    for(int i=0;i<str2[i] != '\0';i++)
        if(hashmap[str2[i]]){
            hashmap[str2[i]] = false;
            str2[i] = '0';
        }

    char *finalstr = new char[strlen(str1)+strlen(str2)];
    int index = 0;
    for(int i=0;str1[i] != '\0';i++)
        if(hashmap[str1[i]]){
            finalstr[index++] = str1[i];
        }

    for(int i=0;i<str2[i] != '\0';i++){
        if(str2[i] != '0')
            finalstr[index++] = str2[i];
    }

    finalstr[index] = '\0';

    return finalstr;

}

int main(){

    char str1[] = "abcghi";
    char str2[] = "cvuvaagoo";

    //bhivuvoo

    char *str = CrossCommon(str1,str2);

    printf("%s\n",str);
    return 0;
}