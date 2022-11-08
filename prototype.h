#ifndef PROTOTYPE_H
#define PROTOTYPE_H

template <size_t S>
class Bitset {
public:
        Bitset();
        Bitset(int);
        Bitset(const Bitset&);
        Bitset& operator=(const Bitset&);
        ~Bitset();
public:
        Bitset& operator&=(const Bitset&);
        Bitset& operator|=(const Bitset&);
        Bitset& operator^=(const Bitset&);
        Bitset operator<<(int) const;
        Bitset operator>>(int) const;
        Bitset& operator<<=(int);
        Bitset& operator>>=(int);
        Bitset operator~();
        char* operator[](int);
        bool operator[](int) const;
        template <size_t SS>
        friend bool operator==(const Bitset<SS>&, const Bitset<SS>&);
        template <size_t SS>
        friend bool operator==(const Bitset<SS>&, const int&);
        template <size_t SS>
        friend bool operator==(const int&, const Bitset<SS>&);
        template <size_t SS>
        friend bool operator!=(const Bitset<SS>&, const Bitset<SS>&);
        template <size_t SS>
        friend bool operator!=(const Bitset<SS>&, const int&);
        template <size_t SS>
        friend bool operator!=(const int&, const Bitset<SS>&);
        template <size_t SS>
        friend bool operator>=(const Bitset<SS>&, const Bitset<SS>&);
        template <size_t SS>
        friend bool operator>=(const Bitset<SS>&, const int&);
        template <size_t SS>
        friend bool operator>=(const int&, const Bitset<SS>&);
        template <size_t SS>
        friend bool operator<=(const Bitset<SS>&, const Bitset<SS>&);
        template <size_t SS>
        friend bool operator<=(const Bitset<SS>&, const int&);
        template <size_t SS>
        friend bool operator<=(const int&, const Bitset<SS>&);
        template <size_t SS>
        friend bool operator<(const Bitset<SS>&, const Bitset<SS>&);
        template <size_t SS>
        friend bool operator<(const Bitset<SS>&, const int&);
        template <size_t SS>
        friend bool operator<(const int&, const Bitset<SS>&);
        template <size_t SS>
        friend bool operator>(const Bitset<SS>&, const Bitset<SS>&);
        template <size_t SS>
        friend bool operator>(const Bitset<SS>&, const int&);
        template <size_t SS>
        friend bool operator>(const int&, const Bitset<SS>&);
        template <size_t SS>
        friend std::ostream& operator<<(std::ostream&, const Bitset<SS>&);
public:
        int get() const;
        void swap(Bitset&);
        void reverse();
        void clear();
        Bitset& set();
        Bitset& set(int, bool = true);
        Bitset& reset();
        Bitset& reset(int);
        Bitset& flip();
        Bitset& flip(int);
        bool test(int);
        bool any() const;
        bool none() const;
        int count() const;
        int size() const;
private:
        char* m_ptr;
};
#include "implementation.hpp"
#endif //PROTOTYPE_H
