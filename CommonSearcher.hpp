#pragma once
#include "Searcher.hpp"
#include <queue>
#include <chrono>

template <class T,class K>
class CommonSearcher : public Searcher<T,K>
{
public:
	CommonSearcher(): m_evaluatedNodes(0){}

//Abstraction
public:
	virtual Solution<T> search( Searchable<T,K>& s) = 0;
	virtual int getNumberOfNodesEvaluated() { return m_evaluatedNodes; };
	virtual void checkEfficiency( Searchable<T,K>& s)
	{
		auto start_time = chrono::high_resolution_clock::now();
        search(s);
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        cout << "Time taken: " << duration.count() << " microseconds" << endl;
	}
	

public:
	const State<T>& popOpenList() { m_evaluatedNodes++; return m_openList.top(); }

protected:
	int m_evaluatedNodes;
	priority_queue<State<T>> m_openList;
};

