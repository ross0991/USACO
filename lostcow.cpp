#include <iostream>
#include <fstream>

using namespace std;
int main(){
        ifstream fin("lostcow.in");
        ofstream fout("lostcow.out");

        int x, y;
        fin >> x >> y;

        if(x == y){
                fout << 0;
                return 0;
        }


        int c=x, m=1, d=0;

        if(x < y){
                while(c < y){
                        d+=abs(x+m-c);
                        c+=x+m-c;
                        m*=-2;
                }
        }
        else{
                while(c  > y){
                        d+=abs(x+m-c);
                        c+=x+m-c;
                        m*=-2;

                }
        }

        fout << d-(abs(c-y));
        return 0;
}
