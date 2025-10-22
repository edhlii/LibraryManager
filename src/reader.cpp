#include "reader.h"

Reader::Reader() {}

Reader::Reader(std::string id, std::string name, int year,
               std::string borrowDate, std::string dueDate,
               std::vector<Book*> borrowedBook) {
  this->id = id;
  this->name = name;
  this->year = year;
  this->borrowDate = borrowDate;
  this->dueDate = dueDate;
  this->borrowedBook = borrowedBook;
}

std::string Reader::getId() { return this->id; }
std::string Reader::getName() { return this->name; }
int Reader::getYear() { return this->year; }
std::string Reader::getBorrowDate() { return this->borrowDate; }
std::string Reader::getDueDate() { return this->dueDate; }
std::vector<Book*> Reader::getBorrowedBook(){ return this->borrowedBook;}

void Reader::setId(std::string id) { this->id = id; }
void Reader::setName(std::string name) { this->name = name; }
void Reader::setYear(int year) { this->year = year; }
void Reader::setBorrowDate(std::string borrowDate) {
  this->borrowDate = borrowDate;
}
void Reader::setDueDate(std::string dueDate) { this->dueDate = dueDate; }
