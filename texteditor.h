#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Editor {
private:
  list <char> textList;
  list <char>::iterator pos;
  list <char> buffer;
  void customAdvance(list <char>::iterator& it, size_t num){
    for (size_t i = 0; (i < num) && (it != textList.end()); ++i, ++it) { }
  }
public:
  explicit Editor(){
    pos = textList.end();
  }
  void Left(){
    if(pos != textList.begin())
      --pos;
  }
  void Right(){
    if(pos != textList.end())
      ++pos;
  }
  void Insert(char token){
    textList.insert(pos, token);
  }
  void Cut(size_t tokens = 1){
    buffer.clear();
    auto tokensIt = pos;
    customAdvance(tokensIt, tokens);
    buffer.splice(buffer.begin(), textList, pos, tokensIt);
    this->pos = tokensIt;
  }
  void Copy(size_t tokens = 1){
    buffer.clear();
    auto tokensIt = pos;
    customAdvance(tokensIt, tokens);
    buffer.insert(buffer.begin(), pos, tokensIt);
  }
  void Paste(){
    textList.insert(pos, buffer.begin(), buffer.end());
  }

  string GetText() const{
    return {textList.begin(), textList.end()};
  }

  //debug methods
  const list<char>& getTextList() const{
    return textList;
  }
  list <char>::iterator getIterator() const{
    return this->pos;
  }
  const list <char>& getBuffer() const {
    return buffer;
  }
};

void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}
