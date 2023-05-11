//
//  main.cpp
//  Assembly Project 1
//  Group 6
//  By Lina Serry 900203355, Amany Shehata 900212086, Farida Amin 900192074
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "opcodes.hpp"
using namespace std;

map<int, string> instruction_mem;

void decode(int start, string instruction,vector<string> instructions,int pc);
void arrange_data(vector<string> data);
void arrange_inst(vector<string> instruction, int start);
void execute (int pc,int start, vector<string> instructions, int index);


int main()
{
    string input_program, input_data;
    int start;

//    cout<<"Enter instruction file name: ";
//    getline(cin, input);
    input_program= "program.txt";

    ifstream prog_file;
    prog_file.open(input_program);
    vector <string> instructions;
    string line;

    while (getline(prog_file, line))
    {
        instructions.push_back(line);
    }

    //    cout<<"Enter data file name: ";
    //    getline(cin, input);

    input_data= "data.txt";

    ifstream data_file;
    data_file.open(input_data);
    vector <string> data;
    string l;

    while (getline(data_file, l))
    {
        data.push_back(l);
    }


//    cout<<"Starting Address: ";
//    cin>> start;
    start=2000;
   

    arrange_data(data);
    arrange_inst(instructions, start);

    execute(start,start,instructions,0);
 
    return 0;
}



void execute (int start, int pc, vector<string> instructions, int index)
{
    for(int i=index;i<instruction_mem.size();i++)
    {
        cout<<"\tpc= " <<pc<<endl;
        decode(start,instruction_mem[pc],instructions,pc);
        pc += 4;
    }
}



void decode (int start, string instruction,vector<string> instructions, int pc)
{
    
    string opcode;

    opcode= instruction.substr(0, instruction.find(' '));

    if(opcode=="ADD")
      add(instruction);
    if(opcode=="SUB")
       sub(instruction);
    if(opcode=="SLT")
        slt(instruction);
    if(opcode=="SLTU")
        sltu(instruction);
    if(opcode=="SLTIU")
       sltiu(instruction);
    if(opcode=="SLL")
       sll(instruction);
    if(opcode=="ADDI")
       addi(instruction);
    if(opcode=="SLTI")
       slti(instruction);
    if(opcode=="XORI")
        xori(instruction);
    if(opcode=="ORI")
        ori(instruction);
    if(opcode=="ANDI")
       andi(instruction);
    if(opcode=="SLLI")
        slli(instruction);
    if(opcode=="AND")
        annd(instruction);
    if(opcode=="BEQ")
    { int p= beq(instruction, instructions, start, pc);
        execute(start, p, instructions, (p-start)/4);
    }
    if(opcode=="BNE")
    { int p= bne(instruction, instructions, start, pc);
        execute(start, p, instructions, (p-start)/4);
    }
    if(opcode=="BLT")
    { int p= blt(instruction, instructions, start, pc);
        execute(start, p, instructions, (p-start)/4);
    }
    if(opcode=="BGE")
    { int p= bge(instruction, instructions, start, pc);
        execute(start, p, instructions, (p-start)/4);
    }
    if(opcode=="XOR")
        xorr(instruction);
    if(opcode=="OR")
        orr(instruction);
    if(opcode=="SRAI")
        srai(instruction);
    if(opcode=="SRLI")
        srli(instruction);
    if(opcode=="LW")
        lw(instruction);
    if(opcode=="LBU")
        lbu(instruction);
    if(opcode=="LB")
        lb(instruction);
    if(opcode=="LHU")
        lhu(instruction);
    if(opcode=="LH")
        lh(instruction);
    if(opcode=="SB")
        sb(instruction);
    if(opcode=="SW")
        sw(instruction);
    if(opcode=="SH")
        sh(instruction);
    if(opcode=="LUI")
        lui(instruction);
    
    if((opcode=="ECALL")||(opcode=="EBREAK")||(opcode=="FENCE"))
        terminate();
}



void arrange_inst(vector<string> instructions, int start)
{
    vector<int> key(instructions.size());
    vector<string> value(instructions.size());
    
    for (int i=0; i<instructions.size();i++)
    {
        key[i]=start;
        value[i]=instructions[i];
        start += 4;
        
        instruction_mem[key[i]]=value[i];
    }
}


