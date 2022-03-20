#include <iostream>
#include <vector>

using namespace std;

class Person {
    public: 
            Person(){}
            Person(string n, int a) : n{n}, a{a}{
                if(a<0 || 0>= 150){
                    throw runtime_error("Invalid age in Person");
                }
            /*string chara = ";:'[]*&^%$#@!";
            for(int i=0; n.size(); ++i)
                for(int j=0; chara.size(); ++j)
                    if(n[i]==chara[j])
                            throw runtime_error("Invalid name in Person");
            */
            };
            string name() const{return n;}
            int age() const{return a;}
    private:
            string n;
            int a;
}
ostream& operator <<(ostream& os, const Person& p)
{
    return os <<p.name() << " " << p.age();
}
istream& operator >>(istream& is, Person& p)
{
    string n;
    int a;

    is >> n >> a;
    p=Person(n,a);

    return is;
}

int main () 
{
    Person p = Person("Goofy",63);

    //cout << p.name << " " << p.age << endl;
    cout << p << endl;
    Person p2;
    cin >> p2;

    cout << p2 << endl;

    vector<Person> vec;
    for(Person p; cin >> p;)
    {
        if(p.name()=="end") break;
        vec.push_back(p);
    }
    for(Person P: vec)
        cout << p << endl;
}