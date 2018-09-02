#pragma once

#include <vector>
#include "item.h"
#include "user.h"

class Machine {
public:
	std::vector<Item> m_Stock;
	void Widthdraw(const char* code, User user);
};
