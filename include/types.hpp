#pragma once

#include <string>
#include <vector>
#include <map>
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <utility>

using String = std::string;
using StringView = std::string_view;
template <typename T>
using Vec = std::vector<T>;
template <typename M, typename N>
using Map = std::map<M, N>;
template <typename M, typename N>
using UMap = std::unordered_map<M, N>;
template <typename M, typename N>
using Pair = std::pair<M, N>;
template <typename S, int N>
using Array = std::array<S, N>;
using SizeT = size_t;