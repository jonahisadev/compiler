#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <Compiler/List.h>
#include <Compiler/Token.h>
#include <Compiler/Util.h>

namespace Compiler {

	template class List<char*>;

	class Parser {
	private:
		char* source;
		List<Token*>* tokenList;
		List<char*>* nameList;
		
	public:
		Parser(char* source);
		~Parser();
		
		void start();
		bool important(char c);
		void printTokenList();
	};

}

#endif // COMPILER_PARSER_H