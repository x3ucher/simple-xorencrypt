#include <XOREncrypt.h>

using namespace signal_functions;
using namespace vector_functions;

std::string convertToBase3(int num) {
    if (num == 0) {
        return "00000";
    }
    std::string result = "";
    while (num > 0) {
        int tmp = num % 3;
        result = std::to_string(tmp) + result;
        num /= 3;
    }
    while (result.length() < 5) {
        result = "0" + result;
    }
    return result;
}

std::string stringToTernary(const std::string &word) {
    std::string ternary_word;
    for (char c : word) {
        ternary_word += convertToBase3(c);
    }
    return ternary_word;
}

int convertFromBase3(const std::string &base3) {
    int result = 0;
    int base = 1;
    for (int i = base3.length() - 1; i >= 0; i--) {
        result += (base3[i] - '0') * base;
        base *= 3;
    }
    return result;
}

std::string ternaryToString(const std::string &ternary_word) {
    std::string result = "";
    for (int i = 0; i < ternary_word.length(); i += 5) {
        std::string tmp = ternary_word.substr(i, 5);
        int num = convertFromBase3(tmp);
        result += static_cast<char>(num);
    }
    return result;
}

void keyRelength(int new_len, std::string &key){
    while (key.length() < new_len){
        key += key;
    }
    key = key.substr(0, new_len);
}

void keyChanger(Vector &key){
    size_t size = key.getSize();
    for (size_t i = 0; i < size; i++){
        if ((key.getValues())[i].get() == sigtype::X){
            (key.getValues())[i].set(static_cast<sigtype>((i % 2) || (size %2)));
        }
    }
}

Vector XOR(Vector &word, Vector &key){
    Vector result;
    Vector a = (~word) & key;
    Vector b = (~key) & word;
    result = a | b;
    return result;
}

std::string VectorToString(Vector &signal){
    std::string result = "";
    size_t len = signal.getLength();
    for (size_t i = 0; i < len; i++){
        result += std::to_string(static_cast<int>((signal.getValues())[i].get()));
    }
    return result;
}

Vector encrypt(std::string &message, std::string &key){
    std::string tern_message = stringToTernary(message);
    return decrypt(tern_message, key);
}

Vector decrypt(std::string &tern_message, std::string &key){
    std::string tern_key = stringToTernary(key);
    Vector vec_message = Vector(tern_message);
    Vector vec_key = Vector(tern_key);
    keyChanger(vec_key);
    Vector result = XOR(vec_message, vec_key);
    
    return result;
}

void encoder(){
    std::string message;
    std::string key;
    std::cout << "enter your message:\n>> ";
    std::cin.ignore();
    std::getline(std::cin, message);
    std::cout << "enter your key:\n>> ";
    std::cin >> key;

    keyRelength(message.length(), key);
    Vector crypt = encrypt(message, key);

    std::string result = VectorToString(crypt);
    std::cout << "your encrypted message:" << std::endl;
    std::cout << ">> \"" << result << "\"" << std::endl;
}

void decoder(){
    std::string code;
    std::string key;
    std::cout << "enter your code:\n>> ";
    std::cin >> code;
    if (code.find_first_not_of("012") != std::string::npos){
      throw std::invalid_argument("invalid characters in string");
    }
    if (code.length()%5 != 0){ 
        throw std::invalid_argument("invalid code");
    }
    std::cout << "enter your key:\n>> ";
    std::cin >> key;

    keyRelength(code.length()/5, key);
    Vector crypt = decrypt(code, key);

    std::string result = ternaryToString(VectorToString(crypt));
    std::cout << "your message:" << std::endl;
    std::cout << ">> \"" << result << "\"" << std::endl;
}

void welcome(){
    std::cout <<
    "==================================================================\n"; 
    std::string ternary =
    " _____ \n"
    "(_   _)                                      \n"
    "  | |   __   _ __   ___     _ _  _ __  _   _ \n"
    "  | | /'__`\\( '__)/' _ `\\ /'_` )( '__)( ) ( )\n"
    "  | |(  ___/| |   | ( ) |( (_| || |   | (_) |\n"
    "  (_)`\\____)(_)   (_) (_)`\\__,_)(_)   `\\__, |\n"
    "                                      ( )_| |\n"
    "                                      `\\___/'";
    std::string coder = 
    " _    _  _____  ___                            _              \n"
    "( )  ( )(  _  )|  _`\\                         ( )             \n"
    "`\\`\\/'/'| ( ) || (_) )______   ___    _      _| |   __   _ __ \n"
    "  >  <  | | | || ,  /(______)/'___) /'_`\\  /'_` | /'__`\\( '__)\n"
    " /'/\\`\\ | (_) || |\\ \\       ( (___ ( (_) )( (_| |(  ___/| |   \n"
    "(_)  (_)(_____)(_) (_)      `\\____)`\\___/'`\\__,_)`\\____)(_)   ";
  
    std::cout << ternary << std::endl;
    std::cout << coder << std::endl;
    std::cout <<
    "==================================================================\n"
    << std::endl; 
}

void bye(){
    std::cout <<
    "==================================================================\n";
    std::cout << 
    "         ,_         _,\n"
    "         |\\.-\"\"\"-.//|\n"
    "         `\\         `/\n"
    "        /    _   _    \\\n"
    "        |    a _ a    |\n"
    "        '.=    Y    =.'\n"
    "          >._  ^  _.<\n" 
    "         /   `````   \\\n" 
    "         )           (                bye...\n" 
    "        ,(           ),\n" 
    "       / )   /   \\   ( \\\n" 
    "       ) (   )   (   ) (\n" 
    "       ( )   (   )   ( )\n" 
    "       )_(   )   (   )_(-.._\n" 
    "      (  )_  (._.)  _(  )_, `\\\n" 
    "       ``(   )   (   )`` .' .'\n" 
    "           ```     ```   ( (`\n" 
    "                         '-'\n" << std::endl;
    std::cout <<
    "==================================================================\n";
}

void sadBye(){
    std::cout <<
    "==================================================================\n\n";
    std::cout <<
    "                        ,/|         _.--''^``-...___.._.,;\n"
    "  it seems like       /, \'.     _-'          ,--,,,--'''\n"
    " something went      { \\\\    `_-''       '    /}\n"
    "   wrong...             `;;'             ;   ; ;\n"
    "                  ._.--''     ._,,, _..'  .;.'\n"
    "                  (,_....----'''     (,..--''\n" << std::endl; 
    std::cout <<
    "==================================================================\n";
}