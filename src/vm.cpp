#include <sapi/embed/php_embed.h>

#include "php_scripting/vm.hpp"
#include "php_scripting/php_module.hpp"


using namespace Pachy;


vm::vm()
{
    int argc = 1;
    char *argv[2] = {"TestPachy", NULL};
    php_embed_init(argc, argv);

}

vm::~vm()
{
    php_embed_shutdown();
}

void vm::addModule(php_module &module)
{
    zend_startup_module(module.getModule());
}


void vm::execute(const std::filesystem::path &script)
{
    zend_file_handle file_handle;
    zend_stream_init_filename(&file_handle, script.c_str());

    if (php_execute_script(&file_handle) == FAILURE) {
        php_printf("Failed to execute PHP script.\n");
    }

}


void vm::evaluate(const std::string &script)
{
    zend_first_try
            {
                char *include_script;
                spprintf(&include_script, 0, "include ‘%s’;", script.c_str());
                zend_eval_string(include_script, NULL, script.c_str());
                efree(include_script);
            }
    zend_end_try();
}