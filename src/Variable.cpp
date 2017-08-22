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

}