#include "HtmlParser.h"
#include "HtmlNode.h"
#include <istream>
#include <string>
#include <stdexcept>

namespace HtmlParser
{
HtmlNode GetNode(std::istream& io_is);
bool FindNext(const char i_symbol, std::istream& io_is);
std::string GetString(const char i_symbol, std::istream& io_is);

std::vector<HtmlNode> ParseHtml(std::istream& io_is)
  {
  if(io_is.eof())
    {
    throw std::logic_error("eof");
    }

  std::vector<HtmlNode> parsed_html;
  while(io_is)
    {
    if(FindNext('<', io_is))
      {
      parsed_html.push_back(GetNode(io_is));
      }
    }
  return parsed_html;
  }
////////////////////////////////////////////////////////////////////////////////////////////////

HtmlNode GetNode(std::istream& io_is)
  {
  //get name
  std::string node_name = GetString('>', io_is);
  if(!FindNext('>', io_is))
    {
    throw std::logic_error("no >");
    }

  auto pos = io_is.tellg();
  //get childs
  std::vector<HtmlNode> node_childs;
  while(FindNext('<', io_is) && io_is.peek() != '/')
    {
    node_childs.push_back(GetNode(io_is));
    pos = io_is.tellg();
    }

  io_is.seekg(pos);
  //get text
  std::string node_text;
  if(node_childs.empty())
    {
    //get text
    node_text = GetString('<', io_is);
    }

  if(!FindNext('<', io_is))
    {
    throw std::logic_error("no <");
    }
  if(!FindNext('/', io_is))
    {
    throw std::logic_error("no /");
    }

  //get closed name
  std::string node_close_name = GetString('>', io_is);
  if(!FindNext('>', io_is))
    {
    throw std::logic_error("no >");
    }
  if(node_close_name != node_name)
    {
    throw std::logic_error("invalid close name");
    }

  HtmlNode node(node_name, node_text, node_childs);
  return node;
  }
////////////////////////////////////////////////////////////////////////////////////////////////

bool FindNext(const char i_symbol, std::istream& io_is)
  {
  while(io_is.peek() != i_symbol && io_is)
    {
    io_is.get();
    }
  if(io_is.eof())
    {
    return false;
    }
  io_is.seekg(1, std::istream::cur);
  return true;
  }
////////////////////////////////////////////////////////////////////////////////////////////////

std::string GetString(const char i_symbol, std::istream& io_is)
  {
  std::string str;
  while(io_is.peek() != i_symbol && io_is)
    {
    str += io_is.get();
    }
  return str;
  }
////////////////////////////////////////////////////////////////////////////////////////////////

}