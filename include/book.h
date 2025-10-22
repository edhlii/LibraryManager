#pragma once

#include <iostream>
#include <string>
#include <vector>

class Book {
private:
  std::string title;
  std::string author;
  int id = 0;
  int totalNumber = 0;
  int availableNumber = 0;
  int releaseYear;

public:
  Book();
  Book(const std::string &title, const std::string &author, int releaseYear,
       int totalNumber, int availableNumber);
  ~Book();

  void setId(int newId);
  void setTitle(const std::string &newTitle);
  void setAuthor(const std::string &newAuthor);
  void setAvailable(int newAvailable);
  void setTotal(int newTotal);
  void setReleaseYear(int newReleaseYear);

  int getId();
  std::string getTitle();
  std::string getAuthor();
  int getReleaseYear();
  int getTotalNumber();
  int getAvailableNumber();
  void getBookInfo();
};