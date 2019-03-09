#pragma once
#include <iostream>
#include <string>
//#include <experimental/string_view>

using namespace std;
//using namespace std::experimental;

class Editor {
private:
  class Position{
  public:
    Position() {

    }

    Position& operator++(){
      if(text_size > 0 && pos < text_size)
        this->pos++;
      return *this;
    }
    Position& operator--(){
      if(pos > 0)
        this->pos--;
      return *this;
    }
    void Insert(){
      pos++;
      text_size++;
    }
    size_t getPosition() const{
      return pos;
    }
    void nextPosition(size_t next){
      size_t newPosition = pos + next;
      if(newPosition <= text_size)
        pos = newPosition;
      else {
        pos = text_size;
      }
    }

  private:
    size_t pos = 0;
    size_t text_size = 0;
  };

  Position* cursor;
  string text;
  string buffer; //for copy paste operations

public:
  Editor(){
    cursor = new Position();
  }
  void Left(){
    --(*cursor);
  }
  void Right(){
    ++(*cursor);
  }
  void Insert(char token){
    text.insert(cursor->getPosition(), new char(token));
    cursor->Insert();
  }
  void Cut(size_t tokens = 1){
   buffer = text.substr(cursor->getPosition(), tokens);
   text.erase(cursor->getPosition(), tokens);
  }
  void Copy(size_t tokens = 1){
    buffer = text.substr(cursor->getPosition(), tokens);
  }
  void Paste(){
    text.insert(cursor->getPosition(), buffer);
    cursor->nextPosition(buffer.size());
  }
  string GetText() const{
    return text;
  }
  //debug methods
//  const Position& GetCursor() const{
//    return *cursor;
//  }
//  const string& GetBuffer() const {
//    return  buffer;
//  }
};

void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}
