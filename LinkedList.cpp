#include <iostream>


template<typename T>
class LinkedList {

public:
    LinkedList();
    ~LinkedList();
    T front() const;
    void pop_front();
    void push_front(T data);
    void push_back(T data);
    void print_list() const;
    int size();
    bool empty();

private:

    class Node {
    public:
        Node *next;
        T data;

        Node(T data = T(), Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };

    Node *head;
    Node *tail;
    int size_;

};

template<typename T>
LinkedList<T>::LinkedList() {
    size_ = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while(!empty()) {
        pop_front();
    }
}

template<typename T>
int LinkedList<T>::size() {
    return size_;
}

template<typename T>
bool LinkedList<T>::empty() {
    return size_ == 0;
}

template<typename T>
T LinkedList<T>::front() const{
    if (head == nullptr) {
        return T();
    }
    return head->data;
}

template<typename T>
void LinkedList<T>::pop_front() {
    if (head == nullptr) {
        return;
    }

    if (size_ == 1) {
        tail = nullptr;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
    --size_;
}

template<typename T>
void LinkedList<T>::push_front(T data) {
    if (head == nullptr) {
        head = new Node(data);
        tail = head;
    } else {
        Node *tmp = head;
        head = new Node(data);
        head->next = tmp;
    }

    size_++;
}

template<typename T>
void LinkedList<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node(data);
        tail = head;
    } else {
        tail->next = new Node(data);
        tail = tail->next;
    }

    size_++;
}

template<typename T>
void LinkedList<T>::print_list() const{

        for (Node *cur = head; cur != nullptr; cur = cur->next) {
            std::cout << cur->data << " ";
        }

}
