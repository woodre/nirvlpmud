#include "/players/vertebraker/define.h"


id(str) { return str == "horse_extra_look"; }

drop() { return 1; }
get() { return 1; }

extra_look()
{
    if(!USER) return;
    if(!USER->query_mounted())
    {
       destruct(this_object());
       return;
    }
    return USER->QN + " is riding a warhorse";
}
