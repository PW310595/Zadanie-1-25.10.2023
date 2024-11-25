###############Przemo
##########structure

#pragma once
#include <iostream>
#include <string>

namespace data_structures
{
	//zadanie6
	class ISerializable
	{
	public:
		virtual std::string save() const = 0;
	};
	inline std::ostream& operator<<(std::ostream& os, const ISerializable& obj)
	{
		return os << obj.save();
	}


	template <typename T>
	class Element
	{
	private:
		Element<T>* next;
		T data;
	public:
		// Konstruktor inicjalizujący składowe klasy
		Element(T data, Element<T>* next = nullptr) : data(data), next(next) {}

		//zadanie2
		Element<T>* getNext() const { return next; }
		void setNext(Element<T>* next) { this->next = next; }
		T getData() const { return data; }
		//operator dereferencji * zwracający referencję na przechowywaną daną typu T.
		T& operator*() { return data; }
	};


	//zadanie3
	template <typename T>
	class List//lista jednokierunkowa
	{
	private:
		//wskaźnik na pierwszy element listy
		Element<T>* first;
		//wskaźnik na ostatni element listy
		Element<T>* last;
	public:
		//zadanie4
		List() : first(nullptr), last(nullptr) {}
		~List() {}
		//akcesory
		Element<T>* getFIrst() const { return first; }
		Element<T>* getLast() const { return last; }

		//zadanie5 metoda dodająca element na koniec listy
		void add(T data)
		{
			Element<T>* newElement = new Element<T>(data);
			if (first == nullptr)
			{
				first = newElement;
				last = newElement;
			}
			else
			{
				last->setNext(newElement);
				last = newElement;
			}
		}
		//zadanie7
		std::string save() const
		{
			std::string result;
			Element<T>* currentElement = first;
			while (currentElement != nullptr)
			{
				result += std::to_string(currentElement->getData()) + " ";
				currentElement = currentElement->getNext();
			}
			return result;
		}
	};

	
	
}
################################main

#include <iostream>

#include "data_structures.h"

using std::cout;
using std::endl;

int main()
{
    //testowanie 1 zadania
    data_structures::Element<int> element1(10);
    data_structures::Element<int> element2(20, &element1);

    cout << "Element 1 data: " << element1.getData() << endl;
	cout << "Element 2 data: " << element2.getData() << endl;
	cout << "Dereferencja elementu 2: " << *element2 << endl;
    //koniec testowania 1 zadania


    //testowanie 5 zadania
	data_structures::List<int> list1;
	list1.add(10);
	list1.add(20);
	list1.add(30);

	//wypisanie elementów listy
	data_structures::Element<int>* currentElement = list1.getFIrst();
	while (currentElement != nullptr)
	{
		cout << "Element data: " << currentElement->getData() << endl;
		currentElement = currentElement->getNext();
	}
	//koniec testowania 5 zadania

	
	//testowanie 7 zadania
	cout << "Serialized list (po ludzku zrobiona w stringa): " << list1.save() << endl;
	//koniec testowania 7 zadania

	cout << "\nKoniec\n";
}
=========================================================================================== OLEK

#structures 

#pragma once
#include <iostream>

// (1)
namespace data_structures {

template<typename T>
class Element {
private:
    T item;
    Element<T>* nextptr;
public:
    Element(const T& _item) : item(_item), nextptr(nullptr) {}

    // (2)
    Element<T>* getNext() const {
        return this->nextptr;
    }
    void setNext(Element<T>* _nextptr) {
        this->nextptr = _nextptr;
    }
    
    // przeładowanie dereferencji
    T& operator *() {
        return this->item;
    }
};

// (3), (4)
template<typename T>
class List {
private:
    Element<T>* first;
    Element<T>* last;
    size_t len;
public:
    List () : first(nullptr), last(nullptr), len(0) {
    }

    const size_t getLength() const {
        return this->len;
    }

    T& getAt(size_t index) {
        Element<T>* elem_cur = this->first;
        for (size_t i=0; i<this->len; i++) {
            if (i == index) {
                break;
            }
            elem_cur = elem_cur->getNext();
        }
        // jak nie znajdzie indeksu to zwróci ostatnią wartość
        return **elem_cur;
    }

    // (5)
    bool add(const T& item) {

        Element<T>* elem_next = new Element<T>(item);
        if (elem_next == nullptr) return false;

        if (first == nullptr) {
            first = elem_next;
        } else {
            this->last->setNext(elem_next);
        }
    
        this->last = elem_next;
        this->len++;
        std::cout << "added " << this->len << std::endl;

        return true;

    }

    // (5)
    ~List() {
        Element<T>* elem_cur = this->first;
        while (elem_cur != nullptr) {
            Element<T>* elem_next = elem_cur->getNext();
            delete elem_cur;
            elem_cur = elem_next;
            std::cout << "delete" << std::endl;
        }
    }
};

}
#############################################################main

#include <iostream>
#include "data_structures.h"

int main() {

    data_structures::List<int> my_list;
    my_list.add(1);
    my_list.add(2);
    my_list.add(7);

    std::cout << "Wartość: " << my_list.getAt(2) << std::endl;

    std::cout << "Hiena world" << std::endl;

    return 0;

}
