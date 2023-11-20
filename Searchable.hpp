#pragma once

#include <vector>
#include "State.hpp"

template <class T,class K>
class Searchable
{
public:
	virtual State<pair<K, K>> *getStartState() = 0;
	virtual State<pair<K, K>> *getGoalState() = 0;
	virtual State<T> *getProblemState() = 0;
	virtual State<K> *getWidthState() = 0;
	virtual State<K> *getHeightState() = 0;
};
