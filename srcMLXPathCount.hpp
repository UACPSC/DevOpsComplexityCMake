/*
    srcMLXPathCount.hpp

    Include file for function srcMLXPathCount()
*/

#ifndef INCLUDED_SRCMLXPATHCOUNT_HPP
#define INCLUDED_SRCMLXPATHCOUNT_HPP

#include <string_view>

/**
 * Count of the result of applying the xpath to the srcML file
 * 
 * XPath expression must result in a numeric, integer result.
 * In general, this means it needs to use the XPath count() function
 *
 * @param srcMLfile filename of srcML file
 * @param xpath XPath expression as string
 * @retval Number of conditions in the srcMLfile
 * @retval -1 Error in XPath
 * @retval -2 Invalid argument
 */
int srcMLXPathCount(std::string_view srcMLfile, std::string_view xpath);

#endif
