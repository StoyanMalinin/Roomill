#include <iostream>

#include "Graph/Graph.cpp"

using namespace std;

int main()
{
	Graph<10> G;

	for (int i = 0; i < 10; i++)
		G.setNode(make_shared<Node>(i, i % 2));

	G.addEdge(1, 2);
	G.addEdge(5, 4);
	G.addEdge(2, 3);
	G.addEdge(0, 4);

	auto v = G.getComponentDecomposition();
	for (auto& comp : *v)
	{
		for (auto& x : comp) cout << x->id << " ";
		cout << '\n';
	}
}