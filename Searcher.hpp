#pragma once

#include "Solution.hpp"
#include "Searchable.hpp"

template <class T,class K>
class Searcher
{
public:
	virtual Solution<T> search( Searchable<T,K>& s) = 0;
	virtual int getNumberOfNodesEvaluated() = 0;
};

