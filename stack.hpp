/**
 * @brief Stack implementation using std::vector and templates
 * @author Ulysse Bouchet
 * @date 14/03/2020
 */

#ifndef CPP_STACK_HPP
    #define CPP_STACK_HPP

    #include <vector>
    #include <stdexcept>

    /**
     * @brief Stack implementation
     * @tparam T The type/class of the stack elements
     */
    template <typename T>
    class stack {
        private:
            std::vector<T> m_stack;
        public:
            T top();
            T pop();
            void push(T t);
            bool empty();
    };

    /**
     * @brief Returns the element at the top of the stack, or throws an exception if the stack is empty
     * @tparam T The type/class of the stack elements
     * @return The element at the top of the stack
     */
    template <typename T>
    T stack<T>::top() {
        if(empty())
            throw std::out_of_range("Stack is empty.");
        return m_stack.back();
    }

    /**
     * @brief Returns and removes the element at the top of the stack, or throws an exception if the stack is empty
     * @tparam T The type/class of the stack elements
     * @return The element at the top of the stack
     */
    template<typename T>
    T stack<T>::pop() {
        if(empty())
            throw std::out_of_range("Stack is empty.");
        T top = m_stack.back();
        m_stack.pop_back();
        return top;
    }

    /**
     * @brief Adds an element on top of the stack
     * @tparam T The type/class of the stack elements
     * @param t The element to add
     */
    template<typename T>
    void stack<T>::push(T t) {
        m_stack.push_back(t);
    }

    /**
     * @brief Checks if the stack is empty
     * @tparam T The type/class of the stack elements
     * @return true if the stack is empty, else false
     */
    template<typename T>
    bool stack<T>::empty() {
        return m_stack.empty();
    }

#endif //CPP_STACK_HPP