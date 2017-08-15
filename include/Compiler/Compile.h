#ifndef COMPILER_COMPILE_H
#define COMPILER_COMPILE_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <Compiler/List.h>
#include <Compiler/Token.h>

namespace Compiler {

	class Compile {
	private:
		List<Token*>* tokenList;
		List<char*>* nameList;
		
		FILE* out;
		
	public:
		Compile();
		~Compile();
		
		void start();
		
		void setTokenList(List<Token*>* tokenList);
		void setNameList(List<char*>* nameList);
		
	private:
		static constexpr char* const ASM_TEMPLATE = "global start\n\n"
			"section .data\n"
			"db 0x00\n\n"
			"section .text\n"
			"start:\n"
			"\tcall main\n"
			"\tmov rdi, rdx\n"
			"\tmov rax, 0x2000001\n"
			"\tsyscall\n\n";
	};

}

#endif // COMPILER_COMPILE_H