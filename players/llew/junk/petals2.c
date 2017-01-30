#include "/players/llew/closed/ansi.h"
inherit "obj/treasure";

reset(arg)
{   if (arg) return;
   set_id("petals");
   set_short("Red "+RED+"rose"+NORM+" petals");
   set_long("Many soft red "+RED+"rose "+NORM+"petals blowing in the breeze.\n");
   call_out("fade",random(240)+60);
}

get() {
    write("You touch the silky petals but they slip away...\n");
    return 1;
}

fade() {
   destruct(this_object());
}
