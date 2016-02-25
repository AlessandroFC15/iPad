#ifndef DATA_H
#define DATA_H

# include <iostream>

using namespace std;

class Data
{
    friend ostream &operator<<(ostream &, const Data &);
public:
    Data(int = 17, int = 2, int = 2016);
    Data(const Data &);
    ~Data();
    
    const Data &operator=(const Data &);
    bool operator==(const Data &) const;
    bool operator!=(const Data &data) const
    {
        return ! (*this == data);
    }
    
    void setDate(int, int, int);
private:
    int mes;
    int dia;
    int ano;

    int checarDia(int) const;

};

#endif // DATA_H
