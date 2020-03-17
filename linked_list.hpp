/**
 * @brief Linked list implementation using struct and templates
 * @author Ulysse Bouchet
 * @date 15/03/2020
 */

#ifndef CPP_LINKED_LIST_HPP
#define CPP_LINKED_LIST_HPP

#include <stdexcept>

/**
 * @brief Linked list implementation
 * @tparam T The type/class of the list elements
 */
template <typename T>
class LinkedList {
    /**
     * @brief Linked list node implementation
     */
    struct Node {
        T m_value; //Node value
        Node* m_next; //Pointer to the next node
    };

    private:
        Node* m_head; //The node at the front of the list
        int m_size; //The size of the list

    public:
        LinkedList ();
        T get (int index);
        void add (T value);
        void insert (int index, T value);
        void remove (int index);
        bool empty ();
        bool contains (T value);
        int size ();
};

/**
 * @brief Default list constructor
 * @tparam T The type/class of the list elements
 */
template <typename T>
LinkedList<T>::LinkedList() : m_size {0}, m_head {NULL} { }

/**
 * @brief Returns the value of the node at a given index
 * @tparam T The type/class of the list elements
 * @param index The index of the node in the list
 * @return the value corresponding to the index
 */
template <typename T>
T LinkedList<T>::get (int index) {
    if (index >= size())
        throw std::out_of_range("Index out of range.");

    Node* cur {m_head};

    int cpt {0};
    while (cpt++ != index)
        cur = cur->m_next;

    return cur->m_value;
}

/**
 * @brief Adds a value at the end of the list
 * @tparam T The type/class of the list elements
 * @param value the value to add to the list
 */
template <typename T>
void LinkedList<T>::add (T value) {
    Node *n = new Node();
    n->m_value = value;
    n->m_next = NULL;

    if (m_head == NULL) {
        m_head = n;
        ++m_size;
        return;
    }

    Node *cur {m_head};
    while (cur->m_next != NULL)
        cur = cur->m_next;


    cur->m_next = n;
    ++m_size;
}

/**
 * @brief Inserts a value at a given position in the list
 * @tparam T The type/class of the list elements
 * @param index the position where the value needs to be inserted
 * @param value the value to insert to the list
 */
template <typename T>
void LinkedList<T>::insert (int index, T value) {
    if (index > size())
        throw std::out_of_range("Index out of range.");

    if (index == size()) {
        add(value);
        return;
    }
    Node *n = new Node();
    n->m_value = value;

    if (index == 0) {
        n->m_next = m_head;
        m_head = n;
        return;
    }

    int cpt {0};
    Node *cur {m_head};
    while (++cpt != index) {
        cur = cur->m_next;
    }

    n->m_next = cur->m_next;

    cur->m_next = n;
    ++m_size;
}

/**
 * @brief Removes the value for a given position in the list
 * @tparam T The type/class of the list elements
 * @param index the position where an element needs to be removed
 */
template <typename T>
void LinkedList<T>::remove (int index) {
    if (index >= size())
        throw std::out_of_range("Index out of range.");

    if (index == 0) {
        m_head = m_head->m_next;
        --m_size;
        return;
    }

    int cpt {0};
    Node *cur = m_head;
    while (++cpt != index)
        cur = cur->m_next;

    cur->m_next = cur->m_next->m_next;
    --m_size;
}

/**
 * @brief Checks if the list is empty
 * @tparam T The type/class of the list elements
 * @return true if it is empty, else false
 */
template <typename T>
bool LinkedList<T>::empty () {
    return m_head == NULL;
}

/**
 * @brief Checks if the list contains an element
 * @tparam T The type/class of the list elements
 * @param value The value to check if it is contained
 * @return true if it contains the element, else false
 */
template <typename T>
bool LinkedList<T>::contains (T value) {
    if (empty())
        return false;

    Node *cur = m_head;
    while (cur) {
        if (cur->m_value == value)
            return true;
        cur = cur->m_next;
    }
    return false;
}

/**
 * @brief Returns the size of the list
 * @tparam T The type/class of the list elements
 * @return the size of the list
 */
template <typename T>
int LinkedList<T>::size () {
    return m_size;
}

#endif //CPP_LINKED_LIST_HPP
