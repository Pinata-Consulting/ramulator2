#ifndef     RAMULATOR_BASE_EXCEPTION_H
#define     RAMULATOR_BASE_EXCEPTION_H

#include <stdexcept>
#include <string>
#include <string_view>

#include <spdlog/spdlog.h>

namespace Ramulator {

struct InitializationError : public std::logic_error {
  template <typename... Args>
  InitializationError(std::format_string<Args...> format_str, Args&&... args) : std::logic_error(std::format(format_str, std::forward<Args>(args)...)){};
};

struct ConfigurationError : public std::runtime_error {
  template <typename... Args>
  ConfigurationError(std::format_string<Args...> format_str, Args&&... args) : std::runtime_error(std::format(format_str, std::forward<Args>(args)...)){};
};

}        // namespace Ramulator


#endif   // RAMULATOR_BASE_EXCEPTION_H