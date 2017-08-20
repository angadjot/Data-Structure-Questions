//find its first non-repeating character
#include <iostream>
using namespace std;

struct countIndex{
    int count;
    int index;
};

int getFirstChar(char *str){

    countIndex countArr[28];
    for(int i=0;i<27;i++){
        countArr[i].count = 0;
        countArr[i].index = 0;
    }

    for(int i=0;str[i] != '\0';i++){
        countArr[str[i]-'a'].count++;
        if(countArr[str[i]-'a'].count == 1 ){
            countArr[str[i]-'a'].index = i;
        }
    }

    for(int i=0;i<27;i++){
        cout<<(char)('a'+i)<<" ";
        cout<<countArr[i].count<<" ";
        cout<<countArr[i].index<<endl;
    }
    cout<<endl;

    int result = INT_MAX;

    for(int i=0;i<27;i++){
        if(countArr[i].count == 1){
            if(countArr[i].index < result){
                result = countArr[i].index;
            }
        }
    }
    cout<<result<<endl;
    return result;

}


int main(){

    char str[] = "geeksforgeeks";
    int index =  getFirstChar(str);
    if (index == INT_MAX)
        printf("Either all characters are repeating or string is empty");
    else
        printf("First non-repeating character is %c", str[index]);
  return 0;

}