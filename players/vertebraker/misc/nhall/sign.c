#include <ansi.h>
inherit "/obj/treasure";

void
reset(int arg)
{
    if(arg) return;
    set_no_clean(1);
    set_id("sign");
    set_short("A sign sticks out of the ground ["+BOLD+"read me"+NORM+"]");
    set_long("\t\tKulgar's Weapon Repair\n\n\
\tRepair      50 coins\n\
\tSharpen    100 coins\n\n");
    set_weight(666);
}

status
get()
{
    return 0;
}
