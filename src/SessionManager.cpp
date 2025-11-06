#include "SessionManager.h"

void SessionManager::logIn() {
  std::cout << "Enter username: ";
  std::cin >> username;
  std::cout << "Enter password: ";
  std::cin >> password;
  if (username == "admin" && password == "admin") {
    type = "admin";
  } else if (username == "guest" && password == "guest") {
    type = "guest";
  }
}

void printBanner() {}

void SessionManager::run() {
  printBanner();
  logIn();
  if (type == "admin") {
    AdminSession *adminSession = new AdminSession();
    adminSession->run();
  } else if (type == "guest") {
    GuestSession *guestSession = new GuestSession();
    guestSession->run();
  }
}