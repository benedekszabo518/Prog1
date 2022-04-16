#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>
int main () {
    
    std::vector<double> vd;
    
    std::ifstream bemenet;
    bemenet.open("vector.txt");
    double x=0.0;
    for(int i=0; i<16; i++)
    {
        bemenet >> x;
        vd.push_back(x);
        
    }
    bemenet.close();
    for(int i = 0; i<16; i++){
        std::cout << vd[i] << std::endl;
    }

    std::vector<int> vi (vd.size());
    std::copy(vd.begin(),vd.end(),vi.begin());

    for(int i = 0; i<vd.size(); i++){
        std::cout << vd[i] << "\t" << vi[i] <<  std::endl;
    }

    double d_sum = std::accumulate(vd.begin(), vd.end(), 0.0);
    std::cout << "Sum of vector<double> : " << d_sum << std:: endl;

    double i_sum = std::accumulate(vi.begin(), vi.end(), 0.0);
    std::cout << "Sum of vector<int> : " << i_sum << std::endl;

    /*double diff_sum = std::inner_product(vd.begin(), vd.end(),
                vi.begin(),vi.end(), 
                0.0, 
                std::plus<double>(), 
                std::minus<double>());
    std::cout << "diff: " << d_sum-i_sum << " " << diff_sum << std::endl;*/
    std::cout << "diff: " << d_sum-i_sum << std::endl;

    std::reverse(vd.begin(), vd.end());
    for(int i = 0; i<16; i++){
        std::cout << vd[i] << std::endl;
    }

    double vd_mean = d_sum / vd.size();
    std::cout << "Mean Value: " << vd_mean << std::endl;
//van copy_if
    std::vector<double> vd2 (vd.size());
    for(int i = 0; i<16; i++){
        if(vd[i] < vd_mean)
        vd2.push_back(vd[i]);
    }
    for(int i=0; vd2[i] > 0; i++){
        std::cout << vd2[i] << std::endl;
    }



}