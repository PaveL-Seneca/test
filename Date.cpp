#include <iomanip>
#include <iostream>
#include "Date.h"
#include "general.h"
using namespace std;


namespace sict
{
    int Date::value()const
    {
        return year_ * 372 + mon_ * 31 + day_;
    }
    
    int Date::mdays()const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
        mon--;
        return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
    }
    
    Date::Date(){
        day_ = 0;
        mon_ = 0;
        year_ = 0;
        readErrorCode_ = 0;
    }
    
    Date::Date(int x, int y, int z){
        day_ = x;
        mon_ = y;
        year_ = z;
        readErrorCode_ = 0;
    }
    
    bool Date::operator==(const Date& D) const{
       return ((year_ == D.year_) && (mon_ == D.mon_) && (day_ == D.day_) && (readErrorCode_ == D.readErrorCode_));
    }
    
    bool Date::operator!=(const Date& D) const{
        return !(*this == D);
    }
    
    bool Date::operator<(const Date& D) const{
        return (*this < D);
    }
    bool Date::operator>(const Date& D) const{
        return (*this > D);
    }
    bool Date::operator<=(const Date& D)const{
        return (*this <= D);
    }
    bool Date::operator>=(const Date& D)const{
        return (*this >= D);
    }
    std::ostream& Date::write(std::ostream& ostr)const
    {
        return ostr << year_ << "/" << mon_ << "/" << day_;
    }
    std::istream& Date::read(std::istream& istr)
    {
        istr >> year_ >> mon_  >>day_;
        if (istr.fail())
        {
            readErrorCode_ = 1;
            this ->mdays();
        }
        return istr;
    }
    std::ostream& operator<<(std::ostream& ostr, Date &something)
    {
        return something.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, Date &something)
    {
        return something.read(istr);
    }
    bool Date::bad()const
    {
        if (readErrorCode_ != 0) {
            return true;
        }
        else
            return false;

    }
    int Date::errCode()const
    {
        return readErrorCode_;
    }
   
}