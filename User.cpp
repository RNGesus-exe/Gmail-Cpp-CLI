#include"Mail.h"

User::User(string user, string pass) : username(user), password(pass) {}

User::User(User& user) : username(user.getUsername()), password(user.getPassword()) {}

void User::print() const
{
	cout << "\n\nUsername = " << this->username << endl
		<< "Password = " << this->password << endl;
}

void User::input()
{
	cout << "\n\nEnter username = ";
	getline(cin, this->username);
	char  ch;
	string check;
	do
	{
		password = check = "";
		cout << "\nEnter password = ";
		while ((ch = _getch()) != '\r')
		{
			cout << "*";
			password.push_back(ch);
		}
		cout << "\nEnter password again to confirm = ";
		while ((ch = _getch()) != '\r')
		{
			cout << "*";
			check.push_back(ch);
		}
		if (this->password != check)
		{
			cerr << "\nThe entered passwords dont match please enter again !!!" << endl;
		}
	} while (this->password != check);
}

void User::setUsername(string user)
{
	this->username = user;
}

void User::setPassword(string pass)
{
	this->password = pass;
}

string User::getUsername() const
{
	return this->username;
}

string User::getPassword() const
{
	return this->password;
}

bool User::check_contact(User& user) const
{
	if ((user.getUsername() != this->username)|| (user.getPassword() != this->password))
	{
		return false;
	}
	return true;
}

bool User::check_contact(string user, string pass) const
{
	if ((user != this->username)|| (pass != this->password))
	{
		return  false;
	}
	return true;
}

User::~User()
{
	this->username = this->password = "";
}