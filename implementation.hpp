template <size_t S>
Bitset<S>::Bitset() : m_ptr(nullptr){}

template <size_t S>
Bitset<S>::Bitset(int number)
{
    if (!m_ptr) {
        delete m_ptr;
    }
    m_ptr = new char[S];
    int i = S - 1;
    if (number >= 0) {
        while (number) {
            m_ptr[i--] = number % 2;
            number /= 2;
        }
        while (i > -1) {
            m_ptr[i--] = 0;
        }
    } else {
        ~number;
        while (number) {
            m_ptr[i--] = number % 2;
            number /= 2;
        }
        while (i > -1) {
            m_ptr[i--] = 0;
        }
        for (int i = 0; i < S; ++i) {
            m_ptr[i] = !m_ptr[i];
        }
    }
}

template <size_t S>
Bitset<S>::Bitset(const Bitset& ob)
{
    if (this != &ob) {
        m_ptr = new char[S];
        for (int i = 0; i < S; ++i) {
            m_ptr[i] = ob.m_ptr[i];
        }
    }
}

template <size_t S>
Bitset<S>::~Bitset<S>()
{
    if (m_ptr) {
        delete m_ptr;
        m_ptr = nullptr;
    }
}

template <size_t S>
Bitset<S>& Bitset<S>::operator=(const Bitset& ob)
{
    if (this == &ob) {
        return *this;
    }
    for (int i = 0; i < S; ++i) {
        m_ptr[i] = ob.m_ptr[i];
    }
    return *this;
}

template <size_t S>
Bitset<S>& Bitset<S>::operator&=(const Bitset& ob)
{
    if (!ob.m_ptr) {
        return *this;
    }
    for (int i = S - 1; i >= 0; --i) {
        m_ptr[i] &= ob.m_ptr[i];
    }
    return *this;
}

template <size_t S>
Bitset<S>& Bitset<S>::operator|=(const Bitset& ob)
{
    if (!ob.m_ptr) {
        return *this;
    }
    for (int i = S - 1; i >= 0; --i) {
        m_ptr[i] |= ob.m_ptr[i];
    }
    return *this;
}

template <size_t S>
Bitset<S>& Bitset<S>::operator^=(const Bitset& ob)
{
    if (!ob.m_ptr) {
        return *this;
    }
    for (int i = S - 1; i >= 0; --i) {
        m_ptr[i] ^= ob.m_ptr[i];
    }
    return *this;
}

template <size_t S>
Bitset<S>& Bitset<S>::operator<<=(int count)
{
    char arr[S];
    for(int i = 0; i < S; ++i) {
        arr[i] = m_ptr[S-i-1];
    }
    for (int i = 0; i < count; ++i) {
        m_ptr[S-1-i] = 0;
    }
    int j = 0;
    for (int i = S - count - 1; i >= 0; --i) {
        m_ptr[i] = arr[j++];
    }
    return *this;
}

template <size_t S>
Bitset<S>& Bitset<S>::operator>>=(int count)
{
    char arr[S];
    for (int i = 0; i < S; ++i) {
        arr[i] = m_ptr[i];
    }
    for (int i = 0; i < count; ++i) {
        m_ptr[i] = 0;
    }
    int j = 0;
    for (int i = count; i < S; ++i) {
        m_ptr[i] = arr[j++];
    }
    return *this;
}

template <size_t S>
Bitset<S> Bitset<S>::operator>>(int count) const
{
    Bitset<S> pp(*this);
    pp >>= count;
    return pp;
}

template <size_t S>
Bitset<S> Bitset<S>::operator<<(int count) const
{
    Bitset<S> pp(*this);
    pp <<= count;
    return pp;
}

template <size_t S>
Bitset<S> Bitset<S>::operator~()
{
    char arr[S];
    for (int i = 0; i < S; ++i) {
        arr[i] = m_ptr[i];
        m_ptr[i] = !m_ptr[i];
    }
    Bitset<S> pp(*this);
    for (int i = 0; i < S; ++i) {
        m_ptr[i] = arr[i];
    }
    return pp;
}

template <size_t S>
bool operator==(const Bitset<S>& ob1, const Bitset<S>& ob2)
{
    for (int i = S-1; i >= 0; --i) {
        if (ob1.m_ptr[i] != ob2.m_ptr[i]) {
            return false;
        }
    }
    return true;
}

template <size_t S>
bool operator==(const Bitset<S>& ob1, const int& ob2)
{
    Bitset<S> tmp = ob2;
    return (ob1 == tmp);
}

template <size_t S>
bool operator==(const int& ob1, const Bitset<S>& ob2)
{
    Bitset<S> tmp = ob1;
    return (tmp == ob2);
}

template <size_t S>
bool operator!=(const Bitset<S>& ob1, const Bitset<S>& ob2)
{
    return !(ob1 == ob2);
}

template <size_t S>
bool operator!=(const Bitset<S>& ob1, const int& ob2)
{
    Bitset<S> tmp = ob2;
    return !(ob1 == tmp);
}

template <size_t S>
bool operator!=(const int& ob1, const Bitset<S>& ob2)
{
    Bitset<S> tmp = ob1;
    return !(tmp == ob2);
}

template <size_t S>
bool operator>=(const Bitset<S>& ob1, const Bitset<S>& ob2)
{
    int x = ob1.get();
    int x2 = ob2.get();
    return (x >= x2);
}

template <size_t S>
bool operator>=(const Bitset<S>& ob1, const int& ob2)
{
    int x = ob1;
    return (x >= ob2);
}

template <size_t S>
bool operator>=(const int& ob1, const Bitset<S>& ob2)
{
    int x = ob2.get();
    return (ob1 >= x);
}

template <size_t S>
bool operator<=(const Bitset<S>& ob1, const Bitset<S>& ob2)
{
    int x = ob1.get();
    int x2 = ob2.get();
    return (x <= x2);
}

template <size_t S>
bool operator<=(const Bitset<S>& ob1, const int& ob2)
{
    int x = ob1;
    return (x <= ob2);
}

template <size_t S>
bool operator<=(const int& ob1, const Bitset<S>& ob2)
{
    int x = ob2.get();
    return (ob1 <= x);
}

template <size_t S>
bool operator<(const Bitset<S>& ob1, const Bitset<S>& ob2)
{
    int x = ob1.get();
    int x2 = ob2.get();
    return (x < x2);
}

template <size_t S>
bool operator<(const Bitset<S>& ob1, const int& ob2)
{
    int x = ob1;
    return (x < ob2);
}

template <size_t S>
bool operator<(const int& ob1, const Bitset<S>& ob2)
{
    int x = ob2.get();
    return (ob1 < x);
}
template <size_t S>
bool operator>(const Bitset<S>& ob1, const Bitset<S>& ob2)
{
    int x = ob1.get();
    int x2 = ob2.get();
    return (x > x2);
}

template <size_t S>
bool operator>(const Bitset<S>& ob1, const int& ob2)
{
    int x = ob1;
    return (x > ob2);
}

template <size_t S>
bool operator>(const int& ob1, const Bitset<S>& ob2)
{
    int x = ob2.get();
    return (ob1 > x);
}

template <size_t S>
bool Bitset<S>::operator[](int index) const
{
    if (index >= S || index <= -1) {
        std::cout << "undifine";
        return false;
    }
    return m_ptr[S - 1 - index];
}

template <size_t S>
char* Bitset<S>::operator[](int index)
{
    char* p = &m_ptr[S-1-index];
    return p;
}

template <size_t S>
std::ostream& operator<<(std::ostream& os, const Bitset<S>& ob)
{
    int k = 0;
    int j = 3;
    if (!ob.m_ptr) {
        os << "empty";
        return os;
    }
    for (int i = 0; i < S; ++i) {
        os << (int)ob.m_ptr[i];
        if (k < j) {
            ++k;
        } else {
            k = 0;
            os << " ";
        }
    }
    return os;
}

template <size_t S>
int Bitset<S>::get() const
{
    int tmp = 0;
    int i = S - 1;
    int N = 1;
    while (i >= -1) {
        tmp += N * this->m_ptr[i--];
        N *= 2;
    }
    return tmp;
}

template <size_t S>
void Bitset<S>::swap(Bitset& ob)
{
    Bitset<S> tmp(ob);
    ob = (*this);
    *this = tmp;
}

template <size_t S>
void Bitset<S>::reverse()
{
    int j = S - 1;
    for (int i = 0; i < j; ++i) {
        char ch = m_ptr[i];
        m_ptr[i] = m_ptr[j];
        m_ptr[j--] = ch;
    }
}

template <size_t S>
void Bitset<S>::clear()
{
    if (m_ptr) {
        for (int i = 0;i < S; ++i) {
            m_ptr[i] = 0;
        }
    }
}

template <size_t S>
Bitset<S>& Bitset<S>::set()
{
    for (int i = 0; i < S; ++i) {
        m_ptr[i] = 1;
    }
    return *this;
}

template <size_t S>
Bitset<S>& Bitset<S>::set(int index, bool b)
{
    m_ptr[S-1-index] = b;
    return *this;
}

template <size_t S>
Bitset<S>& Bitset<S>::reset()
{
    for(int i = 0; i < S; ++i) {
        m_ptr[i] = 0;
    }
    return *this;
}

template <size_t S>
Bitset<S>& Bitset<S>::reset(int index)
{
    m_ptr[S-1-index] = 0;
    return *this;
}

template <size_t S>
Bitset<S>& Bitset<S>::flip()
{
    *this = ~*this;
    return *this;
}

template <size_t S>
Bitset<S>& Bitset<S>::flip(int index)
{
    m_ptr[S-1-index] = !m_ptr[S-1-index];
    return *this;
}

template <size_t S>
bool Bitset<S>::test(int index)
{
    return m_ptr[S-1-index];
}

template <size_t S>
bool Bitset<S>::any() const
{
    for (int i = 0; i < S; ++i) {
        if (m_ptr[i]) {
            return true;
        }
    }
    return false;
}

template <size_t S>
bool Bitset<S>::none() const
{
    return !any();
}

template <size_t S>
int Bitset<S>::count() const
{
    int num = 0;
    for (int i = 0; i < S; ++i) {
        if (m_ptr[i]) {
            ++num;
        }
    }
    return num;
}

template <size_t S>
int Bitset<S>::size() const
{
    return S;
}
