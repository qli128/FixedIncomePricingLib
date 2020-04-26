//
//  IDiscount.h
//  AdvCMidTerm
//
//  Created by YinManlin on 2020/3/24.
//  Copyright © 2020 YinManlin. All rights reserved.
//

#ifndef IDiscount_h
#define IDiscount_h
#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>

class IDiscount{
public:
    IDiscount();
    // discount factor starts from 0
    virtual double DF(const boost::gregorian::date &T, const std::string &) = 0;
};

#endif /* IDiscount_h */
