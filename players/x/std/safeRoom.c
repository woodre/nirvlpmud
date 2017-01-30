/* Safe for darkness-dwellers, i.e. Vampire .. */
#include "../x.h"

inherit ROOM;

void reset(status x)
{
 if(x) return;
 ::reset();
 set_light(1);
}

int no_light_damage() { return 1; }
