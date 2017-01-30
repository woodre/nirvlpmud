/*  Object for summoning pets */

inherit "obj/treasure";
#include "/players/saber/closed/bard/extra.h"
#include "/players/saber/closed/bard/pet/pet.c"

reset(arg)  {
   if (arg) return;
   set_id("circle");
   set_short(BOLD+"A "+HIB+"blue"+NORM+BOLD+" circle of power"+NORM);
   set_alias("circle of power");
   set_long(
    "A circle of "+HIB+"blue power"+NORM+" floating about six inches off of the floor.\n"+
    "If you stand within it, you can summon an animal companion.\n"+
    "Type: < summon > < animal # > < animal name > to summon an animal companion.\n"+
    "Type: < companion_list > for help.\n");
   set_weight(300);
   set_value(0);
}

init()  { add_action("summon_pet","summon");  }
