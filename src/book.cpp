#include "book.h"

Book::Book() {
  name = "test";
  author = "hieu";
  releaseDate = "today";
}

Book::~Book() {}

void Book::getBookInfo() {
  std::cout << "Book name: " << name << std::endl;
  std::cout << "Book author: " << author << std::endl;
  std::cout << "Release date: " << releaseDate << std::endl;
  std::cout << "Available number: " << availableNumber << std::endl;
}

void Book::updateAll() {
  updateName();
  updateAuthor();
}

void Book::updateAuthor() {
  std::cout << "Enter the updated author: ";
  getline(std::cin, author);
  std::cout << "Author updated!" << std::endl;
}

void Book::updateName() {
  std::cout << "Enter the updated book name: ";
  getline(std::cin, name);
  std::cout << "Book name updated!" << std::endl;
}
