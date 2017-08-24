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
    //Preconditions
    if (n<p)
        return;//throw?
    ///////////

    //Initialization
    std::vector<int> vec;    

    for (int i=0; i<p ;++i)
        vec.push_back(i);//First possible combination for all cases
    ///////////////

    //processamento    
    for (int i = 0;i< num(n,p); ++i)
    {
        std::cout << std::setw(5) << (i+1) << "- "; 
        show(vec, set);//Displays the combination
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
    // or
    //std::vector<std::string>
    //combinacao<std::string>(set, set.size(), 3);

    return 0;
}
