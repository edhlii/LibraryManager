#include "book.h"
#include "common.h"
#include "manager.h"
#include <iostream>

void printMenu() {
  std::cout << "[1] Add a book to database." << std::endl;
  std::cout << "[2] Remove a book from database by ID." << std::endl;
  std::cout << "[3] Edit book information by ID." << std::endl;
  std::cout << "[4] Find a book information by title." << std::endl;
  std::cout << "[5] Lend a book." << std::endl;
  std::cout << "[6] Return a book." << std::endl;
  std::cout << "[7] Print book list." << std::endl;
  std::cout << "[8] Save book list to database." << std::endl;
  std::cout << "[9] Exit." << std::endl;
}

void editBookById(Manager *manager) {
  int id;
  Book *book = new Book();
  std::string line;
  std::cout << "[!] Enter book ID: ";
  std::cin >> id;
  std::cout << "[!] Enter book infomation: " << std::endl;
  std::cout << "Book title: ";
  std::cin.ignore();
  getline(std::cin, line);
  if (!line.empty())
    book->setTitle(line);
  std::cout << "Book author: ";
  getline(std::cin, line);
  if (!line.empty())
    book->setAuthor(line);
  int year, total, available;
  std::cout << "Book released year: ";
  getline(std::cin, line);
  if (!line.empty())
    book->setReleaseYear(stoi(line));
  std::cout << "Book total number: ";
  getline(std::cin, line);
  if (!line.empty())
    book->setTotal(stoi(line));
  std::cout << "Book available number: ";
  getline(std::cin, line);
  if (!line.empty())
    book->setAvailable(stoi(line));
  if (!manager->editBook(id, book)) {
    std::cout << "[-] Failed to edit book information." << std::endl;
  } else {
    std::cout << "[+] Changed book information at " << id << "." << std::endl;
  }
  std::cout << std::endl;
}

void lendBook(Manager *manager) {
  int id;
  std::cout << "[!] Enter book ID to lend: ";
  std::cin >> id;
  if (!manager->lendBook(id)) {
    std::cout << "[-] Failed to lend book at " << id << "." << std::endl;
  }
}

void addBook(Manager *manager) {
  Book *book = new Book();
  std::string line;
  std::cout << "[!] Enter book infomation: " << std::endl;
  std::cout << "Book title: ";
  std::cin.ignore();
  getline(std::cin, line);
  book->setTitle(line);
  std::cout << "Book author: ";
  getline(std::cin, line);
  book->setAuthor(line);
  int year, total, available;
  std::cout << "Book released year: ";
  std::cin >> year;
  book->setReleaseYear(year);
  std::cout << "Book total number: ";
  std::cin >> total;
  book->setTotal(total);
  std::cout << "Book available number: ";
  std::cin >> available;
  book->setAvailable(available);
  manager->addBook(book);
  std::cout << "[+] Added book to book list." << std::endl;
  std::cout << std::endl;
}

void removeBookById(Manager *manager) {
  int id;
  std::cout << "[!] Enter book id to remove: ";
  std::cin >> id;
  if (manager->removeBookById(id)) {
    std::cout << "[+] Book has been removed from booklist." << std::endl;
  } else {
    std::cout << "[-] Failed to remove book from booklist." << std::endl;
  }
  std::cout << std::endl;
}

void printBookList(Manager *manager) {
  std::cout << std::endl;
  std::cout << "[+] Book list: " << std::endl;
  manager->printList();
  std::cout << std::endl;
}

void saveBookList(Manager *manager) { manager->saveBookList(bookPath); }

void findBook(Manager *manager) {
  std::string title;
  std::cout << "Enter book title: ";
  std::cin.ignore();
  getline(std::cin, title);
  std::cout << "[+] Search result: " << std::endl;
  manager->findBookByName(title);
  std::cout << std::endl;
}

int main() {
  Manager *manager = new Manager();
  manager->loadBookList("book.txt");
  bool isRunning = 1;
  std::cout << "[+] Program started!" << std::endl;
  std::cout << "[+] Welcome to Library Manager v1.0!" << std::endl;
  std::cout << "---" << std::endl;
  while (isRunning) {
    int choice;
    std::cout << std::endl;
    printMenu();
    std::cout << std::endl;
    std::cout << "[!] Enter your choice: " << std::endl;
    std::cin >> choice;
    std::cout << std::endl;
    switch (choice) {
    case 1:
      addBook(manager);
      break;
    case 2:
      removeBookById(manager);
      break;
    case 3:
      editBookById(manager);
      break;
    case 4:
      findBook(manager);
      break;
    case 5:
    case 6:
    case 7:
      printBookList(manager);
      break;
    case 8:
      saveBookList(manager);
      break;
    case 9: {
      isRunning = 0;
      int save = 0;
      std::cout << "[!] Do you want to save book list to database? "
                << std::endl;
      std::cout << "[1] Yes.  [2] No. ";
      std::cout << "Enter your choice: ";
      std::cin >> save;
      // std::cout << "[?] You choose: " << save << std::endl;
      if (save == 1)
        saveBookList(manager);
      break;
    }

    default:
      std::cout << "[-] Invalid choice, try again!" << std::endl;
      break;
    }
  }

  std::cout << "[+] Program end!" << std::endl;
  std::cout << "[+] Press any key to exit!" << std::endl;
  getchar();
  getchar();
  return 0;
}