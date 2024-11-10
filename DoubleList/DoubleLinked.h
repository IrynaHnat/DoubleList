#pragma once
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr)
        : data(data), prev(prev), next(next) {}
};

template<typename T>
class List {
public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    List(const List<T>& other) : head(nullptr), tail(nullptr), size(0) {
        Node<T>* current = other.head;
        while (current != nullptr) {
            addTail(current->data);  
            current = current->next;
        }
    }

    
    List<T>& operator=(const List<T>& other) {
        if (this == &other)  
            return *this;

        clear();  
        Node<T>* current = other.head;
        while (current != nullptr) {
            addTail(current->data);  
            current = current->next;
        }
        return *this;
    }

    ~List() {
        clear();
    }

    void clear() {
        while (!empty()) {
            removeHead();
        }
    }

    void addHead(const T& data) {
        auto tmp = new Node<T>(data, nullptr, head);
        if (empty())
            tail = tmp;
        else
            head->prev = tmp;
        head = tmp;
        ++size;
    }

    void addTail(const T& data) {
        auto tmp = new Node<T>(data, tail, nullptr);
        if (empty())
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
        ++size;
    }

    void removeHead() {
        if (empty())
            return;
        auto tmp = head;
        head = head->next;
        delete tmp;
        if (head == nullptr)
            tail = nullptr;
        else
            head->prev = nullptr;
        --size;
    }

    void removeTail() {
        if (empty())
            return;
        auto tmp = tail;
        tail = tail->prev;
        delete tmp;
        if (tail == nullptr)
            head = nullptr;
        else
            tail->next = nullptr;
        --size;
    }

    void print() const {
        if (empty()) {
            cout << "List is empty" << endl;
            return;
        }
        auto tmp = head;
        cout << "List :: \t";
        while (tmp != nullptr) {
            cout << tmp->data << "\t";
            tmp = tmp->next;
        }
        cout << endl;
    }

    void printR() const {
        if (empty()) {
            cout << "List is empty" << endl;
            return;
        }
        auto tmp = tail;
        cout << "List :: \t";
        while (tmp != nullptr) {
            cout << tmp->data << "\t";
            tmp = tmp->prev;
        }
        cout << endl;
    }

    bool empty() const {
        return head == nullptr;
    }

    void removeByData(const T& data) {
        auto find = findNode(data);
        if (find == nullptr)
            return;
        if (find == head) {
            removeHead();
            return;
        }
        if (find == tail) {
            removeTail();
            return;
        }
        find->prev->next = find->next;
        find->next->prev = find->prev;

        delete find;
        --size;
    }

    void insertAt(const T& data, size_t position) {
        if (position > size) return; 

        if (position == 0) {
            addHead(data);
        }
        else if (position == size) {
            addTail(data);
        }
        else {
            auto current = head;
            for (size_t i = 0; i < position - 1; ++i) {
                current = current->next;
            }
            auto newNode = new Node<T>(data, current, current->next);
            current->next->prev = newNode;
            current->next = newNode;
            ++size;
        }
    }

    void removeAt(size_t position) {
        if (position >= size) return; 

        if (position == 0) {
            removeHead();
        }
        else if (position == size - 1) {
            removeTail();
        }
        else {
            auto current = head;
            for (size_t i = 0; i < position; ++i) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            --size;
        }
    }

    int find(const T& data) const {
        auto current = head;
        int position = 0;
        while (current != nullptr) {
            if (current->data == data) {
                return position;
            }
            current = current->next;
            ++position;
        }
        return -1; 
    }

    int replace(const T& oldData, const T& newData) {
        auto current = head;
        int replaceCount = 0;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                ++replaceCount;
            }
            current = current->next;
        }
        return replaceCount > 0 ? replaceCount : -1; 
    }

    void reverse() {
        Node<T>* current = head;
        Node<T>* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }


private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

    Node<T>* findNode(const T& data) {
        auto tmp = head;
        while (tmp != nullptr && tmp->data != data) {
            tmp = tmp->next;
        }
        return tmp;
    }
};
