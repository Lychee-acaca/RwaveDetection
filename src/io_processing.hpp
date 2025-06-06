/*
 * Copyright (c) 2025 Junwei Lin
 * All rights reserved.
 *
 * Licensed under the MIT License. You may obtain a copy of the License at
 *
 *     https://opensource.org/licenses/MIT
 */

#pragma once

#include <string>

#include "src/dataStructure.hpp"

class Signal {
 public:
  explicit Signal(int fs = 0) : signal(new DoublyLL<float>()), fs(fs) {}
  explicit Signal(const Signal &s)
      : signal(new DoublyLL<float>(*(s.signal))), fs(s.fs) {}
  DoublyLL<float> *signal;
  int fs;
};

class IO_Processing {
 public:
  static DoublyLL<int> *readAnnFromFile(const std::string);
  static Signal *readFromFile(const std::string);
  static void writeToFile(const std::string, DoublyLL<int> *);
  static void writeToFile(const std::string, Signal *);
};
