#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

#include <cstdio>
#include <cstdlib>

namespace Compiler {

	class Parser {
	private:
		char* source;
		
	public:
		Parser(char* source);
		~Parser();
		
		void start();
		bool important(char c);
	};

}

#endif // COMPILER_PARSER_H