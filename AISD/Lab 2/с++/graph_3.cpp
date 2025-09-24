#include <iostream>
#include <vector>
#include <limits>

class GraphMatrix {
private:
    std::vector<std::vector<int>> matrix;
    int vertices;

public:
    GraphMatrix(int vertices) : vertices(vertices) {
        matrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    GraphMatrix(const std::vector<std::vector<int>>& mat, int vertexCount) {
        matrix = mat;
        vertices = vertexCount;
    }

    void addEdge(int from, int to, int weight) {
        matrix[from][to] = weight;
        matrix[to][from] = weight;
    }

    void printGraph() const {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    static int getClosestVertex(const std::vector<int>& distance, const std::vector<bool>& visited) {
        int min = std::numeric_limits<int>::max();
        int minIdx = -1;

        for (int i = 0; i < distance.size(); i++) {
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

    void main() {
        GraphMatrix graph(5);

        graph.addEdge(0, 1, 10);
        graph.addEdge(0, 4, 5);
        graph.addEdge(1, 2, 1);
        graph.addEdge(4, 2, 9);
        graph.addEdge(2, 3, 4);
        graph.printGraph();

        std::vector<int> dist = graph.dijkstraFind(0);

        std::cout << "\nКратчайшие расстояния от вершины 0:" << std::endl;
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] == std::numeric_limits<int>::max()) {
                std::cout << i << ": недостижимо" << std::endl;
            }
            else {
                std::cout << i << ": " << dist[i] << std::endl;
            }
        }
    }
};
