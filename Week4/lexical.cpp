#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

enum TokenType{
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    NUMBER,
    PUNCTUATION,
    UNKNOWN
};


struct Token{
    string lexeme;
    TokenType type;
};


unordered_set<string> keywords={"if","else","for","while","return","int","float","char","void","double"};
unordered_set<char> operators={'+','-','*','/','=','>','<','&','|','!'};
unordered_set<char> punctuation={'(',')','{','}',';',','};

bool iskeyword(const string& str){
    return keywords.find(str)!=keywords.end();
}

vector<Token> tokenize(const string& input){
    vector<Token> tokens;
    int i=0;
    while (i< input.length()){
        
     if(isspace(input[i])){
        i++;
        continue;
     }  
     if(isalpha(input[i])){
        string lexeme;
        while(isalnum(input[i])){
            lexeme +=input[i];
            i++;
        }
        if(iskeyword(lexeme)){
            tokens.push_back({lexeme,KEYWORD});
        } else{
            tokens.push_back({lexeme,IDENTIFIER});
        }
     } 
     else if(isdigit(input[i])){
        string lexeme;
        while(isdigit(input[i])){
            lexeme+=input[i];
            i++;
        }
        tokens.push_back({lexeme,NUMBER});
     }

     else if(operators.find(input[i]) !=operators.end()){
        string lexeme(1,input[i]);
        tokens.push_back({lexeme,OPERATOR});
        i++;
     }

     else if(punctuation.find(input[i]) != punctuation.end()){
        string lexeme(1,input[i]);
        tokens.push_back({lexeme,PUNCTUATION});
        i++;
     }
     else{
        string lexeme(1,input[i]);
        tokens.push_back({lexeme,UNKNOWN});
        i++;
     }
    }
    return tokens;
}


void printTokens(const vector<Token>& tokens){
    for(const auto& token:tokens){
        cout<<"Token: " <<token.lexeme<<", Type: ";
        switch(token.type){
            case KEYWORD:
            cout<<"Keyword";
            break;
            case IDENTIFIER:
            cout<<"Identifier";
            break;
            case OPERATOR:
            cout<<"Operator";
            break;
            case NUMBER:
            cout<<"Number";
            break;
            case PUNCTUATION:
            cout<<"Punctuation";
            break;
            case UNKNOWN:
            cout<<"Unknown";
            break;
        }
        cout<< endl;
    }
}

int main() {
    string input = "int x = 10 + 20; if (x > 5) { x++; }";

    // Tokenize the input
    vector<Token> tokens = tokenize(input);

    // Print the tokens
    printTokens(tokens);

    return 0;
}