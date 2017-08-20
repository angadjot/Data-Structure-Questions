#include <iostream>
#include <map>
using namespace std;

void printwb(bool wb[],int size){

    for(int i=0;i<size;i++)
        cout<<wb[i]<<" ";
    cout<<endl;
}

bool wordBreak(string str,map<string,int> &dict){

    int size = str.length();
    bool wb[size+1];
    memset(wb,0,sizeof(wb));
    wb[0] = true;

    for(int i=1;i<=size;i++){
        for(int j=i-1;j>=0;j--){
            if(wb[i] == false && wb[j] == true && dict[str.substr(j,i-j)]){
                wb[i] = true;
            }
        }
        printwb(wb,size+1);
    }

    return wb[size];

}

int main(){

    map<string,int> dict;
    dict["i"] = 1;
    dict["like"] = 1;
    dict["sam"] = 1;
    dict["sung"] = 1;
    dict["samsung"] = 1;
    dict["ice"] = 1;

    string str = "isamsunglike";
    if(wordBreak(str,dict))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

}