#ifndef DATA_H
#define DATA_H

class Data
{
public:
    Data(int = 17, int = 2, int = 2016);
    ~Data();
    
    void print() const;
    void setDate(int, int, int);
private:
    int mes;
    int dia;
    int ano;

    int checarDia(int) const;

};

#endif // DATA_H
