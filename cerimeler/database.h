#pragma once

class Database
{

private:

	map<string, list<Penalty>> _totalPenalties;
	map<string, double> _totalPrices;

public:

	//	Get method of penalties
	const map<string, list<Penalty>>& get_totalPenalties() const
	{
		return this->_totalPenalties;
	}
	
	//	Set method of totalPenalties
	void set_totalPenalties(const map<string, list<Penalty>>& totalPenalties)
	{
		//	Check is not empty
		if (!this->_totalPenalties.empty())
		{
			this->_totalPenalties.clear();
		}

		//	Add elements
		for (auto& totalPenalty : totalPenalties)
		{
			string carNumber = totalPenalty.first;
			list<Penalty> penalties;
			for (auto& penalty : totalPenalty.second)
			{
				penalties.push_back(penalty);
			}
			this->_totalPenalties.insert({ carNumber, penalties });
		}
	}

	//	Show penalties
	void showTotalPenalties()
	{
		for (auto& totalPenalty : this->_totalPenalties)
		{
			double totalPrice = 0;
			cout << totalPenalty.first << ": [ ";
			for (auto& penalty : totalPenalty.second)
			{
				cout << *penalty.get__name() << ", ";
				totalPrice += *penalty.get__price();
			}
			cout << "] - "<<totalPrice<<" AZN\n";
		}
	}
};