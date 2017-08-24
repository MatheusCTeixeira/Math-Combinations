#include <iostream>
#include <string>
#include <vector>


template <typename T>
void show(const std::vector<int>& v, const T& set)
{
    for (int i=0;i<v.size(); ++i)
        std::cout << set[v[i]] << " ";
    std::cout << "\n";
}

template <typename T>
void combinacao(const T& set, int n, int p)
{ 
    std::vector<int> vec;    
    for (int i=0; i<p ;++i)
        vec.push_back(i);//primeira combinação possível para todos os casos  
    
    while (true)
    {                
        show(vec, set);//exibe a combinação
        vec.back()++;
        while ((vec.back()+(p-vec.size())) >= n)
        {
            vec.pop_back();
            if (vec.empty())
                return;
            vec.back()++;
        }     
        while (vec.size() < p)
            vec.push_back(vec.back() + 1);
    }
}

int main()
{
    std::string set{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};    
    combinacao<std::string>(set, set.size(), 6);
    return 0;
}
