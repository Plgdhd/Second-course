#include <iostream>
#include <vector>

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
        for ( auto& edge : edges) {
            std::cout << edge.first << " -> " << edge.second << std::endl;
        }
    }
};
