#include "/sys/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if (arg) return;
    set_name("whale meat");
    add_alias("meat");
    set_short(RED + "A bloody chunk of whale meat" + NORM);
    set_long("This is a steaming chunk of whale meat which appears to be perfectly fresh\n"+
             "but has a somewhat sulphurous odor to it. It is raw, but is rather warm to\n"+
             "the touch, and some of the exposed surfaces have been singed a bit.\n");
    set_type("chunks");
    set_type_single("chunk");
    set_msg(HIY+"Not bad, despite being totally burned on one side and raw on the other.\n"+NORM);
    set_msg2(" takes a bite out of a chunk of whale meat.\n");
    add_cmd("eat");
    set_heal(50,50);
    set_charges(4);
    set_soak(0);
    set_stuff(13);
    set_value(400);
}

query_save_flag()
{
    return 1;
}


