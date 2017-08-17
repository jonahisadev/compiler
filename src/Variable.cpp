#include <Compiler/Variable.h>

namespace Compiler {

	Variable(char* name, int data, int size) {
	    this->name = strdup(name);
	    this->data = data;
	    this->size = size;
	}
	
    ~Variable() {
        delete name;
    }

}