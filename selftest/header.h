struct A
{
    int &_data;
    A(int &data) : _data(data) {}
    void Incr() const { _data++; }
};

A Fn()
{
    int d = 0;
    return A(d);
}

int GetData()
{
    return 0;
}

void Incr(int &data) 
{
    data++;
}

