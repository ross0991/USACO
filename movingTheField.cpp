#include <iostream>


using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second

const int INF = 1e9;


bool field[2001][2001];
int fi[2001][2001];

int main(){
        for(int i=0; i<2001; ++i){
                for(int j=0; j<2001; ++j){
                        field[i][j] = false;
                        fi[i][j] = -1;
                }
        }

        int n, x=1000, y=1000, dm, dt=0, ans = INF;
        char d;

        cin >> n;
        for(int i=0; i<n; ++i){
                cin >> d >> dm;

                dt+=dm;
                if(d == 'N'){
                        for(int i=0; i<dm; ++i){

                                if(field[x+i][y] == true){
                                        ans = min(ans, dt-(fi[x+i][y])+1);
                                }else{
                                        field[x+i][y] = true;
                                        fi[x+i][y] = dt;
                                }
                        }
                        x+=dm;
                }else if(d == 'S'){
                        for(int i=0; i<dm; ++i){
                                if(field[x-i][y] == true){
                                        ans = min(ans, dt-(fi[x-i][y])+1);
                                }else{
                                        field[x-i][y] = true;
                                        fi[x+i][y] = dt;
                                }
                        }
                        x-=dm;
                }else if(d == 'E'){
                        for(int i=0; i<dm; ++i){
                                if(field[x][y+i] == true)
                                {
                                        ans = min(ans, dt-(fi[x][y+i])+1);
                                }else{
                                        field[x][y+i] = true;
                                        fi[x][y+i] = dt;
                                }
                        }
                        y+=dm;
                }else if(d == 'W'){
                        for(int i=0; i<dm; i++){
                                if(field[x][y-i] == true){
                                        ans = min(ans, dt-(fi[x][y-i])+1);
                                }else{
                                        field[x][y-i] = true;
                                        fi[x][y-i] = dt;
                                }
                        }
                        y-=dm;
                }


        }
        cout << ans;

        return 0;
}


