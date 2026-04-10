#pragma once

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <utility>

template <typename T>
class LinkedList {
private:
    struct Node {
        T value;
        std::unique_ptr<Node> next;

        template <typename U>
        explicit Node(U&& v) : value(std::forward<U>(v)), next(nullptr) {}
    };

    std::unique_ptr<Node> head_{};
    Node* tail_{nullptr};
    std::size_t size_{0};

public:
    class iterator {
    public:
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using reference = T&;
        using pointer = T*;
        using iterator_category = std::forward_iterator_tag;

        iterator() = default;
        explicit iterator(Node* p) : current_(p) {}

        reference operator*() const { return current_->value; }
        pointer operator->() const { return &current_->value; }

        iterator& operator++() {
            current_ = current_ ? current_->next.get() : nullptr;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        friend bool operator==(const iterator& a, const iterator& b) {
            return a.current_ == b.current_;
        }

        friend bool operator!=(const iterator& a, const iterator& b) {
            return !(a == b);
        }

    private:
        Node* current_{nullptr};
    };

    class const_iterator {
    public:
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using reference = const T&;
        using pointer = const T*;
        using iterator_category = std::forward_iterator_tag;

        const_iterator() = default;
        explicit const_iterator(const Node* p) : current_(p) {}
        const_iterator(iterator it) : current_(it.operator->() ? nullptr : nullptr) {
            // iterator -> const_iterator 변환을 위해 별도 생성자 제공 대신 begin/end에서 직접 생성 사용 권장
            // (아래 const begin/end는 Node* 접근이 가능하므로 문제 없음)
        }

        reference operator*() const { return current_->value; }
        pointer operator->() const { return &current_->value; }

        const_iterator& operator++() {
            current_ = current_ ? current_->next.get() : nullptr;
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        friend bool operator==(const const_iterator& a, const const_iterator& b) {
            return a.current_ == b.current_;
        }

        friend bool operator!=(const const_iterator& a, const const_iterator& b) {
            return !(a == b);
        }

    private:
        const Node* current_{nullptr};
    };

    LinkedList() = default;

    LinkedList(std::initializer_list<T> init) {
        for (const auto& v : init) {
            push_back(v);
        }
    }

    LinkedList(const LinkedList& other) {
        for (const auto& v : other) {
            push_back(v);
        }
    }

    LinkedList(LinkedList&& other) noexcept
        : head_(std::move(other.head_)), tail_(other.tail_), size_(other.size_) {
        other.tail_ = nullptr;
        other.size_ = 0;
    }

    LinkedList& operator=(LinkedList other) noexcept {
        swap(other);
        return *this;
    }

    ~LinkedList() = default;

    void swap(LinkedList& other) noexcept {
        using std::swap;
        swap(head_, other.head_);
        swap(tail_, other.tail_);
        swap(size_, other.size_);
    }

    [[nodiscard]] bool empty() const noexcept { return size_ == 0; }
    [[nodiscard]] std::size_t size() const noexcept { return size_; }

    T& front() {
        if (empty()) throw std::out_of_range("LinkedList::front: empty list");
        return head_->value;
    }

    const T& front() const {
        if (empty()) throw std::out_of_range("LinkedList::front: empty list");
        return head_->value;
    }

    T& back() {
        if (empty()) throw std::out_of_range("LinkedList::back: empty list");
        return tail_->value;
    }

    const T& back() const {
        if (empty()) throw std::out_of_range("LinkedList::back: empty list");
        return tail_->value;
    }

    void push_front(const T& value) { emplace_front(value); }
    void push_front(T&& value) { emplace_front(std::move(value)); }

    template <typename... Args>
    T& emplace_front(Args&&... args) {
        auto node = std::make_unique<Node>(T(std::forward<Args>(args)...));
        if (!head_) {
            tail_ = node.get();
        } else {
            node->next = std::move(head_);
        }
        head_ = std::move(node);
        ++size_;
        return head_->value;
    }

    void push_back(const T& value) { emplace_back(value); }
    void push_back(T&& value) { emplace_back(std::move(value)); }

    template <typename... Args>
    T& emplace_back(Args&&... args) {
        auto node = std::make_unique<Node>(T(std::forward<Args>(args)...));
        Node* new_tail = node.get();

        if (!head_) {
            head_ = std::move(node);
            tail_ = new_tail;
        } else {
            tail_->next = std::move(node);
            tail_ = new_tail;
        }

        ++size_;
        return tail_->value;
    }

    void pop_front() {
        if (empty()) throw std::out_of_range("LinkedList::pop_front: empty list");
        head_ = std::move(head_->next);
        --size_;
        if (!head_) tail_ = nullptr;
    }

    void clear() noexcept {
        head_.reset();
        tail_ = nullptr;
        size_ = 0;
    }

    iterator begin() noexcept { return iterator(head_.get()); }
    iterator end() noexcept { return iterator(nullptr); }

    const_iterator begin() const noexcept { return const_iterator(head_.get()); }
    const_iterator end() const noexcept { return const_iterator(nullptr); }

    const_iterator cbegin() const noexcept { return const_iterator(head_.get()); }
    const_iterator cend() const noexcept { return const_iterator(nullptr); }
};