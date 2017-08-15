#include <Compiler/Token.h>

namespace Compiler {

	Token::Token(int type, int data, int line) {
		this->type = type;
		this->data = data;
		this->line = line;
	}
	
	Token::~Token() {
		// Nothing
	}
	
	void Token::printList(List<Token*>* tokenList, List<char*>* nameList) {
		Token* t;
		for (int i = 0; i < tokenList->getSize(); i++) {
			t = tokenList->get(i);
			printf("%d: ", t->getLine());
			
			// Keywords
			if (t->getType() == TokenType::KEYWORD ||
					t->getType() == TokenType::TYPE) {
				switch (t->getData()) {
					case TokenKeyword::INT:
						printf("INT\n"); break;
					case TokenKeyword::RETURN:
						printf("RETURN\n"); break;
					default:
						break;
				}
			}
			
			// Special Characters
			else if (t->getType() == TokenType::SPECIAL) {
				switch(t->getData()) {
					case TokenSpecial::LEFT_PAR:
						printf("(\n"); break;
					case TokenSpecial::RIGHT_PAR:
						printf(")\n"); break;
					case TokenSpecial::LEFT_BRACKET:
						printf("{\n"); break;
					case TokenSpecial::RIGHT_BRACKET:
						printf("}\n"); break;
					case TokenSpecial::SEMICOLON:
						printf(";\n"); break;
					default:
						break;
				}
			}
			
			// Numbers
			else if (t->getType() == TokenType::NUMBER) {
				printf("NUM: %d\n", t->getData());
			}
			
			// Name
			else if (t->getType() == TokenType::NAME) {
				printf("NAME: %s\n", nameList->get(t->getData()));
			}
			
			else {
				printf("???\n");
			}
		}
	}

}