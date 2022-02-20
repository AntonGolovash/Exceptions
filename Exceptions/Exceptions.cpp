#include <iostream>
#include <climits>
using namespace std;

class IOExceptionDivideByZero : exception
{
public:
    virtual char const* what() const override
    {
        return "Divide by zero:";
    }
};

static double Divide(double x, double y)
{
    if (x == 0 || y == 0)
    {
        throw IOExceptionDivideByZero();
    }
    return x / y;
}

int main()
{
    try
    {
        cout << Divide(5, 0) << endl;
    }
    catch (const IOExceptionDivideByZero& ex)// One check
    {
        cerr << ex.what() << endl;
        return 1;
    }
    catch (const exception& ex)// Two check
    {
        cerr << ex.what() << endl;
        return 1;
    }
    catch (...)// Last chance
    {
        return 1;
    }
    system("pause");
    return 0;
}
