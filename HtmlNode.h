#pragma once

#include <string>
#include <vector>

namespace HtmlParser
{
/////////////////////////////////////////////////////////////////////////////////////////////
// HtmlNode
/////////////////////////////////////////////////////////////////////////////////////////////
class HtmlNode
  {
  public:
    friend bool operator==(const HtmlNode& i_lhs_node, const HtmlNode& i_rhs_node);

    HtmlNode(const std::string& i_name, const std::string& i_text, const std::vector<HtmlNode>& i_childs = std::vector<HtmlNode>());

    std::string GetName() const;
    std::string GetText() const;
    std::vector<HtmlNode> GetChilds() const;

  private:
    std::string m_name;
    std::string m_text;

    std::vector<HtmlNode> m_childs;
  };

bool operator==(const HtmlNode& i_lhs_node, const HtmlNode& i_rhs_node);
}
