#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <Compiler/Util.h>
#include <Compiler/Parser.h>

using namespace Compiler;

int main(int argc, char** argv) {
	char* src = strdup(Util::readFile("tests/ret_num.c"));
	
	Parser p(src);
	p.start();
	p.printTokenList();
	
	return 0;
}