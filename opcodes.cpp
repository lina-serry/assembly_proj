//
//  opcodes.cpp
//  Assembly Project 1
//
//
//

#include "opcodes.hpp"
int reg_f[32]={0};

map<int, int> data_mem;


void arrange_data(vector<string> data)
{
    vector<int> key(data.size()), value(data.size());
    
    for (int i=0; i<data.size();i++)
    {
        key[i]=stoi(data[i].substr(0, data[i].find(' ')));
   
        value[i]=stoi(data[i].substr(data[i].find(' ')+1, data.size()+1));
        
        data_mem[key[i]]=value[i];
    }
}


vector<string> split (string instruction)
{
    vector<string> regs;
    int start_index=0, end_index=0;
    
    for (int i=0;i<=instruction.length();i++)
    {
        if(instruction[i]==' '||instruction[i]==','||i==instruction.length()||instruction[i]=='('||instruction[i]==')')
        {    end_index=i;
             string temp;
             temp.append(instruction,start_index,end_index-start_index);
             regs.push_back(temp);
             start_index=end_index+1;
        }
    }
        return regs;
}



void binary(int n)
{
    int BN[32];
    int i= 0;
    while (n > 0)
    {
        BN[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    for (int j= i-1;j>=0;j--)
        cout<< BN[j];
}



string hex(int n)
{
    string s;

    while (n!=0)
    {
        int r=0;
        char c;
        r = n%16;
        if (r < 10)
             c = r + 48;
        
        else
            c = r + 55;
        
        s+= c;
        n = n/16;
    }
      
    int i=0, j=s.size()-1;
    while(i<=j)
    {
      swap(s[i], s[j]);
      i++;
      j--;
    }
    return s;
}


void display_registers() {
  cout << "Register values:" << endl<<"   D   B    H \n";
  for (int i = 0; i < 32; i++)
  {
      cout << "x"<<i<<":"<<reg_f[i]<<"  ";
      binary(reg_f[i]);cout<<" \t";
      cout<<hex(reg_f[i])<<endl;
  }
}


int reg_name(string r)
{
    if(r=="zero")
        return 0;
    if(r=="ra")
        return 1;
    if(r=="sp")
        return 2;
    if(r=="gp")
        return 3;
    if(r=="tp")
        return 4;
    if(r=="t0")
        return 5;
    if(r=="t1")
        return 6;
    if(r=="t2")
        return 7;
    if(r=="s0")
        return 8;
    if(r=="s1")
        return 9;
    if(r=="a0")
        return 10;
    if(r=="a1")
        return 11;
    if(r=="a2")
        return 12;
    if(r=="a3")
        return 13;
    if(r=="a4")
        return 14;
    if(r=="a5")
        return 15;
    if(r=="a6")
        return 16;
    if(r=="a7")
        return 17;
    if(r=="s2")
        return 18;
    if(r=="s3")
        return 19;
    if(r=="s4")
        return 20;
    if(r=="s5")
        return 21;
    if(r=="s6")
        return 22;
    if(r=="s7")
        return 23;
    if(r=="s8")
        return 24;
    if(r=="s9")
        return 25;
    if(r=="s10")
        return 26;
    if(r=="s11")
        return 27;
    if(r=="t3")
        return 28;
    if(r=="t4")
        return 29;
    if(r=="t5")
        return 30;
    if(r=="t6")
        return 31;
    
    else
        return -1;
}


int reg_num(string r) //taking register number
{
    if (reg_name(r)==-1) //if register written as x
    {
    int x= r[1]-'0';
    if(r.size()==3) //if double digit
    { r.erase(0,1);
        x=stoi(r);}
    return x;
    }
    else
        return reg_name(r);
}


void add(string instruction)
{
    vector<string> regs= split(instruction);
    
    string rd=regs[1];
    string rs1=regs[2];
    string rs2=regs[3];
    
    int d=reg_num(rd);
    int s1=reg_num(rs1);
    int s2=reg_num(rs2);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else
    reg_f[d]=reg_f[s1]+reg_f[s2];
    
    display_registers();
}

void mul(string instruction)
{
    vector<string> regs= split(instruction);
    
    string rd=regs[1];
    string rs1=regs[2];
    string rs2=regs[3];
    
    int d=reg_num(rd);
    int s1=reg_num(rs1);
    int s2=reg_num(rs2);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else
    reg_f[d]=reg_f[s1]*reg_f[s2];
    
    display_registers();
}



void addi(string instruction)
{
    vector<string> regs= split(instruction);
    
    string rd=regs[1];
    string rs=regs[2];
    int imm=stoi(regs[3]);
    
    int d=reg_num(rd);
    int s=reg_num(rs);
    
  if(d==0)
      cout<<"Error: value of x0 is constant \n";
  else
    reg_f[d]=reg_f[s]+imm;
    
    display_registers();
}

void slt(string instruction)
{
    vector<string>regs=split(instruction);
    string rd = regs[1];
    string rs1=regs[2];
    string rs2=regs[3];
    
    int d=reg_num(rd);
    int s1=reg_num(rs1);
    int s2=reg_num(rs2);
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else{
    if (reg_f[s1]<reg_f[s2])
    {
        reg_f[d] = 1;
    } else {
        reg_f[d] = 0;
    }}
    
    display_registers();

}


void sltu(string instruction)
{
    vector<string>regs=split(instruction);
    string rd = regs[1];
    string rs1=regs[2];
    string rs2=regs[3];
    
    int d=reg_num(rd);
    int s1=reg_num(rs1);
    int s2=reg_num(rs2);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else{
    if ((unsigned int)reg_f[s1]<(unsigned int)reg_f[s2])
    {
        reg_f[d] = 1;
    } else {
        reg_f[d] = 0;
    }}
    
    display_registers();

}


void sub(string instruction)
{
    vector<string>regs=split(instruction);
    string rd = regs[1];
    string rs1=regs[2];
    string rs2=regs[3];
    
    int d=reg_num(rd);
    int s1=reg_num(rs1);
    int s2=reg_num(rs2);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else
    reg_f[d] = reg_f[s1] - reg_f[s2];
    
    display_registers();

}


void sll (string instruction)
{
    vector<string>regs=split(instruction);
    string rd = regs[1];
    string rs= regs[2];
    
    int d = reg_num(rd);
    int s = reg_num(rs);
    int t = stoi(regs[3]);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else
    reg_f[d] = reg_f[s] << t;
    
    display_registers();
   
}


void annd (string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    string rs1=regs[2];
    string rs2=regs[3];
    
    int d=reg_num(rd);
    int s1=reg_num(rs1);
    int s2=reg_num(rs2);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else
    reg_f[d] = reg_f[s1] & reg_f[s2];
    
    display_registers();
 
}


void slti(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    string rs= regs[2];
    
    int d = reg_num(rd);
    int s = reg_num(rs);
    int imm = stoi(regs[3]);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else{
    if (reg_f[s] < imm)
    {
        reg_f[d] = 1;
    } else {
        reg_f[d] = 0;
    }}
    
    display_registers();
  
}


void sltiu(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    string rs= regs[2];
    
    int d = reg_num(rd);
    int s = reg_num(rs);

    int imm = stoi(regs[3]);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else{
    if (reg_f[s] < 0 || reg_f[s] >= (unsigned int)imm) {
        reg_f[d] = 0;
    } else {
        reg_f[d] = 1;
    }}
    
    display_registers();
}


void xori(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    string rs= regs[2];
    
    int d = reg_num(rd);
    int s = reg_num(rs);
    
    int imm = stoi(regs[3]);
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else
    reg_f[d] = reg_f[s]^imm;
    
    display_registers();
}


void ori(string instruction)
{
    vector<string> regs = split(instruction);
    string rd=regs[1];
    string rs=regs[2];
    
    int d = reg_num(rd);
    int s = reg_num(rs);
    
    int imm = stoi(regs[3]);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else
    reg_f[d] = reg_f[s]|imm;
    
    display_registers();
}


void andi(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    string rs = regs[2];
    
    int d = reg_num(rd);
    int s = reg_num(rs);
    
    int imm = stoi(regs[3]);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else
    reg_f[d] = reg_f[s]&imm;
    
    display_registers();
}


void slli(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    string rs= regs[2];
    
    int d = reg_num(rd);
    int s = reg_num(rs);
    
    int temp = stoi(regs[3]);
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else
    reg_f[d] = reg_f[s]<<temp;
    
    display_registers();
    
}


void lui(string instruction)
{
    vector<string> regs = split(instruction);
    int rd = reg_num(regs[1]);
    int imm = stoi(regs[2]);
    reg_f[rd] = imm << 16;
    
    if(rd==0)
        cout<<"Error: value of x0 is constant \n";
    else
    display_registers();
}


int beq(string instruction,vector<string> instructions, int start, int pc)
{
    vector<string> regs = split(instruction);
    int s = reg_num(regs[1]);
    int t = reg_num(regs[2]);
    string temp = regs[3];
    
    if(reg_f[s]==reg_f[t])
    {  for(int i=0;i<instructions.size();i++)
            {
                if(temp+":"==instructions[i])
                { pc=start+(i*4);}
            }
        return pc;
    }
    else
     return pc+4;
}


int bne(string instruction, vector<string> instructions, int start, int pc)
{
    vector<string> regs = split(instruction);
    int s = reg_num(regs[1]);
    int t = reg_num(regs[2]);
    string temp = regs[3];
    
    if (reg_f[s] != reg_f[t]) {
        for (int i = 0; i < instructions.size(); i++) {
            if (temp + ":"==instructions[i]) {
                pc = start+(i*4);
            }
        }
        return pc;
    }
    else
        return pc+4;
}


int blt(string instruction, vector<string> instructions, int start, int pc)
{
    vector<string> regs = split(instruction);
    int s = reg_num(regs[1]);
    int t = reg_num(regs[2]);
    string temp = regs[3];
    
    if (reg_f[s] < reg_f[t]) {
        for (int i = 0; i < instructions.size(); i++) {
            if (temp + ":"==instructions[i]) {
                pc = start+(i*4);
            }
        }
        return pc;
    }
    else
        return pc+4;
}


int bge(string instruction,vector<string> instructions, int start, int pc)
{
    vector<string> regs = split(instruction);
    int s = reg_num(regs[1]);
    int t = reg_num(regs[2]);
    string temp = regs[3];
    
    if(reg_f[s]>=reg_f[t])
    {  for(int i=0;i<instructions.size();i++)
            {
                if(temp+":"==instructions[i])
                { pc=start+(i*4);}
            }
        return pc;
    }
    else
     return pc+4;
}


void xorr(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    string rs1 = regs[2];
    string rs2 = regs[3];
    
    int d = reg_num(rd);
    int s1 = reg_num(rs1);
    int s2 = reg_num(rs2);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else
    reg_f[d] = reg_f[s1] ^ reg_f[s2];
    
    display_registers();
}


void orr(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    string rs1 = regs[2];
    string rs2 = regs[3];
    
    int d = reg_num(rd);
    int s1 = reg_num(rs1);
    int s2 = reg_num(rs2);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else
    reg_f[d] = reg_f[s1] | reg_f[s2];
    
    display_registers();
}


void srli(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    string rs1 = regs[2];
    string imm_str = regs[3];
    
    int d = reg_num(rd);
    int s1 = reg_num(rs1);
    int imm = stoi(imm_str);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else
    reg_f[d] = static_cast<uint32_t>(reg_f[s1]) >> imm;
    
    display_registers();
}


void srai(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    string rs1 = regs[2];
    string imm_str = regs[3];
    
    int d = reg_num(rd);
    int s1 = reg_num(rs1);
    int imm = stoi(imm_str);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else
    reg_f[d] = reg_f[s1] >> imm;
    
    display_registers();
}


void lw(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    int offset = stoi(regs[2]);
    string rs1 = regs[3];
    
    int d = reg_num(rd);
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else{
    int s1 = reg_num(rs1);
    
    int addr = reg_f[s1] + offset;
    int32_t value = data_mem[addr];
    
        reg_f[d] = value;}
    
    display_registers();
}


void lbu(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    int offset = stoi(regs[2]);
    string rs1 = regs[3];
    
    int d = reg_num(rd);
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else{
    int s1 = reg_num(rs1);
    
    int addr = reg_f[s1] + offset;
    uint8_t value = data_mem[addr];
    
        reg_f[d] = static_cast<int32_t>(value);}
    
    display_registers();
}


void lb(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    int offset = stoi(regs[2]);
    string rs1 = regs[3];
    
    int d = reg_num(rd);
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else{
    int s1 = reg_num(rs1);
    
    int addr = reg_f[s1] + offset;
    int8_t value = data_mem[addr];
    
        reg_f[d] = static_cast<int32_t>(value);}
    
    display_registers();
}


void lhu(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    int offset = stoi(regs[2]);
    string rs1 = regs[3];
    
    int d = reg_num(rd);
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else{
    int s1 = reg_num(rs1);
    
    int addr = reg_f[s1] + offset;
    uint16_t value = data_mem[addr];
    
        reg_f[d] = static_cast<int32_t>(value);}
    
    display_registers();
}


void lh(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    int offset = stoi(regs[2]);
    string rs1 = regs[3];
    
    int d = reg_num(rd);
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else{
    int s1 = reg_num(rs1);
    
    int addr = reg_f[s1] + offset;
    int16_t value = data_mem[addr];
    
        reg_f[d] = static_cast<int32_t>(value);}
    
    display_registers();
}


void sb(string instruction)
{
    vector<string> regs = split(instruction);
    string rs2 = regs[1];
    int offset = stoi(regs[2]);
    string rs1 = regs[3];
    
    int s2 = reg_num(rs2);
    int s1 = reg_num(rs1);
    
    int addr = reg_f[s1] + offset;
    int8_t value = reg_f[s2] & 0xFF;
    
    data_mem[addr] = value;
    
    display_registers();
}


void sw(string instruction)
{
    vector<string> regs = split(instruction);
    string rs2 = regs[1];
    int offset = stoi(regs[2]);
    string rs1 = regs[3];
    
    int s2 = reg_num(rs2);
    int s1 = reg_num(rs1);
    
    int addr = reg_f[s1] + offset;
    int32_t value = reg_f[s2];
    
    *(int32_t *)&data_mem[addr] = value;
    
    display_registers();
}


void sh(string instruction)
{
    vector<string> regs = split(instruction);
    string rs2 = regs[1];
    int offset = stoi(regs[2]);
    string rs1 = regs[3];
    
    int s2 = reg_num(rs2);
    int s1 = reg_num(rs1);
    
    int addr = reg_f[s1] + offset;
    int16_t value = reg_f[s2];
    
    *(int32_t *)&data_mem[addr] = value;
    
    display_registers();
}


void srl(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    string rs1 = regs[2];
    string shamt_str = regs[3];
    
    int d = reg_num(rd);
    
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else{
    int s1 = reg_num(rs1);
    int shamt = stoi(shamt_str);
    
    int32_t zero_ext_s1 = static_cast<int32_t>(reg_f[s1]); // Zero-extend rs1 to 32 bits
    
        reg_f[d] = zero_ext_s1 >> shamt;}
    
    display_registers();
}


void sra(string instruction)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    string rs1 = regs[2];
    string shamt_str = regs[3];
    
    int d = reg_num(rd);
    if(d==0)
        cout<<"Error: value of x0 is constant \n";
    else{
    int s1 = reg_num(rs1);
    int shamt = stoi(shamt_str);
    
    int32_t sign_ext_s1 = static_cast<int32_t>(reg_f[s1]); // Sign-extend rs1 to 32 bits
    
        reg_f[d] = static_cast<uint32_t>(sign_ext_s1 >> shamt);}
    
    display_registers();
}


void auipc(string instruction)
{
    vector<string> regs = split(instruction);
    int rd = reg_num(regs[1]);
    int offset = stoi(regs[2]);

    if(rd==0)
        cout<<"Error: value of x0 is constant \n";
    else{
    int imm = offset << 12;
        reg_f[rd] += imm;}
    
    display_registers();
}


int bgeu(string instruction,vector<string> instructions, int start, int pc)
{
    vector<string> regs = split(instruction);
    int s = reg_num(regs[1]);
    int t = reg_num(regs[2]);
    string temp = regs[3];
    
    if((uint32_t)reg_f[s]>=(uint32_t)reg_f[t])
    {  for(int i=0;i<instructions.size();i++)
            {
                if(temp+":"==instructions[i])
                { pc=start+(i*4);}
            }
        return pc;
    }
    else
     return pc+4;
}


int bltu(string instruction, vector<string> instructions, int start, int pc)
{
    vector<string> regs = split(instruction);
    int s = reg_num(regs[1]);
    int t = reg_num(regs[2]);
    string temp = regs[3];
    
    if ((uint32_t)reg_f[s] < (uint32_t)reg_f[t]) {
        for (int i = 0; i < instructions.size(); i++) {
            if (temp + ":"==instructions[i]) {
                pc = start+(i*4);
            }
        }
        return pc;
    }
    else
        return pc+4;
}


int jal(string instruction,  vector<string> instructions, int start, int pc)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    string label = regs[2];
    
    reg_f[reg_num(rd)] = pc + 4;
    
    for (int i = 0; i < instructions.size(); i++) {
        if (label + ":"==instructions[i]) {
            pc = start+(i*4);
        }
    }
    
    return pc;
}


int jalr(string instruction,  vector<string> instructions, int start, int pc)
{
    vector<string> regs = split(instruction);
    string rd = regs[1];
    int offset = stoi(regs[2]);
    string rs = regs[3];
    
    if(reg_num(rd)!=0)
      reg_f[reg_num(rd)] = pc + 4;
    
    pc=offset+reg_f[reg_num(rs)];
    
    return pc;
}
