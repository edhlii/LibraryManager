#include "book.h"
#include <iostream>

int main() {
  Book *test = new Book();
  test->updateAll();
  test->getBookInfo();
  return 0;
}