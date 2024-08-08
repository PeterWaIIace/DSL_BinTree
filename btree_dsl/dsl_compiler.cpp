#include "dsl_tokenizer.hpp"
#include "dsl_tree.hpp"
#include <iostream>
#include <fstream>
#include <string>

std::string read_input(std::string filename)
{
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return "";
    }

    std::string input((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return input;
};

void write_output(std::string filename, std::string payload)
{
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    outFile << "#include <stdio.h>\n#include \"btree.h\"\n";
    outFile << "int main(){\n";
    outFile << payload << "\n";
    outFile << "    return 0;\n";
    outFile << "};\n";
    outFile.close();

};


int main(int argc, char* argv[])
{
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
        return 1;
    }

    std::string output_filename = argv[2];
  
    BT_DSL::btTokenizer tknzr;
    auto tokens = tknzr.process(
        read_input(argv[1])
    );

    BT_DSL::AST abstract_syntax_tree(tokens);

    if(argc > 3)
    {
        if(0 == std::string("-i").compare(argv[3]))
        {
            std::cout << argv[3] << std::endl;
            write_output(
                argv[2],
                abstract_syntax_tree.emit_iter()
            );
        }
    }
    else
    {
        write_output(
            argv[2],
            abstract_syntax_tree.emit()
        );
    }

    return 0;
};