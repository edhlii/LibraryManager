#pragma once

#include <iostream>
#include <string>
#include <vector>

class Book {
private:
  std::string title;
  std::string author;
  std::string releaseYear;
  std::string genre;
  // std::string isbn;
  int id = 0;
  int totalNumber = 0;
  int availableNumber = 0;

public:
  Book();
  Book(const std::string &title, const std::string &author,
       const std::string &genre, const std::string &releaseYear,
       int totalNumber, int availableNumber);
  ~Book();

  void setId(int newId);
  void setTitle(const std::string &newTitle);
  void setAuthor(const std::string &newAuthor);
  void setAvailable(int newAvailable);
  void setTotal(int newTotal);
  void setReleaseYear(const std::string &newReleaseYear);
  void setGenre(const std::string &genre);

  int getId();
  std::string getTitle();
  std::string getAuthor();
  std::string getReleaseYear();
  std::string getGenre();
  int getTotalNumber();
  int getAvailableNumber();
  void getBookInfo(int index = 0);
  void editBook();
};