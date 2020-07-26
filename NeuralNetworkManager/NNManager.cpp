#include "NNManager.h"

#include <Json/Value.h>


namespace NNManager_NS
{
    void  foo()
    {
        Json::Value v;
        v["first_key"] = "string_value";
        v["second_key"] = 41;

        std::cout << v << std::endl;
    }
}