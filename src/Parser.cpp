#include <Compiler/Parser.h>

namespace Compiler {

	Parser::Parser(char* source) {
		this->source = source;
		this->tokenList = new List<Token*>(1);
		this->nameList = new List<char*>(1);
	}
	
	Parser::~Parser() {
		delete[] this->source;
		
		delete this->tokenList;
		delete this->nameList;
	}
	
	void Parser::start() {
		char* lex = new char[256];
		int lexi = 0;
		int i = 0;
		int line = 1;
		
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
		
		// Special Characters
		if (lexi == 0) {
			switch (source[i]) {
				case '(': {
					tokenList->add(new Token(TokenType::SPECIAL, TokenSpecial::LEFT_PAR, line));
					break;
				}
				case ')': {
					tokenList->add(new Token(TokenType::SPECIAL, TokenSpecial::RIGHT_PAR, line));
					break;
				}
				case '{': {
					tokenList->add(new Token(TokenType::SPECIAL, TokenSpecial::LEFT_BRACKET, line));
					break;
				}
				case '}': {
					tokenList->add(new Token(TokenType::SPECIAL, TokenSpecial::RIGHT_BRACKET, line));
					break;
				}
				case ';': {
					tokenList->add(new Token(TokenType::SPECIAL, TokenSpecial::SEMICOLON, line));
					break;
				}
				case '=': {
					tokenList->add(new Token(TokenType::SPECIAL, TokenSpecial::EQUALS, line));
					break;
				}
				default:
					break;
			}
			
			i++;
			goto end;
		}
		
		// Keywords
		else if (!strcmp(lex, "return")) {
			tokenList->add(new Token(TokenType::KEYWORD, TokenKeyword::RETURN, line));
			goto end;
		} else if (!strcmp(lex, "int")) {
			tokenList->add(new Token(TokenType::TYPE, TokenKeyword::INT, line));
			goto end;
		}
		
		// Numbers
		else if (Util::isNumber(lex)) {
			tokenList->add(new Token(TokenType::NUMBER, Util::toNumber(lex, 10), line));
			goto end;
		}
		
		// Names
		else {
			nameList->add(strdup(lex));
			tokenList->add(new Token(TokenType::NAME, nameList->getPointer()-1, line));
			goto end;
		}
		
		end:
		if (source[i] == ' ') {
			i++;
		} else if (source[i] == '\n') {
			i++;
			line++;
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
				c == ';' ||
				c == '=') {
			return true;
		}
		return false;
	}
	
	void Parser::printTokenList() {
		Token::printList(this->tokenList, this->nameList);
	}
	
	Compile* Parser::createCompiler() {
		Compile* c = new Compile();
		c->setTokenList(this->tokenList);
		c->setNameList(this->nameList);
		return c;
	}

}