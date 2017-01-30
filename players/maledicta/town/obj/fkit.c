#include "/players/maledicta/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("kit");
  add_alias("firstaid");
  add_alias("firstaid kit");
  set_short(HIG + "FirstAid Kit" + NORM);
  set_long("  A small pouch containing a few medical tools.  It will\n" +
         "provide limited healing ability to the user.  You can 'apply'\n"+
         "the kit for healing.\n");
  set_type("uses");
  set_msg("You quickly apply the contents of the first aid kit to your wounds.\n");
  set_msg2(" uses a first-aid kit.\n");
  add_cmd("apply");
  set_heal(15,15);
  set_charges(9);
  set_soak(3);
  set_stuff(3);
  set_value(200);
  set_msg_soaked(HIR+"You are too soaked to use it!"+NORM);
  set_msg_stuffed(HIR+"You are too stuffed to use it!"+NORM);
  set_msg_precharges(BOLD+BLK+"[");
  set_msg_postcharges("]"+NORM);
  set_type_single("use"); /* verte */
}

int query_weight()
{
  switch(charges) {
    case 7..20000: return 3;
    case 4..6: return 2;
    case 1..3: return 1;
    default: return 0;
  }
}

query_save_flag(){
  return 1;
  }
