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
  for (int i = 0; i < 1000000; ++i) { //5000ms
    TestEditing();
    TestReverse();
    TestNoText();
    TestEmptyBuffer();
  }
  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);

  auto debugInfo = [](const Editor& editor){
    cout << "textList: {";
    for (const auto& it : editor.getTextList()) {
      cout << it << " ";
    }
    cout << "}" << endl;
    if (editor.getIterator() == editor.getTextList().end())
      cout << "iterator points to: end()" << endl;
    else {
      cout << "iterator position: {"  << *editor.getIterator() << "}" << endl;
    }
    cout << "buffer: {";
    for (const auto& it : editor.getBuffer()) {
      cout << it << " ";
    }
    cout << "}" << endl << endl;
  };


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
    cout << editor.GetText() << endl;
    debugInfo(editor);
*/


    return 0;
}
