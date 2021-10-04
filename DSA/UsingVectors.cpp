#include<iostream>
#include<vector>

using namespace std;

int main() {

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator it;
    for(it=v.begin(); it!=v.end(); it++) {
        cout<<*it<<endl;
    }

    for(auto element:v) {
        cout<<element<<endl;
    }

    v.pop_back(); // 1 2

    vector<int> v2(3,40); // 40 40 40

    swap(v,v2);

    for(auto element:v) {
        cout<<element<<endl;
    }


    return 0;
}