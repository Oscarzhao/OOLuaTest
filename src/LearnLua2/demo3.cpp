extern "C"
{
#include <lua/lua.h>   // Lua ���Խ�����
#include <lua/lualib.h>  // Lua ��׼��
#include <lua/lauxlib.h>  // Lua��������
};
#include <iostream>
#include <string>

int main()
{
    lua_State * s = luaL_newstate();            // ����һ�������
    luaL_openlibs(s);                           // �� Lua ���ӿ�
    // ��Ҫ �� demo3.lua �ŵ�Working Directory ���棬�ſ��Զ���
    int ret = luaL_dofile(s, "../../src/LearnLua2/demo3.lua");                // ִ���ļ��е�Դ����

    if(0 != ret)
    {
        std::string strErr = lua_tostring(s, -1);
        std::cout << strErr << std::endl;
        lua_pop(s, 1);
    }
    
    lua_getglobal(s, "show");  //               // ��Luaȫ�ֱ�����ջ
    lua_pushstring(s, "It is from C++");        // ���ַ�����ջ
    lua_call(s, 1, 1);                          // ���� Lua����
    const char *result = lua_tostring(s, -1);   // ��ȡջ���ķ���ֵ

    std::cout << "C++ has got: " << result << std::endl;
    lua_pop(s, 1);

    lua_close(s);                                // �ر������
    return 0;
}