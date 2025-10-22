#pragma once

#include "book.h"
#include "common.h"
#include <iostream>
#include <string>
#include <vector>

class Manager {
private:
  std::vector<Book *> bookList;

public:
  Manager();
  ~Manager();
  void printList();
  bool editBook(int id, Book *newBook);
  bool rentBook(int id);
  bool addBook(Book *book);
  bool removeBookById(int id);
  bool isValidId(int id);
  bool loadBookList(const std::string &bookPath);
  bool saveBookList(const std::string &bookPath);
  bool findBookByName(const std::string &bookName);
  bool setBookTitle(int id, const std::string &title);
  bool setBookAuthor(int id, const std::string &author);
  bool setBookReleaseYear(int id, const int &year);
  bool setBookTotal(int id, const int &total);
  bool setBookAvailable(int id, const int &available);
};