#include "BookManager.h"

BookManager::BookManager() {}

BookManager::~BookManager() {}

bool BookManager::loadBookList(const std::string &bookPath) {
  std::ifstream file(bookPath);
  if (!file.is_open()) {
    std::cout << "[-] Failed to open book list data!" << std::endl;
    return 0;
  }
  bookList.clear();
  std::string title, author;
  int releaseYear, total, available;
  while (getline(file, title)) {
    getline(file, author);
    file >> releaseYear >> total >> available;
    file.ignore();
    Book* currentBook = new Book(title, author, releaseYear, total, available);
    bookList.push_back(currentBook);
  }
  return 1;
}

bool BookManager::addBook(Book *book) {
  bookList.push_back(book);
  return 1;
}

bool BookManager::removeBookById(int id) {
  bookList.erase(bookList.begin() + id, bookList.begin() + id + 1);
  return 1;
}

bool BookManager::saveBookList(const std::string &bookPath) {
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
  for (char& c : a) c = tolower(c);
  for (char& c : b) c = tolower(c);
  if (a.size() > b.size()) swap(a, b);
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) return 0;
  }
  return 1;
}

bool BookManager::findBookByName(const std::string &bookName) {
  printListBanner();
  for (int i = 0; i < bookList.size(); ++i) {
    if (cmp(bookList[i]->getTitle(), bookName)) {
      // std::cout << i << ": " << std::endl;
      bookList[i]->getBookInfo(i);
    }
  }
  return 1;
}

bool BookManager::isValidId(int id) {
  if (id < 0 || id >= bookList.size()) {
    std::cout << "[!] Invalid id!" << std::endl;
    return 0;
  }
  return 1;
}

bool BookManager::setBookTitle(int id, const std::string &title) {
  if (!isValidId(id))
    return 0;
  bookList[id]->setTitle(title);
  return 1;
}
bool BookManager::setBookAuthor(int id, const std::string &author) {
  if (!isValidId(id))
    return 0;
  bookList[id]->setAuthor(author);
  return 1;
}
bool BookManager::setBookReleaseYear(int id, const int &year) {
  if (!isValidId(id))
    return 0;
  bookList[id]->setReleaseYear(year);
  return 1;
}
bool BookManager::setBookTotal(int id, const int &total) {
  if (!isValidId(id))
    return 0;
  bookList[id]->setReleaseYear(total);
  return 1;
}
bool BookManager::setBookAvailable(int id, const int &available) {
  if (!isValidId(id))
    return 0;
  bookList[id]->setReleaseYear(available);
  return 1;
}

void BookManager::printListBanner() {
  const int indexWidth = 10;
  const int titleWidth = 30;
  const int authorWidth = 20;
  const int numberWidth = 10;
  std::cout << "\033[1;34m";
  std::cout << std::string(
                   indexWidth + titleWidth + authorWidth + numberWidth * 2, '=')
            << std::endl;
  std::cout << std::left << std::setw(indexWidth) << "INDEX"
            << std::setw(titleWidth) << "BOOK TITLE" << std::setw(authorWidth)
            << "AUTHOR" << std::setw(numberWidth) << "TOTAL"
            << std::setw(numberWidth) << "AVAILABLE" << std::endl;
  std::cout << std::string(
                   indexWidth + titleWidth + authorWidth + numberWidth * 2, '=')
            << std::endl;
  std::cout << "\033[0m";
}

void BookManager::printList() {
  printListBanner();
  int index = 0;
  for (auto book : bookList) {
    book->getBookInfo(index++);
  }
}

bool BookManager::borrowBook(int id) {
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

bool BookManager::returnBook(int id) {
  if (!isValidId(id)) {
    return 0;
  }
  int available = bookList[id]->getAvailableNumber();
  int total = bookList[id]->getTotalNumber();
  bookList[id]->setAvailable(available + 1);
  if (available == total) {
    bookList[id]->setTotal(total + 1);
  }
  return 1;
}

bool BookManager::editBook(int id) {
  if (!isValidId(id))
    return 0;
  bookList[id]->getBookInfo(id);
  bookList[id]->editBook();
  return 1;
}