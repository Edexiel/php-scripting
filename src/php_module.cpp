
#include "php_scripting/php_module.hpp"
#include <string>

using namespace Pachy;


zend_module_entry *php_module::getModule()
{

    function_entries.push_back(PHP_FE_END);

    _module_entry = {
            STANDARD_MODULE_HEADER,
            _name.c_str(), /* extension name */
            function_entries.data(), /* function entries */
            NULL, /* MINIT */
            NULL, /* MSHUTDOWN */
            NULL, /* RINIT */
            NULL, /* RSHUTDOWN */
            NULL, /* MINFO */
            "0.1", /* version */
            STANDARD_MODULE_PROPERTIES
    };

    _readOnly = true;
    return &_module_entry;

}

php_module::php_module(const std::string& name)
{
    _name = name;
}

void php_module::registerfunction(const char * name, void (*func)(INTERNAL_FUNCTION_PARAMETERS))
{
    if (_readOnly)
        return;

    function_entries.push_back({name, func, NULL});


}
//
//php_module::php_module(const std::string &name, zend_function_entry)
//{
//    _name = name;
//
//}
