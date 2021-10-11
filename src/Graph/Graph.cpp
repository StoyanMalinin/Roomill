#pragma once

#include <vector>
#include <bitset>
#include <memory>

struct Node
{
	int id;
	uint8_t gender;

	Node(int id, uint8_t gender) : id(id), gender(gender) {}
};

struct Edge
{
	std::shared_ptr<Node> a, b;

	Edge(std::shared_ptr<Node> a, std::shared_ptr<Node> b) : a(a), b(b) {}
};

template <std::size_t nodesCnt>
class Graph
{
private:
	std::vector <Edge> edges;
	std::vector <std::shared_ptr<Node>> adj[nodesCnt];
	
	std::shared_ptr <Node> ind2Node[nodesCnt];

	std::bitset <nodesCnt> used;
	std::vector <std::vector <std::shared_ptr<Node>>> *components;

public:
	Graph() : components(nullptr)
	{
		used.reset();
	}

	void addEdge(std::shared_ptr<Node> a, std::shared_ptr<Node> b)
	{
		edges.emplace_back(a, b);
		adj[a->id].push_back(b);
		adj[b->id].push_back(a);
	}

	void addEdge(int a, int b)
	{
		addEdge(ind2Node[a], ind2Node[b]);
	}

	void setNode(std::shared_ptr<Node> x)
	{
		ind2Node[x->id] = x;
	}

private:
	void dfsCover(std::shared_ptr<Node> x, std::vector <std::shared_ptr<Node>> &v)
	{
		used[x->id] = true;
		v.push_back(x);

		for (auto& item : adj[x->id])
		{
			if (used[item->id] == false)
				dfsCover(item, v);
		}
	}

public:
	const std::vector <std::vector <std::shared_ptr<Node>>>* getComponentDecomposition()
	{
		components = new std::vector <std::vector <std::shared_ptr<Node>>>();
		for (int x = 0; x < nodesCnt; x++)
		{
			if (used[x] == false)
			{
				components->emplace_back();
				dfsCover(ind2Node[x], components->back());
			}
		}

		return components;
	}
};