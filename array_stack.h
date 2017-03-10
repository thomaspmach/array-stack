#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint> // std::size_t
#include <stdexcept> // C++ exceptions

namespace structures {

template<typename T>
class ArrayStack {
public:
    //! Construtor
    /*!
        Cria um array com o tamanho de DEFAULT_SIZE e inicializa top_ com -1
    */
    ArrayStack();

    //! Construtor que cria array com tamanho do parametro
    /*!
        \param max tipo size_t demarca o tamanho do array criado
        Cria um array com o tamanho do parametro e inicializa top_ com -1
    */
    ArrayStack(std::size_t max);

    //! Destrutor
    ~ArrayStack();

    //! Funçao Push na Pilha
    /*!
        \param data elemento a ser inserido na pila
        \return void
        Se pilha estiver cheia retorna excessão, senão adiciona elemento na pilha
        e incrementa _top
    */
    void push(const T& data); // empilha

     //! Funçao Pop na Pilha
    /*!
        \return T
        Se pilha estiver vazia retorna excessão, senão retorna primeiro elemento
        e decrementa _top
    */
    T pop(); // desempilha

    //! Funcao top
    /*!
        \return &T
        Se pilha estiver vazia retorna excessão, senão retorna primeiro elemento
    */
    T& top();

    //! Funcao Clear
    /*!
        \return void
        atribui -1 à top
    */
    void clear(); // limpa
    
    //! Funcao Size
    /*!
        \return size_t
        Retorna tamanho da pilha
    */
    std::size_t size(); // tamanho

    //! Funcao max_size
    /*!
        \return size_t
        Retorna tamanho máximo possível da pilha
    */
    std::size_t max_size();

    //! Funcao empty
    /*!
        \return bool
        Retorna true caso pilha esiver vazia
    */
    bool empty(); // vazia

    //! Funcao empty
    /*!
        \return bool
        Retorna true caso pilha esiver cheia
    */
    bool full(); // cheia

private:
    //! Ponteiro T
    /*!
        Aponta para a pilha
    */
    T* contents;
    
    //! Uma variável int
    /*!
        Indica a posicao do topo da pilha
    */
    int top_;
    
    //! Uma variável size_t
    /*!
        Indica o tamanho maximo da pilha
    */
    std::size_t max_size_;

    //! Uma constante
    /*!
        Indica o tamanho maximo default da pilha
    */
    const static auto DEFAULT_SIZE = 10u;
};

template <class T>
ArrayStack<T>::ArrayStack() {
    top_ = -1;
    max_size_ = DEFAULT_SIZE;
    contents = new T[max_size_];
}

template <class T>
ArrayStack<T>::ArrayStack(std::size_t max) {
    top_ = -1;
    max_size_ = max;
    contents = new T[max_size_];
}

template <class T>
ArrayStack<T>::~ArrayStack() {
    delete contents;
}

template <class T>
bool ArrayStack<T>::empty() {
    return (top_ == -1);
}

template <class T>
bool ArrayStack<T>::full() {
    return (top_ + 1 == max_size_);
}

template <class T>
std::size_t ArrayStack<T>::size() {
    return (top_ + 1);    
}

template <class T>
std::size_t ArrayStack<T>::max_size() {
    return max_size_;    
}

template <class T>
void ArrayStack<T>::clear() {
    top_ = -1;    
}

template <class T>
T& ArrayStack<T>::top() {
    if (empty()) {
        throw std::out_of_range ("Empty Stack");
    }
    else {
        return contents[top_];
    }
}

template <class T>
T ArrayStack<T>::pop() {
    if (empty()) {
        throw std::out_of_range ("Empty Stack");
    }
    else {
        --top_;
        return contents[++top_];
    }
}

template <class T>
void ArrayStack<T>::push (const T& data) {
    if (full()) {
        throw std::out_of_range("Full Stack");
    }
    else {
        ++top_;
        contents[top_] = data;
    }
}

}

#endif
