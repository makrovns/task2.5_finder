#pragma once
#include <vector>
#include <string>
#include <utility>


template<class T, class U> using my_pair_vector = std::vector<std::pair<T, U>>;

namespace myfind
{
    template<typename T, typename U>
    auto find_key(my_pair_vector<T,U>& vec, const T& key);
}

template<typename T, typename U> auto myfind::find_key(my_pair_vector<T,U>& vec, const T& key)
{
    auto it = std::lower_bound(vec.begin(), vec.end(), key, [](const std::pair<T, U>& pair, const T& key)
        {
            return pair.first < key;
        });
 
    return it != vec.end() ? (it->first == key ? it : vec.end()) : vec.end();
}