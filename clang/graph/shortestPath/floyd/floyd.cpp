#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int direction[5][5];

void print(){
    cout << "\n";
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << direction[i][j] << " ";
        }
        cout << "\n";
    }
}

void fillInf(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(i==j) continue;
            direction[i][j] = 99999999;
        }
    }
}

void floyd(){
    for(int via=0; via<5; via++){
        for(int from=0; from<5; from++){
            for(int to=0; to<5; to++){
                if(via==from || via==to || from==to) continue;
                if(direction[from][to] > direction[from][via] + direction[via][to]){
                    direction[from][to] = direction[from][via] + direction[via][to];
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fillInf();

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> direction[i][j];
        }
    }
    
    floyd();
    print();
    
    return 0;
}

