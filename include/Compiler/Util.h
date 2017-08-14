#ifndef COMPILER_UTIL_H
#define COMPILER_UTIL_H

#include <cstdio>
#include <cstdlib>

namespace Compiler {

	class Util {
	public:
		static char* readFile(const char* path);
	};

}

#endif // COMPILER_UTIL_H