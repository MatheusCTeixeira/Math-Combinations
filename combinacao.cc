#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

int fat(int n)
{
    int result = 1;
    while (n>1)    
        result *= n--;       
    return result;
}

int num(int n, int p)
{
    return static_cast<int>(fat(n)/(fat(p)*fat(n-p)));
}

template <typename T>
void show(const std::vector<int>& v, const T& set)
{
    for (int i=0;i<v.size(); ++i)
        std::cout << set[v[i]] << " ";
    std::cout << std::endl;
}

template <typename T>
void combinacao(const T& set, int n, int p)
{
    //pré-condições
    if (n<p)
        return;//throw?
    ///////////

    //inicialização
    std::vector<int> vec;    

    for (int i=0; i<p ;++i)
        vec.push_back(i);//primeira combinação possível para todos os casos
    ///////////////

    //processamento    
    for (int i = 0;i< num(n,p); ++i)
    {
        std::cout << std::setw(5) << (i+1) << "- "; 
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
    //////////////////
}

int main()
{
    std::vector<std::string> set{std::string{"A"},std::string{"B"},std::string{"C"},std::string{"D"},std::string{"E"}};    
    combinacao<std::vector<std::string>>(set, set.size(), 3);

    return 0;
}