#include"Mail.h"

Mail mail;
string user, pass;
char choice;

void accountRegistration();
void accountLogIn();


int main()
{
	accountRegistration();
	return EXIT_SUCCESS;
}

void accountRegistration()
{
	while (1)
	{
		user = pass = "";
		system("CLS");
		cout << "\nDo you want to Login or Signup or Exit (L/S/E) = ";
		choice = _getch();
		switch (choice)
		{
		case 'L':
		case 'l':
			cout << "\nEnter username = ";
			getline(cin, user);
			char  ch;
			cout << "\nEnter password = ";
			while ((ch = _getch()) != '\r')
			{
				cout << " ";
				pass.push_back(ch);
			}
			if (mail.checkUser(user, pass))
			{
				accountLogIn();
			}
			else
			{
				system("CLS");
				cerr << "The entered username and password are incorrect !!!" << endl;
				clog << "Press any key to continue..." << endl;
				choice = _getch();
			}
			break;
		case 'S':
		case 's':
			mail.addUser();
			cout << "\n\nSuccess Your account has been successfully created !!";
			cout << "Press any key to continue..." << endl;
			choice = _getch();
			break;
		case 'E':
		case 'e':
			cout << "\nAre you sure you want to exit(y/n)?" << endl;
			choice = _getch();
			if (choice == 'y' || choice == 'Y')
			{
				exit(1);
			}
			break;
		default:
			cerr << "\nSuch an option does not exist !!!" << endl;
			cout << "Press any key to continue..." << endl;
			choice = _getch();
		}
	}
}

void accountLogIn()
{
	int choice;
	while (1)
	{
		system("CLS");
		mail.InboxContents(user, pass);
		cout << "\n\n 1) Compose a new mail " << endl
			<< " 2) Check Inbox " << endl
			<< " 3) Check Starred mails " << endl
			<< " 4) Check Draft mails " << endl
			<< " 5) Check Sent mails " << endl
			<< " 6) Check Trash mails " << endl
			<< " 7) Check Spam mails "<<endl
			<< " 8) LogOut " << endl;
		cout << "\n\nEnter what you want to do = ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
			system("CLS");
		case 1:
			mail.compose(user, pass);
			break;
		case 2:
			mail.ShowInbox(user, pass);
			mail.addToStarred(user, pass);
			mail.addToTrashFromInbox(user, pass);
			cout << "Press any key to continue..." << endl;
			::choice = _getch();
			break;
		case 3:
			mail.ShowStarred(user, pass);
			mail.UnStar(user, pass);
			cout << "Press any key to continue..." << endl;
			::choice = _getch();
			break;
		case 4:
			mail.ShowDraft(user, pass);
			mail.AskToSend(user, pass);
			mail.addToTrashFromDraft(user, pass);
			cout << "Press any key to continue..." << endl;
			::choice = _getch();
			break;
		case 5:
			mail.ShowSent(user, pass);
			mail.addToTrashFromSent(user, pass);
			cout << "Press any key to continue..." << endl;
			::choice = _getch();
			break;
		case 6:
			mail.ShowTrash(user, pass);
			mail.PermaDelete(user, pass);
			mail.Restore(user, pass);
			cout << "Press any key to continue..." << endl;
			::choice = _getch();
			break;
		case 7:
			mail.showSpam(user, pass);
			cout << "Press any key to continue..." << endl;
			::choice = _getch();
			break;
		case 8:
			cout << "Are you sure you want to Logout(y/n)?" << endl;
			::choice = _getch();
			if ((::choice == 'y') || (::choice == 'Y'))
			{
				cout << "You have successfully logged out of your account!!" << endl;
				cerr << "Press any key to continue..." << endl;
				::choice = _getch();
				return;
			}
			break;
		default:
			cerr << "Such a choice doesnt not exist !!!" << endl;
			cerr << "Press any key to go to log in page again..." << endl;
			::choice = _getch();
		}
	}
}