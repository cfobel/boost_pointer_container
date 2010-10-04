#include <iostream>
#include <boost/ptr_container/ptr_vector.hpp> 
#include <boost/foreach.hpp>
#include "xrange.hpp"

using namespace std;

int main() 
{ 
    boost::ptr_vector<int> v; 
    v.push_back(new int(1)); 
    v.push_back(new int(2)); 

    std::auto_ptr<int> i;

    BOOST_FOREACH(int w, xrange(1, 11)) {
        i = std::auto_ptr<int>(new int(10 * w));
        v.push_back(i);
    }

    BOOST_FOREACH(int w, v) {
        cout << w << endl;
    }

    return 0;
} 
