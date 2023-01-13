//
// Created by guillaume on 05/05/22.
//

#ifndef PHP_SCRIPTING_PHP_MODULE_HPP
#define PHP_SCRIPTING_PHP_MODULE_HPP

#include <sapi/embed/php_embed.h>
#include <utility>


namespace Pachy
{
    class php_module
    {
    private:
        std::string _name;

        zend_module_entry _module_entry;
        zend_function_entry *_function_entry;

    public:
        php_module(std::string& name,zend_function_entry * functionEntry);


        zend_module_entry *getModule();
    };

    zend_module_entry *php_module::getModule()
    {
        return &_module_entry;
    }

    php_module::php_module(std::string& name,zend_function_entry * functionEntry)
    {
        _name = name;
        _function_entry = functionEntry;
        _module_entry = {
                STANDARD_MODULE_HEADER,
                _name.c_str(), /* extension name */
                _function_entry, /* function entries */
                NULL, /* MINIT */
                NULL, /* MSHUTDOWN */
                NULL, /* RINIT */
                NULL, /* RSHUTDOWN */
                NULL, /* MINFO */
                "0.1", /* version */
                STANDARD_MODULE_PROPERTIES
        };
    }


}
#endif //PHP_SCRIPTING_PHP_MODULE_HPP
