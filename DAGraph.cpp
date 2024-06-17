// Fill out your copyright notice in the Description page of Project Settings.

#include "DAGraph.h"

UDAGraph::UDAGraph() {}

UDAGraph::UDAGraph(int vertices) // Number of vertices
{
	V = vertices;
	adj = new std::list<std::pair<int, float>>[vertices];
}

void UDAGraph::addEdge(int u, int v, float w)  // vertex : u, v, weight : w
{
	adj[u].push_back(std::make_pair(v, w));
}

bool UDAGraph::isCyclicUtil(int v, std::vector<bool>& visited, std::vector<bool>& recStack)
{
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (auto neighbor : adj[v]) {
            if (!visited[neighbor.first] && isCyclicUtil(neighbor.first, visited, recStack))
                return true;
            else if (recStack[neighbor.first])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool UDAGraph::isCyclic() {
    std::vector<bool> visited(V, false);
    std::vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}

void UDAGraph::topologicalSortUtil(int v, std::vector<bool>& visited, std::stack<int>& Stack) {
    visited[v] = true;

    for (auto neighbor : adj[v])
        if (!visited[neighbor.first])
            topologicalSortUtil(neighbor.first, visited, Stack);

    Stack.push(v);
}


void UDAGraph::topologicalSort() {
    std::stack<int> Stack;
    std::vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            topologicalSortUtil(i, visited, Stack);

    while (!Stack.empty()) {
        //std::cout << Stack.top() << " ";
        Stack.pop();
    }
    //std::cout << std::endl;
}



