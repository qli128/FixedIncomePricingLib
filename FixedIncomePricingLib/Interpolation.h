//
//  Interpolation.h
//  AdvCMidTerm
//
//  Created by YinManlin on 2020/4/15.
//  Copyright © 2020 YinManlin. All rights reserved.
//

#ifndef Interpolation_h
#define Interpolation_h

#include <vector>
#include <string>
#include <algorithm>
#include "DateUtil.h"


double interpolation(const boost::gregorian::date &dt, std::vector<std::tuple<boost::gregorian::date, double, double>> &curve, const std::string &method);



double interpolation(const boost::gregorian::date &dt, std::vector<std::tuple<boost::gregorian::date, double>> &curve, const std::string &method);


#endif /* Interpolation_h */
