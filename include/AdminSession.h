#pragma once

#include "BookManager.h"
#include <string>

class AdminSession {
private:
  BookManager *bookManager;

public:
  AdminSession();
  AdminSession(BookManager *bookManager);

  BookManager* getBookManager();
  void setBookManager(BookManager *bookManager);

  void printMenu();
  void addBook();
  void removeBook();
  void editBook();
  void borrowBook();
  void returnBook();
  void searchBook();
  void printBookList();
  void saveBookList();
  void run();
};