//
// MIT License
//
// Copyright 2018-2019
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#include <boost/filesystem.hpp>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "cpu.hh"
#include "main_screen.hh"

namespace fs = boost::filesystem;
namespace po = boost::program_options;
namespace ip = boost::interprocess;
namespace jo = jones;

int main(int argc, char *argv[]) {
  std::string file_argument;
  bool has_file_argument;
  try {
    po::options_description desc{"Options"};
    desc.add_options()
      ("help,h", "Help screen")
      ("file,f", po::value<std::string>(&file_argument), "path to file");

    po::variables_map vm;
    const auto command_line_args = parse_command_line(argc, argv, desc);
    po::store(command_line_args, vm);
    po::notify(vm);

    has_file_argument = vm.count("file");
  } catch (const po::error &ex) {
    std::cerr << ex.what() << '\n';
    return -1;
  }

  const fs::path file_path(file_argument);
  if (has_file_argument) {
    if (!fs::exists(file_path)) {
      std::cout << "file does not exist; please check path" << std::endl;
      return -2;
    }
    if (fs::is_directory(file_path)) {
      std::cout << "file is a directory; please check path" << std::endl;
      return -3;
    }
  }

  jo::main_screen screen;
  screen.initialize();
  screen.show();
  screen.release();

  return 0;
}
