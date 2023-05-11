//
//  opcodes.hpp
//  Assembly Project 1
//
//  
//

#ifndef opcodes_hpp
#define opcodes_hpp

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;


void arrange_data(vector<string> data);
vector<string> split (string instruction);
int reg_num(string r);
int reg_name(string r);
void display_registers();
void binary(int n);
string hex(int n);

void add(string instruction);
void addi(string instruction);
void slt(string instruction);
void sltu(string instruction);
void sub(string instruction);
void sll (string instruction);
void annd (string instruction); //because 'and' is a key word
void slti(string instruction);
void sltiu(string instruction);
void xori(string instruction);
void ori(string instruction);
void andi(string instruction);
void slli(string instruction);
void lui(string instruction);
int beq(string instruction,vector<string> instructions, int start, int pc);
int bne(string instruction,vector<string> instructions, int start, int pc);
int blt(string instruction,vector<string> instructions, int start, int pc);
int jalr (string instruction, vector<string> instructions, int start, int pc);
int bge(string instruction,vector<string> instructions, int start, int pc);
void xorr(string instruction); //because 'xor' is a key word
void orr(string instruction);  //because 'or' is a key word
void srli(string instruction);
void srai(string instruction);
void lw(string instruction);
void lbu(string instruction);
void lb(string instruction);
void lhu(string instruction);
void lh(string instruction);
void sb(string instruction);
void sw(string instruction);
void sh(string instruction);

#endif /* opcodes_hpp */



