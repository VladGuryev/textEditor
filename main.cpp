#include "test_runner.h"
#include "profile.h"
#include "tests.cpp"
#include <experimental/string_view>
using namespace std;
using namespace std::experimental;

int main()
{
  TestRunner tr;
  LOG_DURATION("Total tests duration");
  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);

//  string* t = new string("AAAAAAAAAaaaa");
//  string_view sv(*t);
//  delete t;
//  for (int i = 0; i < 10000; i++) {
//    string* p = new string("123456789");
//    p->at(1);
//  }
//  cout << sv << endl;


//  auto debugInfo = [](const Editor& editor){
//    cout << "text = {" <<editor.GetText() << "}" << endl;
//    cout << "position = " << editor.GetCursor().getPosition() << endl;
//    cout << "buffer = {"  << editor.GetBuffer() << "}" << endl;
//  };
  //--------------------------

//  Editor editor;
//  debugInfo(editor);
//  TypeText(editor, "a");
//  debugInfo(editor);
//  TypeText(editor, "a");
//  debugInfo(editor);

//  Editor editor2;
//  TypeText(editor2, "ab");
//  debugInfo(editor2);
//  editor2.Insert('c');
//  debugInfo(editor2);

//  Editor editor3;
//  debugInfo(editor3);
//  TypeText(editor3, "bc");
//  debugInfo(editor3);
//  editor3.Left();
//  editor3.Left();
//  debugInfo(editor3);
//  editor3.Insert('a');
//  debugInfo(editor3);

//  Editor editor4;
//  debugInfo(editor4);
//  TypeText(editor4, "world");
//  debugInfo(editor4);
//  for (int i = 0; i < 5; ++i) {
//    editor4.Left();
//  }
//  debugInfo(editor4);
//  TypeText(editor4, "hello_");
//  debugInfo(editor4);

//  Editor editor5;
//  debugInfo(editor5);
//  TypeText(editor5, "hello_");
//  debugInfo(editor5);
//  TypeText(editor5, "world");
//  debugInfo(editor5);

//  Editor editor6;
//  TypeText(editor6, "12378");
//  debugInfo(editor6);
//  editor6.Left();
//  editor6.Left();
//  debugInfo(editor6);
//  TypeText(editor6, "456");
//  debugInfo(editor6);

/*
  Editor editor;
    const string text = "hello, world";
    for (char c : text) {
      editor.Insert(c);
    }
    // Текущее состояние редактора: `hello, world|`
    debugInfo(editor);
    for (size_t i = 0; i < text.size(); ++i) {
      editor.Left();
    }
     debugInfo(editor);
    // Текущее состояние редактора: `|hello, world`


     editor.Cut(7);
//    // Текущее состояние редактора: `|world`
      debugInfo(editor);
//    // в буфере обмена находится текст `hello, `
    for (size_t i = 0; i < 5; ++i) {
      editor.Right();
    }
    debugInfo(editor);
//    // Текущее состояние редактора: `world|`
    editor.Insert(',');
    editor.Insert(' ');
    debugInfo(editor);
//    // Текущее состояние редактора: `world, |`
    editor.Paste();
    debugInfo(editor);
//    // Текущее состояние редактора: `world, hello, |`
    editor.Left();
    editor.Left();
    debugInfo(editor);
//    //Текущее состояние редактора: `world, hello|, `
    editor.Cut(3); // Будут вырезаны 2 символа
    debugInfo(editor);
//    // Текущее состояние редактора: `world, hello|`
    cout << editor.GetText();
*/

//  Editor editor7;
//  TypeText(editor7, "abcd");
//  debugInfo(editor7);
//  for (int i = 0; i < 100; ++i) {
//    editor7.Left();
//  }
//  debugInfo(editor7);
//  for (int i = 0; i < 100; ++i) {
//    editor7.Right();
//  }
//  debugInfo(editor7);

//  Editor editor8;
//  TypeText(editor8, "abcdef");
//  debugInfo(editor8);
//  editor8.Left(); editor8.Left(); editor8.Left(); editor8.Left();
//  debugInfo(editor8);
//  editor8.Cut(3);
//  debugInfo(editor8);

  return 0;
}
