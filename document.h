#pragma once

#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<Windows.h>
using namespace std;

/*Category|Topic
	Document	Composition 
	Tags	Composition
	*/

void Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//COLORS LIST
//1: Blue
//2: Green
//3: Cyan
//4: Red
//5: Purple
//6: Yellow (Dark)
//7: Default white
//8: Gray/Grey
//9: Bright blue
//10: Brigth green
//11: Bright cyan
//12: Bright red
//13: Pink/Magenta
//14: Yellow
//15: Bright white
//Numbers after 15 include background colors


void screen_font(int x, int y)
{
	HANDLE Hout = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX Font = { sizeof(Font) };
	COORD fsize = { x,y };
	::GetCurrentConsoleFontEx(Hout, FALSE, &Font);
	Font.dwFontSize = fsize;
	SetCurrentConsoleFontEx(Hout, 0, &Font);
}


class Category
{
	int category_id;
	string cateogory_name;
public:
	//default constructor
	Category()
	{
		category_id = 0;
		cateogory_name = "";
	}

	//parameterized constructor
	Category(string name, int idd)
	{
		category_id = idd;
		cateogory_name = name;
	}
	//copy constructor
	Category(const Category& c)
	{
		category_id = c.category_id;
		cateogory_name = c.cateogory_name;
	}

	//--------------------getter and setters-------------------

	//setter
	void set_id(int n)
	{
		category_id = n;
	}

	void set_cat_name(string name)
	{
		cateogory_name = name;
	}

	//getter

	int get_id()
	{
		return category_id;
	}

	string get_cat_name()
	{
		return cateogory_name;
	}

	//Destructor
	~Category()
	{
	}

	//operators overloading

	//istream operator overloading for cin>> 
	friend istream& operator>>(istream& in, Category& c)
	{
		cout << "\n\tCategory details";
		
		cout << "\nEnter Document Category ID: ";
		in >> c.category_id;

		cout << "\nEnter Document Category Name: ";
		in >> c.cateogory_name;

		return in;
	}

	//ostream operator overloading for cout<<

	friend ostream& operator<<(ostream& out, Category& c)
	{
		out << "\n\t\tCategory details";

		out << "\n-->\tDocument Category ID: " << c.category_id;
		out << "\n-->\tDocument Category Name: " << c.cateogory_name;
		out << endl;

		return out;
	}

	//ifstream operator overloading for fin>> 
	friend ifstream& operator>>(ifstream& in, Category& c)
	{
		in >> c.category_id;
		char temp[10] = {};
		in.getline(temp, 10, '\t');
		in >> c.cateogory_name;

		return in;
	}

	//ofstream operator overloading for fout<<
	friend ofstream& operator<<(ofstream& out, Category& c)
	{
		out << c.category_id;
		out << "\t";
		out<< c.cateogory_name;
		out << endl;

		return out;
	}

	//equal operator overloading
	Category& operator=(const Category& c)
	{
		if (this != &c)
		{
			category_id = c.category_id;
			cateogory_name = c.cateogory_name;
		}
		return *this;
	}

	// not equal operator over loading

	bool operator!=(const int n)
	{
		if (category_id == n)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	// == operator overloading

	bool operator==(const int n)
	{
		if (category_id == n)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	

};




class Topic
{
	int Topic_ID;
	string Topic_Name;

public:
	//default constructor
	Topic()
	{
		Topic_ID = 0;
		Topic_Name = "";
		
	}


	//parameterized constructor
	Topic(string name, int id = 0)
	{
		Topic_ID = id;
		Topic_Name = name;
		
	}

	//copy constructor
	Topic(const Topic& t)
	{
		Topic_ID = t.Topic_ID;
		Topic_Name = t.Topic_Name;
	}

	//--------------------getter and setters-------------------

	//setters
	void set_topic_id(int n)
	{
		Topic_ID = n;
	}

	void set_topic_name(string nam)
	{
		Topic_Name = nam;
	}

	//getters
	int get_topic_id()
	{
		return Topic_ID;
	}

	string get_topic_name()
	{
		return Topic_Name;
	}

	//destructor
	~Topic()
	{
	}


	//----------------------operators overloading--------------------

	//istream operator overloading for cin>> 
	friend istream& operator>>(istream& in, Topic& t)
	{
		cout << "\n\tTopic details";

		cout << "\nEnter Document Topic ID: ";
		in >> t.Topic_ID;

		cout << "\nEnter Document Topic Name: ";
		in >> t.Topic_Name;


		return in;
	}

	//ostream operator overloading for cout<<

	friend ostream& operator<<(ostream& out, Topic& t)
	{
		out << "\n\t\tTopic details";

		out << "\n-->\tDocument Topic ID: " << t.Topic_ID;
		out << "\n-->\tDocument Topic Name: " << t.Topic_Name;
		out << endl;

		return out;
	}

	//ifstream operator overloading for fin>> 
	friend ifstream& operator>>(ifstream& in, Topic& t)
	{
		in >> t.Topic_ID;
		char temp[10] = {};
		in.getline(temp, 10, '\t');
		in >> t.Topic_Name;

		return in;
	}

	//ofstream operator overloading for fout<<
	friend ofstream& operator<<(ofstream& out, Topic& t)
	{
		out << t.Topic_ID;
		out << "\t";
		out << t.Topic_Name;
		out << endl;

		return out;
	}


	//equal operator overload
	Topic& operator=(const Topic& t)
	{
		if (this != &t)
		{
			Topic_ID = t.Topic_ID;
			Topic_Name = t.Topic_Name;
		}
		return *this;
	}

	// not equal operator over loading

	bool operator!=(const int n)
	{
		if (Topic_ID == n)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	// == operator overloading

	bool operator==(const int n)
	{
		if (Topic_ID == n)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};

class Tag
{
	string Tag_Name;
public:
	//default constructor
	Tag()
	{
		Tag_Name = "";
	}

	//parameterized constructor
	Tag(string name)
	{
		Tag_Name = name;
	}

	//copy constructor
	Tag(const Tag& t)
	{
		Tag_Name = t.Tag_Name;
	}

	//--------------------getter and setters-------------------

	//setter
	void set_tag_name(string name)
	{
		Tag_Name = name;
	}

	//getter
	string get_tag_name()
	{
		return Tag_Name;
	}

	//Destructor
	~Tag()
	{
	}

	//--------------------operators overloading----------------------

	//istream operator overloading for cin>> 
	friend istream& operator>>(istream& in, Tag& t)
	{
		cout << "\n\tTag details";

		cout << "\nEnter Document Tag Name: ";
		in >> t.Tag_Name;

		return in;
	}

	//ostream operator overloading for cout<<

	friend ostream& operator<<(ostream& out, Tag& t)
	{

		out << t.Tag_Name;

		return out;
	}

	//ifstream operator overloading for fin>> 
	friend ifstream& operator>>(ifstream& in, Tag& t)
	{
		in >> t.Tag_Name;

		return in;
	}


	//ofstream operator overloading for fout<<
	friend ofstream& operator<<(ofstream& out, Tag& t)
	{
		out << t.Tag_Name;

		return out;
	}

	//equal operator overloading
	Tag& operator=(const Tag& t)
	{
		if (this != &t)
		{
			Tag_Name = t.Tag_Name;
		}
		return *this;
	}
};


class Document
{
	int Doc_ID;
	string File_Name;
	Category File_Category;
	Topic File_Topic;
	Tag* File_Tags;
	int count_tags;
public:
	//defualt constructor
	Document(int id = 0)
	{
		Doc_ID = 0;
		File_Name = "";
		File_Tags = new Tag[30];//max limit of 30 tags
		count_tags = 0;
	}
	//Copy constructor
	Document(const Document& d)
	{
		Doc_ID = d.Doc_ID;
		File_Name = d.File_Name;
		File_Category = d.File_Category;
		File_Tags = d.File_Tags;
		File_Topic = d.File_Topic;
		count_tags = d.count_tags;
	}

	//--------------------getter and setters-------------------
	void set_doc_id(int n)
	{
		Doc_ID = n;
	}

	void set_file_name(string nam)
	{
		File_Name = nam;
	}

	void set_file_Cat(Category c)
	{
		File_Category = c;
	}

	void set_file_topic(Topic t)
	{
		File_Topic = t;
	}

	void set_file_tags(Tag* t)
	{
		File_Tags = t;
	}

	void set_topic_name_from_handler_class(string name)
	{
		File_Topic.set_topic_name(name);
	}

	void set_cat_name_from_handler_class(string name)
	{
		File_Category.set_cat_name(name);
	}

	void set_count_tags(int n)
	{
		count_tags = n;
	}
	//getters
	int get_doc_id()
	{
		return Doc_ID;
	}

	string get_doc_name()
	{
		return File_Name;
	}

	Category get_doc_cat()
	{
		return File_Category;
	}

	Topic get_doc_topic()
	{
		return File_Topic;
	}

	Tag* get_doc_tags()
	{
		return File_Tags;
	}

	int get_count_tags()
	{
		return count_tags;
	}

	int get_doc_topic_id()
	{
		return	File_Topic.get_topic_id();
	}

	int get_doc_cat_id()
	{
		return File_Category.get_id();
	}



	//tags seprator form char array

	void tags_separator(char temp[])
	{
		int len = strlen(temp);

		char t[30] = {};

		int j = 0;

		for (int i = 1; temp[i] != '\0'; i++)
		{
			t[j++] = temp[i];
			if (temp[i + 1] == ',' || temp[i + 1] == '\0')
			{
				t[j] = '\0';
				File_Tags[count_tags++] = (string)t;
				
				j = 0;

				if (temp[i + 1] != '\0')
				{
					i++;
					i++;
				}
			}
		}


	}

	//operators overloading

	//istream operator overloading for cin>> 
	friend istream& operator>>(istream& in, Document& d)
	{
		cout << "\n\tDocuments details";

		cout << "\nEnter Document ID: ";
		in >> d.Doc_ID;

		cout << "\nEnter Document Name: ";
		in >> d.File_Name;

		int n = 0;
		cout << "\nEnter Document Category ID: ";
		in >> n;
		d.File_Category.set_id(n);

		cout << "\nEnter Document Topic ID: ";
		in >> n;

		d.File_Topic.set_topic_id(n);

		return in;
	}

	//ostream operator overloading for cout<<

	friend ostream& operator<<(ostream& out, Document& d)
	{
		out << "\n\t\tDocument details";

		out << "\n-->\tDocument ID: " << d.Doc_ID;
		out << "\n-->\tDocument Name: " << d.File_Name << endl;
		out << d.File_Category << d.File_Topic;

		out << "Tags:\n";
		for (int i = 0; i < d.count_tags; i++)
		{
			out << "\tTag# " << i + 1 << ": " << d.File_Tags[i] << endl;
		}

		return out;
	}


	//ifstream operator overloading for fin>> 
	friend ifstream& operator>>(ifstream& in, Document& d)
	{
		char temp[10] = {};

		in >> d.Doc_ID;
		in.getline(temp, 10, '\t');
		int n = 0;
		
		in >> n;
		d.File_Category.set_id(n);

		in.getline(temp, 10, '\t');

		in >> n;
		d.File_Topic.set_topic_id(n);

		char temp2[500] = {};

		in.getline(temp, 10, '\t');

		in.getline(temp2, 500, ']');

		d.tags_separator(temp2);

		in.getline(temp, 10, '\t');
		in >> d.File_Name;



		return in;
	}


	//ofstream operator overloading for fout<<
	friend ofstream& operator<<(ofstream& out, Document& d)
	{
		out << d.Doc_ID;
		
		out << "\t";
		
		out << d.File_Category.get_id();
		
		out << "\t";
		
		out << d.File_Topic.get_topic_id() << "\t";
		
		out << "[";
		
		for (int i = 0; i < d.count_tags; i++)
		{
			out << d.File_Tags[i];
			if (i + 1 != d.count_tags)
			{
				out << ", ";
			}
		}
		out << "]\t";

		out << d.File_Name << endl;

		return out;
	}


	//equal operator overload
	Document& operator=(const Document& d)
	{
		if (this != &d)
		{
			Doc_ID = d.Doc_ID;
			File_Category = d.File_Category;
			File_Name = d.File_Name;
			count_tags = d.count_tags;
			File_Tags = d.File_Tags;
			File_Topic = d.File_Topic;
		}
		return *this;
	}
	
	// not equal operator over loading

	bool operator!=(const int n)
	{
		if (Doc_ID == n && File_Category == 0 && File_Topic == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}


	//destructor
	~Document()
	{
	}
};


class Document_handler
{
	Document* docs;
	Topic* topics_list;
	Category* cat_list;
	static int no_of_docs;
	static int no_of_topics;
	static int no_of_cat;

	//------------------------ID CHECKS IN ARRAY FUNCTIONS-----------------

	bool repeat_of_doc_id(int id)
	{
		for (int i = 0; i < no_of_docs; i++)
		{
			if (docs[i].get_doc_id() == id)
			{
				return true;
			}
		}
		return false;
	}

	bool not_found_of_topic_id(int id)
	{
		for (int i = 0; i < no_of_topics; i++)
		{
			if (topics_list[i].get_topic_id() == id)
			{
				return false;
			}
		}
		return true;
	}

	bool not_found_of_cat_id(int id)
	{
		for (int i = 0; i < no_of_cat; i++)
		{
			if (cat_list[i].get_id() == id)
			{
				return false;
			}
		}
		return true;
	}

	bool found_of_doc_cat_id(int id)
	{
		for (int i = 0; i < no_of_docs; i++)
		{
			if (docs[i].get_doc_cat_id() == id)
			{
				return true;
			}
		}
		return false;
	}

	bool found_of_doc_topic_id(int id)
	{
		for (int i = 0; i < no_of_docs; i++)
		{
			if (docs[i].get_doc_topic_id() == id)
			{
				return true;
			}
		}
		return false;
	}


	//------------------set documents according to topic id and category id--------------------
	void set_doc_cat_and_top_names_by_id()
	{
		for (int i = 0; i < no_of_docs; i++)
		{
			int n1 = docs[i].get_doc_topic_id();
			int n2 = docs[i].get_doc_cat_id();

			for (int j = 0; j < no_of_cat; j++)
			{
				if (n2 == cat_list[j].get_id())
				{
					string name = cat_list[j].get_cat_name();
					docs[i].set_cat_name_from_handler_class(name);
					break;
				}
			}

			for (int j = 0; j < no_of_topics; j++)
			{
				if (n2 == topics_list[j].get_topic_id())
				{
					string name = topics_list[j].get_topic_name();
					docs[i].set_topic_name_from_handler_class(name);
					break;
				}
			}

		}
	}


	//---------------------seting up tags for document-------------------------
	void set_tags_of_doc(int index)
	{
		int t = docs[index].get_count_tags();
		if (t == 0)
		{
			int n = 0;
			cout << "\n\nHow many tags you want to enter:";
			cin >> n;

			Tag* temp = new Tag[n];

			for (int i = 0; i < n; i++)
			{
				cin >> temp[i];
			}

			docs[index].set_file_tags(temp);
			docs[index].set_count_tags(n);
		}
		else
		{
			cout << "\n\nYou have already " << t << " Tags";
			int n = 0;
			cout << "\n\nHow many more tags you want to enter:";
			cin >> n;

			Tag* temp = new Tag[n + t];

			temp = docs[index].get_doc_tags();


			for (int i = t; i < (n + t); i++)
			{
				cin >> temp[i];
			}

			docs[index].set_file_tags(temp);
			docs[index].set_count_tags(n + t);
		}
	}


	//------------------array inceaser functions----------------

	void increase_docs_array_size()
	{
		Document* temp = new Document[no_of_docs];
		for (int i = 0; i < no_of_docs; i++)
		{
			temp[i] = docs[i];
		}
		delete[]docs;

		docs = new Document[200];

		for (int i = 0; i < no_of_docs; i++)
		{
			docs[i] = temp[i];
		}

		cout << "\n\nDocument Limits now increased from 30 to 200\n\n";
		set_doc_cat_and_top_names_by_id();
	}

	void increase_cat_array_size()
	{
		Category* temp = new Category[no_of_cat];
		for (int i = 0; i < no_of_cat; i++)
		{
			temp[i] = cat_list[i];
		}
		delete[]cat_list;

		cat_list = new Category[200];

		for (int i = 0; i < no_of_cat; i++)
		{
			cat_list[i] = temp[i];
		}

		cout << "\n\nCategories Limits now increased from 50 to 200\n\n";
	}

	void increase_topics_array_size()
	{
		Topic* temp = new Topic[no_of_topics];
		for (int i = 0; i < no_of_topics; i++)
		{
			temp[i] = topics_list[i];
		}
		delete[]topics_list;

		topics_list = new Topic[200];

		for (int i = 0; i < no_of_topics; i++)
		{
			topics_list[i] = temp[i];
		}

		cout << "\n\nTopics Limits now increased from 50 to 200\n\n";
	}




protected:
	//-----------------adder functions------------------------
	void add_document()
	{
	repeat_doc:
		cin >> docs[no_of_docs];
		enter_data_in_doc_file();

		int n = docs[no_of_docs].get_doc_id();

		if (repeat_of_doc_id(n))
		{
			cout << "\n\nYour document id already coverd please enter info again\n";
			goto repeat_doc;
		}

		n = docs[no_of_docs].get_doc_topic_id();

		if (not_found_of_topic_id(n))
		{
			cout << "\n\nYour topic Id not found";
			cout << "\nEnter the topic name for id " << n << " : ";
			string name;
			cin >> name;

			docs[no_of_docs].set_topic_name_from_handler_class(name);

		}

		n = docs[no_of_docs].get_doc_cat_id();

		if (not_found_of_cat_id(n))
		{
			cout << "\n\nYour Category Id not found";
			cout << "\nEnter the Category name for id " << n << " : ";
			string name;
			cin >> name;

			docs[no_of_docs].set_topic_name_from_handler_class(name);

		}

		set_tags_of_doc(no_of_docs);
		no_of_docs++;
		enter_data_in_doc_file();
		set_doc_cat_and_top_names_by_id();

		cout << "\n\nSUCESSFULLY ADDED!!!!\n\n";


		if (no_of_docs == 30)
		{
			increase_docs_array_size();
		}

	}
	void add_topics()
	{

	repeat_topics:
		cin >> topics_list[no_of_topics];

		int n = topics_list[no_of_topics].get_topic_id();

		if (not_found_of_topic_id(n) == false)
		{
			cout << "\n\nRepeating of topic id found";
			cout << "\nEnter info again\n";

			goto repeat_topics;
		}



		no_of_topics++;

		cout << "\n\nSUCESSFULLY ADDED!!!!\n\n";


		enter_data_in_topic_file();

		if (no_of_topics == 50)
		{
			increase_topics_array_size();
		}
	}
	void add_cat()
	{

	repeat_cat:
		cin >> cat_list[no_of_cat];


		int n = cat_list[no_of_cat].get_id();

		if (not_found_of_topic_id(n) == false)
		{
			cout << "\n\nRepeating of Category id found";
			cout << "\nEnter info again\n";

			goto repeat_cat;
		}

		no_of_cat++;
		cout << "\n\nSUCESSFULLY ADDED!!!!\n\n";

		enter_data_in_cat_file();
	
		if (no_of_cat == 50)
		{
			increase_topics_array_size();
		}
	}
	void add_more_tags(int id)
	{
		bool check = false;
		for (int i = 0; i < no_of_docs; i++)
		{
			if (docs[i].get_doc_id() == id)
			{
				set_tags_of_doc(i);
				enter_data_in_doc_file();
				check = true;
				cout << "\n\nSUCESSFULLY ADDED!!!!\n\n";
				break;
			}
		}

		if (check == false)
		{
			cout << "\n\nID NOT FOUND!!!!\n\n";
		}
	}

	//----------------removel functions----------------------
	void remove_document_by_doc_id(int doc_id)
	{
		bool check = false;
		bool check2 = false;
		for (int i = 0; i < no_of_docs; i++)
		{
			if (docs[i].get_doc_id() == doc_id)
			{
				check = true;
			}

			if (check)
			{
				check2 = true;
				docs[i] = docs[i + 1];
			}
		}

		if (check2 == true)
		{
			no_of_docs--;
			enter_data_in_doc_file();
			cout << "\n\nSUCESSFULLY REMOVED!!!!\n\n";
		}
		else
		{

			cout << "\n\nID NOT FOUND!!!!\n\n";
		}
	}
	void remove_docs_by_cat_id(int cat_id)
	{
		if (found_of_doc_cat_id(cat_id))
		{
			int count = 0;
			Document* temp = new Document[no_of_docs - 1];

			for (int i = 0; i < no_of_docs; i++)
			{
				if (docs[i].get_doc_cat_id() != cat_id)
				{
					temp[count] = docs[i];
					count++;
				}
			}

			delete[]docs;

			docs = new Document[count];

			no_of_docs = count;

			for (int i = 0; i < no_of_docs; i++)
			{
				docs[i] = temp[i];
			}


			enter_data_in_doc_file();
			cout << "\n\nSUCESSFULLY REMOVED!!!!\n\n";
		}
		else
		{
			cout << "\n\nID NOT FOUND!!!!\n\n";
		}
	}
	void remove_doc_by_topic_id(int top_id)
	{
		if (found_of_doc_topic_id(top_id))
		{
			int count = 0;
			Document* temp = new Document[no_of_docs - 1];

			for (int i = 0; i < no_of_docs; i++)
			{
				if (docs[i].get_doc_topic_id() != top_id)
				{
					temp[count] = docs[i];
					count++;
				}
			}

			delete[]docs;

			docs = new Document[count];

			no_of_docs = count;

			for (int i = 0; i < no_of_docs; i++)
			{
				docs[i] = temp[i];
			}


			enter_data_in_doc_file();
			cout << "\n\nSUCESSFULLY REMOVED!!!!\n\n";
		}
		else
		{
			cout << "\n\nID NOT FOUND!!!!\n\n";
		}
	}
	void remove_topics(int id)
	{
		bool check = false;
		bool check2 = false;
		for (int i = 0; i < no_of_topics; i++)
		{
			if (topics_list[i].get_topic_id() == id)
			{
				check = true;
			}

			if (check)
			{
				check2 = true;
				topics_list[i] = topics_list[i + 1];
			}
		}
		if (check2)
		{
			no_of_topics--;
			enter_data_in_topic_file();
			cout << "\n\nSUCESSFULLY REMOVED!!!!\n\n";
		}
		else
		{
			cout << "\n\nID NOT FOUND!!!!\n\n";
		}
	}
	void remove_cat(int id)
	{
		bool check = false;
		bool check2 = false;
		for (int i = 0; i < no_of_cat; i++)
		{
			if (cat_list[i].get_id() == id)
			{
				check = true;
			}

			if (check)
			{
				check2 = true;
				cat_list[i] = cat_list[i + 1];
			}
		}
		if (check2)
		{
			no_of_cat--;
			enter_data_in_cat_file();
			cout << "\n\nSUCESSFULLY REMOVED!!!!\n\n";
		}
		else
		{
			cout << "\n\nID NOT FOUND!!!!\n\n";
		}
	}

	//---------------------printing functions-----------------
	void print_all_by_cat_id(int id)
	{
		bool check = false;
		for (int i = 0; i < no_of_docs; i++)
		{
			if (docs[i].get_doc_cat_id() == id)
			{
				check = true;
				cout << docs[i] << endl << endl << endl;
			}
		}

		if (check == false)
		{
			cout << "\n\nID NOT FOUND!!!!";
		}
	}
	void print_all_by_top_id(int id)
	{
		bool check = false;
		for (int i = 0; i < no_of_docs; i++)
		{
			if (docs[i].get_doc_topic_id() == id)
			{
				check = true;
				cout << docs[i] << endl << endl << endl;
			}
		}

		if (check == false)
		{
			cout << "\n\nID NOT FOUND!!!!";
		}
	}
	void print_doc_by_id(int id)
	{
		bool check = false;
		for (int i = 0; i < no_of_docs; i++)
		{
			if (docs[i].get_doc_id() == id)
			{
				check = true;
				cout << docs[i] << endl << endl << endl;
				break;
			}
		}

		if (check == false)
		{
			cout << "\n\nID NOT FOUND!!!!";
		}
	}

	//---------------------filing functions--------------------

	//entering data in file
	void enter_data_in_cat_file()
	{
		ofstream file;
		file.open("Category.txt", ios::trunc);

		for (int i = 0; i < no_of_cat; i++)
		{
			if (cat_list[i] != 0)
			{
				file << cat_list[i];
			}
		}
		file.close();
	}
	void enter_data_in_topic_file()
	{
		ofstream file;
		file.open("Topic.txt", ios::trunc);

		for (int i = 0; i < no_of_topics; i++)
		{	
			if (topics_list[i] != 0)
			{
				file << topics_list[i];
			}
		}
		file.close();
	}
	void enter_data_in_doc_file()
	{
		ofstream file;
		file.open("Document.txt", ios::trunc);

		for (int i = 0; i < no_of_docs; i++)
		{
			if (docs[i] != 0)
			{
				file << docs[i];
			}
			
		}
		file.close();
	}

	//reading from the file
	void read_data_from_doc_file()
	{
		ifstream file("Document.txt");

		while (!file.eof())
		{
			file >> docs[no_of_docs];
			no_of_docs++;
		}
		file.close();

		set_doc_cat_and_top_names_by_id();
	}
	void read_data_from_cat_file()
	{
		ifstream file("Category.txt");

		while (!file.eof())
		{
			file >> cat_list[no_of_cat];
			no_of_cat++;
		}
		file.close();
	}
	void read_data_from_topic_file()
	{
		ifstream file("Topic.txt");

		while (!file.eof())
		{
			file >> topics_list[no_of_topics];
			no_of_topics++;
		}
		file.close();
	}

	//----------------------editing functions----------------
	void edit_doc(int id)
	{
		bool check = false;
		for (int i = 0; i < no_of_docs; i++)
		{
			if (docs[i].get_doc_id() == id)
			{
				check = true;
				cout << "\n\n\t!!!DOC FOUND!!!\n";
				cout << "Enter Info again\n";
				cout << "You can overwrite everything at this doc_id\n";
				cin >> docs[i];
				set_tags_of_doc(i);
				enter_data_in_doc_file();
				set_doc_cat_and_top_names_by_id();
				cout << "\n\nSUCESSFULLY EDIT!!!!\n\n";
				break;
			}
		}

		if (check == false)
		{
			cout << "\n\nID NOT FOUND!!!!";
		}
	}
	void edit_topics(int id)
	{
		bool check = false;
		for (int i = 0; i < no_of_topics; i++)
		{
			if (topics_list[i].get_topic_id() == id)
			{
				check = true;
				cout << "\n\n\t!!!Topic FOUND!!!\n";
				cout << "Enter Info again\n";
				cout << "You can overwrite everything at this Topic ID\n";
				cin >> topics_list[i];
				enter_data_in_topic_file();
				set_doc_cat_and_top_names_by_id();
				enter_data_in_doc_file();
				cout << "\n\nSUCESSFULLY EDIT!!!!\n\n";
				break;
			}
		}

		if (check == false)
		{
			cout << "\n\nID NOT FOUND!!!!";
		}
	}
	void edit_cat(int id)
	{
		bool check = false;
		for (int i = 0; i < no_of_cat; i++)
		{
			if (cat_list[i].get_id() == id)
			{
				check = true;
				cout << "\n\n\t!!!Category FOUND!!!\n";
				cout << "Enter Info again\n";
				cout << "You can overwrite everything at this Category ID\n";
				cin >> cat_list[i];
				enter_data_in_cat_file();
				set_doc_cat_and_top_names_by_id();
				enter_data_in_doc_file();
				cout << "\n\nSUCESSFULLY EDIT!!!!\n\n";
				break;
			}
		}

		if (check == false)
		{
			cout << "\n\nID NOT FOUND!!!!";
		}
	}
	//--------------------------------Search By tags--------------

	void search_by_tags(string tag)
	{
		bool check = false;
		for (int i = 0; i < no_of_docs; i++)
		{
			int n = docs[i].get_count_tags();
			Tag* t = new Tag[n];
			t = docs[i].get_doc_tags();
			for (int j = 0; j < n; j++)
			{
				if (t[j].get_tag_name() == tag)
				{
					check = true;
					cout << "\n\n\t!!!TAG FOUND!!!\n";
					cout << "Document Details are following\n\n";
					cout << docs[i] << endl << endl << endl;
				}
			}
		}

		if (check == false)
		{
			cout << "\n\nOPPS!!! Tag Not Found!!!\n\n";
		}
	}

public:

	Document_handler()
	{
		docs = new Document[30];
		topics_list = new Topic[50];
		cat_list = new Category[50];
	}

	inline void menu()
	{
		read_data_from_topic_file();
		read_data_from_cat_file();
		read_data_from_doc_file();

		int choice = 9999;
		int id = 0;
		while (true)
		{
		menu:
			
			system("CLS");
			Color(12);
			
			screen_font(18, 18);
			cout << "\n\t\t\t\tDocument Management System\n";

			Color(10);
			
			cout << "\n--> Enter \t1\t to add new Document\n";

			cout << "\n--> Enter \t2\t to add new Topic\n";

			cout << "\n--> Enter \t3\t to add new Category\n";

			cout << "\n--> Enter \t4\t to delete the document by document ID\n";

			cout << "\n--> Enter \t5\t to delete the documents by Topics ID\n";

			cout << "\n--> Enter \t6\t to to delete the documents by Category ID\n";

			cout << "\n--> Enter \t7\t to Print Specific Document\n";

			cout << "\n--> Enter \t8\t to Print all Documents having same Topic ID\n";

			cout << "\n--> Enter \t9\t to Print all documents having same Category ID\n";

			cout << "\n--> Enter \t10\t to delete the topic\n";

			cout << "\n--> Enter \t11\t to delete the category\n";

			cout << "\n--> Enter \t12\t to add more tags to existing documents\n";

			cout << "\n--> Enter \t13\t to edit document\n";

			cout << "\n--> Enter \t14\t to edit topics\n";

			cout << "\n--> Enter \t15\t to edit category\n";

			cout << "\n--> Enter \t16\t to search documents by tags\n";

			cout << "\n--> Enter \t-1\t to exit:";

			cin >> choice;


			if (choice == 1)
			{
				system("CLS");
				Color(14);
				add_document();
				_getch();
			}
			else if (choice == 2)
			{
				system("CLS");
				Color(14);
				add_topics();
				_getch();
			}
			else if (choice == 3)
			{
				system("CLS");
				Color(14);
				add_cat();
				_getch();
			}
			else if (choice == 4)
			{
				system("CLS");
				Color(13);
				cout << "\nEnter ID of document:";
				cin >> id;
				remove_document_by_doc_id(id);
				_getch();
			}
			else if (choice == 5)
			{
				system("CLS");
				Color(13);
				cout << "\nEnter Topic ID:";
				cin >> id;
				remove_doc_by_topic_id(id);
				_getch();
			}
			else if (choice == 6)
			{
				system("CLS");
				Color(13);
				cout << "\nEnter Category ID:";
				cin >> id;
				remove_docs_by_cat_id(id);
				_getch();
			}
			else if (choice == 7)
			{
				system("CLS");
				Color(13);
				cout << "\nEnter ID of document:";
				cin >> id;
				print_doc_by_id(id);
				_getch();
			}
			else if (choice == 8)
			{
				system("CLS");
				Color(13);
				cout << "\nEnter topic ID:";
				cin >> id;
				print_all_by_top_id(id);
				_getch();
			}
			else if (choice == 9)
			{
				system("CLS");
				Color(13);
				cout << "\nEnter Category ID:";
				cin >> id;
				print_all_by_cat_id(id);
				_getch();
			}
			else if (choice == 10)
			{
				system("CLS");
				Color(13);
				cout << "\nEnter Topic ID:";
				cin >> id;
				remove_topics(id);
				_getch();
			}
			else if (choice == 11)
			{
				system("CLS");
				Color(13);
				cout << "\nEnter Category ID:";
				cin >> id;
				remove_cat(id);
				_getch();
			}
			else if (choice == 12)
			{
				system("CLS");
				Color(13);
				cout << "\nEnter ID of document:";
				cin >> id;
				add_more_tags(id);
				_getch();
			}
			else if (choice == 13)
			{
				system("CLS");
				Color(13);
				cout << "\nEnter ID of document:";
				cin >> id;
				edit_doc(id);
				_getch();
			}
			else if (choice == 14)
			{
				system("CLS");
				Color(13);
				cout << "\nEnter Topic ID:";
				cin >> id;
				edit_topics(id);
				_getch();
			}
			else if (choice == 15)
			{
				system("CLS");
				Color(13);
				cout << "\nEnter Category ID:";
				cin >> id;
				edit_cat(id);
				_getch();
			}
			else if (choice == 16)
			{
				system("CLS");
				Color(13);
				string name;
				cout << "\nEnter Tag:";
				cin >> name;
				search_by_tags(name);
				_getch();
			}
			else if (choice == -1)
			{
				cout << "Thanks!!!" << endl;
				break;
			}
			else
			{
				cout << "\n\nChoice Not Found!!!!!\n";
				goto menu;
			}

		}
	}

	~Document_handler()
	{
		delete[]docs;
		delete[]topics_list;
		delete[]cat_list;
	}
	
};

int Document_handler::no_of_docs = 0;
int Document_handler::no_of_topics = 0;
int Document_handler::no_of_cat = 0;