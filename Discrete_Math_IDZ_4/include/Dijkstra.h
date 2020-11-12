#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <fstream>

using namespace std;


class Dijkstra
{
    public:
        Dijkstra(int n1, int m);
        ~Dijkstra();

        void read_from_file(); // считывает матрицу с текстовика
        void rast_output(); // выводит на экран матрицу расстояний

        void algr_dijkstra();
        void final_output();

    private:
        int n; // Кол-во вершин графа
        int nachalnay_versh;

        int *previous_versh;
        int *D;
        bool *flag;

        int **matrix;

};

#endif // DIJKSTRA_H
