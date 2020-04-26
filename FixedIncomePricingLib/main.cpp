//
//  main.cpp
//  AdvCMidTerm
//
//  Created by YinManlin on 2020/3/24.
//  Copyright © 2020 YinManlin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "LIBOR.h"
#include "CapFloor.h"
#include "European_Swaption.h"


int main() {
    
    

    // 1 libor curve not accurate need convexity adjustment
    // 2 libor curve not stable              *done problem is with PaymentDate function
    // 3 european swaption price not okay    *done
    // 4 black implied vol
    // 5 check pricing is correct or not 
    
    // 整体定价思路 structure
    // yield curve, ois comparison
    // black implied vol SABR vol surface cube
    // swap/tion
    // cap
    // further improvement SABR(vol) LMM(interest model simulate for pricing exotic products) Portfolio, record holding,
    // risk management system calculate portoflio greeks VaR
    

    boost::gregorian::date today{2020,4,26};
    OIS ois(today, "OIS.csv");
    LIBOR l(today, 3, "LIBOR.csv", ois);

    
    std::cout << "zero \n";
    for (auto & e : ois.curve)
    {
        std::cout << std::get<1>(e) << "\n";
    }
    
    std::cout << "\n";
    std::cout << "zero df \n";
    for (auto & e : ois.curve)
    {
        std::cout << std::get<2>(e) << "\n";
    }
    
    std::cout << "\n";
    std::cout << "libor fwd \n";
    for (auto & e : l.curve)
    {
        std::cout << std::get<1>(e) << "\n";
    }
    
    std::cout << "\n";
    
    

    /*
    double StrikeRate = 0.002;
    double vol = 0.4;
    double freq = 3;
    std::string cap_or_floor = "Cap";
    std::string basis = "ACT/360";
    
    boost::gregorian::date valuation_date(2020, 4, 19);
    boost::gregorian::date effective_date(2021, 4, 19);
    boost::gregorian::date Maturity(2025, 4, 19);
    
    
    std::string type ="call";
    std::string method ="linear";
    

    std::cout << "zero \n";
    for (auto & e : ois.curve)
    {
        std::cout << std::get<2>(e) << " ";
    }
    
    std::cout << "\n";
    
    
    
    CapFloor Cap1(today, effective_date, Maturity, StrikeRate, vol, freq, cap_or_floor, basis, "linear");
    std:: cout << "cap price: " << Cap1.Price(ois, l) << "\n";
    
    
    for (auto & e : l.curve)
    {
        std::cout << std::get<0>(e) << " " <<  std::get<1>(e) << " ";
    }
    
    std:: cout << "\n";
    
    
    Swap s(today, effective_date, Maturity, freq, 0.0 , "linear");
    std:: cout << s.FixedRate(ois, l)<< "\n";
    
    Euro_Swaption so(today,
                  effective_date,
                  Maturity,
                  freq,
                  0.0,
                  "linear",
                  StrikeRate,
                  vol,
                  basis,
                  "put");
   
    std:: cout << so.Price(ois, l)<< "\n";
    */

   
  
    return 0;
}
