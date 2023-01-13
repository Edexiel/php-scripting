#ifndef PHP_SCRIPTING_LIB_HPP
#define PHP_SCRIPTING_LIB_HPP

//#include <sapi/embed/php_embed.h>

#include <filesystem>


namespace Pachy
{
    class vm
    {
    public :
        vm();

        ~vm();

        void addModule(class php_module &module);

        void execute(const std::filesystem::path &script);

        void evaluate(const std::string &script);

    };


}


#endif //PHP_SCRIPTING_LIB_HPP
