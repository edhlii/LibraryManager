#include "book.h"

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

void Book::getBookInfo() {
  std::cout << "Book name: " << title << std::endl;
  std::cout << "Book author: " << author << std::endl;
  std::cout << "Total number: " << totalNumber << std::endl;
  std::cout << "Available number: " << availableNumber << std::endl;
  std::cout << "---" << std::endl;
}
