#ifndef COMPILER_VARIABLE_H
#define COMPILER_VARIABLE_H

#include <cstdlib>
#include <cstring>

#include <Compiler/List.h>

namespace Compiler {

    enum VariableSize {
        BYTE,
        WORD,
        DOUBLE,
        STRING
    };

	class Variable {
	private:
    	char* name;
		int data;
		int size;
		
	public:
	    Variable(char* name, int data, int size);
	    ~Variable();
	    
	    static int variableExists(List<Variable*>* list, char* name);
	    
	    inline char* getName() const { return name; }
	    inline int getData() const { return data; }
	    inline int getSize() const { return size; }
	    
	    const char* getSizeASM();
	};

}

#endif // COMPILER_VARIABLE_H