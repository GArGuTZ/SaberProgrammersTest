#include "Solution 03.h"

List::List() : count_(0), head_(NULL), tail_(NULL) {}

List::~List()
{
	clear();
}

int List::get_size() const 
{
	return count_;
}

bool List::is_empty() const
{
	return count_ == 0;
}

void List::clear()
{
	if (head_ == NULL || tail_ == NULL)
	{
		return;
	}
	if (head_->next == NULL || tail_->prev == NULL)
	{
		--count_;

		delete head_;
		tail_ = NULL;

		return;
	}

	ListNode *nextNode = head_->next;
	while (nextNode != tail_)
	{
		ListNode *temporary = nextNode;
		nextNode = nextNode->next;
		--count_;
		delete temporary;
	}

	--count_;
	delete nextNode;
	--count_;
	delete head_;
	tail_ = NULL;
}

void List::push_back(const std::string &_input)
{
	if (is_empty())
	{
		tail_ = new ListNode{ NULL, NULL, NULL, _input };
		head_ = tail_;
		++count_;
		return;
	}
	if (count_ == 1)
	{
		tail_ = new ListNode{ head_, NULL, NULL, _input };
		head_->next = tail_;
		++count_;
		return;
	}

	ListNode* newNode = new ListNode{ tail_, NULL, NULL, _input };
	tail_->next = newNode;
	tail_ = newNode;
	++count_;
}

void List::push_front(const std::string &_input)
{
	if (is_empty())
	{
		head_ = new ListNode{ NULL, NULL, NULL, _input };
		tail_ = head_;
		++count_;
		return;
	}
	if (count_ == 1)
	{
		head_ = new ListNode{ NULL, tail_, NULL, _input };
		tail_->prev = head_;
		++count_;
		return;
	}

	ListNode* newNode = new ListNode{ NULL, head_, NULL, _input };
	head_->prev = newNode;
	head_ = newNode;
	++count_;
}

void List::pop_back()
{
	if (is_empty())
	{
		return;
	}
	if (count_ == 1)
	{
		--count_;
		delete tail_;
		head_ = NULL;
		return;
	}

	--count_;
	ListNode* deletedNode = tail_;
	tail_ = tail_->prev;
	delete deletedNode;
	tail_->next = NULL;
}

void List::pop_front()
{
	if (is_empty())
	{
		return;
	}
	if (count_ == 1)
	{
		--count_;
		delete head_;
		tail_ = NULL;
		return;
	}

	--count_;
	ListNode* deletedNode = head_;
	head_ = head_->next;
	delete deletedNode;
	head_->prev = NULL;
}

std::string List::front() const
{
	if (is_empty())
	{
		return "";
	}
	return head_->data;
}

std::string List::back() const
{
	if (is_empty())
	{
		return "";
	}
	return tail_->data;
}

void List::set_random(int _nodeIndex, int _randIndex)
{
	if (_nodeIndex <= 0 || _randIndex <= 0 || _nodeIndex > count_ || _randIndex > count_)
	{
		return;
	}

	int counter = 1;
	ListNode* thisNode = NULL;
	ListNode* randNode = NULL;
	if (counter == _nodeIndex)
	{
		thisNode = head_;
	}
	if (counter == _randIndex)
	{
		randNode = head_;
	}
	if (thisNode != NULL && randNode != NULL)
	{
		thisNode->rand = randNode;
		return;
	}

	ListNode *nextNode = head_->next;
	while (nextNode != tail_)
	{
		++counter;
		if (counter == _nodeIndex)
		{
			thisNode = nextNode;
		}
		if (counter == _randIndex)
		{
			randNode = nextNode;
		}
		if (thisNode != NULL && randNode != NULL)
		{
			thisNode->rand = randNode;
			return;
		}
		nextNode = nextNode->next;
	}
	++counter;
	if (counter == _nodeIndex)
	{
		thisNode = tail_;
	}
	if (counter == _randIndex)
	{
		randNode = tail_;
	}
	if (thisNode != NULL && randNode != NULL)
	{
		thisNode->rand = randNode;
		return;
	}

	return;
}

std::ostream &operator<< (std::ostream &_out, const List &_list)
{
	if (_list.is_empty())
	{
		_out << "List is empty" << std::endl;
		return _out;
	}
	
	if (_list.get_size() == 1)
	{
		_out << "Nodes: 1	Head == Tail" << std::endl << _list.head_->prev << " " << _list.head_->data << " " << _list.head_->next << " " << _list.head_->rand << std::endl;
		return _out;
	}

	int counter = 0;
	ListNode *currentNode = _list.head_;
	while (currentNode != _list.tail_)
	{
		++counter;
		_out << "Node: " << counter << std::endl << currentNode->prev << " " << currentNode->data << " " << currentNode->next << " " << currentNode->rand << std::endl;
		currentNode = currentNode->next;
	}
	++counter;
	_out << "Node: " << counter << std::endl << currentNode->prev << " " << currentNode->data << " " << currentNode->next << " " << currentNode->rand << std::endl;
	
	_out << "List Size: " << _list.count_ << ", de-facto: " << counter << std::endl;
	return _out;
}

void List::Serialize(FILE* _file)
{
	if (_file == NULL)
	{
		std::cout << "File not found or path is wrong" << std::endl;
		return;
	}
	std::map<ListNode*, int> addresses;


	if (head_ == NULL || tail_ == NULL)
	{
		return;
	}
	if (head_->next == NULL || tail_->prev == NULL) // Primitive Case
	{
		unsigned int N (head_->data.size());

		std::cout << N << std::endl;
		//char d[10];
		//_itoa_s(N, d, 10);
		fwrite(&N, sizeof(N), 1, _file);           // Size of data
		fwrite(head_->data.c_str(), 1, N, _file);  // Data

		std::map<ListNode*, int> experimentMap = { { head_, 1 } };
		std::cout << "Map value: " << experimentMap[tail_] << std::endl;
		for (auto it = experimentMap.begin(); it != experimentMap.end(); ++it)
		{
			std::cout << "Node Address: " << it->first << ", Index " << it->second << std::endl;
		}




		fflush(_file);
		return;
	}
	// Filling the map with indexes of Nodes

	int counter = 1;
	std::map<ListNode*, int> counterMap = { { head_, counter } };
	ListNode *nextNode = head_->next;
	while (nextNode != tail_)
	{
		++counter;
		counterMap[nextNode] = counter;
		nextNode = nextNode->next;
	}
	++counter;
	counterMap[tail_] = counter;

	for (auto it = counterMap.begin(); it != counterMap.end(); ++it)
	{
		std::cout << "Node Address: " << it->first << ", Index " << it->second << std::endl;
	}

	// Filling second map with pairs (thisNode,randNode) if rand != NULL

	counter = 1;
	std::map<int, int> incidenceMap;
	if (head_->rand != NULL)
	{
		incidenceMap[counter] = counterMap[head_->rand];
	}
	nextNode = head_->next;
	while (nextNode != tail_)
	{
		++counter;
		if (nextNode->rand != NULL)
		{
			incidenceMap[counter] = counterMap[nextNode->rand];
		}
		nextNode = nextNode->next;
	}
	++counter;
	if (tail_->rand != NULL)
	{
		incidenceMap[counter] = counterMap[tail_->rand];
	}

	for (auto it = incidenceMap.begin(); it != incidenceMap.end(); ++it)
	{
		std::cout << "Node Index: " << it->first << ", Have rand on index: " << it->second << std::endl;
	}

	return;
}

void List::Deserialize(FILE* _file)
{
	std::string new_s("");
	unsigned int N(0);
	fread(&N, sizeof(N), 1, _file);
	char* c(new char[N + 1]);
	fread(c, 1, N, _file);
	c[N] = '\0';
	new_s = c;
	delete[] c;
	std::cout << N << std::endl;
	std::cout << new_s << std::endl;
	return;
}
