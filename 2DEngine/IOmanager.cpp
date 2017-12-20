#include "IOmanager.h"

namespace Engine {
	bool  IOmanager::readFileToBuffer(std::vector<unsigned char>& buffer, std::string filePath)
	{
		std::ifstream file(filePath, std::ios::binary);
		if (file.fail())
		{
			perror(filePath.c_str());
			return false;
		}

		//hledani konce filu
		file.seekg(0, std::ios::end);

		//file size
		int fileSize = file.tellg();
		//hledani zacatku filu
		file.seekg(0, std::ios::beg);
		//redukuje file size od headeru filu
		fileSize -= file.tellg();

		buffer.resize(fileSize);
		file.read((char*)&(buffer[0]), fileSize);
		file.close();
		return true;
	}
}

