#include "HtmlNode.h"

namespace HtmlParser
{

HtmlNode::HtmlNode(const std::string& i_name, const std::string& i_text, const std::vector<HtmlNode>& i_childs)
  : m_name(i_name)
  , m_text(i_text)
  , m_childs(i_childs)
  {
  }
/////////////////////////////////////////////////////////////////////////////////////////////

std::string HtmlNode::GetName() const
  {
  return m_name;
  }
/////////////////////////////////////////////////////////////////////////////////////////////

std::string HtmlNode::GetText() const
  {
  return m_text;
  }
/////////////////////////////////////////////////////////////////////////////////////////////

std::vector<HtmlNode> HtmlNode::GetChilds() const
  {
  return m_childs;
  }
/////////////////////////////////////////////////////////////////////////////////////////////

bool operator==(const HtmlNode& i_lhs_node, const HtmlNode& i_rhs_node)
  {
  return (i_lhs_node.GetName() == i_rhs_node.GetName())
    && (i_lhs_node.GetText() == i_rhs_node.GetText())
    && (i_lhs_node.GetChilds() == i_rhs_node.GetChilds());
  }
/////////////////////////////////////////////////////////////////////////////////////////////
}