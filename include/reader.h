#pragma once

#include <string>
#include <vector>

#include "book.h"

class Reader {
 private:
  std::string id;
  std::string name;
  int year;
  std::vector<Book*> borrowedBook;

 public:
  Reader();
  Reader(std::string id, std::string name, int year, std::string borrowDate,
         std::string dueDate, std::vector<Book*> borrowedBook);

  std::string getId();
  std::string getName();
  int getYear();
  std::vector<Book*> Reader::getBorrowedBook();

  void setId(std::string id);
  void setName(std::string name);
  void setYear(int year);
  void setBorrowedBook(std::vector<Book*> borrowedBook);
};