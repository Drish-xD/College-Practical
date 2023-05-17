#include <bits/stdc++.h>

struct ProductionRule
{
  std::string nonTerminal;
  std::vector<std::string> expansions;
};
void eliminateLeftRecursion(std::vector<ProductionRule> &grammar)
{
  std::vector<ProductionRule> newGrammar;
  for (const auto &rule : grammar)
  {
    std::vector<std::string> recursiveExpansions;
    std::vector<std::string> nonRecursiveExpansions;
    for (const auto &expansion : rule.expansions)
    {
      if (expansion[0] == rule.nonTerminal[0])
      {
        recursiveExpansions.push_back(expansion.substr(1));
      }
      else
      {
        nonRecursiveExpansions.push_back(expansion);
      }
    }
    if (!recursiveExpansions.empty())
    {
      std::string newNonTerminal = rule.nonTerminal + "'";
      std::string newExpansion;
      for (const auto &recursiveExp : recursiveExpansions)
      {
        newExpansion += recursiveExp + newNonTerminal + "|";
      }
      newExpansion += "epsilon";
      newGrammar.push_back({rule.nonTerminal,
                            nonRecursiveExpansions});
      newGrammar.push_back({newNonTerminal,
                            {newExpansion}});
    }
    else
    {
      newGrammar.push_back(rule);
    }
  }
  grammar = newGrammar;
}
void eliminateLeftFactoring(std::vector<ProductionRule> &grammar)
{
  std::vector<ProductionRule> newGrammar;
  for (const auto &rule : grammar)
  {
    std::vector<std::string> expansions = rule.expansions;
    while (!expansions.empty())
    {
      std::string currentExpansion = expansions[0];
      std::vector<std::string> commonPrefixes;
      for (size_t i = 1; i < expansions.size(); ++i)
      {
        size_t j = 0;
        while (j < currentExpansion.length() && j < expansions[i].length() && currentExpansion[j] == expansions[i][j])
        {
          ++j;
        }
        commonPrefixes.push_back(currentExpansion.substr(0, j));
      }
      if (!commonPrefixes.empty())
      {
        std::string longestPrefix = *std::max_element(commonPrefixes.begin(), commonPrefixes.end(),
                                                      [](const std::string &prefix1,
                                                         const std::string &prefix2)
                                                      {
                                                        return prefix1.length() < prefix2.length();
                                                      });
        std::string newNonTerminal = rule.nonTerminal + "'";
        std::vector<std::string> newExpansions;
        for (const auto &expansion : expansions)
        {
          if (expansion.substr(0, longestPrefix.length()) ==
              longestPrefix)
          {
            newExpansions.push_back(expansion.substr(longestPrefix.length()));
          }
          else
          {
            newExpansions.push_back(expansion);
          }
        }
        newExpansions.push_back(newNonTerminal);
        newGrammar.push_back({rule.nonTerminal,
                              newExpansions});
      }
      else
      {
        newGrammar.push_back(rule);
      }
      expansions.erase(expansions.begin());
    }
  }
  grammar = newGrammar;
}
int main()
{
  std::vector<ProductionRule> recgrammar = {
      {"S",
       {"S+A",
        "A"}},
      {"A",
       {"a"}}};
  std::cout << "Original Grammar:" << std::endl;
  for (const auto &rule : recgrammar)
  {
    std::cout << rule.nonTerminal << " -> ";
    for (const auto &expansion : rule.expansions)
    {
      std::cout << expansion << " | ";
    }
    std::cout << std::endl;
  }
  eliminateLeftRecursion(recgrammar);
  std::cout << "Grammar after eliminating left recursion:" << std::endl;
  for (const auto &rule : recgrammar)
  {
    std::cout << rule.nonTerminal << " -> ";
    for (const auto &expansion : rule.expansions)
    {
      std::cout << expansion << " | ";
    }
    std::cout << std::endl;
  }
  std::vector<ProductionRule> facgrammar = {
      {"S",
       {"S+A",
        "S-B",
        "A"}},
      {"A",
       {"a",
        "b"}}};
  std::cout << "Original Grammar:" << std::endl;
  for (const auto &rule : facgrammar)
  {
    std::cout << rule.nonTerminal << " -> ";
    for (const auto &expansion : rule.expansions)
    {
      std::cout << expansion << " | ";
    }
    std::cout << std::endl;
  }
  eliminateLeftFactoring(facgrammar);
  std::cout << "Grammar after eliminating left factoring:" << std::endl;
  for (const auto &rule : facgrammar)
  {
    std::cout << rule.nonTerminal << " -> ";
    for (const auto &expansion : rule.expansions)
    {
      std::cout << expansion << " | ";
    }
    std::cout << std::endl;
  }
  return 0;
}


// Output

//Original Grammar:
// S -> S+A | A |
// A -> a |
// Grammar after eliminating left recursion:
// S -> A |
// S' -> +AS'|epsilon |
// A -> a |
// Original Grammar:
// S -> S+A | S-B | A |
// A -> a | b |
// Grammar after eliminating left factoring:
// S -> +A | -B | A | S' |
// S -> S-B | A | S' |
// S -> S+A | S-B | A |
// A -> a | b | A' |
// A -> a | b |