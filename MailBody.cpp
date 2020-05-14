#include "Mail.h"



void MailBody::setStarred(bool starred)
{
	this->starred = starred;
}

void MailBody::setReceipent(string receipent)
{
	this->receipent = receipent;
}

void MailBody::setSubject(string subject)
{
	this->subject = subject;
}

void MailBody::setText(string text)
{
	this->text = text;
}

void MailBody::setSender(string sender)
{
	this->sender = sender;
}

bool MailBody::getStarred() const
{
	return this->starred;
}

string MailBody::getReceipent() const
{
	return this->receipent;
}

string MailBody::getSubject() const
{
	return this->subject;
}

string MailBody::getText() const
{
	return this->text;
}

string MailBody::getSender() const
{
	return this->sender;
}

void MailBody::display() const
{
	cout << "\nReceipent = " << receipent << endl;
	cout << "Sender = " << sender << endl;
	cout << "Subject = " << subject << endl;
	cout << "Mail Body : \n\t" << text << endl;
}

void MailBody::input()
{
	cout << "Enter subject = ";
	getline(cin, subject);
	cout << "Enter the main body of mail = ";
	getline(cin, text);
}

MailBody::MailBody(string sender, string receipent, string txt, string subject, bool starred)
{
	setSender(sender);
	setReceipent(receipent);
	setText(txt);
	setSubject(subject);
	setStarred(starred);
}

MailBody::~MailBody()
{
	receipent = subject = text = sender = "";
	starred = NULL;
}