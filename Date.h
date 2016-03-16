#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#include <iostream>

namespace sict
{
    class Date
    {
    private:
        int value()const;
        void errCode(int errorCode);
        
        int year_; //Holds the year; a four digit integer between MIN_YEAR and MAX_YEAR, defined in “general.h”
        int mon_; //Month of the year, between 1 to 12
        int day_; //Day of the month, note that in a leap year February is 29 days, (see mday() member function)
        int readErrorCode_;
        
    public:
        int mdays()const;
        
        Date();
        Date(int, int, int);

        
        bool operator==(const Date& D)const;//left current object
        bool operator!=(const Date& D)const;
        bool operator<(const Date& D)const;
        bool operator>(const Date& D)const;
        bool operator<=(const Date& D)const;
        bool operator>=(const Date& D)const;
        
        int errCode()const; //Returns the readErrorCode_ value
        bool bad()const; //Returns true if readErrorCode_ is not equal to zero
        
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr)const;
        
    };
    std::istream& operator>>(std::istream& istr, Date &something);
    std::ostream& operator<<(std::ostream& ostr, Date &something);
    

}

#endif