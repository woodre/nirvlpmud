inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/rml/armor/rockoshoes.c"), this_object()); 
  command("wear shoes", this_object());
  move_object(clone_object("/players/wicket/tv/rml/armor/rockoshirt.c"), this_object()); 
  command("wear shirt", this_object());
  set_name("rocko");
  set_alt_name("wallaby");
  set_race("toon");
  set_alias("toon rocko");
  set_short(CYN+"Ro"+YEL+"ck"+CYN+"o"+NORM+"\, the"+WHT+" protagonist"+NORM);
  set_long("\
   A wallaby that moved from Australia to O Town, he is a little foreign to the\n\
  area. He has a really strong foriegn accient and very off outlook on life.\n\
  He seems to be very cautious with every movement but is very friendly in nature.\n");
  add_spell("rockokick","#MN# leans back on his tail as he kicks you with his feet causing you to fly backwards.\n",
                        "#MN# leans back on his tail as he kicks #TN# causing them to fly backwards.\n",
                        50,30,0,0);
  set_level(19);
  set_hp(570+ random(30));
  set_ac(18+ random(1));
  set_wc(28+ random(4));
  set_al(0);
  add_money(random(1500)+2500);
  }