#include "BookManager.h"
#include "SessionManager.h"
#include "book.h"
#include "common.h"
#include <iostream>

int main() {
  SessionManager *sessionManager = new SessionManager();
  sessionManager->run();

  std::cout << "[+] Program end!" << std::endl;
  // std::cout << "[+] Press any key to exit!" << std::endl;
  // getchar();
  return 0;
}