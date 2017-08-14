#include <Compiler/Util.h>

namespace Compiler {

	char* Util::readFile(const char* path) {
		FILE* file = fopen(path, "r");
		if (!file) {
			printf("Couldn't open file '%s'\n", path);
			return nullptr;
		}
		
		fseek(file, 0, SEEK_END);
		int size = ftell(file);
		fseek(file, 0, SEEK_SET);
		
		char* buf = new char[size];
		fread(buf, 1, size, file);
		fclose(file);
		
		buf[size] = '\0';
		
		return buf;
	}

}