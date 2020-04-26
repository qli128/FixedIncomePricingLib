//
//  DateUtil.cpp
//  AdvCMidTerm
//
//  Created by YinManlin on 2020/3/28.
//  Copyright © 2020 YinManlin. All rights reserved.
//


#include "DateUtil.h"


// different day count conventions
double durationWDaycount(const boost::gregorian::date &d1, const boost::gregorian::date &d2, const std::string &str)
{
    if (str == "ACT/360")
    {
        return (d2-d1).days()/360.0;
    }else if (str == "30I/360")
    {
        return ((d2.year()-d1.year())*360+(d2.month()-d1.month())*30+(d2.day()-d1.day()))/360.0;
    }else if (str == "ACT/365"){
        return (d2-d1).days()/365.0;
    }else
    {
        // by default is ACT/360
        return (d2-d1).days()/360.0;
    }
}


boost::gregorian::date returnWeekday(const boost::gregorian::date &d)
{
    if (d.day_of_week() == boost::date_time::Saturday)
    {
        return d + boost::gregorian::days(2);
    }else if (d.day_of_week() == boost::date_time::Sunday)
    {
        return d + boost::gregorian::days(1);
    }else{
        return d;
    }
}


// note here the paymentDates are in REVERSE order!!!!!
// note cannot match with bloomberg
// eg 2025, 4, 15 as maturity, 2020, 4, 15 as start
// cash flow day count convention???
std::vector<boost::gregorian::date> paymentDates(const boost::gregorian::date &start, const boost::gregorian::date &maturity, const int &payFreq)
{
    std::vector<boost::gregorian::date> payDates;
    // if payFreq is 0
    // not swap rate, just interest rate
    if (payFreq == 0)
    {
        payDates.push_back(maturity);
        payDates.push_back(start);
        return payDates;
    }else
    {
        int interval = 12 / payFreq;
        payDates.push_back(maturity);
        
        if (maturity - boost::gregorian::months(interval) > start + boost::gregorian::days(7))
        {
            // here not sure day count convention
            for (boost::gregorian::date i = maturity - boost::gregorian::months(interval); i > start + boost::gregorian::months(interval) - boost::gregorian::days((interval*30/6)); i = i - boost::gregorian::months(interval))
            {
                // check whether i is weekday or not
                i = returnWeekday(i);
                payDates.push_back(i);
            }
        }
        payDates.push_back(start);
        return payDates;
    }
}

/*
// takes in format mmddyyyy with specified delimiter
Date::Date(std::string str, char split_char)
{
    std::istringstream split(str);
    std::vector<int> tokens;
    std::string substr;
    while (std::getline(split, substr, split_char)){
        tokens.push_back(std::stoi(substr));
    }
                         assert(tokens.size() == 3);
    month = tokens[0];
    day = tokens[1];
    year = tokens[2];
}

// ref: http://www.cs.utsa.edu/~cs1063/projects/Spring2011/Project1/jdn-explanation.html
int Date::toJulian()
{
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    return day + static_cast<int>((153*m+2)/5) + 365*y + static_cast<int>(y/4) - static_cast<int>(y/100) + static_cast<int>(y/400) - 32045;
}

// overload << operator
std::ostream& operator<<(std::ostream& os, Date& t)
{
    os << t.month << "/" << t.day << "/" << t.year << "\n" ;
    return os;
}

// different day count conventions
double Date::dayCount(Date &d1, Date &d2, std::string str){
    if (str == "ACT/360"){
        return (d1-d2)/360.0;
    }else if (str == "30/360"){
        return ((d2.year-d1.year)*360+(d2.month-d1.month)*30+(d2.day-d1.day))/360.0;
    }else if (str == "ACT/365"){
        return (d1-d2)/365.0;
    }else {
        // act/360 
        return (d1-d2)/360.0;
    }
}

// input a date, if the date is weekend or holiday then return the next weekday
Date Date::returnWeekday(const Date &d){
    // to be implemented, exclude holiday and weekends
    // return next business day
    return d;
}


std::vector<Date> paymentDates(const Date& start, const Date &maturity, const int &payFreq){
    
}
*/
