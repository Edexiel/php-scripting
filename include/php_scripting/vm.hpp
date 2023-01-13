#ifndef PHP_SCRIPTING_LIB_HPP
#define PHP_SCRIPTING_LIB_HPP

#include <sapi/embed/php_embed.h>

#include <filesystem>
#include <string>


namespace Pachy
{



    class vm
    {

    public :
        vm();

        ~vm();

        void startup();

        void shutdown();

        void addModule(class php_module &module);

        void execute(const std::filesystem::path &script);

//        void evaluate(const std::string &script);

        static void hello();

        static PHP_FUNCTION (test)
        {
            php_printf("COUCOU");
        };
//        PHP_FUNCTION (draw_fps);
//        PHP_FUNCTION (draw_text);

//        void ExecuteScript(std::filesystem::path &script);
    };


}


#endif //PHP_SCRIPTING_LIB_HPP
