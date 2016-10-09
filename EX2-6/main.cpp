#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, const char * argv[])
{
    string s(5, '\0');
    s[0] = 'a';
    printf("%s\n", s.c_str());
    s = "abcde";
    printf("%s\n", s.c_str());
    printf("%lu\n", s.length());
    s.push_back('a');
    printf("%s\n", s.c_str());
    printf("%ld\n", count(s.begin(), s.end(), 'a'));
    printf("%s\n", s.erase(2, 2).c_str());
    printf("%s\n", s.erase(0, 1).c_str());

    char buf[] = "Hello";
    s = string(buf);
    printf("%s\n", s.c_str());
    printf("%lu\n", strchr(s.c_str(), 'l') - s.c_str());
    printf("%lu\n", s.find("l"));
    printf("%lu\n", s.find("el"));

    // #3.
    char c = 'l';
    unsigned long int ch = strchr(s.c_str(), c)-s.c_str();
    while( ch <= s.length() )
    {
        s.erase(ch, 1);
        ch = strchr(s.c_str(), c)-s.c_str();
    }
    printf("%s\n", s.c_str());

    // #4.
    s = "Hello";
    string w = "el";
    string x = "le";
    s.replace(s.find(w), x.length(), x);
    printf("%s\n", s.c_str());

    s = "Hel";
    string t = "Hello";
    printf("%d\n", strncmp(s.c_str(), t.c_str(), 4));
    int n = s.length();
    int i = 1;
    while ((strncmp(t.c_str(), s.c_str(), i) == 0) && i <= n)
    {
        i++;
    }

    // #5.
    printf("%d\n", strncmp(s.c_str(), t.c_str(), 3));
    if (strncmp(t.c_str(), s.c_str(), i) > 0)
    {
        printf("s<t\n");
    }

    return 0;

}
