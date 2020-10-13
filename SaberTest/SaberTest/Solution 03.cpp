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

		std::cout << std::endl << "List Cleared" << std::endl;

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

	std::cout << std::endl << "List Cleared" << std::endl;

	return;
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

	// Nulling rands->deletingNode in List
	ListNode *prevNode = tail_;
	while (prevNode != head_)
	{
		if (prevNode->rand != NULL && prevNode->rand == deletedNode)
		{
			prevNode->rand = NULL;
		}
		prevNode = prevNode->prev;
	}
	if (head_->rand != NULL && head_->rand == deletedNode)
	{
		head_->rand = NULL;
	}

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

	// Nulling rands->deletingNode in List
	ListNode *nextNode = head_;
	while (nextNode != tail_)
	{
		if (nextNode->rand != NULL && nextNode->rand == deletedNode)
		{
			nextNode->rand = NULL;
		}
		nextNode = nextNode->next;
	}
	if (tail_->rand != NULL && tail_->rand == deletedNode)
	{
		tail_->rand = NULL;
	}

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

	if (head_ == NULL || tail_ == NULL)
	{
		std::cout << "Serializing file " << _file << std::endl;

		std::cout << "Nodes: " << count_ << std::endl;
		fwrite(&count_, sizeof(count_), 1, _file);         // Number of Nodes = 0

		fflush(_file);
		return;
	}

	std::cout << "Serializing file " << _file << std::endl;
	// Filling the map with indexes of Nodes

	std::cout << "Nodes: " << count_ << std::endl;
	fwrite(&count_, sizeof(count_), 1, _file);         // Number of Nodes

	int counter = 0;
	std::map<ListNode*, int> counterMap;
	ListNode *nextNode = head_;
	unsigned int dataLength = 0;
	while (nextNode != NULL)
	{
		++counter;
		counterMap[nextNode] = counter;

		dataLength = nextNode->data.size();
		std::cout << "Node: " << counter << ", ";
		std::cout << "Data length: " << dataLength << ",	Data: " << nextNode->data << std::endl;
		fwrite(&dataLength, sizeof(dataLength), 1, _file); // Size of data
		fwrite(nextNode->data.c_str(), 1, dataLength, _file); // Data

		nextNode = nextNode->next;
	}

	for (auto it = counterMap.begin(); it != counterMap.end(); ++it)
	{
		std::cout << "Node Address: " << it->first << ", Index " << it->second << std::endl;
	}

	// Filling second map with pairs (thisNode,randNode) if rand != NULL

	unsigned int randsCount = 0;
	counter = 0;
	std::map<int, int> incidenceMap;
	nextNode = head_;
	while (nextNode != NULL)
	{
		++counter;
		if (nextNode->rand != NULL)
		{
			incidenceMap[counter] = counterMap[nextNode->rand];
		}
		nextNode = nextNode->next;
	}

	randsCount = incidenceMap.size();
	std::cout << "Rands: " << randsCount << std::endl;
	fwrite(&randsCount, sizeof(randsCount), 1, _file);

	for (auto it = incidenceMap.begin(); it != incidenceMap.end(); ++it)
	{
		std::cout << "Node Index: " << it->first << ", Have rand on index: " << it->second << std::endl;
		fwrite(&it->first, sizeof(it->first), 1, _file);
		fwrite(&it->second, sizeof(it->second), 1, _file);
	}

	return;
}

void List::Deserialize(FILE* _file)
{
	if (_file == NULL)
	{
		std::cout << "File not found or path is wrong" << std::endl;
		return;
	}

	std::cout << "Deserializing file " << _file << std::endl;
	clear();

	int amount = 0;
	fread(&amount, sizeof(amount), 1, _file);
	std::cout << "Nodes: " << amount << std::endl;

	if (amount < 0)
	{
		std::cout << "Negative amount or file format is wrong" << std::endl;
		return;
	}
	if (amount == 0)
	{
		std::cout << "Readed List is empty" << std::endl;
		return;
	}
	if (amount == 1) // Primitive Case
	{
		unsigned int dataLength(0);
		fread(&dataLength, sizeof(dataLength), 1, _file);
		std::cout << "Data length: " << dataLength;

		std::string newData("");
		char* readedString(new char[dataLength + 1]);
		fread(readedString, 1, dataLength, _file);
		readedString[dataLength] = '\0';
		newData = readedString;
		delete[] readedString;
		std::cout << ",	Data: " << newData << std::endl;

		head_ = new ListNode{ NULL, NULL, NULL, newData };
		tail_ = head_;
		++count_;

		unsigned int randsCount(0);
		fread(&randsCount, sizeof(randsCount), 1, _file);
		std::cout << "Rands: " << randsCount << std::endl;

		if (randsCount == 1) // => rand == head_
		{
			head_->rand = head_;
		}

		return;
	}

	unsigned int dataLength(0);
	std::map<int, ListNode*> indexMap;
	std::string newData("");
	for (int i = 1; i <= amount; ++i)
	{
		std::cout << "Reading Node " << i << ", ";
		fread(&dataLength, sizeof(dataLength), 1, _file);
		std::cout << "Data length: " << dataLength;

		char* readedString(new char[dataLength + 1]);
		fread(readedString, 1, dataLength, _file);
		readedString[dataLength] = '\0';
		newData = readedString;
		delete[] readedString;
		std::cout << ",	Data: " << newData << std::endl;

		push_back(newData);
		indexMap[i] = tail_;
	}


	unsigned int randsCount(0);
	fread(&randsCount, sizeof(randsCount), 1, _file);
	std::cout << "Rands: " << randsCount << std::endl;
	int nodeIndex = 0;
	int nodeRandom = 0;
	std::map<int, int> incidenceMap;
	for (int i = 1; i <= randsCount; ++i)
	{
		fread(&nodeIndex, sizeof(nodeIndex), 1, _file);
		fread(&nodeRandom, sizeof(nodeRandom), 1, _file);
		std::cout << "Node Index: " << nodeIndex << ", Have rand on index: " << nodeRandom << std::endl;
		//set_random(nodeIndex, nodeRandom);
		incidenceMap[nodeIndex] = nodeRandom;
		indexMap[nodeIndex]->rand = indexMap[nodeRandom];
	}

	return;
}
