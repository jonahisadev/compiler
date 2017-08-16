#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <Compiler/Util.h>
#include <Compiler/Parser.h>
#include <Compiler/Compile.h>

using namespace Compiler;

int main(int argc, char** argv) {
	char* src = strdup(Util::readFile("tests/ret_num.c"));
	
	// Begin parsing
	Parser p(src);
	p.start();
	p.printTokenList();
	
	// Begin compilation
	Compile* c = p.createCompiler();
	c->start();
	delete c;
	
	// Run builds
	system("nasm out.s -f macho64 -o temp.o");
	system("ld temp.o -o out");
	system("rm temp.o");
	
	return 0;
}