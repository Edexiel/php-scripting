#ifndef PHP_SCRIPTING_PHP_MODULE_HPP
#define PHP_SCRIPTING_PHP_MODULE_HPP

#include <sapi/embed/php_embed.h>
#include <vector>
#include <string>


namespace Pachy
{
    class php_module
    {
    private:
        bool _readOnly = false;
        std::string _name;
        zend_module_entry _module_entry;
        std::vector<zend_function_entry> function_entries;

    public:

        php_module(const std::string &name);
//        php_module(const std::string &name,zend_function_entry* functionEntries);

        zend_module_entry *getModule();

        void registerfunction(const std::string &name, void (*func)(INTERNAL_FUNCTION_PARAMETERS));
    };

}


#endif //PHP_SCRIPTING_PHP_MODULE_HPP
