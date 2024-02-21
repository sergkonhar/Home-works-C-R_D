#include "Graph.h"
#include <vector>
#include <iostream>


GraphAdjList::GraphAdjList(int Vertixes, ConnectionType type)
	: Graph(Vertixes, type)
{
	m_list.resize(Vertixes);
}

void GraphAdjList::addEdge(int v, int w)
{
	m_list[v].push_back(w);
	if (m_connectionType == ConnectionType::undirected)
	{
		m_list[w].push_back(v);
	}
}

void GraphAdjList::BFS(int vertex)
{
	// Mark all the vertices as not visited
	std::vector<bool> visited;
	visited.resize(m_vertixes, false);

	std::list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[vertex] = true;
	queue.push_back(vertex);

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		int currentVertex = queue.front();

		//or make anything else with it: push to vector, string, pass to another object, whatever
		std::cout << currentVertex << " ";

		queue.pop_front();

		// Get all adjacent vertices
		for (int adjacent : m_list[currentVertex])
		{
			if (!visited[adjacent])
			{
				visited[adjacent] = true;
				queue.push_back(adjacent);
			}
		}
	}
}

int GraphAdjList::numberOfNodesInLevel(int level) 
{
    if (level < 1)
    {
        return 0;
    }

    std::vector<bool> visited(m_vertixes, false);
    std::list<int> queue;

    queue.push_back(0); 
    visited[0] = true;

    int currentLevel = 1;
    int nodesInCurrentLevel = 0;

    while (!queue.empty() && currentLevel <= level)
    {
        int nodesAtCurrentLevel = queue.size();

        while (nodesAtCurrentLevel > 0)
        {
            int currentVertex = queue.front();
            queue.pop_front();

            for (int adjacent : m_list[currentVertex])
            {
                if (!visited[adjacent])
                {
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }

            nodesAtCurrentLevel--;
        }

        if (currentLevel == level)
        {
          
            nodesInCurrentLevel = queue.size();
            break;
        }

        currentLevel++;
    }

    return nodesInCurrentLevel;
}

bool GraphAdjList::isStronglyConnected()
{
    for (int i = 0; i < m_vertixes; ++i)
    {
        std::vector<bool> visited(m_vertixes, false);
        std::list<int> stack;

        visited[i] = true;
        stack.push_back(i);

        while (!stack.empty())
        {
            int currentVertex = stack.back();
            stack.pop_back();

            for (int adjacent : m_list[currentVertex])
            {
                if (!visited[adjacent])
                {
                    visited[adjacent] = true;
                    stack.push_back(adjacent);
                }
            }
        }

        
        for (bool visit : visited)
        {
            if (!visit)
                return false;
        }
    }

    
    return true;
}
