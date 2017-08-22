#include <Compiler/Compile.h>

namespace Compiler {

	Compile::Compile() {
	    this->varList = new List<Variable*>(1);
	    
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
				writeLabel(name);
			}
			
			// Return a number
			else if (t->getType() == TokenType::KEYWORD && t->getData() == TokenKeyword::RETURN &&
					tok[i+1]->getType() == TokenType::NUMBER &&
					tok[i+2]->getType() == TokenType::SPECIAL && tok[i+2]->getData() == TokenSpecial::SEMICOLON) {
				retLiteral(tok[i+1]->getData());
				//i += 2;
			}
			
			// Declare a variable
			else if (t->getType() == TokenType::TYPE && t->getData() == TokenKeyword::INT &&
			        tok[i+1]->getType() == TokenType::NAME &&
			        tok[i+2]->getType() == TokenType::SPECIAL && tok[i+2]->getData() == TokenSpecial::SEMICOLON) {
			    char* name = strdup(nameList->get(tok[i+1]->getData()));
			    this->varList->add(new Variable(name, 0, VariableSize::DOUBLE));
			}
			
			// Declare and define a variable
			// int name = num;
			else if (t->getType() == TokenType::TYPE && t->getData() == TokenKeyword::INT &&
			        tok[i+1]->getType() == TokenType::NAME &&
			        tok[i+2]->getType() == TokenType::SPECIAL && tok[i+2]->getData() == TokenSpecial::EQUALS &&
			        tok[i+3]->getType() == TokenType::NUMBER &&
			        tok[i+4]->getType() == TokenType::SPECIAL && tok[i+4]->getData() == TokenSpecial::SEMICOLON) {
			    char* name = strdup(nameList->get(tok[i+1]->getData()));
			    int num = tok[i+3]->getData();
			    this->varList->add(new Variable(name, num, VariableSize::DOUBLE));
		    }
		}
		
		// Write out variables
		writeVariables();
	}
	
	void Compile::writeVariables() {
	    if (varList->getSize() == 0)
	        return;
	    
	    fprintf(this->out, "%s", "section .data\n");
	    
	    Variable* v;
	    for (int i = 0; i < varList->getSize(); i++) {
	        v = varList->get(i);
	        switch (v->getSize()) {
	            case VariableSize::DOUBLE: {
	                fprintf(this->out, "%s: dd %d", v->getName(), v->getData());
	                break;
	            }
	            case VariableSize::WORD: {
	                fprintf(this->out, "%s: dw %d", v->getName(), v->getData());
	                break;
	            }
	            case VariableSize::BYTE: {
	                fprintf(this->out, "%s: db %d", v->getName(), v->getData());
	                break;
	            }
	        }
	        fprintf(this->out, "%s", "\n");
	    }
	}
	
	void Compile::writeLabel(char* label) {
		fprintf(this->out, "%s:\n", label);
	}
	
	void Compile::retLiteral(int num) {
	    #if defined(C_BUILD_MAC)
		    fprintf(this->out, "\tmov rdx, %d\n", num);
		#elif defined(C_BUILD_LINUX)
		    fprintf(this->out, "\tmov edx, %d\n", num);
		#endif
		fprintf(this->out, "%s", "\tret\n\n");
	}
	
	void Compile::setTokenList(List<Token*>* tokenList) {
		this->tokenList = tokenList;
	}
	
	void Compile::setNameList(List<char*>* nameList) {
		this->nameList = nameList;
	}

}