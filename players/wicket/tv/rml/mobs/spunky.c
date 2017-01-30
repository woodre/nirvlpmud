inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/rml/armor/spunkycollar.c"), this_object()); 
  command("wear collar", this_object());
  set_name("spunky");
  set_alt_name("dog");
  set_race("toon");
  set_alias("toon spunky");
  set_short(HIW+"Sp"+HIK+"un"+HIW+"ky"+NORM+"" );
  set_long("\
   A sweet little dog and pet to Rocko, he is a friendly companion. \n\
  He loves turning circles and chasing his butt, he is not the smartest\n\
  of the canine kingdom.\n");
  add_spell("spunkypee","#MN# $HY$urinates$N$ on your leg causing you to $Y$slip $N$and $R$fall!$N$.\n",
                        "#MN# $HY$urinates$N$ on #TN# \'s leg causing them to $Y$slip $N$and $R$fall!$N$.\n",
                        30,30,0,0);
  set_level(19);
  set_hp(560+ random(40));
  set_ac(15+ random(3));
  set_wc(22+ random(5));
  set_al(0);
  add_money(random(2500)+500);
  }