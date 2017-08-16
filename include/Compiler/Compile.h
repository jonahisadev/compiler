#ifndef COMPILER_COMPILE_H
#define COMPILER_COMPILE_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <Compiler/List.h>
#include <Compiler/Token.h>

/*
	C_BUILD_MAC: Build the compiler for 64-bit Mac assembly output
	C_BUILD_LINUX: Build the compiler for 32-bit Linux assembly output
*/
#define C_BUILD_MAC

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
		
		void writeLabel(char* label);
		void retLiteral(int num);
		
	private:
		#ifdef C_BUILD_MAC
			static constexpr char* const ASM_TEMPLATE = "global start\n\n"
				"section .data\n"
				"db 0x00\n\n"
				"section .text\n"
				"start:\n"
				"\tcall main\n"
				"\tmov rdi, rdx\n"
				"\tmov rax, 0x2000001\n"
				"\tsyscall\n\n";
		#elif C_BUILD_LINUX
			static constexpr char* const ASM_TEMPLATE = "global start\n\n"
				"section .text\n"
				"start:\n"
				"\tcall main\n"
				"\tmov rbx, rdx\n"
				"\tmov rax, 1\n"
				"\tint 0x80\n\n";
		#endif
	};

}

#endif // COMPILER_COMPILE_H