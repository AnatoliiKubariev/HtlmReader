#pragma once

#include <iosfwd>
#include <vector>

namespace HtmlParser
  {
  class HtmlNode;
  std::vector<HtmlNode> ParseHtml(std::istream& io_is);
  }