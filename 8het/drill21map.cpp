#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <numeric>

template<typename K, typename V>
void print(const std::map<K,V>& m) {
    //for(const auto& a : m )
    for(const std::pair<K,V>& a : m)
    {
        std::cout << a.first << "\t" << a.second << std::endl;
    }
}
void read_map(std::map<std::string,int>& m) {
    std::string s;
    int i=0;

    while(m.size()<10)
    {
        std::cin >> s >> i;
        //m[s] = i;
        m.insert(std::make_pair(s,i));
    }
}
//8 /std::accumulate utolso 2 
template<typename K, typename V>
void sum(const std::map<K,V>& m) {
    int sum=0;
    for(const std::pair<K,V>& a : m)
    {
        sum = a.second + sum;
    }
    std::cout << "Az eredmeny: " << sum << std::endl;
}

int main()
try {
    //1
    std::map<std::string, int> msi;
    

    //2
    msi["a"] = 42;
    msi["e"] = 21;
    msi["ughjk"] = 2;
    msi["key"] = 3;
    msi["ab"] = 17;
    msi["cd"] = 93;
    msi["po"] = 62;
    msi["tt"] = 37;
    msi["x"] = 11;
    msi["k"] = 34;
    //3
    print(msi);
    std::cout <<"Törlés után"<< std::endl;
    //4
    msi.erase("a");
    print(msi);
    msi.erase(msi.begin(), msi.end());
    std::cout << "Teljes törlés után" << std::endl;
    print(msi);
    //5-7
    std::cout << "Adjon meg 10 kulcs-érték párt" << std::endl;
    read_map(msi);
    print(msi);
    sum(msi);

    //9 
    std::map<int,std::string>mis;
    //10
    for(const auto& a : msi)
    {
        mis[a.second] = a.first;
        //m.insert(std::make_pair(a.second,a.first));
    }
    std::cout << "mis map: " << std::endl;
    print(mis);

}   catch (std::exception& e) {
    std::cerr << "Ecxeption: " << e.what() << "\n";
    return 1;
}   catch(...) {
    std::cerr << "Ecxeption: " << "\n";
    return 1;
}