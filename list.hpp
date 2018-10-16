#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <functional>

template <typename T>
struct List {
private:
    struct Node {
        Node(T data, Node * const next) : data(std::move(data)), next(next) {};
        Node(Node const & rhs) = delete;
        Node(Node && rhs) :
            data(std::move(rhs.data)),
            next(rhs.next)
        {
            rhs.next = nullptr;
        }

        ~Node() {
            if (!next) return;
            delete next;
        }

        T * find(T const & rhs) {
            if (data == rhs) return &data;
            if (!next) return nullptr;
            return next->find(rhs);
        }

        T data;
        Node * next { nullptr };
    };

	Node * head { nullptr };

public:
    List() = default;
    List(List const & rhs) = delete;
    List(List && rhs) : head(rhs.head) {
        rhs.head = nullptr;
    }

	~List() {
        if (head) delete head;
    }

	void insert_sort_by(T data, std::function<bool(T const &, T const &)> greater_than) {
        Node ** iter { &head };

        while(*iter && greater_than((*iter)->data, data)) {
            iter = &(*iter)->next; // advance
        }

        *iter = new Node { std::move(data), *iter };
    }

    void push_front(T data) {
        head = new Node { std::move(data), head };
    }

    void filter(std::function<bool(T const &)> keep) {
        Node ** iter { &head };

        while (*iter) {
            if (!keep((*iter)->data)) {
                Node * deleted { *iter };
                *iter = deleted->next; // remove deleted from list
                deleted->next = nullptr; // disconnect list from deleted
                delete deleted;
                continue;
            }

            iter = &(*iter)->next; // advance
        }
    }

    void for_each(std::function<void(T &)> func) {
        for (Node * iter { head }; iter; iter = iter->next)
            func(iter->data);
    }

    T extract(T const& rhs) {
        Node ** iter { &head };

        while (*iter) {
            if ((*iter)->data == rhs) {
                Node * extract { *iter };
                *iter = extract->next; // remove extracted from list
                extract->next = nullptr; // disconnect list from extracted
                T data = std::move(extract->data);
                delete extract;
                return data;
            }

            iter = &(*iter)->next; // advance
        }

        throw std::runtime_error("Item not found.");
    }

    T * find(T const& rhs) const {
        if (!head) return nullptr;
        return head->find(rhs);
    }

	friend std::ostream & operator<<(std::ostream & out, List<T> const & list) {
        for (Node * curr { list.head }; curr; curr = curr->next)
            out << '\n' << curr->data;

        return out;
    }
};

#endif
