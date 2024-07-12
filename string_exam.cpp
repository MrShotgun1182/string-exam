// www.quera.ir code: 197002
#include <iostream>
using namespace std;

string shift (string);
string axks (string);
bool test (string ,string);

int main()
{
    int _round;

    cin >> _round;
    bool answer[_round];
    string index1 , index2;

    for (int i = 0 ; i < _round ; i++)
    {
        cin >> index1 >> index2;

        if (index1.length() != index2.length())
        {
            answer[i] = false;
            continue;
        }
        answer[i] = test (index1,index2);
    }

    for (int i = 0 ; i < _round ; i++)
    {
        if (answer[i])
        {
            cout << "YES";
        }
        else 
        {
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}

string shift (string index){
    string index_fun = index;
    index_fun[0] = index[index.length() - 1];
    for (int i = 0 ; i < index.length() - 1 ; i++ )
    {
        index_fun[i+1] = index[i];
    }
    return index_fun;
}

string axks (string index){
    int count = index.length() - 1;
    string index_fun=index;
    for (int i = 0 ; i < index.length() ; i++)
    {
        index_fun[count] = index[i];
        count --;
    }
    return index_fun;
}

bool test (string index1 , string index2){
    int count=0;
    while (true)
    {
        if (index1 == index2)
        {
            return true;
        }
        
        index2 = shift(index2);
        count ++;
        if (count == index1.length())
        {
            index2 = axks (index2);
        }
        else if (count == index1.length() * 2)
        {
            return false ;
        }
    }
    
}