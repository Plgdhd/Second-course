#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class GraphEdges {
private:
    std::vector<std::pair<int, int>> edges;

public:
    GraphEdges() = default;

    void addEdge(int from, int to) {
        edges.push_back({ from, to });
    }

    void printGraph() {
        std::cout << "Список рёбер:" << std::endl;
        for (auto& edge : edges) {
            std::cout << edge.first << " -> " << edge.second << std::endl;
        }
    }
};

class GraphMatrix {
private:
    std::vector<std::vector<int>> matrix;
    int vertices;

public:
    GraphMatrix(int vertices) : vertices(vertices) {
        matrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    GraphMatrix( std::vector<std::vector<int>>& mat, int vertexCount) {
        matrix = mat;
        vertices = vertexCount;
    }

    void addEdge(int from, int to, int weight) {
        matrix[from][to] = weight;
        matrix[to][from] = weight;
    }

    void printGraph() {
        std::cout << "\nМатрица смежности:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    static int getClosestVertex(std::vector<int>& distance, std::vector<bool>& visited) {
        int min = std::numeric_limits<int>::max();
        int minIdx = -1;

        for (int i = 0; i < (int)distance.size(); i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                minIdx = i;
            }
        }
        return minIdx;
    }

    std::vector<int> dijkstraFind(int start) {
        std::vector<int> distance(vertices, std::numeric_limits<int>::max());
        std::vector<bool> visited(vertices, false);

        distance[start] = 0;

        for (int i = 0; i < vertices; i++) {
            int closestVertex = getClosestVertex(distance, visited);
            if (closestVertex == -1) {
                return distance;
            }

            visited[closestVertex] = true;

            for (int j = 0; j < vertices; j++) {
                if (!visited[j] && matrix[closestVertex][j] != 0) {
                    int d = distance[closestVertex] + matrix[closestVertex][j];
                    if (d < distance[j]) {
                        distance[j] = d;
                    }
                }
            }
        }
        return distance;
    }
};

class Graph {
private:
    std::unordered_map<int, std::vector<int>> neighbours;

public:
    Graph() = default;

    void addVertex(int vertex) {
        if (neighbours.find(vertex) == neighbours.end()) {
            neighbours[vertex] = std::vector<int>();
        }
    }

    void addEdge(int from, int to) {
        if (neighbours.find(from) == neighbours.end()) {
            neighbours[from] = std::vector<int>();
        }
        if (neighbours.find(to) == neighbours.end()) {
            neighbours[to] = std::vector<int>();
        }
        neighbours[from].push_back(to);
    }

    std::vector<int> getNeighbour(int vertex) {
        if (neighbours.find(vertex) != neighbours.end()) {
            return neighbours[vertex];
        }
        return {};
    }

    void printGraph() {
        std::cout << "\nСписок смежности:\n";
        for (auto& pair : neighbours) {
            std::cout << pair.first << " -> ";
            for (int v : pair.second) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    }

    void bfs(int start) {
        std::queue<int> q;
        std::unordered_set<int> visited;

        q.push(start);
        visited.insert(start);

        std::cout << "\nBFS:\n";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            std::cout << current << " ";

            for (int neighbour : neighbours[current]) {
                if (visited.find(neighbour) == visited.end()) {
                    visited.insert(neighbour);
                    q.push(neighbour);
                }
            }
        }
        std::cout << std::endl;
    }

    void dfs(int start) {
        std::unordered_set<int> visited;
        std::cout << "\nDFS:\n";
        recursiveSearch(start, visited);
        std::cout << std::endl;
    }

private:
    void recursiveSearch(int vertex, std::unordered_set<int>& visited) {
        if (visited.find(vertex) != visited.end()) return;

        visited.insert(vertex);
        std::cout << vertex << " ";
        for (int neighbour : neighbours[vertex]) {
            recursiveSearch(neighbour, visited);
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    //Graph graphMap;
    //graphMap.addEdge(1, 2);
    //graphMap.addEdge(1, 5);
    //graphMap.addEdge(2, 7);
    //graphMap.addEdge(2, 8);
    //graphMap.addEdge(2, 1);
    //graphMap.addEdge(3, 8);
    //graphMap.addEdge(4, 6);
    //graphMap.addEdge(4, 9);
    //graphMap.addEdge(5, 6);
    //graphMap.addEdge(5, 1);
    //graphMap.addEdge(6, 9);
    //graphMap.addEdge(6, 4);
    //graphMap.addEdge(7, 8);
    //graphMap.addEdge(7, 2);
    //graphMap.addEdge(8, 7);
    //graphMap.addEdge(8, 3);
    //graphMap.addEdge(8, 2);
    //graphMap.addEdge(9, 10);
    //graphMap.addEdge(9, 4);
    //graphMap.addEdge(10, 9);

    //graphMap.printGraph();
    //graphMap.bfs(1);
    //graphMap.dfs(1);

    GraphMatrix gm(9);
    gm.addEdge(0, 1, 7);
    gm.addEdge(0, 2, 10);
    gm.addEdge(1, 5, 9);
    gm.addEdge(1, 6, 27);
    gm.addEdge(2, 4, 31);
    gm.addEdge(2, 5, 8);
    gm.addEdge(4, 3, 32);
    gm.addEdge(5, 7, 11);
    gm.addEdge(6, 8, 15);
    gm.addEdge(7, 3, 17);
    gm.addEdge(7, 8, 15);
    gm.addEdge(3, 8, 21);


    gm.printGraph();

    //GraphEdges graphEdge;
    //graphEdge.addEdge(1, 2);
    //graphEdge.addEdge(1, 5);
    //graphEdge.addEdge(2, 7);
    //graphEdge.addEdge(2, 8);
    //graphEdge.addEdge(3, 8);
    //graphEdge.addEdge(4, 6);
    //graphEdge.addEdge(4, 9);
    //graphEdge.addEdge(5, 6);
    //graphEdge.addEdge(6, 9);
    //graphEdge.addEdge(7, 8);
    //graphEdge.addEdge(9, 10);

    /*std::cout << std::endl;*/
    /*graphEdge.printGraph();*/
    int vertex = 0;
    std::cout << "Введите вершину для поиска: ";
    std::cin >> vertex;
    std::vector<int> dist = gm.dijkstraFind(vertex);

    std::cout << "\nКратчайшие расстояния от вершины  " << vertex << ":" << std::endl;
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] == std::numeric_limits<int>::max()) {
            std::cout << i << " недостижимо" << std::endl;
        }
        else {
           std::cout << i << ": " << dist[i] << std::endl;
        }
    }

}
