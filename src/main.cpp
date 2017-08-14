#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <Compiler/Util.h>

using namespace Compiler;

int main(int argc, char** argv) {
	char* src = strdup(Util::readFile("tests/ret_num.c"));
	printf("%s\n", src);
	return 0;
}