#pragma once
#include <iostream>
using namespace std;

class Editor {
private:
  class Position{
  public:
    Position() = default;
    Position(size_t string_size): text_size(string_size){

    }
    Position& operator++(){
      if(text_size > 0 && pos < text_size)
        this->pos++;
      return *this;
    }
    Position& operator--(){
      if(text_size > 0 && pos > 0)
        this->pos--;
      return *this;
    }

  private:
    size_t pos = 0;
    size_t text_size = 0;
  };


  Position cursor; //string_view or iterator or pointer
  string text;
  //??? buffer; //for copy paste operations
public:
  Editor(){
    //empty text;
    //empty buffer;
  }
  void Left(){
    --cursor;
  }
  void Right(){
    ++cursor;
  }
  void Insert(char token){
    //text.push_back(token);
  }
  //
  void Cut(size_t tokens = 1){

  }
  void Copy(size_t tokens = 1){

  }
  void Paste(){

  }
  string GetText() const{
    return text;
  }
};

void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}
