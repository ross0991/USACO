#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){

        ifstream fin("cowqueue.in");
        ofstream fout("cowqueue.out");

        int n;
        fin >> n;

        int t=0, c, tl;

        vector<pair<int, int>> v;

        for(int i=0; i<n; ++i){
                fin >> c >> tl;

                pair<int, int> p;
                p.first = c;
                p.second = tl;
                v.push_back(p);
        }

        sort(v.begin(), v.end());
        for(int i=0; i<n; ++i){
                c = v[i].first;
                tl = v[i].second;

                if(t < c){
                        t+= c - t;
                        t+= tl;
                }else t+= tl;
        }
        fout << t;
        return 0;
}
