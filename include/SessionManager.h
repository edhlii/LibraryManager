#pragma once

#include "AdminSession.h"
#include "GuestSession.h"
#include <iostream>
#include <string>

class SessionManager {
private:
  std::string username, password;
  std::string type;

public:
  void logIn();
  void run();
};