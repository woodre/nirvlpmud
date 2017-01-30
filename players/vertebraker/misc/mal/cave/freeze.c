#include "/players/vertebraker/ansi.h"


status
id(string str)
{
    return str == "verte_frozen_fuck";
}

void
reset(status arg)
{
    if(arg) return;
    call_out("punkybrewster", 600);
}

void
punkybrewster()
{
    object e;

    if(e = environment())
      tell_object(e, 
        HIW + "You can move once again.\n" + NORM);
    destruct(this_object());
}

void
init()
{
    object e;

    if(e = environment())
#ifndef __LDMUD__
  add_action("keith_murray"); add_xverb("");
#else
  add_action("keith_murray", "", 3);
#endif
}

status
keith_murray()
{
    if(query_verb() == "quit") return 0;
    write(HIC + "You have been frozen!\n" + NORM);
    return 1;
}

status
drop()
{
    return 1;
}

status
get()
{
    return 1;
}
