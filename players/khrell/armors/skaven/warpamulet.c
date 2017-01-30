#include <ansi.h>
#define ENV environment(this_object())
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("amulet");
set_short(GRN+"Warpstone"+NORM+HIK+" Amulet"+NORM);
set_long(
  "A small chunk of refined"+GRN+" warpstone"+NORM+" set into a heavy \n"+
  "bronze chain.\n");
set_type("amulet");
set_ac(1);
set_params("magical",0,20,0);
set_weight(1);
set_value(10000);
}

do_special(owner){
  if(random(100) < 10)
  {
    tell_object(owner,
      HIK+"The Warpstone's energy invigorates your mind yet your body feels weaker!\n"+NORM);
    owner->add_spell_point(5);
    owner->add_hit_point(-5);
    return 1;
  }
  return 0;
}
