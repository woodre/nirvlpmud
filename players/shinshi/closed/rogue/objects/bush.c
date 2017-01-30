#include <ansi.h>
inherit "/obj/treasure.c";

id(str) { return str == "bush" || str == "shinshi_bush"; }

short() { return HIG+"A bush with berries"+NORM; }

long()
{
	write("A bush covered in berries. Maybe you could 'pick' the 'berries' off of it.\n");
}

get() { return 0; }