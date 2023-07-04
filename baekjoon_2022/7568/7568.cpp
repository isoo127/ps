#include <iostream>
#include <vector>
using namespace std;

class Person {
private:
    int weight;
    int height;
    int rank = 1;
    Person();
public:
    inline Person(int weight, int height) {
        this->weight = weight; this->height = height;
    }

    inline bool operator> (const Person p) const {
        if(this->weight > p.weight && this->height > p.height)
            return true;
        else
            return false;
    }

    inline void addRank() { this->rank++; }

    inline int getRank() { return this->rank; }
};

int main() {
    int N;
    cin >> N;

    vector<Person> vp;
    for(int i = 0; i < N; i++) {
        int w, h;
        cin >> w >> h;
        Person p(w, h);
        for(int j = 0; j < vp.size(); j++) {
            if(p > vp.at(j)) vp.at(j).addRank();
            else if(vp.at(j) > p) p.addRank();
        }
        vp.push_back(p);
    }

    for(int i = 0; i < N; i++) {
        cout << vp.at(i).getRank() << " ";
    }
    
    return 0;
}