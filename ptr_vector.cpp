#include <iostream>
#include <boost/ptr_container/ptr_vector.hpp> 
#include <boost/foreach.hpp>
#include "xrange.hpp"

using namespace std;

int main() 
{ 
    typedef boost::ptr_vector<int> ptr_vec;
    ptr_vec v; 

    v.push_back(new int(1)); 
    v.push_back(new int(2)); 

    std::auto_ptr<int> w;

    BOOST_FOREACH(int i, xrange(1, 11)) {
        w = std::auto_ptr<int>(new int(10 * i));
        v.push_back(w);
    }

    /* Modify values in ptr_vec in-place */
    BOOST_FOREACH(int &i, v) {
        cout << i << endl;
        i *= 2;
    }

    BOOST_FOREACH(int i, xrange(v.size())) {
        cout << "[" << i << "]: " << v[i] << endl;
    }

    return 0;
} 
