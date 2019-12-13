//Leila Kalantari
//date;12/11/2019
//Program 4 Caesar CaeserCipher
//course 1063
// 
//
// 
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;
ifstream input("encrypt.txt");
ofstream output("decrypt.txt");
// CaeserCipher class that contains functions and variables 
//to encrypt/decrypt the strings
class CaeserCipher {
  private:
  string E;
  string D;
  int shift;
  public:
  CaeserCipher();
  string Encrypt();
  string Decrypt();
  string UpperCase();
  void SetShift();

  string ReadCipherText();
  void WriteCipherText();
  string ReadPlainText();
  void WritePlainText();
};
// default conestruction
CaeserCipher::CaeserCipher(){
  string E=" ";
  string D=" ";
  int shift=0;
}
 // Encrypt
// Description :  Encrypts a plain text

  // params: none

  // returns: encrypted string
  string CaeserCipher::Encrypt(){
    int integer=0;
    string str=D;

    for(int i=0;i<D.length();i++){
      if(str[i]>=65 && str[i]<=90){
        integer =(int)str[i]-65;
       integer += shift;
      integer = integer % 26;       
      str[i] = integer + 65;
      }
      }
      E=str;

    return E;

    // decrypt
    // Description :  decrypts an encripted string

  // params: none

  // returns: decrypted text
}
  string CaeserCipher::Decrypt(){
      int integer=0;
    string str=E;

    for(int i=0;i<E.length();i++){
      if(str[i]>=65 && str[i]<=90){
          integer =(int)str[i]-65;
       integer -= shift;
       if(integer<0){
         integer +=26;
       }
      integer = integer % 26;       
      str[i] = integer + 65;
      }
      }
      D=str;

    return D;
}

// UpperCase
// Description: uppercase

 // Params:
 // none
 // Returns: Encrpted string but uppercase
 
  string CaeserCipher::UpperCase(){
    for(int i=0;i<E.length();i++){
       int intVal=0;
      intVal=(int)E[i]-65;
      intVal += shift % 26;       // Shift the letter, using mod to wrap back around
      E[i] = intVal + 65;

    }
    return E ;
  }
  //reads shift from file
  void CaeserCipher::SetShift(){
    input>>shift;

  }
//
  string CaeserCipher::ReadCipherText(){
    SetShift();
    getline(input, E);
    getline(input, E);
    return E;
  }
  void CaeserCipher::WriteCipherText(){
    output<<E<<endl;

  }
  //reads plain text 
  string CaeserCipher::ReadPlainText(){
     getline(input, D);
    getline(input, D);
    UpperCase();
    
    return D;
  }
  void CaeserCipher::WritePlainText(){
    output<<D<<endl;

  }

  // main
  // description: calling all the functions and reads the file 
  //and print it in the output file

  // params: none

  // returns: 0

int main() {
  //ofstream input; 
  output<< "Leila Kalantari"<<endl;
  output<< "date;12/11/2019"<<endl;
  output<< "program 4"<<endl<<endl;
  int count = 0;
input >> count;

for (int i = 0; i < count; i++) {
CaeserCipher a;
a.ReadCipherText();
a.Decrypt();
a.WritePlainText();
}
return 0;
}

