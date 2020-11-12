#include "Dijkstra.h"

Dijkstra::Dijkstra(int n1, int m)
{
    n = n1;

    nachalnay_versh = m;

    matrix = new int*[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }

    previous_versh = new int[n];

    D = new int[n];

    flag = new bool[n];

}

Dijkstra::~Dijkstra()
{
    for (int i = 0; i < n; i++)
	{
		delete []matrix[i];
	}
    delete []matrix;

    delete []previous_versh;

    delete []D;

    delete[]flag;
}

void Dijkstra:: read_from_file()
{
    ifstream f;
    string s;

    f.open ("rast_mtrx.txt");

    while(f>>s)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                f >> matrix[i][j];
            }
        }
    }

    f.close();
}

void Dijkstra:: rast_output()
{
    cout << "Distance matrix: \n\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == 999)
            {
                cout << "inf" << '\t';
            }
            else
            {
                cout << matrix[i][j] << '\t';
            }
        }
            cout << endl;
    }
}

void Dijkstra::algr_dijkstra()
{
    for (int i = 0; i < n; i++)
    {
        previous_versh[i] = nachalnay_versh;
        flag[i] = false;
        D[i] = matrix[nachalnay_versh][i];
    }

    flag[nachalnay_versh] = true;
    previous_versh[nachalnay_versh] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int k = 0;
        int min_rast = 999;
        // Находим минимальное расстояние до непомеченных вершин
        for (int j = 0; j < n; j++) {
            if (flag[j] == false && min_rast > D[j])
            {
                min_rast = D[j]; // принимаем за минимальное расстояние D[j]
                k = j;
            }
        }

        flag[k] = true;
        for (int j = 0; j < n; j++) {
            /*  Если для вершины j еще не найдено кратчайшее расстояние от
                нач. и из вершины k по дуге matrix[k][j] путь в j короче
                чем найденное ранее, то запоминаем его.
             */
            if (flag[j] == false && D[j] > D[k] + matrix[k][j]) {
                D[j] = D[k] + matrix[k][j];
                previous_versh[j] = k;
            }
        }
    }
}

void Dijkstra::final_output()
{
    cout << "\n\nPath ";
    cout << "from " << n << " to " << nachalnay_versh + 1 << ": ";

    for (int j = n - 1 ; j > nachalnay_versh;)
    {
        cout << j + 1 << " ";
        j = previous_versh[j];
    }

    cout << nachalnay_versh + 1 << endl;

    cout << "\nPath length = " << D[n-1] << endl;

}
