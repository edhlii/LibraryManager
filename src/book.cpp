#include "Book.h"
#include <iomanip>

Book::Book() {}

Book::Book(const std::string &title, const std::string &author, int releaseYear,
           int totalNumber, int availableNumber) {
  this->title = title;
  this->author = author;
  this->releaseYear = releaseYear;
  this->totalNumber = totalNumber;
  this->availableNumber = availableNumber;
}

Book::~Book() {}

void Book::setId(int newId) { this->id = newId; }
void Book::setTitle(const std::string &newTitle) { this->title = newTitle; }
void Book::setAuthor(const std::string &newAuthor) { this->author = newAuthor; }
void Book::setAvailable(int newAvailable) {
  this->availableNumber = newAvailable;
}
void Book::setTotal(int newTotal) { this->totalNumber = newTotal; }
void Book::setReleaseYear(int newReleaseYear) {
  this->releaseYear = newReleaseYear;
}

int Book::getId() { return this->id; }
std::string Book::getTitle() { return this->title; }
std::string Book::getAuthor() { return this->author; }
int Book::getReleaseYear() { return this->releaseYear; }
int Book::getTotalNumber() { return this->totalNumber; }
int Book::getAvailableNumber() { return this->availableNumber; }

void Book::getBookInfo(int index) {
  const int indexWidth = 10;
  const int titleWidth = 30;
  const int authorWidth = 20;
  const int numberWidth = 10;
  std::cout << std::left;
  std::cout << "\033[37m" << std::setw(indexWidth) << index
            << std::setw(titleWidth)
            << (title.length() > 28 ? title.substr(0, 27) + "..." : title)
            << std::setw(authorWidth)
            << (author.length() > 23 ? author.substr(0, 22) + "..." : author)
            << "\033[36m" << std::setw(numberWidth) << totalNumber
            << std::setw(numberWidth) << availableNumber << "\033[0m"
            << std::endl
            << std::endl;
}

void Book::editBook() {
  int id;
  std::string line;
  std::cout << "[!] Enter book ID: ";
  std::cin >> id;
  std::cout << "[!] Enter book infomation: " << std::endl;
  std::cout << "Book title: ";
  std::cin.ignore();
  getline(std::cin, line);
  if (!line.empty())
    title = line;
  std::cout << "Book author: ";
  getline(std::cin, line);
  if (!line.empty())
    author = line;
  int year, total, available;
  std::cout << "Book released year: ";
  getline(std::cin, line);
  if (!line.empty())
    releaseYear = stoi(line);
  std::cout << "Book total number: ";
  getline(std::cin, line);
  if (!line.empty())
    total = stoi(line);
  std::cout << "Book available number: ";
  getline(std::cin, line);
  if (!line.empty())
    available = stoi(line);
}
