#include <iostream>
#include <string>
#include <map>

struct ListNode {
	ListNode *      prev;
	ListNode *      next;
	ListNode *      rand; // указатель на произвольный элемент данного списка, либо NULL
	std::string     data;
};

class List {
public:
	List ();
	List (ListNode _beginner);
	~List ();

	int get_size() const;
	bool is_empty() const;
	void clear();
	void push_front(const std::string &_input);
	void push_back(const std::string &_input);
	void pop_front();
	void pop_back();
	std::string front() const;
	std::string back() const;
	void set_random(int _nodeIndex, int _randIndex);

	void Serialize(FILE* _file);  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
	void Deserialize(FILE* _file);  // загрузка из файла (файл открыт с помощью fopen(path, "rb"))

	friend std::ostream &operator<< (std::ostream &_out, const List &_list);

private:
	ListNode* head_;
	ListNode* tail_;
	int count_;

	List (List &_obj) {}
	List &operator= (List &_obj)
	{
		return *this;
	}
};
