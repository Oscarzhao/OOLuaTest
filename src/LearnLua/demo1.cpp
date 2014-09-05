extern "C"
{
#include <lua/lua.h>   // Lua ���Խ�����
#include <lua/lualib.h>  // Lua ��׼��
#include <lua/lauxlib.h>  // Lua��������
};

char * code = "for i = 0, 5 do print(\'Hello, World!\') end";

int main()
{
    lua_State * s = luaL_newstate();            // ����һ�������
    luaL_openlibs(s);                           // �� Lua ���� ��
    luaL_dostring(s, code);                     // ִ���ַ�����Դ����
    lua_close(s);                                // �ر������

    getchar();
    return 0;
}