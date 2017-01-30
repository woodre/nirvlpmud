inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/herospandex.c"), this_object()); 
  command("wear spandex", this_object());
  set_name("freakazoid");
  set_alt_name("freak");
  set_race("toon");
  set_alias("toon freakazoid");
  set_short(HIC+"Freakazoid"+NORM+" the "+HIR+"Spandex Hero"+NORM);
  set_long("\
   Freakazoid is a blue skin super human. His hair is just black with a\n\
  white stripe down the center. He is wearing red spandex with a lightning\n\
  symbol on the front. Running around with his arms straight out in of him\n\
  making noises, he looks to save the world. He looks around wondering what\n\
  to do next.\n");
  set_level(20);
  set_hp(450+ random(50));
  set_ac(15+ random(2));
  set_wc(25+ random(5));
  set_al(0);
  add_money(random(1500)+2500);
  set_aggressive(1);
  }