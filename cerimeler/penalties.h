#pragma once

//	Qirmizi ishiq
class RedLight final : public Penalty
{

public:

	//	Constructor with parameters
	RedLight(const Datetime& date) : Penalty(date)
	{
		this->__name = new string("Red light");
		this->__price = new double(60);
	}

	//  Pure virtual method (Get method of price)
	const string* get__name() const override
	{
		Penalty::get__name();
	}

	//  Pure virtual method (Get method of price)
	const double* get__price() const override
	{
		Penalty::get__price();
	}

	//	operator <<
	friend ostream& operator << (ostream& output, RedLight& penalty)
	{
		penalty.showSpecifications();
		cout <<"Name: "<< *penalty.__name << endl;
		cout <<"Price: "<< *penalty.__price << endl;
	}

	//	Destructor
	~RedLight()
	{
		delete this->__name;
		delete this->__price;
	}
};

//	Qosha xett
class DoubleLine final : public Penalty
{

public:

	//	Constructor with parameters
	DoubleLine(const Datetime& date) : Penalty(date)
	{
		this->__name = new string("Double line");
		this->__price = new double(100);
	}

	//	operator <<
	friend ostream& operator << (ostream& output, DoubleLine& penalty)
	{
		penalty.showSpecifications();
		cout << "Name: " << *penalty.__name << endl;
		cout << "Price: " << *penalty.__price << endl;
	}

	//  Pure virtual method (Get method of price)
	const string* get__name() const override
	{
		Penalty::get__name();
	}

	//  Pure virtual method (Get method of price)
	const double* get__price() const override
	{
		Penalty::get__price();
	}

	//	Destructor
	~DoubleLine()
	{
		delete this->__name;
		delete this->__price;
	}
};

//	Parking
class Parking final : public Penalty
{

public:

	//	Constructor with parameters
	Parking(const Datetime& date) : Penalty(date)
	{
		this->__name = new string("Parking");
		this->__price = new double(40);
	}

	//  Pure virtual method (Get method of name)
	const string* get__name() const override
	{
		Penalty::get__name();
	}

	//  Pure virtual method (Get method of price)
	const double* get__price() const override
	{
		Penalty::get__price();
	}

	//	Destructor
	~Parking()
	{
		delete this->__name;
		delete this->__price;
	}
};