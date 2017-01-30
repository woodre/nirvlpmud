inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
   move_object(clone_object("/players/wicket/tv/rml/armor/edpants.c"), this_object()); 
  command("wear pants", this_object());
  move_object(clone_object("/players/wicket/tv/rml/armor/edshirt.c"), this_object()); 
  command("wear shirt", this_object());
  move_object(clone_object("/players/wicket/tv/rml/armor/edtie.c"), this_object()); 
  command("wear tie", this_object());
  set_name("ed");
  set_alt_name("bighead");
  set_race("toon");
  set_alias("toon ed");
  set_short(GRN+"Ed Bighead"+NORM+"" );
  set_long("\
   A neighnor of Rocko, He is very mean and grumpy old frog. \n\
  Nothing but complaining and crying comes from this oversized\n\
  frogs mouth.\n");
  add_spell("tonguesmack","#MN# $HK$lashes out his $HR$tongue$N$ smacking you across the face $R$tearing flesh$N$.\n",
                        "#MN# $HK$kasses$N$ out his $HR$tongue$N$ smacking #TN# across the face $R$tearing flesh$N$.\n",
                        40,30,0,0);
  set_level(19);
  set_hp(560+ random(40));
  set_ac(15+ random(3));
  set_wc(22+ random(5));
  set_al(0);
  add_money(random(2500)+1000);
  }