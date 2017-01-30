
#include "/players/maledicta/ansi.h"
inherit "/obj/generic_heal.c";

#define rand_val (41 + random(20))

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("kit");
  add_alias("medical kit");
  add_alias("medical");
  set_short(HIR + "Medical Kit" + NORM);
  set_long("\
This is a small box with a medical symbol imprinted on its lid. Inside\n\
are numerous tools and items used for healing. You can 'medicate' and\n\
heal your wounds.\n");
  set_type("uses");
  set_msg("You open the medical kit and apply some of the contents to your wounds.\n");
  set_msg2(" uses a medical kit.\n");
  add_cmd("use");
  set_heal(rand_val, 0);
  set_charges(3);
  set_soak(4);
  set_stuff(4);
  set_value(450);
  set_msg_soaked(HIR+"You are too soaked to use it!"+NORM);
  set_msg_stuffed(HIR+"You are too stuffed to use it!"+NORM);
  set_msg_precharges(BOLD+BLK+"[");
  set_msg_postcharges("]"+NORM);
  set_type_single("use"); /* verte */
}

void
init()
{
  ::init();
  add_action("cmd_medicate", "medicate");
}

int cmd_imbibe(string arg)
{
  hp_heal=rand_val;
  sp_heal=rand_val;
  return ::cmd_imbibe(arg);
}

int cmd_medicate(string arg)
{
  return cmd_imbibe("medical kit");
}
query_save_flag(){
  return 1;
  }
