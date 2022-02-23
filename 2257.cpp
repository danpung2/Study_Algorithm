#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
    string str;
    int i;
    int tmp;
    int total = 0;
    stack<string> s;
    cin >> str;

    for (i = 0; i < str.length(); i++)
    {
        string ch(1, str.at(i));
        if (ch == ")")
        {
            tmp = 0;
            while (s.top() != "(")
            {
                if (s.top() == "H")
                    tmp += 1;
                else if (s.top() == "C")
                    tmp += 12;
                else if (s.top() == "O")
                    tmp += 16;
                else
                    tmp += stoi(s.top());
                s.pop();
            }
            s.pop();
            s.push(to_string(tmp));
        }
        else if ("1" <= ch && ch <= "9")
        {
            tmp = 0;
            if (s.top() == "H")
                tmp = 1;
            else if (s.top() == "C")
                tmp = 12;
            else if (s.top() == "O")
                tmp = 16;
            else
                tmp = stoi(s.top());
            s.pop();
            tmp = tmp * stoi(ch);
            s.push(to_string(tmp));
        }
        else
            s.push(ch);
    }

    while (s.size() > 0)
    {
        if (s.top() == "H")
            total += 1;
        else if (s.top() == "C")
            total += 12;
        else if (s.top() == "O")
            total += 16;
        else
            total += stoi(s.top());
        s.pop();
    }

    cout << total << endl;

    return 0;
}