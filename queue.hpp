/**
 * @brief Queue implementation using std::vector and templates
 * @author Ulysse Bouchet
 * @date 15/03/2020
 */

#ifndef CPP_QUEUE_HPP
#define CPP_QUEUE_HPP

#include <vector>
#include <stdexcept>

/**
 * @brief Stack implementation
 * @tparam T The type/class of the queue elements
 */
template <typename T>
class Queue {
    private:
        std::vector<T> m_queue;
    public:
        void push(T t);
        T pop();
        T front();
        int size();
        bool empty();
};

/**
 * @brief Returns the element at the front of the queue, or throws an exception if the stack is empty
 * @tparam T The type/class of the queue elements
 * @return The element at the front of the queue
 */
template <typename T>
void Queue<T>::push(T t) {
    m_queue.push_back(t);
}

/**
 * @brief Returns and removes the element at the front of the queue, or throws an exception if the queue is empty
 * @tparam T The type/class of the queue elements
 * @return The element at the front of the queue
 */
template <typename T>
T Queue<T>::pop(){
    if (empty())
        throw std::out_of_range("Queue is empty.");
    T t = m_queue.front();
    m_queue.erase(m_queue.begin());
    return t;
}

/**
 * @brief Adds an element at the back of the queue
 * @tparam T The type/class of the queue elements
 * @param t The element to add
 */
template <typename T>
T Queue<T>::front() {
    if (empty())
        throw std::out_of_range("Queue is empty.");
    return m_queue.front();
}

/**
 * @brief Returns the queue's size
 * @tparam T The type/class of the queue elements
 * @return the queue's size
 */
template <typename T>
int Queue<T>::size() {
    return m_queue.size();
}

/**
 * @brief Checks if the queue is empty
 * @tparam T The type/class of the queue elements
 * @return true if the queue is empty, else false
 */
template <typename T>
bool Queue<T>::empty(){
    return m_queue.empty();
}

#endif //CPP_QUEUE_HPP