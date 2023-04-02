#pragma once

class Datetime
{

private:

    short _day;
    short _month;
    short _year;

public:

    //  Get method of day
    const short get_day() const noexcept
    {
        return this->_day;
    }

    //  Set Method of day
    void set_day(const short& day)
    {
        //  Check sent day 
        if (day < 0 || day > 31)
        {
            throw exception("Day should be more than zero and less than 31!");
        }

        this->_day = day;
    }

    //  Get method of month
    const short get_month() const noexcept
    {
        return this->_month;
    }

    //  Set Method of month
    void set_month(const short month)
    {
        //  Check sent month 
        if (month < 0 || month > 12)
        {
            throw exception("Month should be more than zero and less than 12!");
        }

        this->_month = month;
    }

    //  Get method of year
    const short get_year() const noexcept
    {
        return this->_year;
    }

    //  Set Method of day
    void set_year(const short year)
    {
        //  Check sent year 
        if (year < 0 || year > 2023)
        {
            throw exception("Year should be more than zero and less than 2023!");
        }

        this->_year = year;
    }

    //  Constructor with parameters
    Datetime(const short day, const short month, const short year)
    {
        set_day(day);
        set_month(month);
        set_year(year);
    }

    //  Operator = 
    Datetime& operator = (const Datetime other)
    {
        this->_day = other._day;
        this->_month = other._month;
        this->_year = other._year;
    }

    //  Operator << 
    friend ostream& operator << (ostream& output, const Datetime& date)
    {
        output << "Day: " << date._day << endl
            << "Month: " << date._month << endl
            << "Year: " << date._year << endl;
    }

    //  Destructor
    ~Datetime() noexcept {};

};

//  Abstract class
class Penalty
{

private:

    static int _staticID;
    int* _ID;
    Datetime* _date;

protected:

    string* __name;
    double* __price;

public:

    //  Get method of ID
    const int* get_ID() const noexcept
    {
        return this->_ID;
    }

    //  Pure virtual method (Get method of name)
    virtual const string* get__name() const = 0 
    {
        return this->__name;
    }

    //  Get method of date
    const Datetime* get_date() const noexcept
    {
        return this->_date;
    }

    //  Pure virtual method (Get method of price)
    virtual const double* get__price() const = 0 
    {
        return this->__price;
    }

    //  Set method of date
    void set_date(const Datetime& other)
    {
        this->_date->set_day(other.get_day());
        this->_date->set_month(other.get_month());
        this->_date->set_year(other.get_year());
    }

    //  Constructor with parameters
    Penalty(const Datetime& date)
    {
        this->_ID = new int(++this->_staticID);
        set_date(date);
    }
    
    //  Show ID, Date
    void showSpecifications()
    {
        cout << *this->_ID << endl
            << *this->_date;
    }

    //  Destructor
    ~Penalty() noexcept
    {
        delete this->_ID;
        delete this->_date;
    }
};

int Penalty::_staticID = 0;