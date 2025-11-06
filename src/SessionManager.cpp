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

void printBanner() {
  std::cout << R"(
 _     _ _                           ___  ___                                  
| |   (_) |                          |  \/  |                                  
| |    _| |__  _ __ __ _ _ __ _   _  | .  . | __ _ _ __   __ _  __ _  ___ _ __ 
| |   | | '_ \| '__/ _` | '__| | | | | |\/| |/ _` | '_ \ / _` |/ _` |/ _ \ '__|
| |___| | |_) | | | (_| | |  | |_| | | |  | | (_| | | | | (_| | (_| |  __/ |   
\_____/_|_.__/|_|  \__,_|_|   \__, | \_|  |_/\__,_|_| |_|\__,_|\__, |\___|_|   
                               __/ |                            __/ |          
                              |___/                            |___/           
)" << std::endl;
}

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