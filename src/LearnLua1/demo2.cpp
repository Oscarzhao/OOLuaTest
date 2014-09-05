extern "C"
{
#include <lua/lua.h>   // Lua ���Խ�����
#include <lua/lualib.h>  // Lua ��׼��
#include <lua/lauxlib.h>  // Lua��������
};
#include <iostream>
#include <string>

int divide(lua_State * s) // �� Luaʹ�õĺ���ͨ��ԭ��
{
    double a = lua_tonumber(s, -2);   // ȡ�õ�һ������
    double b = lua_tonumber(s, -1);   // ȡ�õڶ�������
    int quot = int(a)/int(b);
    int rem = int(a)%int(b);
    lua_pushnumber(s, quot);   // ����һ������ֵ��ջ
    lua_pushnumber(s, rem);    // ���ڶ�������ֵ��ջ
    return 2;
}

int main()
{
    lua_State * s = luaL_newstate();            // ����һ�������
    luaL_openlibs(s);                           // �� Lua ���ӿ�
    
    lua_register(s, "div", divide);             // �������ע�����
    // ��Ҫ�� demo2.lua �ŵ�Working Directory ���棬�ſ��Զ���
    int ret = luaL_dofile(s, "../../src/LearnLua1/demo2.lua");                // ִ���ļ��е�Դ����

    if(0!=ret)
    {
        std::string strErr = lua_tostring(s, -1);
        std::cout << strErr<< std::endl;
        lua_pop(s, 1);
    }


    //std::string error = lua_tostring(s, -1);
    //std::cout << error;

    lua_close(s);                                // �ر������
    return 0;
}