////////////////////////////////////////////////////////////////////////
//  profile.cpp
//
//  Created by Jonathan Maletic.
//  Copyright 2022 Kent State University. All rights reserved.
//  Spring  2022
//  Modified by:
//

#include "profile.hpp"

////////////////////////////////////////////////////////////////////////
// Prints out the profile.
// 
// TODO: Very simple, need to make it into columns with nice headings
// 
std::ostream& operator<< (std::ostream& out, const profile& p) {
    
    out << "File: " << p.filename << std::endl;
    for(std::map<std::string, int>::const_iterator i = p.stmt.begin(); i != p.stmt.end(); ++i) {
        out << i->first << " " << i->second << std::endl;        
    }
    return out;
}



////////////////////////////////////////////////////////// 
// REQUIRES:  n >= 0
// ENSURES: Returns a text version of a positive integer long
std::string intToString(long n) {
    assert(n >= 0);
    std::string result;
    
    if (n == 0) return "0";
    while (n > 0) {
        result = char(int('0') + (n % 10)) + result;
        n = n / 10;
    }  
    return result;
}
