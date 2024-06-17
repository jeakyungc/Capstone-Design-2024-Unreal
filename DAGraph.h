// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include <list>
#include <vector>
#include <stack>
#include <algorithm>

#include "DAGraph.generated.h"

/**
 * 
 */
UCLASS()
class WFC_API UDAGraph : public UObject
{
	GENERATED_BODY()
public:
	UDAGraph();
	UDAGraph(int verticesNum);
	void addEdge(int u, int v, float w);
	bool isCyclic();
	void topologicalSort();

private:
	int V; // Number of vertices
	std::list<std::pair<int, float>>* adj; // Adjacency list
	bool isCyclicUtil(int v, std::vector<bool>& visited, std::vector<bool>& recStack);
	void topologicalSortUtil(int v, std::vector<bool>& visited, std::stack<int>& Stack);
};
