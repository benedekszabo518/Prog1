#include <iostream>
#include <vector>

using namespace std;

class Person {
    public: 
            Person(){}
            Person(string first_name, string second_name, int a) : first_name{first_name}, second_name{second_name}, a{a}{
                int aa = a;
                if(a<0 || a>= 150){
                    throw runtime_error("Invalid age in Person");
                }
                string fullname = first_name + second_name;
                for(char c: fullname) {
                    switch(c) {
                        case ';': case ':': case '"':
                        case '[': case ']': case '*':
                        case '&': case '^': case '%':
                        case '$': case '#': case '@':
                        case '!':
                            throw runtime_error("Person(): bad char in names");
                            break;
                        default : break;
                    }
                }
            };
            string first() const{return first_name;}
            string second() const{return second_name;}
            int age() const{return a;}
            
    private:
            string first_name;
            string second_name;
            int a;
};
ostream& operator <<(ostream& os, const Person& p)
{
    return os <<p.first() << " " << p.second() << " " << p.age();
}
istream& operator >>(istream& is, Person& p)
{
    string n1;
    string n2;
    int a;

    is >> n1 >> n2 >> a;
    p=Person(n1,n2,a);

    return is;
}

int main () 
{
    Person p = Person("Goofy","Smol",63);

    //cout << p.name << " " << p.age << endl;
    cout << p << endl;
    Person p2;
    cin >> p2;

    cout << p2 << endl;

    vector<Person> vec;
    for(Person p; cin >> p;)
    {
        if(p.first()=="end" || p.second()=="end") break;
        vec.push_back(p);
    }
    for(Person P: vec)
        cout << p << endl;
}