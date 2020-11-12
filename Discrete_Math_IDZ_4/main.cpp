#include <iostream>

#include "Dijkstra.h"

using namespace std;

int main()
{
    int m;
    cout << "Enter start versh: ";
    cin >> m;
    m--;
    cout << endl;
    Dijkstra obj1(6, m);
    obj1.read_from_file();
    obj1.rast_output();
    obj1.algr_dijkstra();
    obj1.final_output();


    return 0;
}
