#include <iostream>
using namespace std;

class Hash_Table
{
    int data[10] = {0};
    bool flag[10] = {0};

public:
    int insert(int key)
    {
        int loc = key % 10;
       
        for (int i = 0; i < 10; i++)
        {  
            if (flag[loc] == 0)
            {
                data[loc] = key;
                flag[loc] = 1;
                return (key);
            }
            loc = (loc + 1) % 10; //increment loc and dont increment key;
        }
        return (-1);
    }
    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << data[i] << "  ";
        }
        cout << endl;
    }
};

int main()
{
    Hash_Table h;
    h.insert(5);
    h.insert(18);
    h.insert(55);
    h.insert(78);
    h.insert(35);
    h.insert(15);
    h.display();
}