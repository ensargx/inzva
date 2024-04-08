// Brace your keyboard
// inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

int main()
{
    // write your code here
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::string s;
    std::cin >> s;

    // remove all 'BUCODE' from the string
    std::string bucode = "BUCODE";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
        {
            bool found = true;
            for (int j = 0; j < bucode.size(); j++)
            {
                if (s[i + j] != bucode[j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                s.erase(i, bucode.size());
                i = -1;
            }
        }
    }

    if (s.size() == 0)
    {
        std::cout << "UTKU";
        return 0;
    }
    std::cout << s << std::endl;

    return 0;
}