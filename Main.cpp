#include "HtmlParser.h"
#include "HtmlNode.h"
#include <fstream>
#include <iostream>

using namespace HtmlParser;

int main()
  {
  std::vector<HtmlNode> test_html1 =
    { HtmlNode{ "h1", " c++ " }
    , HtmlNode{ "h2", " c# " }
    , HtmlNode{ "h3", " java " }
    , HtmlNode{ "h4", " python " }
    , HtmlNode{ "h5", " js " } };
  std::vector<HtmlNode> test_html2 =
    { HtmlNode("h1", "", { HtmlNode("h1.1", "", { HtmlNode("h1.1.1", "c")})
      , HtmlNode("h1.2", "c++")
      , HtmlNode("h1.3", "obj c") })

    , HtmlNode("h2", "c#" )
    , HtmlNode("h3", "", { HtmlNode("h3.1", "java")})
    , HtmlNode("h4", "python") 
    , HtmlNode("h5", "js") };

  std::fstream fs1("test_html1.txt");
  std::vector<HtmlNode> html1 = ParseHtml(fs1);
  std::cout << "Test #1: "<< (test_html1 == html1 ? "Passed" : "Failed") << std::endl;

  std::fstream fs2("test_html2.txt");
  std::vector<HtmlNode> html2 = ParseHtml(fs2);
  std::cout << "Test #2: " << (test_html2 == html2 ? "Passed" : "Failed") << std::endl;

  return 0;
  }