#include <Compiler/Compile.h>

namespace Compiler {

	Compile::Compile() {
		this->out = fopen("out.s", "w");
		fprintf(this->out, "%s", ASM_TEMPLATE);
	}
	
	Compile::~Compile() {
		fclose(this->out);
	}
	
	void Compile::start() {
		Token* t;
		Token** tok = tokenList->getRawData();
		
		for (int i = 0; i < tokenList->getSize(); i++) {
			t = tok[i];
			
			// Function returning an integer
			if (t->getType() == TokenType::TYPE && t->getData() == TokenKeyword::INT &&
					tok[i+1]->getType() == TokenType::NAME &&
					tok[i+2]->getType() == TokenType::SPECIAL && tok[i+2]->getData() == TokenSpecial::LEFT_PAR &&
					tok[i+3]->getType() == TokenType::SPECIAL && tok[i+3]->getData() == TokenSpecial::RIGHT_PAR) {
				char* name = strdup(nameList->get(tok[i+1]->getData()));
				fprintf(this->out, "%s:\n", name);
				//i += 3;
			}
			
			// Return a number
			else if (t->getType() == TokenType::KEYWORD && t->getData() == TokenKeyword::RETURN &&
					tok[i+1]->getType() == TokenType::NUMBER &&
					tok[i+2]->getType() == TokenType::SPECIAL && tok[i+2]->getData() == TokenSpecial::SEMICOLON) {
				fprintf(this->out, "\tmov rdx, %d\n", tok[i+1]->getData());
				fprintf(this->out, "%s", "\tret\n\n");
				//i += 2;
			}
		}
	}
	
	void Compile::setTokenList(List<Token*>* tokenList) {
		this->tokenList = tokenList;
	}
	
	void Compile::setNameList(List<char*>* nameList) {
		this->nameList = nameList;
	}

}