package com.example;

public class GraphMatrix {
    private int[][] matrix;
    private int vertices;

    public GraphMatrix(int vertices) {
        this.vertices = vertices;
        this.matrix = new int[vertices][vertices];
    }

    public GraphMatrix(int[][] matrix, int vertex) {
        this.matrix = matrix;
        this.vertices = vertex;
    }

    // public void addEdge(int from, int to) {
    // matrix[from][to] = 1;
    // }

    public void addEdge(int from, int to, int weight) {
        matrix[from][to] = weight;
        matrix[to][from] = weight;
    }

    public void printGraph() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static int getClosestVertex(int[] distance, boolean[] visited){
        int min = Integer.MAX_VALUE;
        int minInx = -1;
        for(int i = 0; i<distance.length; ++i){
            if(distance[i] <min){
                if(visited[i] == false && distance[i] < min){
                    min = distance[i];
                    minInx = i;
                }
            }
        }
        return minInx;
    }

    public int[] dijkstraFind(int start){
        int[] distance = new int[this.vertices];
        boolean[] visited = new boolean[this.vertices];

        for(int i = 0; i<this.vertices; ++i){
            distance[i] = Integer.MAX_VALUE; 
            visited[i] = false;
        }

        distance[start] = 0;

        for(int i = 0; i<this.vertices; ++i){
            int closestVertex = getClosestVertex(distance, visited);
            if(closestVertex == -1 || closestVertex == Integer.MAX_VALUE){
                return distance;
            }

            visited[closestVertex] = true;
            for(int j = 0; j<this.vertices; ++j){
                if(visited[j] == false){
                    if(this.matrix[closestVertex][j] != 0){
                        int d = distance[closestVertex] + this.matrix[closestVertex][j];
                        if(d < distance[j]){
                            distance[j] = d;
                        }
                    }
                }
            }
        }
        return distance;

    }
}
