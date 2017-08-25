#include <Compiler/Variable.h>

namespace Compiler {

	Variable::Variable(char* name, int data, int size) {
	    this->name = strdup(name);
	    this->data = data;
	    this->size = size;
	}
	
    Variable::~Variable() {
        delete name;
    }
    
    int Variable::variableExists(List<Variable*>* list, char* name) {
        for (int i = 0; i < list->getSize(); i++) {
            if (!strcmp(name, list->get(i)->getName())) {
                return i;
            }
        }
        return -1;
    }
    
    const char* Variable::getSizeASM() {
        switch (getSize()) {
            case VariableSize::BYTE: {
                return "byte";
            }
            case VariableSize::WORD: {
                return "word";
            }
            case VariableSize::DOUBLE: {
                return "dword";
            }
            default: {
                return "";
            }
        }
    }

}