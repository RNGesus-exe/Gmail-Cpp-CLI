#ifndef MAIL_H
#define MAIL_H

#include<iostream>
#include<vector>
#include<string>
#include<conio.h>

using namespace std;

class String {
	int length;
	int listSize;
	char* str;
	char** list;
	int Plen(const char*);
public:
//------------------------------------------------------------------------CONSTRUCTOR/DESTRUCTOR	
	String();
	~String();
//------------------------------------------------------------------------SETTERS/GETTERS/COPYCONSTRUCTOR
	const char* get();
	String(const char*);
	void setString(string);
	void set(const char*);
//--------------------------------------------------------------------------METHODS
	bool equal(const char*);
	void print();
	void reverse();
	void clear();
	int len();
	void concat(const char*, const char*);
	void append(const char*);
	bool contain(const char&);
	bool contain(const char*);
	int find(const char&);
	int find(const char*);
	void empty(const char&);
	void empty(const char*);
	void empty();
	void remove(const char&);
	void removeAll(const char*);
	void remove(const char*);
	int count(const char&);
	int count(const char*);
	void replace(const char&, const char&);
	void replace(const char*, const char*);
	char** tokenizer();
};

class User {
	string username;
	string password;
public:
//------------------------------------------------------------------------------CONSTRUCTOR/DESTRUCTOR/COPYCONSTRUCTOR
	User(string = "", string = "");
	~User();
	User(User&);
//-----------------------------------------------------------------------------SETTERS
	void setUsername(string);
	void setPassword(string);
//-----------------------------------------------------------------------------GETTERS
	string getUsername() const;
	string getPassword() const;
//-----------------------------------------------------------------------------METHODS
	void print() const;
	void input();
	bool check_contact(User&) const;
	bool check_contact(string, string) const;
};

class MailBody {
	string receipent;   //To be filled by user
	string subject;     //To be filled by user
	string text;        //To be filled by user

	string sender;     //Will be auto filled with logged in id

	bool starred;               //To make a starred section in mail//
public:
//--------------------------------------------------------------------------------------------------CONSTRUCTOR/DESTRUCTOR
	MailBody(string = "", string = "", string = "", string = "", bool = false);
	~MailBody();
//---------------------------------------------------------------------------------------------------SETTERS
	void setStarred(bool);
	void setReceipent(string);
	void setSubject(string);
	void setText(string);
	void setSender(string);
//-----------------------------------------------------------------------------------------------------GETTERS
	bool getStarred() const;
	string getReceipent() const;
	string getSubject() const;
	string getText() const;
	string getSender() const;
//------------------------------------------------------------------------------------------------------METHODS
	void display() const;
	void input();
};

class Mail {
//-------------------------------------USER DATA
	struct Person {
		User user;
		vector<MailBody> inbox;
		vector<MailBody> draft;
		vector<MailBody> sent;
		vector<MailBody> trash;
		vector<MailBody> spam;           //IMPLEMENTING
		Person* next;
	};
//--------------------------------------LIST POINTER
	Person* head;
//--------------------------------------To return amount of starred mail in inbox
	int AmountOfStarredMails(string,string);
public:
//-------------------------------------------------------CONSTRUCTOR/DESTRUCTOR
	Mail();
	~Mail();
//-------------------------------------------------------METHODS
	void addUser();								//Signup
	bool checkUser(string, string);	   			//Verify Login
	void InboxContents(string, string);			//Display data in user account
	void compose(string, string);				//Write a new mail
	void ShowInbox(string, string);				//Check user inbox
	void ShowDraft(string, string);				//Move a composing mail to draft
	void AskToSend(string, string);				//Send from draft to reciepent
	void ShowStarred(string, string);			//Check for starred mails
	void ShowTrash(string, string);	  	        //Check for trash mails
	void ShowSent(string, string);				//Check sent mails
	void addToStarred(string, string);		    //Star a mail from inbox
	void addToTrashFromInbox(string, string);   //Move a mail from inbox to trash
	void addToTrashFromDraft(string, string);   //Move a mail from draft to trash
	void addToTrashFromSent(string, string);    //Move a mail from sent to trash
	void UnStar(string, string);                //Unstar a starred mail from starred area
	void PermaDelete(string, string);           //Permanently delete a mail from inbox
	void Restore(string, string);               //Restore a mail to inbox from trash
	void showSpam(string, string);              //Check for spam mails
};



#endif // !MAIL_H