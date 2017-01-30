#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("walmart cashier");
  set_race("human");
  set_alias("cashier");
  set_alt_name("bob");
  set_short( BOLD + GRN + "Bob" + NORM + ", a " + BOLD + BLU + "Wal-Mart" + NORM + " cashier");
  set_long("\
This Wal-Mart associate has worked here for over 25 years.\n\
He is wearing a maroon vest for cashier of the month and there\n\
is a 25 year pin on his name tag.\n");
  set_level(30);
  set_hp(10000);
  set_wc(60);
  set_ac(60);
  set_al(1000);
  set_chat_chance(1);
  load_chat(query_name()+" asks, \"Did you find everything you needed today?\"\n");
}
