#include"MyVector.h"

int main()
{
    try {
        cout << "Test Message:" << endl;
        cout << "Create a empty vector, execute  \"Vector<int> a;\"" << endl;
        Vector<int> a;
        cout << "Judge if a is empty,execute \"a.empty()\" :";
        if (a.empty())cout << "Empty" << endl;
        try {
            cout << "Get invalid index by calling \"a.at(10)\" :";
            int t = a.at(10);
        }
        catch (std::out_of_range& exc) {
            std::cerr << exc.what() << " Line:" << __LINE__ << " File:" << __FILE__ << endl;
        }
        cout << "Insert 1,2,3,4,5,6 one by one :(call a.push_back(int)) :" << endl;
        a.push_back(1);
        a.push_back(2);
        a.push_back(3);
        a.push_back(4);
        a.push_back(5);
        a.push_back(6);
        cout << "Test constructor function \"Vector<int> b(a);\"" << endl;;
        Vector<int> b(a);
        cout << "a.Size = " << a.GetSize() << endl;
        cout << "a.Cap = " << a.GetCap() << endl;
        cout << "b.Size = " << b.GetSize() << endl;
        cout << "b.Cap = " << b.GetCap() << endl;
        cout << "a's elements:" << endl;
        for (int i = 0; i < a.GetSize(); i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "Test and execute function  \"a.clear();\"" << endl;
        a.clear();
        cout << "Size = " << a.GetSize() << endl;
        cout << "Cap = " << a.GetCap() << endl;
        cout << "a's elements:" << endl;
        for (int i = 0; i < a.GetSize(); i++)
            cout << a[i] << " ";
        cout << "Judge if a is empty,execute \"a.empty()\" :";
        if (a.empty())cout << "Empty" << endl;
        Vector <int>c(10);
        cout << "Test and execute function  \" Vector <int>c(10);\"" << endl;
        cout << "Size = " << c.GetSize() << endl;
        cout << "Cap = " << c.GetCap() << endl;
    }
    catch (...) {
        cout << "exit because some unexcepted reasons" << endl;
    }
}

