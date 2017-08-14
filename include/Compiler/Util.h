#ifndef COMPILER_UTIL_H
#define COMPILER_UTIL_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace Compiler {

	class Util {
	public:
		static char* readFile(const char* path);
		static bool isNumber(char* num);
		static int toNumber(char* num, int base);
	};

}

#endif // COMPILER_UTIL_H