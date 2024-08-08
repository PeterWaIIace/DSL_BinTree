#pragma once

#include <string>
#include <vector>
#include <regex>
#include <map>
#include <variant>
#include <functional>

namespace BT_DSL{

    constexpr int NO_POS_REQ = -1;

    // Helper values for processing commands
    constexpr int PARAM_POS     = 1;
    constexpr int ID_POS        = 2;
    constexpr int PAYLOAD_START = 3;

    // Token types
    enum TYPES{
        NONE = 0, // NONE TYPE
        TREE,
        NODE,
        LEFT,
        RIGHT,
        BRACKET_OPEN,
        BRACKET_CLOSE,
        NUMBER,
        VALUE,
        WHITECHAR
    };

    /**
     * @brief Structure to represent token.
     */
    typedef struct{
        int characters;     // length of the token
        int type;           // type of the token
        std::string value;  // value stored by token
    }token;

    /**
     * @brief Helper structure for returning error messages.
     */
    struct error
    {
        std::string message;
    };


    using tokens = std::vector<token>;

    /**
     * @brief Helper structure to keep tokenizer information.
     */
    typedef struct{
        int type;           // type of tokenizer
        std::string value;  // pattern
        int req_pos;        // positional requirements
        bool accept;        // accept or discard detected token from output
    }tokenizer;

    /**
     * @class PatternTokenizer
     * @brief A class for single run tokenization of input based on pattern.
     */
    class PatternTokenizer
    {
        public:
        /**
         * @brief Constructs a PatternTokenizer object.
         *
         * @param[in] input The input string to tokenize.
         * @param[in] current The current position in the input string.
         */
        PatternTokenizer(std::string input, int current);

        /**
         * @brief pattern to detect token in string.
         *
         * @param[in] type    The type of token to look for.
         * @param[in] pattern The patter string can be detected by.
         */
        token pattern(int type, std::string pattern);

        private:

        std::string m_input;
        int m_current;
    };

    /**
     * @class UniTokenizer
     * @brief A class for detecting multiple tokens.
     */
    class UniTokenizer
    {
        public:

        /**
         * Adding token and tokenizer rules how to process it.
         *
         * @param[in] TYPE numerical type of the token
         * @param[in] pattern regex pattern for detecting token
         * @param[in] accept control bit allowing to accept or discard token from processed output
         * @param[in] req_pos positional requirement for token. By default NO_POS_REQ means no requirements.
         */
        void addToken(int TYPE, std::string pattern, bool accept = true , int req_pos = NO_POS_REQ);

        /**
         * Bind command with command call. After command is properly parsed it can call binded function
         *
         * @param[in] sg string command prefix, for now only "s" and "g" are accepted.
         * @param[in] cmd_name name of the command
         * @param[in] func function accepting id of the device and list of payload tokens, returning string
         * @return A response string which is outcome of executing command. Return <Error> if command is not processable.
         */
        tokens process(std::string cmd_str);

        private:

        PatternTokenizer tokenize(std::string input, int current);
        std::vector<tokenizer> m_tokenizers;

    };


    /**
     * @class CmdTokenizer
     * @brief A class for processing commands and calling binded functions.
     */
    class btTokenizer
    {
        UniTokenizer m_tokenizer;
        public:

        btTokenizer();

        /**
         * Processes string command passed by user.
         *
         * @param[in] cmd the data to analyze
         * @return A response string which is outcome of executing command. Return <Error> if command is not processable.
         */
        tokens process(std::string bt_file);
    };
};