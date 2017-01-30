#include "../x.h"
void reset(status x)
{
 if(!x) set_light(1);
}

string short()
{
 return BOLD+"THE VOID"+NORM;
}

void init()
{
 add_action("cmd_green", "green");
}

void long()
{
 write("\n\n\tA pocket dimension in the fabric of reality.\nType 'green'.\n");
}

status no_light_damage() { return 1; }

int cmd_green()
{
 TP->MP("to the village green#/room/vill_green");
 return 1;
}
