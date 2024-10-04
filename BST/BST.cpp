
#include <iostream>
#include "BST.h"
#include <unordered_set> //for hash table
#include <unordered_map> // for hash table
#include <list> //Double linked list
#include <forward_list> //single linked list
#include <set> //for bst
#include <map> //for bst
#include <vector>
#include <queue>
/*
Unordered sets and maps return pairs
*/

pair<int, int> linearSearch(int arr[], int size, int target) {
	int steps = 0;
	for (int i = 0; i < size; i++, steps++) {
		if (arr[i] == target) {
			return { i, steps };
		}
	}
	return { -1, steps };
}


pair<int, int> binarySearch(int arr[], int size, int target) {
	int steps = 0,
		left = 0,
		right = size - 1,
		mid;
	while (left <= right) {
		steps++;
		mid = (left + right) / 2;

		if (arr[mid] == target) {
			return { mid, steps };
		}
		else if (target > arr[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return { -1, steps };
}


//Undirected graph
//Graph modelling
vector<vector<int>> modelGraph(int nodes, int edges) {
	vector<vector<int>> graph(nodes + 1);
	for (int i = 1; i <= edges; i++) {
		int parent, child;
		cin >> parent >> child;
		graph[child].push_back(parent);
		graph[parent].push_back(child);
	}
	return graph;
}

//DFS
//void DFS(int currentNode, vector<vector<int>> graph, bool* visited) {
//	cout << currentNode << " ";
//	visited[currentNode] = true;
//	
//	vector<int> children = graph[currentNode];
//	for (int i = 0; i < children.size(); i++) {
//		if (!visited[children[i]]) {
//			DFS(children[i], graph, visited);
//		}
//	}
//}
// DFS with an end node
void DFS(int currentNode, int endNode, vector<vector<int>> graph, bool* visited, int steps = 0) {
	//cout << currentNode << " ";
	visited[currentNode] = true;
	if (currentNode == endNode) {
		cout << "Steps: " << steps << endl;
		return;
	}
	vector<int> children = graph[currentNode];
	for (int i = 0; i < children.size(); i++) {
		if (!visited[children[i]]) {
			steps++;
			DFS(children[i], endNode, graph, visited, steps);
		}
	}
}
//Breadth First Search
void BFS(int startNode, int nodes, vector<vector<int>> graph) {
	bool* visited = new bool[nodes + 1] {};

	queue<int> queueBFS;
	queueBFS.push(startNode);
	visited[startNode] = true;

	while (!queueBFS.empty()) {
		vector<int> children = graph[queueBFS.front()];
		for (int i = 0; i < children.size(); i++) {  
			int child = children[i];
			if (!visited[child]) {
				queueBFS.push(child);
				visited[child] = true;
			}
		}
		cout << queueBFS.front() << " ";
		queueBFS.pop();
	}


	delete[] visited;
}


//BFS with an end node using steps as a counter while dequeuing each node from the queue
void BFS(int startNode, int endNode, int nodes, vector<vector<int>> graph) {
	bool* visited = new bool[nodes + 1] {};

	queue<int> queueBFS;
	queueBFS.push(startNode);
	visited[startNode] = true;
	int steps = 0;
	while (!queueBFS.empty()) {
		int frontValue = queueBFS.front();
		if (endNode == frontValue) {
			cout << "Steps: " << steps << endl;
			return;
		}
		vector<int> children = graph[queueBFS.front()];
		for (int i = 0; i < children.size(); i++) {
			int child = children[i];
			if (!visited[child]) {
				queueBFS.push(child);
				visited[child] = true;
			}
		}
		steps++;
		cout << queueBFS.front() << " ";
		queueBFS.pop();
	}


	delete[] visited;
}


//BFS end node with levels using var steps
void BFS1(int startNode, int endNode, int nodes, vector<vector<int>> graph) {
	bool* visited = new bool[nodes + 1] {}; // Create a visited array
	queue<int> queueBFS; // Queue for BFS traversal
	queueBFS.push(startNode); // Start from the startNode
	visited[startNode] = true; // Mark startNode as visited

	int steps = 0; // To track the depth (number of levels)

	while (!queueBFS.empty()) {
		int levelSize = queueBFS.size(); // Number of nodes at the current level

		// Process all nodes at the current level
		for (int i = 0; i < levelSize; i++) {
			int frontValue = queueBFS.front();
			queueBFS.pop();

			// If we reached the target node, print the depth and return
			if (frontValue == endNode) {
				cout << "Steps: " << steps << endl;
				delete[] visited;
				return;
			}

			// Add all unvisited children to the queue
			vector<int> children = graph[frontValue];
			for (int j = 0; j < children.size(); j++) {
				int child = children[j];
				if (!visited[child]) {
					queueBFS.push(child);
					visited[child] = true;
				}
			}
		}

		// Increment the step count after processing one full level
		steps++;
	}

	delete[] visited;
}


int main()
{
	//BST<int> bst;
	//bst.insert(9).displayOutput();
	//bst.insert(5).displayOutput();
	//bst.insert(88).displayOutput();
	//bst.insert(9).displayOutput();
	//bst.insert(60).displayOutput();
	//bst.insert(9).displayOutput();
	//bst.insert(22).displayOutput();

	//unique values only
	cout << "Unordered set:\n";
	unordered_set<int> set;

	cout << set.insert(1002).second << endl;
	cout << set.insert(1005).second << endl;
	cout << set.insert(1022).second << endl;
	cout << set.insert(1032).second << endl;
	cout << set.insert(1032).second << endl;
	cout << endl;

	cout << "unordered map:\n";
	//(unique keys) and values
	unordered_map<int, string> map;
	cout << map.insert({ 1000, "A" }).second << endl;

	//Linear search
	int arr[] = { 5, 3 , 2, 6, 77, 99, 44 };
	pair<int, int> linearResult = linearSearch(arr, 7, 44);
	cout << "Index: " << linearResult.first << endl;
	cout << "Steps: " << linearResult.second << endl;

	int arr2[] = {1, 2, 3, 4, 5, 6, 8, 10};
	pair<int, int> binaryResult = binarySearch(arr2, 8, 8);
	cout << "Index: " << binaryResult.first << endl;
	cout << "Steps: " << binaryResult.second << endl;

	//Graph modelling
	//int nodes, edges;
	//cin >> nodes >> edges;
	//vector<vector<int>> graph(nodes + 1);
	//
	//for (int i = 1; i <= edges; i++) {
	//	int parent, child;
	//	cin >> parent >> child;
	//	graph[parent].push_back(child);
	//}

	//for (int i = 1; i <= nodes; i++) {
	//	cout << "Parent: " << i << "---> ";
	//	for (int j = 0; j < graph[i].size(); j++) {
	//		cout << graph[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	//Undirected graph
	//Graph modelling
	/*
	
	*/
	/*int nodes, edges;
	cin >> nodes >> edges;
	vector<vector<int>> graph2 = modelGraph(nodes, edges);*/


	//DFS
	/*
	1	2
	1	4
	1	6
	3	5
	4	5
	*/

	/*
	1	2
	1	5
	2	4
	2	3
	3	4
	4	6
	5	6
	*/
	//bool* visited = new bool[nodes + 1] {};
	////DFS(5, graph2, visited);
	//DFS(4, graph2, visited);

	//DFS with endNode
	//bool* visited = new bool[nodes + 1] {};
	//DFS(1, 5, graph2, visited);


	//BFS
	//BFS(4, nodes, graph2);

	//BFS with end node
	//BFS(5, 5, nodes, graph2);
	
	BST<int> bst;
	bst.insert(9).displayOutput();
	bst.insert(5).displayOutput();
	bst.insert(88).displayOutput();
	bst.insert(9).displayOutput();
	bst.insert(60).displayOutput();
	bst.insert(9).displayOutput();
	bst.insert(22).displayOutput();
	//bst.displayDFS();
	bst.BFS();
}

