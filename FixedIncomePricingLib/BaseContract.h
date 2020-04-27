//
//  BaseContract.h
//  AdvCMidTerm
//
//  Created by YinManlin on 2020/4/23.
//  Copyright © 2020 YinManlin. All rights reserved.
//

#ifndef BaseContract_h
#define BaseContract_h

#include <iostream>
#include <cmath>

class BaseContract{
public:
    virtual std::string name() const = 0;
    virtual double Price(OIS&, LIBOR&){ return 0.0;}
};

#endif /* BaseContract_h */
