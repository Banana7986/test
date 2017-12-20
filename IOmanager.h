#pragma once

#include  <vector>
#include <fstream>

class IOmanager
{
public:
	static bool  readFileToBuffer(std::vector<unsigned char>& buffer, std::string filePath);
};

