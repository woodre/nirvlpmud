inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/cottonshirt.c"), this_object()); 
  command("wear shirt", this_object());
  set_name("plucky");
  set_alt_name("duck");
  set_race("toon");
  set_alias("toon plucky");
  set_short(GRN+"Plucky"+NORM+" the "+HIG+"Duck"+NORM);
  set_long("\
   A younger duck with dark green feathers and a soft orange beak. He is\n\
  wearing a small cotton shirt. The shirt barely comes down past his belly.\n\
  His little fan of a tail sticks out past the back of his shirt. He has\n\
  small orange and stubby legs with huge webbed feet. He wanders around\n\
  looking for what mischeif to get into next.\n");
  add_spell("pluckybill","#MN# $HK$bites$N$ YOU really hard with his $Y$beak$N$.\n",
                       "#MN# $HK$bites$N$ #TN# really hard with his $Y$beak$N$.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(1500)+2300);
  }