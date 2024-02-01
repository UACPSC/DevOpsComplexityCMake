/*
    srcMLXPathCount.cpp

    Implementation file for srcMLXPathCount()
*/

#include "srcMLXPathCount.hpp"
#include <memory>
#include <string_view>

#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

/** Count of the result of applying the xpath to the srcML file
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
int srcMLXPathCount(std::string_view srcMLfile, std::string_view xpath) {

    xmlInitParser();

    // open the srcML file with no encoding change and no options
    xmlDoc* srcMLdoc(xmlReadFile(srcMLfile.data(), nullptr, 0));
    if (!srcMLdoc) {
        return -1;
    }

    // create xpath evaluation context
    xmlXPathContext* xpathCtx(xmlXPathNewContext(srcMLdoc));
    if (!xpathCtx) {
        xmlFreeDoc(srcMLdoc);
        return -1;
    }

    // register srcML namespaces
    if (xmlXPathRegisterNs(xpathCtx, BAD_CAST "src", BAD_CAST "http://www.srcML.org/srcML/src")) {
        xmlFreeDoc(srcMLdoc);
        xmlXPathFreeContext(xpathCtx);
        return -1;
    }
    if (xmlXPathRegisterNs(xpathCtx, BAD_CAST "cpp", BAD_CAST "http://www.srcML.org/srcML/cpp")) {
        xmlFreeDoc(srcMLdoc);
        xmlXPathFreeContext(xpathCtx);
        return -1;
    }

    // evaluate xpath expression
    xmlXPathObject* xpathResults(xmlXPathEvalExpression(BAD_CAST xpath.data(), xpathCtx));
    if (!xpathResults) {
        xmlFreeDoc(srcMLdoc);
        xmlXPathFreeContext(xpathCtx);
        return -1;
    }

    // extract the count
    int count = xmlXPathCastToNumber(xpathResults);
    if (count < 0) {
        xmlFreeDoc(srcMLdoc);
        xmlXPathFreeContext(xpathCtx);
        xmlXPathFreeObject(xpathResults);
        return -1;
    }

    xmlFreeDoc(srcMLdoc);
    xmlXPathFreeContext(xpathCtx);
    xmlXPathFreeObject(xpathResults);

    return count;
} 
