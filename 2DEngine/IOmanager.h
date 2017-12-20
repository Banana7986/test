#pragma once

#include  <vector>
#include <fstream>
namespace Engine {
	class IOmanager
	{
	public:
		static bool  readFileToBuffer(std::vector<unsigned char>& buffer, std::string filePath);
	};

}