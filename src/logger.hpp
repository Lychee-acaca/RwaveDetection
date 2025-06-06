/*
 * Copyright (c) 2025 Junwei Lin
 * All rights reserved.
 *
 * Licensed under the MIT License. You may obtain a copy of the License at
 *
 *     https://opensource.org/licenses/MIT
 */

#pragma once

#include <fstream>
#include <iostream>
#include <string>

class Logger {
 public:
  enum LogLevel { LOW, MEDIUM, HIGH };
  static std::string getLevelString(LogLevel);

  static Logger *getInstance(void) {
    static Logger instance;
    return &instance;
  }
  void log(std::string, LogLevel = LogLevel::LOW);
  void setLogLevel(LogLevel ll) { logLevel = ll; }
  void setLogPath(std::string);

 private:
  Logger(void) : logLevel(LogLevel::MEDIUM) {
    logfile = nullptr;
    setLogPath("log.txt");
  }

  ~Logger(void) {
    logfile->close();
    delete logfile;
  }

  LogLevel logLevel;
  std::ofstream *logfile;
};
