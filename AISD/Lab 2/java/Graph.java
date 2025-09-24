package com.example;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Graph {

    String value;
    Map<Integer, ArrayList<Integer>> neighbours;

    public Graph() {
        this.neighbours = new HashMap<>();
    }

    public void addVertex(int vertex) {
        neighbours.putIfAbsent(vertex, new ArrayList<>());
    }

    public void addEdge(int from, int to) {
        neighbours.putIfAbsent(from, new ArrayList<>());
        neighbours.putIfAbsent(to, new ArrayList<>());
        neighbours.get(from).add(to);
    }

    public ArrayList<Integer> getNeighbour(int vertex) {
        return neighbours.getOrDefault(vertex, new ArrayList<>());
    }

    public void printGraph() {
        for (Map.Entry<Integer, ArrayList<Integer>> entry : neighbours.entrySet()) {
            System.out.println(entry.getKey() + " -> " + entry.getValue());
        }
    }

    public void bfs(int name) {
        Deque<Integer> deque = new ArrayDeque<>();
        Set<Integer> visited = new HashSet<>();

        deque.add(1);
        visited.add(1);

        while (!deque.isEmpty()) {
            int current = deque.poll();
            System.out.println(current);

            for (int neighbour : neighbours.getOrDefault(current, new ArrayList<>())) {
                if (!visited.contains(neighbour)) {
                    visited.add(neighbour);
                    deque.add(neighbour);
                }
            }
        }

    }

    public void dfs(int name){
        Set<Integer> visited = new HashSet<>();
        recursiveSearch(1, visited);
    }

    private void recursiveSearch(int vertex, Set<Integer> visited){
        if((visited.contains(vertex))) return;

        visited.add(vertex);
        System.out.println(vertex);
        for(int neighbour : neighbours.getOrDefault(vertex, new ArrayList<>())){
            recursiveSearch(neighbour, visited);
        }
    }

    
    
}
