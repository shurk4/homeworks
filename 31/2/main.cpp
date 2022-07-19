/*Вам дан базовый интерфейс для представления ориентированного графа. Напишите две реализации интерфейса:
ListGraph, хранящий граф в виде массива списков смежности.
MatrixGraph, хранящий граф в виде матрицы смежности.
Реализуйте конструктор, принимающий IGraph. Такой конструктор должен скопировать переданный граф в создаваемый объект.
 Обратите внимание, что иногда в одну реализацию графа копируется другая.
 Реализуйте в том числе все конструкторы копий и операторы присваивания, если это необходимо.*/

#include <iostream>
#include <vector>
#include <algorithm>

class IGraph
{
    std::vector<std::vector<int>> graph;
public:
    virtual ~IGraph() {};
    IGraph() {};
    IGraph(IGraph *_oth) {};
    bool itMatrix(IGraph& _oth)
    {
        for(int i = 0; i < _oth.graph.size(); i++)
        {
            for(int j = 0; j < _oth.graph[i].size(); j ++)
            {
                if(_oth.graph[i][j] > 1) return false;
            }
        }
        return true;
    }
    virtual void showGraph() = 0;
    virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро
    virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    friend class MatrixGraph;
    friend class ListGraph;
};

class MatrixGraph : virtual public IGraph
{
public:
    MatrixGraph() {};
    MatrixGraph(IGraph &_oth)
    {
        if(!graph.empty()) graph.clear();
        graph.resize(_oth.graph.size());
        if(itMatrix(_oth))
        {
            for(int i = 0; i < graph.size(); i++)
            {
                graph.resize(_oth.graph[i].size());
                for(int j = 0; j < _oth.graph[i].size(); j++)
                {
                    graph[i][j] = _oth.graph[i][j];
                }
            }
        }
        else
        {
            for(int i = 0; i < graph.size(); i++)
            {
                graph[i].resize(_oth.graph.size());
                for(int j = 0; j < _oth.graph[i].size(); j++)
                {
                    graph[i][_oth.graph[i][j] - 1] = 1;
                }
            }
        }
    };

    MatrixGraph& operator = (const IGraph& oth)
    {
        if(graph == oth.graph) return *this;
        else MatrixGraph(oth);
    }

    virtual void showGraph()
    {
        if(!graph.empty())
        {
            for (int i = 0; i < graph.size(); i++)
            {
                for (int j = 0; j < graph[i].size(); j++)
                {
                    std::cout << graph[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << "the graph has " << VerticesCount() << " vertices" << std::endl;
        }
        else
        {
            std::cout << "The graph is empty" << std::endl;
        }
    }

    virtual void matrixFill()
    {
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                if(graph[i][j] != 1) graph[i][j] = 0;
            }
        }
    }

    virtual void AddEdge(int from, int to) // Метод принимает вершины начала и конца ребра и добавляет ребро
    {
        if(graph.size() < from || graph.size() < to)
        {
            int newSize = (from > to ? from : to);
            graph.resize(newSize);
            for(int i = 0; i < newSize; i++)
            {
                graph[i].resize(newSize);
            }
            matrixFill();
        }
        graph[from - 1][to - 1] = 1;
    }

    virtual int VerticesCount() const // Метод должен считать текущее количество вершин
    {
        return graph.size();
    }

    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    {
        for(int i = 0; i < graph[vertex - 1].size(); i++)
        {
            if(graph[vertex - 1][i] == 1)
            {
                vertices.push_back(i + 1);
            }
        }
        std::cout << std::endl;
    }

    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    {
        for(int i = 0; i < graph.size(); i++)
        {
            if(graph[i][vertex - 1] == 1)
            {
                vertices.push_back(i + 1);
            }
        }
        std::cout << std::endl;
    }
};

class ListGraph : virtual public IGraph
{

public:
    ListGraph() {};
    ListGraph(IGraph &_oth)
    {
        if(!graph.empty()) graph.clear();
        graph.resize(_oth.graph.size());
        if(itMatrix(_oth))
        {
            for(int i = 0; i < graph.size(); i++)
            {
                for(int j = 0; j < _oth.graph[i].size(); j++)
                {
                    if(_oth.graph[i][j] == 1) graph[i].push_back(j + 1);
                }
            }
        }
        else
        {
            for(int i = 0; i < graph.size(); i++)
            {
                graph.resize(_oth.graph[i].size());
                for(int j = 0; j < _oth.graph[i].size(); j++)
                {
                    graph[i][j] = _oth.graph[i][j];
                }
            }
        }

    };

    ListGraph& operator = (const IGraph& oth)
    {
        if(graph == oth.graph) return *this;
        else ListGraph(oth);
    }

    virtual void AddEdge(int from, int to)
    {
        int size = (from > to ? from : to);
        if(graph.size() < size)
        {
            graph.resize(size);
        }
        graph[from - 1].push_back(to);
    }

    virtual void showGraph()
    {
        if(!graph.empty())
        {
            for (int i = 0; i < graph.size(); i++) {
                std::sort(graph[i].begin(), graph[i].end());
                std::cout << i + 1 << " : ";
                for (int j = 0; j < graph[i].size(); j++) {
                    std::cout << graph[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << "the graph has " << VerticesCount() << " vertices" << std::endl;
        }
        else
        {
            std::cout << "The graph is empty" << std::endl;
        }
    }

    virtual int VerticesCount() const // Метод должен считать текущее количество вершин
    {
        return graph.size();
    }

    void GetNextVertices(int vertex, std::vector<int> &vertices) const // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    {
        for(int i = 0; i < graph[vertex - 1].size(); i++)
        {
            vertices.push_back(graph[vertex - 1][i]);
        }
        std::sort(vertices.begin(), vertices.end());
    };

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    {
        for(int i = 0; i < graph.size(); i++)
        {
            for(int j = 0; j < graph[i].size(); j++)
            {
                if(graph[i][j] == vertex)
                {
                    vertices.push_back(i + 1);
                }
            }
        }
    }
};

void vecPrint(std::vector<int> vec, std::string way, int _vertex)
{
    std::cout << "The " << way << " vertices of the edge " << _vertex << ": ";
    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "------- NEW MATRIX GRAPH -------" << std::endl;
    MatrixGraph mg;
    std::vector<int> mgNext,
                     mgPrev;
    mg.AddEdge(3, 5);
    mg.AddEdge(1,4);
    mg.AddEdge(2,3);
    mg.AddEdge(4,1);
    mg.AddEdge(5,2);
    mg.showGraph();

    mg.GetNextVertices(5, mgNext);
    vecPrint(mgNext, "next", 5);
    mg.GetPrevVertices(2, mgPrev);
    vecPrint(mgPrev, "previous", 2);

    std::cout << "------- NEW LIST GRAPH -------" << std::endl;

    ListGraph lg;
    std::vector<int> lgNext,
                     lgPrev;
    lg.AddEdge(1,3);
    lg.AddEdge(2,5);
    lg.AddEdge(4,2);
    lg.AddEdge(3,2);
    lg.AddEdge(5,3);

    lg.showGraph();

    lg.GetNextVertices(4, lgNext);
    vecPrint(lgNext, "next", 4);
    lg.GetPrevVertices(2, lgPrev);
    vecPrint(lgPrev, "previous", 2);

    std::cout << "------- MATRIX GRAPH FROM LIST GRAPH -------" << std::endl;

    MatrixGraph mg2(lg);
    mg2.showGraph();

    std::cout << "------- MATRIX GRAPH FROM MATRIX GRAPH -------" << std::endl;

    MatrixGraph mg3(mg);
    mg3.showGraph();

    std::cout << "------- MATRIX GRAPH = LIST GRAPH -------" << std::endl;

    MatrixGraph mg4 = lg;
    mg4.showGraph();

    std::cout << "------- LIST GRAPH FROM MATRIX GRAPH -------" << std::endl;

    ListGraph lg2(mg);
    lg2.showGraph();

    std::cout << "------- LIST GRAPH FROM MATRIX GRAPH -------" << std::endl;

    ListGraph lg3(lg);
    lg3.showGraph();

    std::cout << "------- LIST GRAPH = MATRIX GRAPH -------" << std::endl;

    ListGraph lg4 = mg;
    lg4.showGraph();

    return 0;
}
