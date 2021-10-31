#pragma once

template <typename MyType>
class My_list
{

public:

	My_list();
	void My_pushback(MyType value);
	void My_pop_back();
	void My_print();
	void My_remove(int number);
	void My_erase();

	~My_list();


private:

	int my_size;

	class My_list_element				// nested class
	{

	public:

		My_list_element();
		//My_list_element(MyType* prev, MyType value, MyType* next);		// Do i need it?

		MyType MyGet_value();
		My_list_element* MyGetPrev() {return prev;}		// Can not make definition below, so place it here
		My_list_element* MyGetNext() {return next;}

		void MySetValue(MyType set_value);		// In contrast of this. This can be defined below
		void MySetPrev(My_list_element* set_prev);
		void MySetNext(My_list_element* set_next);
		
	private:

		MyType value;
		My_list_element* prev;
		My_list_element* next;

		int number;

	};

	My_list_element* first;
	My_list_element* last;



};

template<typename MyType>
inline void My_list<MyType>::My_pushback(MyType value)
{
	++my_size;

	My_list_element* current = new My_list_element;

	current->MySetValue(value);
	current->MySetPrev(last);
	current->MySetNext(nullptr);

	if (my_size == 1) first = current;				// if current is very first element
	else last->MySetNext(current);					// linking previous element

	last = current;

}

template<typename MyType>
inline void My_list<MyType>::My_pop_back()
{

	last->MyGetPrev()->MySetNext(nullptr);				// giving end-flag to previous element
	
	My_list_element* tmp = last->MyGetPrev();	// tmp for delete
	delete last;
	last = tmp;

	--my_size;

}

template<typename MyType>
void My_list<MyType>::My_print()
{

	My_list_element* to_console = first;		// temporary container
	
	std::cout << "PRINT\n" << first << std::endl;

	if (first != nullptr) {								// check, is list empty
		
		for (int i = 0; i < my_size; ++i)				// cycle, trust "my_size"
		{

			std::cout << to_console->MyGet_value()
				<< ", THIS is " << to_console
				<< ", prev is "	<< to_console->MyGetPrev()
				<< ", next is " << to_console->MyGetNext()
				<< std::endl;

			to_console = to_console->MyGetNext();		// switch to next element

		}

		std::cout << "End of list\n" << last << std::endl;

	}


}

template<typename MyType>
void My_list<MyType>::My_remove(int number)
{
	std::cout << "Remove " << number << std::endl;

	if (number <= my_size) {

		My_list_element* tmp = first;

		for (int i = 0; i < number; ++i) tmp = tmp->MyGetNext();

		tmp->MyGetNext()->MySetPrev(tmp->MyGetPrev());
		tmp->MyGetPrev()->MySetNext(tmp->MyGetNext());

		delete tmp;

		--my_size;

	}
}

template<typename MyType>
My_list<MyType>::My_list()
{

	first = nullptr;
	last = nullptr;

	my_size = 0;

}


template<typename MyType>
My_list<MyType>::My_list_element::My_list_element()
{

	std::cout << "Constructor is called\n";

	value = 0;
	prev = nullptr;
	next = nullptr;

}

template<typename MyType>
inline MyType My_list<MyType>::My_list_element::MyGet_value()
{
	return value;
}

//template<typename MyType>
//My_list<MyType>::My_list_element* My_list<MyType>::My_list_element::MyGetPrev()
//{
//	return prev;
//}

//template<typename MyType>
//My_list<MyType>::My_list_element* My_list<MyType>::My_list_element::MyGetNext()
//{
//	return next;
//}

template<typename MyType>
inline void My_list<MyType>::My_list_element::MySetValue(MyType set_value)
{

	value = set_value;

}

template<typename MyType>
inline void My_list<MyType>::My_list_element::MySetPrev(My_list_element* set_prev)
{

	prev = set_prev;

}

template<typename MyType>
inline void My_list<MyType>::My_list_element::MySetNext(My_list_element* set_next)
{

	next = set_next;

}

template<typename MyType>
void My_list<MyType>::My_erase()
{
	My_list_element* tmp = first;
	My_list_element* e_next;
		
	for (int i = 0; i < my_size; ++i)
	{

		e_next = tmp->MyGetNext();
		delete tmp;
		tmp = e_next;

	}

	my_size = 0;

	//delete this;				// this is too much
	
}

template<typename MyType>
My_list<MyType>::~My_list()
{

	std::cout << "List deleted\n";

}
