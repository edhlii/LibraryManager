#pragma once

#include "BookManager.h"
#include <string>

class GuestSession {
private:
  BookManager *bookManager;

public:
  GuestSession();
  GuestSession(BookManager *bookManager);

  BookManager* getBookManager();
  void setBookManager(BookManager *bookManager);
  void printMenu();
  void searchBook();
  void printBookList();
  void run();
};