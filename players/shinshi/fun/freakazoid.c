inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
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
  set_hp(500+ random(100));
  set_ac(17 + random(10));
  set_wc(30 + random(5));
  set_al(0);
  add_money(random(3000)+2000);
  	add_spell("freakin","          $HK$#MN# computes some computer code into his head and blasts it against you.$N$\n", "#MN# blasts #TN# with a bit of computer generated code.\n", 15,50,"other|electric");
  }