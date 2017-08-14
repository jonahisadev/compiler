#include <Compiler/Parser.h>

namespace Compiler {

	Parser::Parser(char* source) {
		this->source = source;
	}
	
	Parser::~Parser() {
		delete[] this->source;
	}
	
	void Parser::start() {
		char* lex = new char[256];
		int lexi = 0;
		int i = 0;
		
		resetLex:
		lexi = 0;
		for (int x = 0; x < 256; x++) {
			lex[x] = '\0';
		}
		
		while (!important(source[i])) {
			if (source[i] == '\n') {
				break;
			} else if (source[i] == '\t') {
				i++;
				goto resetLex;
			} else if (source[i] == '\0') {
				break;
			}
			
			lex[lexi++] = source[i++];
		}
		
		lex[lexi] = '\0';
		
		if (lexi == 0) {
			// TODO: switch for tokens
			if (source[i] != '\n' && source[i] != ' ')
				printf("%c\n", source[i]);
			i++;
		} else {
			printf("%s\n", lex);
		}
		
		end:
		if (source[i] == ' ') {
			i++;
		} else if (source[i] == '\n') {
			i++;
			//line++;
		} else if (source[i] == '\0') {
			return;
		}
		goto resetLex;
	}
	
	bool Parser::important(char c) {
		if (c == ' ' ||
				c == '{' ||
				c == '}' ||
				c == '(' ||
				c == ')' ||
				c == ';') {
			return true;
		}
		return false;
	}

}