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

        void read_from_file(); // ��������� ������� � ����������
        void rast_output(); // ������� �� ����� ������� ����������

        void algr_dijkstra();
        void final_output();

    private:
        int n; // ���-�� ������ �����
        int nachalnay_versh;

        int *previous_versh;
        int *D;
        bool *flag;

        int **matrix;

};

#endif // DIJKSTRA_H
