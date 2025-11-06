#include "AdminSession.h"

AdminSession::AdminSession() {
  this->bookManager = new BookManager();
  this->bookManager->loadBookList(bookPath);
}

AdminSession::AdminSession(BookManager *bookManager) {
  this->bookManager = bookManager;
}

void AdminSession::printMenu() {
  std::cout << "[1] Add a book to database." << std::endl;
  std::cout << "[2] Remove a book from database by ID." << std::endl;
  std::cout << "[3] Edit book information by ID." << std::endl;
  std::cout << "[4] Find a book information by title." << std::endl;
  std::cout << "[5] Borrow a book." << std::endl;
  std::cout << "[6] Return a book." << std::endl;
  std::cout << "[7] Print book list." << std::endl;
  std::cout << "[8] Save book list to database." << std::endl;
  std::cout << "[9] Exit." << std::endl << std::endl;
  std::cout << "[?] Enter your choice: ";
}

BookManager *AdminSession::getBookManager() { return bookManager; }

void AdminSession::setBookManager(BookManager *bookManager) {
  this->bookManager = bookManager;
}

void AdminSession::addBook() {
  Book *book = new Book();
  std::string line;
  std::cout << "[!] Enter book infomation. " << std::endl;
  std::cout << "Book title: ";
  std::cin.ignore();
  getline(std::cin, line);
  book->setTitle(line);

  std::cout << "Book author: ";
  getline(std::cin, line);
  book->setAuthor(line);

  std::cout << "Book genre: ";
  getline(std::cin, line);
  book->setGenre(line);

  int year, total, available;
  std::cout << "Book released year: ";
  getline(std::cin, line);
  book->setReleaseYear(line);

  std::cout << "Book total number: ";
  std::cin >> total;
  book->setTotal(total);

  std::cout << "Book available number: ";
  std::cin >> available;
  book->setAvailable(available);

  bookManager->addBook(book);
  std::cout << "[+] Added book to book list." << std::endl;
  std::cout << std::endl;
}

void AdminSession::removeBook() {
  int index;
  std::cout << "[!] Enter index to remove: ";
  std::cin >> index;
  bookManager->removeBookById(index);
}

void AdminSession::editBook() {
  int index;
  std::cout << "Enter index to edit: ";
  std::cin >> index;
  bookManager->editBook(index);
}

void AdminSession::borrowBook() {
  int index;
  std::cout << "Enter book index to borrow: ";
  std::cin >> index;
  bookManager->borrowBook(index);
}

void AdminSession::returnBook() {
  int index;
  std::cout << "Enter book index to return: ";
  std::cin >> index;
  bookManager->returnBook(index);
}

void AdminSession::searchBook() {
  std::cout << "Enter keyword: ";
  std::string query;
  std::cin.ignore();
  getline(std::cin, query);
  bookManager->searchBook(query);
}

void AdminSession::printBookList() { bookManager->printList(); }

void AdminSession::saveBookList() { bookManager->saveBookList(bookPath); }

void AdminSession::run() {
  bool isRunning = true;
  while (isRunning) {
    printMenu();
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1:
      addBook();
      saveBookList();
      break;
    case 2:
      removeBook();
      break;
    case 3:
      editBook();
      break;
    case 4:
      searchBook();
      break;
    case 5:
      borrowBook();
      break;
    case 6:
      returnBook();
      break;
    case 7:
      printBookList();
      break;
    case 8:
      saveBookList();
      break;
    case 9:
      saveBookList();
      isRunning = false;
      break;
    }
  }
}