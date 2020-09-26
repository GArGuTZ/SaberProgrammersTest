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
