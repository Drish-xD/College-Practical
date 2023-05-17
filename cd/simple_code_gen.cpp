#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TACInstruction
{
  string result;
  string operand1;
  string operand2;
  string operation;
};
void generateAssembly(const vector<TACInstruction> &
                          tacInstructions)
{
  string resultRegister = "";
  for (const TACInstruction &instruction : tacInstructions)
  {
    if (instruction.operation == "+")
    {
      if (resultRegister.empty())
      {
        resultRegister = instruction.result;
      }
      else
      {
        cout << "add " << resultRegister << ", " << instruction.operand1 << endl;
      }
      cout << "add " << resultRegister << ", " << instruction.operand2 << endl;
    }
    else if (instruction.operation == "-")
    {
      if (resultRegister.empty())
      {
        resultRegister = instruction.result;
      }
      else
      {
        cout << "sub " << resultRegister << ", " << instruction.operand1 << endl;
      }
      cout << "sub " << resultRegister << ", " << instruction.operand2 << endl;
    }
    else if (instruction.operation == "*")
    {
      if (resultRegister.empty())
      {
        resultRegister = instruction.result;
      }
      else
      {
        cout << "imul " << resultRegister << ", " << instruction.operand1 << endl;
      }
      cout << "imul " << resultRegister << ", " << instruction.operand2 << endl;
    }
    else
    {
      cout << "; Unsupported operation: " << instruction.operation
           << endl;
    }
  }
  cout << "mov " << resultRegister << ", " << tacInstructions.back().result << endl;
}
int main()
{
  vector<TACInstruction> tacInstructions = {
      {"t1",
       "a",
       "b",
       "+"},
      {"t2",
       "t1",
       "c",
       "*"},
      {"result",
       "t2",
       "d",
       "-"}};
  generateAssembly(tacInstructions);
  return 0;
}



// Output

// add t1, b
// imul t1, t1
// imul t1, c
// sub t1, t2
// sub t1, d
// mov t1, result