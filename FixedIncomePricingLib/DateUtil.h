//
//  DateUtil.h
//  AdvCMidTerm
//
//  Created by YinManlin on 2020/3/28.
//  Copyright © 2020 YinManlin. All rights reserved.
//


#ifndef DateUtil_h
#define DateUtil_h

#include <string>
#include <vector>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time.hpp>

// returns d2 - d1 in years ( in decimals )
double durationWDaycount(const boost::gregorian::date &d1, const boost::gregorian::date &d2, const std::string &str);

// if passed in date is not weekday return the next weekday
boost::gregorian::date returnWeekday(const boost::gregorian::date &d);

// return a vector of payment dates
std::vector<boost::gregorian::date> paymentDates(const boost::gregorian::date &, const boost::gregorian::date &, const int &);




/*
class Date{
private:
    int day, month, year;
public:
    Date(std::string, char);
    // Date + -
    int toJulian();
    
    //operator overload
    friend int operator - (Date &d1, Date &d2)
    {
        // return days difference between two dates
        // note here: end date is not included
        
        // first convert both days to julian day number
        return d1.toJulian() - d2.toJulian();
    }
    
    friend std::ostream& operator<<(std::ostream& os, Date& t);
    
    friend bool operator == (const Date &d1, const Date &d2){
        return (d1.day == d2.day) && (d1.month == d2.month) && (d1.year == d2.year);
    }
    
    // counting and stuff
    double dayCount(Date &d1, Date &d2, std::string);
    
    Date returnWeekday(const Date &);
    
    std::vector<Date> paymentDates(const Date&, const Date&, const int&);
    
    
    
};
*/

#endif /* DateUtil_h */
