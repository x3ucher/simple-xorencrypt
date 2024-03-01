#ifndef XORENCRYPT_H
#define XORENCRYPT_H

#include <string>
#include <iostream>
#include <Base/base.h>
#include <Vector/vector.h>

void welcome();
void bye();
void sadBye();
void decoder();
void encoder();

void keyChanger(vector_functions::Vector &key);
std::string convertToBase3(int num);
std::string stringToTernary(const std::string &word);
int convertFromBase3(const std::string &base3);
std::string ternaryToString(const std::string &ternary_word);
void keyRelength(int new_len, std::string &key);
vector_functions::Vector XOR(vector_functions::Vector &word, vector_functions::Vector &key);
std::string VectorToString(vector_functions::Vector &signal);
vector_functions::Vector encrypt(std::string &message, std::string &key);
vector_functions::Vector decrypt(std::string &message, std::string &key);

#endif //XORENCRYPT_H