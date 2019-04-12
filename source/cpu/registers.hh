//
// MIT License
//
// Copyright 2019
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
#ifndef JONES_CPU_REGISTERS_HH
#define JONES_CPU_REGISTERS_HH

#include <array>
#include <boost/static_assert.hpp>
#include <cstdint>

namespace jones {

enum class register_type {

  // program counter (16 bit)
  PC = 0,

  // accumulator (8 bit)
  AC,

  // X register (8 bit)
  X,

  // Y register (8 bit)
  Y,

  // status register (8 bit)
  SR,

  // stack pointer (8 bit)
  SP,

  // number of registers
  COUNT
};

using r8_t = uint8_t;

using r16_t = uint16_t;

template <register_type R>
struct register_traits {

  typedef r8_t type;

  static constexpr uint8_t length = sizeof(type);
};

template <>
struct register_traits<register_type::PC> {

  typedef r16_t type;

  static constexpr uint8_t length = sizeof(type);
};

template <register_type R>
using reg_t = typename register_traits<R>::type;

class registers {
public:
  template <register_type R>
  reg_t<R> get(register_type type) {
    switch (type) {
    case register_type::PC:
      return static_cast<reg_t<R>>(registers_.at(0));
    case register_type::AC:
      return static_cast<reg_t<R>>(registers_.at(1));
    case register_type::X:
      return static_cast<reg_t<R>>(registers_.at(2));
    case register_type::Y:
      return static_cast<reg_t<R>>(registers_.at(3));
    case register_type::SR:
      return static_cast<reg_t<R>>(registers_.at(4));
    case register_type::SP:
      return static_cast<reg_t<R>>(registers_.at(5));
    default:
      BOOST_STATIC_ASSERT("unexpected register type");
      return 0;
    }
  }

  void set(register_type type, r16_t value) {
    switch (type) {
    case register_type::PC:
      registers_.at(0) = value;
      break;
    case register_type::AC:
      registers_.at(1) = value;
      break;
    case register_type::X:
      registers_.at(2) = value;
      break;
    case register_type::Y:
      registers_.at(3) = value;
      break;
    case register_type::SR:
      registers_.at(4) = value;
      break;
    case register_type::SP:
      registers_.at(5) = value;
      break;
    default:
      BOOST_STATIC_ASSERT("unexpected register type");
      break;
    }
  }

private:
  static constexpr size_t register_count = static_cast<size_t>(register_type::COUNT);

  std::array<r16_t, register_count> registers_;
};

} // namespace jones

#endif // JONES_CPU_REGISTERS_HH
