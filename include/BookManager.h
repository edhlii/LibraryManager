#pragma once

#include "book.h"
#include "common.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class BookManager {
private:
  std::vector<Book *> bookList;

public:
  BookManager();
  ~BookManager();
  void printListBanner();
  void printList();
  bool editBook(int id);
  bool borrowBook(int id);
  bool returnBook(int id);
  bool addBook(Book *book);
  bool removeBookById(int id);
  bool isValidId(int id);
  bool loadBookList(const std::string &bookPath);
  bool saveBookList(const std::string &bookPath);
  bool searchBook(const std::string &bookName);
  bool setBookTitle(int id, const std::string &title);
  bool setBookAuthor(int id, const std::string &author);
  bool setBookReleaseYear(int id, const std::string &year);
  bool setBookTotal(int id, const int &total);
  bool setBookAvailable(int id, const int &available);
};