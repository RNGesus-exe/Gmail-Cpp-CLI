#include "Mail.h"

int Mail::AmountOfStarredMails(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			int j = 0;
			vector<MailBody>::iterator i;
			for (i = holder->inbox.begin(); i != holder->inbox.end(); i++)
			{
				MailBody temp = *i;
				if (temp.getStarred() == true)
				{
					j++;
				}
			}
			return j;
		}
		holder = holder->next;
	}
}

Mail::Mail() :head(nullptr) {}

Mail::~Mail()
{
	head = nullptr;
}

void Mail::addUser()
{
	Person* temp = new Person;
	temp->user.input();
	temp->next = nullptr;

	if (head == nullptr)
	{
		head = temp;
		return;
	}

	temp->next = head;
	head = temp;
}

bool Mail::checkUser(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			return true;
		}
		holder = holder->next;
	}
	return false;
}

void Mail::showSpam(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			vector<MailBody>::iterator i;
			int j = 1;
			for (i = holder->spam.begin(); i != holder->spam.end(); i++, j++)
			{
				MailBody temp = *i;
				cout << "\n------------------------------(" << j << ")----------------------------\n" << endl;
				temp.display();
			}
			return;
		}
		holder = holder->next;
	}
}

void Mail::InboxContents(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			cout << "\nInbox = " << holder->inbox.size() << endl
				<< "Draft = " << holder->draft.size() << endl
				<< "Starred = " << AmountOfStarredMails(user,pass) << endl
				<< "Sent = " << holder->sent.size() << endl
				<<"Spam = "<<holder->spam.size()<<endl
				<< "Trash = " << holder->trash.size() << endl;
			return;
		}
		holder = holder->next;
	}
}

void Mail::compose(string user, string pass)
{
	system("CLS");
	char ch;
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			MailBody temp;
			int size;
			string str1;
		    Person* holder2 = head;
			bool flag = false;
			string* names;
			do
			{
				cout << "\nReceipent(s) = ";
				getline(cin, str1);
				String str2;
				str2.setString(str1);
				size = str2.count(",") + 1;
				char** tokens = str2.tokenizer();

				names=new string[size];
				for (int i = 0; i < size; i++)
				{
					names[i] = tokens[i];
				}
				for (int i = 0; i < size; i++)
				{
					holder2 = head;
					flag = false;
					while (holder2 != nullptr)
					{
						if (holder2->user.getUsername() == names[i])
						{
							flag = true;
							break;
						}
						holder2 = holder2->next;
					}
					if (!flag)
					{
						cout << "One of the receipents are incorrect !!" << endl;
						cout << "Please Enter again receipent names..." << endl;
						break;
					}
				}

			} while(!flag);
			
			temp.input();
			temp.setReceipent(str1);
			temp.setSender(user);
			do
			{
				cout << "Do you want to save as <Draft> or <Send> or <Discard> (d/s/z) = ";
				ch = _getche();
				if (ch == 's' || ch == 'S')
				{
					holder->sent.push_back(temp);
					for (int i = 0; i < size; i++)
					{
						holder2 = head;
						while (holder2 != nullptr)
						{
							if (holder2->user.getUsername() == names[i])
							{
									holder2->inbox.push_back(temp);
							}
							holder2 = holder2->next;
						}
					}
				}
				else if (ch == 'd' || ch == 'D')
				{
					holder->draft.push_back(temp);
					cout << "\nSaved in draft successfuly!!!" << endl;
					cout << "Press any key to continue..." << endl;
					ch = _getch();
					ch = 'd';
				}
				else if (ch == 'z' || ch == 'Z')
				{
					delete[] names;
					return;
				}
				else
				{
					cerr << "Please enter a valid option!!!";
					cerr << "\nPress any key to continue..." << endl;
					ch = _getch();
					ch = 'X';
				}
			} while (ch != 'z' && ch != 'Z' && ch != 's' && ch != 'S' && ch != 'd' && ch != 'D');
			delete[] names;
			return;
		}
		holder = holder->next;
	}
}

void Mail::ShowInbox(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			vector<MailBody>::iterator i;
			int j = 1;
			for (i = holder->inbox.begin(); i != holder->inbox.end(); i++, j++)
			{
				MailBody temp = *i;
				cout << "\n------------------------------(" << j << ")----------------------------\n" << endl;
				temp.display();
			}
			return;
		}
		holder = holder->next;
	}
}

void Mail::ShowDraft(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			vector<MailBody>::iterator i;
			int j = 1;
			for (i = holder->draft.begin(); i != holder->draft.end(); i++, j++)
			{
				MailBody temp = *i;
				cout << "\n------------------------------(" << j << ")----------------------------\n" << endl;
				temp.display();
			}
			return;
		}
		holder = holder->next;
	}
}

void Mail::AskToSend(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			char ch;
			do
			{
				cout << "\nDo you want to send a draft(y/n)?";
				ch = _getch();
				if (ch == 'y' || ch == 'Y')
				{
					int choice;
					do
					{
						cout << "\nEnter the draft mail number which you want to send = ";
						cin >> choice;
						if ((choice < 0) || (choice > holder->draft.size()))
						{
							cerr << "\nSuch a mail number does not exist!!!\n" << endl;
						}
					} while ((0 > choice) || (choice > holder->draft.size()));

					vector<MailBody>::iterator i;
					int j = 1;
					bool flag = false;
					for (i = holder->draft.begin(); i != holder->draft.end(); i++, j++)
					{
						if (j == choice)
						{
							flag = true;
							MailBody temp = *i;
							holder->sent.push_back(temp);
							holder->draft.erase(holder->draft.begin() + (j - 1));

							String str;
							str.setString(temp.getReceipent());
							char** tokens = str.tokenizer();
							int size = str.count(",") + 1;
							string* names = new string[size];
							for (int i = 0; i < size; i++)
							{
								names[i] = tokens[i];
							}

							Person* holder2;
							for (int i = 0; i < size; i++)
							{
								holder2 = head;
								while (holder2 != nullptr)
								{
									if (holder2->user.getUsername() == names[i])
									{
										holder2->inbox.push_back(temp);
										break;
									}
									holder2 = holder2->next;
								}
							}
							delete[] names;
						}
						if (flag)
						{
							break;
						}
					}
				}
			} while (ch != 'n' && ch != 'N');
			return;
		}
		holder = holder->next;
	}
}

void Mail::ShowStarred(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			vector<MailBody>::iterator i;
			int j = 1;
			for (i = holder->inbox.begin(); i != holder->inbox.end(); i++)
			{
				MailBody temp = *i;
				if (temp.getStarred() == true)
				{
				cout << "\n------------------------------(" << j << ")----------------------------\n" << endl;
				temp.display();
				j++;
				}
			}
			return;
		}
		holder = holder->next;
	}
}

void Mail::ShowTrash(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			vector<MailBody>::iterator i;
			int j = 1;
			for (i = holder->trash.begin(); i != holder->trash.end(); i++, j++)
			{
				MailBody temp = *i;
				cout << "\n------------------------------(" << j << ")----------------------------\n" << endl;
				temp.display();
			}
			return;
		}
		holder = holder->next;
	}
}

void Mail::ShowSent(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			vector<MailBody>::iterator i;
			int j = 1;
			for (i = holder->sent.begin(); i != holder->sent.end(); i++, j++)
			{
				MailBody temp = *i;
				cout << "\n------------------------------(" << j << ")----------------------------\n" << endl;
				temp.display();
			}
			return;
		}
		holder = holder->next;
	}
}

void Mail::addToStarred(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			char ch;
			do {
				cout << "\nDo you want to star a mail(y/n)?";
				ch = _getch();
				if (ch == 'y' || ch == 'Y')
				{
					int choice;
					do
					{
						cout << "\nEnter the mail number which you want to star = ";
						cin >> choice;
						if ((choice < 0) || (choice > holder->inbox.size()))
						{
							cerr << "\nSuch a mail number does not exist!!!\n" << endl;
						}
					} while ((0 > choice) || (choice > holder->inbox.size()));

					vector<MailBody>::iterator i;
					int j = 1;
					for (i = holder->inbox.begin(); i != holder->inbox.end(); i++, j++)
					{
						if (j == choice)
						{
							(*i).setStarred(true);
							break;
						}
					}
				}
			} while (ch != 'n' && ch != 'N');
			return;
		}
		holder = holder->next;
	}
}

void Mail::addToTrashFromInbox(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			char ch;
			do
			{
			cout << "\nDo you want to send mail to trash(y/n)?";
			ch = _getch();
			if (ch == 'y' || ch == 'Y')
			{
				int choice;
				do
				{
					cout << "\nEnter the mail number which you want to move to trash = ";
					cin >> choice;
					if ((choice < 0) || (choice > holder->inbox.size()))
					{
						cerr << "\nSuch a mail number does not exist!!!\n" << endl;
					}
				} while ((0 > choice) || (choice > holder->inbox.size()));

				vector<MailBody>::iterator i;
				int j = 1;
				for (i = holder->inbox.begin(); i != holder->inbox.end(); i++, j++)
				{
					if (j == choice)
					{
						holder->trash.push_back(*i);
						(*i).setStarred(false);
						holder->inbox.erase(i);
						break;
					}
				}
			}
			} while (ch != 'n' && ch != 'N');
			return;
		}
		holder = holder->next;
	}
}

void Mail::addToTrashFromDraft(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			char ch;
			do{
			cout << "\nDo you want to send mail to trash(y/n)?";
			ch = _getch();
			if (ch == 'y' || ch == 'Y')
			{
				int choice;
				do
				{
					cout << "\nEnter the mail number which you want to move to trash = ";
					cin >> choice;
					if ((choice < 0) || (choice > holder->draft.size()))
					{
						cerr << "\nSuch a mail number does not exist!!!\n" << endl;
					}
				} while ((0 > choice) || (choice > holder->draft.size()));

				vector<MailBody>::iterator i;
				int j = 1;
				for (i = holder->draft.begin(); i != holder->draft.end(); i++, j++)
				{
					if (j == choice)
					{
						holder->trash.push_back(*i);
						(*i).setStarred(false);
						holder->draft.erase(i);
						break;
					}
				}
			}
			} while (ch != 'n' && ch != 'N');
			return;
		}
		holder = holder->next;
	}
}

void Mail::addToTrashFromSent(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			char ch;
			do
			{
			cout << "\nDo you want to permanent delete a mail(y/n)?";
			ch = _getch();
			if (ch == 'y' || ch == 'Y')
			{
				int choice;
				do
				{
					cout << "\nEnter the mail number which you want to delete = ";
					cin >> choice;
					if ((choice < 0) || (choice > holder->sent.size()))
					{
						cerr << "\nSuch a mail number does not exist!!!\n" << endl;
					}
				} while ((0 > choice) || (choice > holder->sent.size()));

				vector<MailBody>::iterator i;
				int j = 1;
				for (i = holder->sent.begin(); i != holder->sent.end(); i++, j++)
				{
					if (j == choice)
					{
						holder->sent.erase(i);
						break;
					}
				}
			}
			} while (ch != 'n' && ch != 'N');
			return;
		}
		holder = holder->next;
	}
}

void Mail::UnStar(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			char ch;
			do
			{
				cout << "\nDo you want to UnStar a mail(y/n)?";
				ch = _getch();
				if (ch == 'y' || ch == 'Y')
				{
					int choice;
					do
					{
						cout << "\nEnter the mail number which you want to UnStar = ";
						cin >> choice;
						if ((choice < 0) || (choice > holder->inbox.size()))
						{
							cerr << "\nSuch a mail number does not exist!!!\n" << endl;
						}
					} while ((0 > choice) || (choice > holder->inbox.size()));

					vector<MailBody>::iterator i;
					int j = 1;
					for (i = holder->inbox.begin(); i != holder->inbox.end(); i++, j++)
					{
						if (j == choice)
						{
							(*i).setStarred(false);
							break;
						}
					}
				}
			} while (ch != 'n' && ch != 'N');
			return;
		}
		holder = holder->next;
	}
}

void Mail::PermaDelete(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			char ch;
			do
			{
				cout << "\nDo you want to delete a mail permanently(y/n)?";
				ch = _getch();
				if (ch == 'y' || ch == 'Y')
				{
					int choice;
					do
					{
						cout << "\nEnter the mail number which you want to delete = ";
						cin >> choice;
						if ((choice < 0) || (choice > holder->trash.size()))
						{
							cerr << "\nSuch a mail number does not exist!!!\n" << endl;
						}
					} while ((0 > choice) || (choice > holder->trash.size()));

					vector<MailBody>::iterator i;
					int j = 1;
					for (i = holder->trash.begin(); i != holder->trash.end(); i++, j++)
					{
						if (j == choice)
						{
							holder->trash.erase(i);
							break;
						}
					}
				}
			} while (ch != 'n' && ch != 'N');
			return;
		}
		holder = holder->next;
	}
}

void Mail::Restore(string user, string pass)
{
	Person* holder = head;
	while (holder != nullptr)
	{
		if ((holder->user.getUsername() == user) && (holder->user.getPassword() == pass))
		{
			char ch;
			do
			{
				cout << "\nDo you want to restore a mail from trash to inbox(y/n)?";
				ch = _getch();
				if (ch == 'y' || ch == 'Y')
				{
					int choice;
					do
					{
						cout << "\nEnter the mail number which you want to restore = ";
						cin >> choice;
						if ((choice < 0) || (choice > holder->trash.size()))
						{
							cerr << "\nSuch a mail number does not exist!!!\n" << endl;
						}
					} while ((0 > choice) || (choice > holder->trash.size()));

					vector<MailBody>::iterator i;
					int j = 1;
					for (i = holder->trash.begin(); i != holder->trash.end(); i++, j++)
					{
						if (j == choice)
						{
							holder->inbox.push_back(*i);
							holder->trash.erase(i);
							break;
						}
					}
				}
			} while (ch != 'n' && ch != 'N');
			return;
		}
		holder = holder->next;
	}
}
