#include <iostream>
#include <queue>
using namespace std;

#define R 3
#define C 5

struct ele{
  int x,y;
};

bool isDelimiter(ele temp){

    return (temp.x == -1 && temp.y == -1);

}

bool isValid(int x,int y){

    return (x >= 0 && y >= 0 && x < R && y < C);
}

bool checkall(int arr[][C]){

    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(arr[i][j] == 1)
                return true;

    return false;
}

int rotOranges(int arr[][C]){

    queue<ele> Q;

    ele temp;
    int ans = 0;

    //push rotten Oranges
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(arr[i][j] == 2){
                temp.x = i;
                temp.y = j;
                Q.push(temp);
            }
        }
    }

    //push delimiter
    temp.x = -1;
    temp.y = -1;
    Q.push(temp);

    while(!Q.empty()){

        bool flag = false;

        while(!isDelimiter(Q.front())){

            temp = Q.front();

            if(isValid(temp.x+1,temp.y) && arr[temp.x+1][temp.y] == 1){
                if(!flag){
                    ans++;
                    flag = true;
                }

                arr[temp.x+1][temp.y] = 2;

                temp.x++;
                Q.push(temp);

                temp.x--;
            }

            if(isValid(temp.x-1,temp.y) && arr[temp.x-1][temp.y] == 1){
                if(!flag){
                    ans++;
                    flag = true;
                }

                arr[temp.x-1][temp.y] = 2;

                temp.x--;
                Q.push(temp);

                temp.x++;
            }

            if(isValid(temp.x,temp.y+1) && arr[temp.x][temp.y+1] == 1){
                if(!flag){
                    ans++;
                    flag = true;
                }

                arr[temp.x][temp.y+1] = 2;

                temp.y++;
                Q.push(temp);

                temp.y--;

            }

            if(isValid(temp.x,temp.y-1) && arr[temp.x][temp.y-1] == 1){
                if(!flag){
                    ans++;
                    flag = true;
                }

                arr[temp.x][temp.y-1] = 2;

                temp.y--;
                Q.push(temp);

                temp.y++;

            }

            Q.pop();

        }

        Q.pop();

        if(!Q.empty()){
            temp.x = -1;
            temp.y = -1;
            Q.push(temp);
        }

    }

    return (checkall(arr)) ? -1 : ans;

}

int main()
{
    int arr[][C] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
    int ans = rotOranges(arr);
    if (ans == -1)
        cout << "All oranges cannot rot\n";
    else
         cout << "Time required for all oranges to rot => " << ans << endl;
    return 0;
}