#include "manager.h"
#include <fstream>

Manager::Manager() {}

Manager::~Manager() {}

bool Manager::loadBookList(const std::string &bookPath) {
  std::ifstream file(bookPath);
  if (!file.is_open()) {
    std::cout << "[!] Failed to open book list data!" << std::endl;
    return 0;
  }
  bookList.clear();
  std::string title, author;
  int releaseYear, total, available;
  while (getline(file, title)) {
    getline(file, author);
    file >> releaseYear >> total >> available;
    file.ignore();
    Book *currentBook = new Book(title, author, releaseYear, total, available);
    bookList.push_back(currentBook);
  }
  return 1;
}

bool Manager::addBook(Book *book) {
  bookList.push_back(book);
  return 1;
}

bool Manager::removeBookById(int id) {
  bookList.erase(bookList.begin() + id, bookList.begin() + id + 1);
  return 1;
}

bool Manager::saveBookList(const std::string &bookPath) {
  std::ofstream file(bookPath);
  for (int i = 0; i < bookList.size(); ++i) {
    file << bookList[i]->getTitle() << std::endl;
    file << bookList[i]->getAuthor() << std::endl;
    file << bookList[i]->getReleaseYear() << std::endl;
    file << bookList[i]->getTotalNumber() << std::endl;
    file << bookList[i]->getAvailableNumber() << std::endl;
  }
  return 1;
}

bool cmp(std::string a, std::string b) {
  for (char &c : a)
    c = tolower(c);
  for (char &c : b)
    c = tolower(c);
  if (a.size() > b.size())
    swap(a, b);
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i])
      return 0;
  }
  return 1;
}

bool Manager::findBookByName(const std::string &bookName) {
  for (int i = 0; i < bookList.size(); ++i) {
    if (cmp(bookList[i]->getTitle(), bookName)) {
      std::cout << i << ": " << std::endl;
      bookList[i]->getBookInfo();
    }
  }
  return 1;
}

bool Manager::isValidId(int id) {
  if (id < 0 || id >= bookList.size()) {
    std::cout << "[!] Invalid id!" << std::endl;
    return 0;
  }
  return 1;
}

bool Manager::setBookTitle(int id, const std::string &title) {
  if (!isValidId(id))
    return 0;
  bookList[id]->setTitle(title);
  return 1;
}
bool Manager::setBookAuthor(int id, const std::string &author) {
  if (!isValidId(id))
    return 0;
  bookList[id]->setAuthor(author);
  return 1;
}
bool Manager::setBookReleaseYear(int id, const int &year) {
  if (!isValidId(id))
    return 0;
  bookList[id]->setReleaseYear(year);
  return 1;
}
bool Manager::setBookTotal(int id, const int &total) {
  if (!isValidId(id))
    return 0;
  bookList[id]->setReleaseYear(total);
  return 1;
}
bool Manager::setBookAvailable(int id, const int &available) {
  if (!isValidId(id))
    return 0;
  bookList[id]->setReleaseYear(available);
  return 1;
}

void Manager::printList() {
  for (auto book : bookList) {
    book->getBookInfo();
  }
}

bool Manager::lendBook(int id) {
  if (!isValidId(id)) {
    return 0;
  }
  int available = bookList[id]->getAvailableNumber();
  if (available <= 0) {
    return 0;
  }
  bookList[id]->setAvailable(available - 1);
  return 1;
}

bool Manager::editBook(int id, Book *book) {
  if (!isValidId(id))
    return 0;
  bookList[id] = book;
  return 1;
}