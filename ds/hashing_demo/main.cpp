/*
 * main.cpp
 *
 *  Created on: 11-Oct-2019
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<vector>
#include<list>
#include<string>

class account
{
private:
	int account_number;
	string account_type;
	float balance;
public:
	account(int account_number=0, string account_type=" ", float balance=0.0)
	{
		this->account_number = account_number;
		this->account_type = account_type;
		this->balance = balance;
	}
	//getter functions

	//setter function

	bool operator==(account& other)
	{
		return ( this->account_number == other.account_number );
	}

	friend ostream& operator<<( ostream& out, account& other )
	{
		out << setw(10) << left << other.account_number;
		out << setw(10) << left << other.account_type;
		out << setw(10) << left << other.balance;
		return out;
	}

	int hash_code(void)
	{
		int result = 1;
		int prime = 31;
		result = prime + result * this->account_number;

		return result;
	}
};


class customer
{
private:
	string name;
	string address;
	string contact_number;
public:
	customer(string name=" ", string address=" ", string contact_number=" ")
	{
		this->name = name;
		this->address = address;
		this->contact_number = contact_number;
	}

	//getter functions

	//setter functions

	friend ostream& operator<<( ostream& out, customer& other )
	{
		out << setw(15) << left << other.name;
		out << setw(15) << left << other.address;
		out << setw(12) << left << other.contact_number;
		return out;
	}
};

class dictionary_entry
{
private:
	account key;
	customer value;
public:
	dictionary_entry()
	{ }

	dictionary_entry(account key)
	{
		this->key = key;
	}

	dictionary_entry(account key, customer value)
	{
		this->key = key;
		this->value = value;
	}

	friend ostream& operator<<(ostream& out, dictionary_entry& other)
	{
		out << other.key << other.value;
		return out;
	}
};

class hash_table
{
	int capacity;
	vector< list<dictionary_entry> > arr;
public:
	hash_table(void)
	{
		this->capacity = 5;

		list<dictionary_entry> empty_list;
		//add capacity no. of empty lists into the vector
		for( int i = 0 ; this->capacity ; i++ )
		{
			this->arr.push_back(empty_list);
		}
	}

	hash_table(int capacity)
	{
		this->capacity = capacity;

		list<dictionary_entry> empty_list;
		//add capacity no. of empty lists into the vector
		for( int i = 0 ; i < this->capacity ; i++ )
		{
			this->arr.push_back(empty_list);
		}
	}

	void put(account key, customer value)
	{
		int hash_code = key.hash_code();
		int slot = hash_code % this->capacity;

		dictionary_entry data(key, value);
		this->arr[slot].push_back(data);
	}

	void print_entries(void)
	{
		cout << "hash table entries are: " << endl;
		list<dictionary_entry>::iterator itr;
		for( int i = 0 ; i < arr.size() ; i++ )
		{
			cout << "-----------------------------------------------------------------------------------" << endl;
			cout << "slot: " << i << endl;
			for( itr = arr[i].begin() ; itr != arr[i].end() ; itr++ )
			{
				cout << "| " << i << " | " << *itr << endl;
			}
		}
	}
};


int main(void)
{
	hash_table table(5);

	table.put( account(101,"Savings",9999.99), customer("S Tendulkar", "MI", "9764658120"));
	table.put( account(102,"Salary",8888.88), customer("S Ganguly", "KKR", "9764658120"));
	table.put( account(104,"Savings",1111.11), customer("R Dravid", "RCB", "9764658120"));
	table.put( account(201,"Salary",7777.77), customer("Z Khan", "MI", "9764658120"));
	table.put( account(209,"Savings",2222.22), customer("Yuvraj Singh", "KIP", "9764658120"));
	table.put( account(304,"Salary",4444.44), customer("MS Dhoni", "CSK", "9764658120"));
	table.put( account(402,"Savings",5555.55), customer("V Kohali", "RCB", "9764658120"));
	table.put( account(503,"Salary",6666.66), customer("Rohit Sharma", "MI", "9764658120"));
	table.put( account(609,"Savings", 1234.12), customer("B Kumar", "SRH", "9764658120"));
	table.put( account(309,"Salary",6655.55), customer("R Jadeja", "CSK", "9764658120"));

	table.print_entries();

	return 0;
}
