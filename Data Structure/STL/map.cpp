//
// Created by hp on 2/9/2021.
//

template
struct DisableCompare : public std::binary_function
{
    bool operator()(T lhs, T rhs) const
    {
        if (lhs == rhs)
            return false;
        return true;
    }
};


int _tmain(int argc, _TCHAR* argv[])
{
    std::map> map1;
    map1.insert(std::make_pair(1, 3));
    map1.insert(std::make_pair(5, 3));
    map1.insert(std::make_pair(2, 3));
    map1.insert(std::make_pair(6, 3));
    map1.insert(std::make_pair(4, 3));

    auto it = map1.begin();
    for (; it != map1.end(); it++)
    {
        std::cout << it->first << std::endl;
    }

    return 0;
}