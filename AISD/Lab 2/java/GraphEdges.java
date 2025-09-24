package com.example;

import java.util.ArrayList;

public class GraphEdges {
        private ArrayList<int[]> edges;

    public GraphEdges() {
        this.edges = new ArrayList<>();
    }

    public void addEdge(int from, int to) {
        edges.add(new int[]{from, to});
    }

    public void printGraph() {
        System.out.println("Список рёбер:");
        for (int[] edge : edges) {
            System.out.println(edge[0] + " -> " + edge[1]);
        }
    }
}
