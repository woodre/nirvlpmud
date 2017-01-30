	/* hot chocolate */

#include <ansi.h>
inherit "/obj/generic_heal.c";

void reset(int arg)
{
    ::reset(arg);
    if(arg) return;
    set_name("coco");
    add_alias("mug"); 
    add_alias("chocolate");
    add_alias("hot chocolate"); 
    set_short("a mug of hot chocolate.");
    set_long("A soothing mug of hot chocolate to melt away worries.\n"+
             "Several marshmellows float lazily across its surface.\n");
    set_type("sips");
 /*   set_singular("sip");*/
    set_msg("You sip the hot chocolate and feel the warmth spread through to your toes.\n");
    set_msg2(" sips from a mug of hot chocolate. \n");
    add_cmd("sip");
    add_cmd("drink");
    set_heal(0,0);
    set_charges(4);
    set_soak(1);
    set_value(0);
}

