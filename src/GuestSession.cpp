#include "GuestSession.h"

GuestSession::GuestSession() {
  this->bookManager = new BookManager();
  this->bookManager->loadBookList(bookPath);
}

GuestSession::GuestSession(BookManager *bookManager) {
  this->bookManager = bookManager;
}

BookManager *GuestSession::getBookManager() { return bookManager; }

void GuestSession::setBookManager(BookManager *bookManager) {
  this->bookManager = bookManager;
}

void GuestSession::printBookList() { bookManager->printList(); }

void GuestSession::searchBook() {
  std::string query;
  std::cin.ignore();
  getline(std::cin, query);
  bookManager->findBookByName(query);
}

void GuestSession::printMenu() {
  std::cout << "[1] Search a book" << std::endl;
  std::cout << "[2] Print book list." << std::endl;
  std::cout << "[3] Exit." << std::endl << std::endl;
  std::cout << "[?] Enter your choice: ";
}

void GuestSession::run() {
  bool isRunning = true;
  while (isRunning) {
    printMenu();
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1:
      searchBook();
      break;
    case 2:
      printBookList();
      break;
    case 3:
      isRunning = false;
      break;
    }
  }
}