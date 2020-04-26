//
//  European_Swaption.cpp
//  AdvCMidTerm
//
//  Created by YinManlin on 2020/4/25.
//  Copyright © 2020 YinManlin. All rights reserved.
//

#include "European_Swaption.h"

Euro_Swaption::Euro_Swaption() {
    valuation_date = boost::gregorian::day_clock::universal_day();
    effective_date = boost::gregorian::day_clock::universal_day();
    T = boost::gregorian::day_clock::universal_day();
    SwapRate = 0.0;
    StrikeRate = 0.0;
    Vol = 0.0;
    dayCount = "ACT/365";
    tenor = 3.0;
    Method = "linear";
    SwaptionType = "call";
}

Euro_Swaption::Euro_Swaption(boost::gregorian::date v,
                             boost::gregorian::date e,
                             boost::gregorian::date t,
                             double Tenor,
                             double pct,
                             std::string method,
                             double k,
                             double vol,
                             std::string day_count_basis,
                             std::string type) : Swap(v, e, t, Tenor, pct, method)
{
    
    StrikeRate = k;
    SwaptionType = type;
    Vol = vol;
    dayCount = day_count_basis;
    
}

//Setters
//Oeverride---------------------------------------------------------------
void Euro_Swaption::SetValuation_date(boost::gregorian::date v) {
    valuation_date = v;
}
void Euro_Swaption::SetEffective_date(boost::gregorian::date e) {
    effective_date = e;
}
void Euro_Swaption::SetT(boost::gregorian::date t) {
    T = t;
}

//Unique---------------------------------------------------------------------------------
void Euro_Swaption::SetStrikeRate(double k){ StrikeRate = k; }
void Euro_Swaption::SetVol(double vol) { Vol = vol; }
void Euro_Swaption::SetDayCount(std::string dayCountBASIS) {
    dayCount = dayCountBASIS;
}

double Euro_Swaption::Price(OIS& Ois, LIBOR& Libor)
{
    double fwdSwapRate = FixedRate(Ois, Libor);
    double price = 0.0;
    double discount = Ois.DF(effective_date, Method);
    
    BlackModel bm(valuation_date, effective_date, discount, fwdSwapRate, StrikeRate, Vol, SwaptionType, Method, dayCount);
    bm.setDF(discount);
    double optionPrice = bm.OptionPrice();
    for (size_t i = 0; i < PaymentDate.size();++i)
    {
        double df = Ois.DF(PaymentDate[i], Method);
        price += tenor/12.0*df*optionPrice;
    }
    return price;
}

