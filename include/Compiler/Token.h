#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H

#include <cstdio>
#include <cstdlib>

#include <Compiler/List.h>

namespace Compiler {

	enum TokenType {
		KEYWORD,
		NAME,
		ID,
		SPECIAL,
		NUMBER
	};
	
	enum TokenKeyword {
		INT,
		RETURN
	};
	
	enum TokenSpecial {
		LEFT_PAR,
		RIGHT_PAR,
		LEFT_BRACKET,
		RIGHT_BRACKET,
		SEMICOLON
	};

	class Token;
	template class List<Token*>;

	class Token {
	private:
		int type;
		int data;
		int line;
		
	public:
		Token(int type, int data, int line);
		~Token();
		
		inline int getType() const { return type; }
		inline int getData() const { return data; }
		inline int getLine() const { return line; }
		
		inline void setType(int type) { this->type = type; }
		inline void setData(int data) { this->data = data; }
		
		static void printList(List<Token*>* tokenList);
	};

}

#endif // COMPILER_TOKEN_H