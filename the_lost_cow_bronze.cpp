#include <iostream>

using namespace std;

int main(){
        int x, y;
        cin >> x >> y;
        if(x == y){
                cout << 0;
                return 0;
        }

        int d=0, m=1, cx=x;
        if(x < y){
                while(cx < y){
                        d+=abs(x+m-cx);
                        cx += x+m-cx;
                        m*=-2;
                }
        }else{
                while(cx > y){
                        d+=abs(cx-(x+m));
                        cx += x + m - cx;
                        m*=-2;
                }
        }

        cout << d - abs(cx -y);

        return 0;
}
