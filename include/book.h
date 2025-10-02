#pragma once

#include <iostream>
#include <string>
#include <vector>

class Book {
private:
  std::string name;
  std::string author;
  std::string releaseDate;
  std::string type;
  int totalNumber;
  int availableNumber;
  int releaseDay, releaseMonth, releaseYear;

public:
  Book();
  ~Book();
  void updateAll();
  void updateAuthor();
  void updateName();
  void updateReleaseDate();
  void updateTotalNumber();
  void updateAvailableNumber();

  void getBookInfo();
};