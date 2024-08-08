#include "dsl_tokenizer.hpp"
#include <iostream>
BT_DSL::PatternTokenizer::PatternTokenizer(std::string input, int current)
{
    m_input = input;
    m_current = current;
}

// tokenization for any pattern based tokens
BT_DSL::token BT_DSL::PatternTokenizer::pattern(int type, std::string pattern)
{
    std::smatch match;
    // obtaining substs so all already parsed characters are ignored.
    std::string substr = m_input.substr(m_current);
    // you need ^ preceeding any pattern so regex can be properly parsed
    if(std::regex_search(substr, match, std::regex("^" + pattern, std::regex_constants::icase)))
    {
        token t = {
            .characters = static_cast<int>(match.length()),
            .type = type,
            .value = substr.substr(0,match.length())
        };
        return t;
    }
    return {
        .characters = 0,
        .type = NONE,
        .value = ""
    };
}

BT_DSL::PatternTokenizer BT_DSL::UniTokenizer::tokenize(std::string input, int current){
    PatternTokenizer ft(input,current);
    return ft;
}

void BT_DSL::UniTokenizer::addToken(int TYPE, std::string pattern, bool accept, int req_pos)
{
    m_tokenizers.push_back({TYPE,pattern,req_pos,accept});
}

BT_DSL::tokens BT_DSL::UniTokenizer::process(std::string input_str)
{
    int current = 0;
    BT_DSL::tokens tokens;

    while(current < input_str.length())
    {
        // iterate through all tokenizers
        for(auto tkzr : m_tokenizers){
            token t = tokenize(input_str, current).pattern(tkzr.type,tkzr.value);
            if(t.characters > 0){
                current += t.characters;
                if(tkzr.accept) tokens.push_back(t);
                break;
            }
        }
    }
    return tokens;
}


// Definitions of the tokens for CMD processor
BT_DSL::btTokenizer::btTokenizer(){
    m_tokenizer.addToken(TREE,"\\bTree\\b");
    m_tokenizer.addToken(NODE,"\\bNode\\b");
    m_tokenizer.addToken(LEFT,"Left:");
    m_tokenizer.addToken(RIGHT,"Right:");
    m_tokenizer.addToken(VALUE,"value:");
    m_tokenizer.addToken(BRACKET_OPEN,"\\{");
    m_tokenizer.addToken(BRACKET_CLOSE,"\\}");
    m_tokenizer.addToken(NUMBER,"\\b[0-9]+\\b");
    m_tokenizer.addToken(WHITECHAR,"\\s",false);
}

BT_DSL::tokens BT_DSL::btTokenizer::process(std::string bt_file){
    BT_DSL::tokens tokens = m_tokenizer.process(bt_file);
    return tokens;
};
