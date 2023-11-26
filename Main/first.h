#pragma once
#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Edge {
	int start;
	int weight;
	int end;
	Edge(int a = 0, int b = 0, int c = 0) : start(a), weight(b), end(c) {};
};

struct dsu
{
	vector <int> leader;
	vector <int> size;

	dsu(int n)
	{
		leader.resize(n);
		for (int i = 0; i < n; i++)
			leader[i] = i;
		size.resize(n, 1);
	}

	int find(int n)
	{
		if (n == leader[n])
			return n;
		int b = find(leader[n]);
		leader[n] = b;
		return leader[n]; // O(alpha)
	}

	void join(int a, int b)
	{
		int leader_a = find(a);
		int leader_b = find(b);
		if (leader_a == leader_b)
			return;

		if (size[leader_a] > size[leader_b])
		{
			leader[leader_b] = leader_a;
			size[leader_a] += size[leader_b];
		}
		else
		{
			leader[leader_a] = leader_b;
			size[leader_b] += size[leader_a];
		}
	}
};



class Graph {
private:
	int versh = 0;
	int num_edges = 0;
	vector<Edge> min_ostov;
	vector<Edge> graph;
	vector<vector<int>> matrix;

	void swap(Edge& a, Edge& b) {
		Edge tmp = a;
		a = b;
		b = tmp;
	}

public:
	Graph() {
		matrix = vector<vector<int>>(0, vector<int>(0, 0));
	}

	Graph(int a, int b, int maxweight) {
		versh = a;
		if (a - 1 > b) {
			num_edges = a - 1;
		}
		else if (num_edges > versh * (versh - 1) / 2) {
			num_edges = versh * (versh - 1) / 2;
		}
		else{
			num_edges = b;
		}

		/*matrix = vector<vector<int>>(a, vector<int>(a, 0));
		int num = 0;
		for (int i = 0; i < a; i++) {
			for (int j = i + 1; j < a; j++) {
				if (num == num_edges)
					break;
				matrix[i][j] = (rand() * rand()) % maxweight + 1;
				matrix[j][i] = matrix[i][j];
				num++;
			}
			if (num == num_edges)
				break;
		}*/


		set<pair<int, int>> out;
		for (int i = 1; i < a; i++) {
			int weight = (rand() * rand()) % maxweight + 1;
			graph.push_back(Edge(i - 1, weight, i));
			/*out.insert({ i - 1, i });
			out.insert({ i, i - 1 });*/
		}
		for (int i = 0; i < b - a + 1; i++) {
			int u = (rand() * rand()) % a;
			int v = (rand() * rand()) % a;
			/*while (out.find({ u, v }) != out.end()) {
				u = (rand() * rand()) % a;
				v = (rand() * rand()) % a;
			}*/
			int weight = (rand() * rand()) % maxweight + 1;
			graph.push_back(Edge(u, weight, v));
			/*out.insert({ u, v });
			out.insert({ v, u });*/
		}
	}

	void ToVector() {
		vector<Edge> tmp;
		for (int i = 0; i < versh; i++) {
			for (int j = i + 1; j < versh; j++) {
				if (matrix[i][j] != 0)
					tmp.push_back(Edge(i, matrix[i][j], j));
			}
		}
		QuiqSort(tmp, 0, tmp.size() - 1);
		graph = tmp;
	}

	

	int Partition(vector<Edge>& edges, int first, int last) {
		int pivot = edges[last].weight;
		int partitionIndex = first;

		for (int j = first; j < last; j++) {
			if (edges[j].weight < pivot) {
				swap(edges[partitionIndex], edges[j]);
				partitionIndex++;
			}
		}

		swap(edges[partitionIndex], edges[last]);
		return partitionIndex;
	}

	void QuiqSort(vector<Edge>& edges, int first, int last) {
		if (first < last) {
			
			int p = Partition(edges, first, last);
			QuiqSort(edges, first, p - 1);		
			QuiqSort(edges, p + 1, last);
		}
		return;
	}

	void Kraskal() {
		//ToVector();
		QuiqSort(graph, 0, graph.size() - 1);
		vector<Edge> result;
		int num = 0;
		for (int i = 0; i < graph.size(); i++) {
			if (graph[i].end > num)
				num = graph[i].end;
			if (graph[i].start > num)
				num = graph[i].start;
		}
		dsu d(num + 1);
		for (int i = 0; i < graph.size(); i++) {
			if (d.find(graph[i].start) != d.find(graph[i].end)) {
				d.join(graph[i].start, graph[i].end);
				result.push_back(graph[i]);
			}
		}
		min_ostov = result;
	}
	
};










