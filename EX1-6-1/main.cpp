#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

#include <fstream>
#include <vector>

using namespace std;

void Perm(char * a, const int m)
{
    do {
        copy(a, a+m, ostream_iterator<char>(cout, " "));
        cout << endl;
    } while(next_permutation(a, a+m));
}

int main(int argc, const char * argv[])
{

    char haha[5] = "haha";
    ofstream out("haha.txt");
    copy(haha, haha+4, ostream_iterator<char>(cout, " "));
    out.close();

    return 0;
    char a[3] = {'5', '1', '2'};
    sort(a, a+3);

    Perm(a, 3);
    return 0;
}
