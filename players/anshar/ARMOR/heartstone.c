#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "obj/armor";

reset(arg)
{
  ::reset(arg);
  set_name("heartstone");
  set_short(HIR+"Bloodstone"+NORM);
  set_type("armor");
  set_long("This is the heartstone of the bloodstones of protection.\n\
It will fix to the chest when worn, draining the wearer to\n\
power the potent spells of protection. It will only be \n\
effective when combined with all six of of the other\n\
bloodstones.\n");
  set_ac(0);
  set_weight(0);
  set_value(1000);
}

id(str)
{
  return str == "heartstone" ||
         str == "bloodstone" ||
         str == "armor" ||
         str == "bloodstone1";
}

init()
{
  ::init();
  add_action("wear","wear");
  add_action("remove","remove");
}

wear(str)
{
  int X;
  object me;
  me =this_player();
  X = this_player()->query_hit_points();
  if(str = "heartstone")
  {
    this_player()->add_hit_points(-200);
    this_player()->add_spell_points(-200);
    if( X < 1) die(me);
    write(HIR + "Energy" + NORM +
          " blasts from the heartgem! A protective field surrounds you!\n"+
          "You feel physically and mentally weakened.\n");
    say(HIR+"Energy"+NORM+
        " blasts from the heartgem, coalescing in a protective field.\n");
    this_player()->set_ac(10+random(15));
    return 1;
  }
}

remove(str)
{
  if(str == "heartstone")
  {
    this_player()->set_ac(0);
    return 1;
  }
}

die(ob)
{
  object blood;
  blood = "/players/anshar/ARMOR/blood.c";
  write("You cannot contain the"+HIR+" energy"+NORM+
        "! The life drains from your body!\n");
  blood->zap_object(ob);
  return 1;
}
