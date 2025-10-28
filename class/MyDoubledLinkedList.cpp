#include <iostream>

template<class T>
struct Node
{
	Node<T>* next;
	Node<T>* prev;
	T data;
};
//head → next → node1 → next → node2 → next → tail → nullptr
//nullptr ← prev ← head ← prev ← node1 ← prev ← node2 ← prev ← tail
template<class T>
class DoubledLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	size_t size;

public:
	DoubledLinkedList() : head(nullptr), tail(nullptr), size(0) {};

	DoubledLinkedList(const DoubledLinkedList& other) : head(nullptr), tail(nullptr), size(0)
	{
		Node<T>* current = other.head;
		while (current != nullptr)
		{
			PushBack(current->data);
			current = current->next;
		}
	}

	~DoubledLinkedList()
	{
		while (head != nullptr)
		{
			PopFront();
		}
	}

	DoubledLinkedList& operator=(const DoubledLinkedList& other)
	{
		if (this != &other)
		{

			while (head != nullptr)
			{
				PopFront();
			}
			Node<T>* current = other.head;
			while (current != nullptr)
			{
				PushBack(current->data);
				current = current->next;
			}

		}
		return *this;
	}

	void PushFront(const T& _data)
	{
		Node<T>* node = new Node<T>();
		node->data = _data;
		if (head == nullptr)
		{
			tail = node;
			node->next = nullptr;
		}
		else
		{
			head->prev = node;
			node->next = head;
		}
		node->prev = nullptr;
		head = node;
		size++;
	}

	void PushBack(const T& _data)
	{
		Node<T>* node = new Node<T>();
		node->data = _data;
		if (head == nullptr)
		{
			head = node;
			node->prev = nullptr;
		}
		else
		{
			tail->next = node;
			node->prev = tail;
		}
		tail = node;
		node->next = nullptr;
		size++;
	}

	void PopFront()
	{
		if (head == nullptr)
		{
			return;
		}
		else if (head == tail)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			head->prev = nullptr;
		}
		size--;
	}

	void PopBack()
	{
		if (tail == nullptr)
		{
			return;
		}
		else if (head == tail)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node<T>* temp = tail;
			tail = tail->prev;
			delete temp;
			tail->next = nullptr;
		}
		size--;
	}

	void insert(size_t position, const T& _data)
	{
		if (position > size)
		{
			std::cout << "wrong position";
			return;
		}
		if (position == 0)
		{
			PushFront(_data);
			return;
		}
		if (position == size)
		{
			PushBack(_data);
			return;
		}

		Node<T>* node = new Node<T>();
		node->data = _data;
		Node<T>* current = head;
		for (size_t i = 0; i < position; i++)
		{
			current = current->next;
		}
		node->next = current;
		node->prev = current->prev;
		current->prev->next = node;
		current->prev = node;
		size++;
	}

	void erase(size_t position)
	{
		if (position >= size)
		{
			std::cout << "wrong position";
			return;
		}
		if (position == 0)
		{
			PopFront();
			return;
		}
		if (position == size - 1)
		{
			PopBack();
			return;
		}

		Node<T>* current = head;
		for (size_t i = 0; i < position; i++)
		{
			current = current->next;
		}
		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete current;
		size--;
	}

	void Print()
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			std::cout << current->data << std::endl;
			current = current->next;
		}
	}

	size_t GetSize()
	{
		return size;
	}
};

int main()
{

	return 0;
}