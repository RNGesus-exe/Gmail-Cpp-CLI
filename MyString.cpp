#include "Mail.h"

int String::Plen(const char* l)   //fucntion to find length of string/char arr
{
	int size = 0;
	while (*l++)
	{
		size++;
	}
	return size;
}
String::String()			//default constructor  
{
	str = nullptr;
	length = 0;
	list = nullptr;            //Will be fixed in V3.0
	listSize = 0;
}
String::~String()			//destructor
{
	delete[] str;
	str = nullptr;
	for (int i = 0; i < listSize; i++)
	{
		delete[] list[i];
	}
	delete[] list;
	list = nullptr;			//will be fixed in V3.0
}
const char* String::get()	//getter/accessor
{
	return str;
}
String::String(const char* s)   //overloaded contructor
{
	length = Plen(s);
	str = new char[length + 1];
	for (int i = 0; *s; s++, i++)
	{
		str[i] = *s;
	}
	str[length] = '\0';
}
int String::len()				//function to get length of a string
{
	return length;
}
void String::set(const char* s)		//mutator/setter
{
	length = Plen(s);
	delete[] str;
	str = new char[length + 1];
	for (int i = 0; *s; s++, i++)
	{
		str[i] = *s;
	}
	str[length] = '\0';
}
bool String::equal(const char* s)      //to check if both strings have same elements
{
	if (Plen(s) == length)
	{
		for (int i = 0; i < length; i++)
		{
			if (s[i] != str[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}
void String::reverse()			//to reverse elements in a string
{
	int i = 0;
	while (i < (length / 2))
	{
		swap(str[i], str[(length - 1) - i]);
		i++;
	}
}
void String::clear()
{
	length = 0;
	delete[] str;
	str = new char[1];
	*str = '\0';
}
void String::concat(const char* s1, const char* s2)   //To combine to strings and overwrite previous string
{
	int len1 = Plen(s1), len2 = Plen(s2);
	int size = len1 + len2;
	delete[] str;
	str = new char[size + 1];
	int i = 0;
	for (; i < len1; i++)
	{
		str[i] = s1[i];
	}
	for (int j = 0; i < size; i++, j++)
	{
		str[i] = s2[j];
	}
	str[size] = '\0';
	length = size;
}
void String::append(const char* s1)					//To combine a new string to the end or old
{
	char* dup = new char[length + 1];
	for (int i = 0; i <= length; i++)
	{
		dup[i] = str[i];
	}
	length += Plen(s1);
	delete[] str;
	str = new char[length + 1];
	int i = 0;
	for (; i < (length - Plen(s1)); i++)
	{
		str[i] = dup[i];
	}
	for (int j = 0; i < length; i++, j++)
	{
		str[i] = s1[j];
	}
	str[length] = '\0';
	delete[] dup;
	dup = nullptr;
}
bool String::contain(const char& ch)      //To find specific character in the string
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ch)
		{
			return true;
		}
	}
	return false;
}
bool String::contain(const char* s)				//To find a specific string in the base string
{
	bool flag;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == s[0])
		{
			flag = true;
			for (int j = i, k = 0; (j < (i + Plen(s))) && (j < length); j++, k++)
			{
				if (str[j] != s[k])
				{
					flag = false;
				}
			}
			if (flag)
			{
				return true;
			}
		}
	}
	return false;
}
int String::find(const char& s)				//returns the index of first matching character
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == s)
		{
			return i;
		}
	}
	return -999;
}
int String::find(const char* s)				//Returns index of first occuring element in string
{
	bool flag;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == s[0])
		{
			flag = true;
			for (int j = i, k = 0; (j < (i + Plen(s))) && (j < length); j++, k++)
			{
				if (str[j] != s[k])
				{
					flag = false;
				}
			}
			if (flag)
			{
				return i;
			}
		}
	}
	return -999;
}
void String::empty(const char& s)    //It fils the matching characters with blank spaces
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == s)
		{
			str[i] = ' ';
		}
	}
}
void String::empty(const char* s)		//It fills the occurings strings with blank spaces
{
	bool flag;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == s[0])
		{
			flag = true;
			for (int j = i, k = 0; (j < (i + Plen(s))) && (j < length); j++, k++)
			{
				if (str[j] != s[k])
				{
					flag = false;
				}
			}
			if (flag)
			{
				for (int j = i; j < (i + Plen(s)) && j < length; j++)
				{
					str[j] = ' ';
				}
			}
		}
	}
}
void String::empty()			//THIS WILL NOT EMPTY THE STRING LITERALLY JUST REPLACES WITH BLANK SPACES
{
	for (int i = 0; i < length; i++)
	{
		str[i] = ' ';
	}
}
void String::remove(const char& s)			//To remove the matching character completely
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == s)
		{
			str[i] = ' ';
			for (int j = i; j < length; j++)
			{
				swap(str[j], str[j + 1]);
			}
			length--;
			i--;
		}
	}
}
void String::removeAll(const char* s)	//removes all of the elements of string seperately 
{
	for (int j = 0; j < Plen(s); j++)
	{
		for (int i = 0; i < length; i++)
		{
			if (str[i] == s[j])
			{
				str[i] = ' ';
				for (int j = i; j < length; j++)
				{
					swap(str[j], str[j + 1]);
				}
				length--;
				i--;
			}
		}
	}
}
void String::remove(const char* s)     //Removes the specified string
{
	while (find(s) != -999)
	{
		for (int i = find(s), k = 0; k < Plen(s); k++, length--)
		{
			for (int j = i; j < length; j++)
			{
				swap(str[j], str[j + 1]);
			}
		}
	}
}
int String::count(const char& ch)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ch)
		{
			count++;
		}
	}
	return count;
}
int String::count(const char* s)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == s[0])
		{
			bool flag = true;
			for (int j = i, k = 0; k < Plen(s); k++, j++)
			{
				if (str[j] != s[k])
				{
					flag = false;
				}
			}
			if (flag)
			{
				count++;
			}
		}
	}
	return count;
}
void String::replace(const char& ch, const char& r)
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ch)
		{
			str[i] = r;
		}
	}
}
void String::replace(const char* s, const char* r)
{
	bool flag;
	int newlen = length + (count(s) * (Plen(r) - Plen(s)));
	char* dup = new char[newlen + 1];
	for (int i = 0, j = 0; i <= length; i++, j++)
	{
		if (str[i] == *s)
		{
			flag = true;
			int ii = i;
			for (int k = 0; k < Plen(s); k++, ii++)
			{
				if (str[ii] != s[k])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				for (int k = 0; k < Plen(r); k++, j++)
				{
					dup[j] = r[k];
				}
				j--;
				i = --ii;
			}
			else
			{
				dup[j] = str[i];
			}
		}
		else
		{
			dup[j] = str[i];
		}
	}
	delete[] str;
	length = newlen;
	str = new char[length + 1];
	for (int i = 0; i <= length; i++)
	{
		str[i] = dup[i];
	}
	delete[] dup;
	dup = nullptr;
}
char** String::tokenizer()
{
	int counter = 0;
	list = new char* [count(',') + 1];        //You can change the delimiter at will
	for (int i = 0, index = 0; i < length; i++)
	{
		counter++;
		if (str[i] == ',' || i == length - 1)
		{
			list[index] = new char[counter];
			list[index][counter] = '\0';
			for (int j = i; counter; j--)
			{
				if (str[j] != ',')
				{
					counter--;
					list[index][counter] = str[j];
				}
				else
				{
					counter--;
					list[index][counter] = '\0';
				}
			}
			index++;
		}
	}
	return list;
}
void String::print()
{
	cout << str << endl;
}
void String::setString(string str)
{
	length = str.length();
	this->str = new char[length + 1];
	for (int i = 0; i <= str.size(); i++)
	{
		this->str[i] = str[i];
	}
}