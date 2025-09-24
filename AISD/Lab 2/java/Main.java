package com.example;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        
        // Graph graph = new Graph();
        
        // graph.addVertex(1);
        // graph.addEdge(1,2);
        // graph.addEdge(1, 5);
        
        // graph.addVertex(2);
        // graph.addEdge(2, 7);
        // graph.addEdge(2, 8);

        // graph.addVertex(3);
        // graph.addEdge(3, 8);

        // graph.addVertex(4);
        // graph.addEdge(4, 6);
        // graph.addEdge(4, 9);

        // graph.addVertex(5);
        // graph.addEdge(5, 6);
        // graph.addEdge(5, 1);

        // graph.addVertex(6);
        // graph.addEdge(6, 4);
        // graph.addEdge(6, 9);

        // graph.addVertex(7);
        // graph.addEdge(7, 2);
        // graph.addEdge(7, 8);

        // graph.addVertex(8);
        // graph.addEdge(8, 2);
        // graph.addEdge(8, 3);

        // graph.addVertex(9);
        // graph.addEdge(9, 10);
        // graph.addEdge(9, 6);
        // graph.addEdge(9,4);

        // graph.addVertex(10);
        // graph.addEdge(10,9);

        
        // graph.bfs(8);
        // graph.dfs(3);
        // graph.printGraph();

    int numOfVertices = 6;
    int[][] adjMat = new int[6][6];
    GraphMatrix graph = new GraphMatrix(adjMat, numOfVertices);

    graph.addEdge(0, 4, 21);
    graph.addEdge(0, 3, 18);
    graph.addEdge(2, 1, 7);
    graph.addEdge(1, 4, 6);
    graph.addEdge(4, 5, 10);
    graph.addEdge(4, 3, 11);
    graph.addEdge(5, 3, 7);

    graph.printGraph();
    int[] dist = graph.dijkstraFind( 4);
    System.out.print(Arrays.toString(dist));

    }
}