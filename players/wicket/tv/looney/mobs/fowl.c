inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/greenshirt.c"), this_object()); 
  command("wear shirt", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/dressypants.c"), this_object()); 
  command("wear pants", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/sneakers.c"), this_object()); 
  command("wear sneakers", this_object());
  set_name("fowlmouth");
  set_alt_name("rooster");
  set_race("toon");
  set_alias("toon babs");
  set_short(HIW+"Fowlmouth"+NORM+" the "+YEL+"Rooster"+NORM);
  set_long("\
   A young rooster with a cocky attitude is wearing loose fitting green\n\
  shirt. White pants hug his waist down to his feet. He is wearing a nice\n\
  pair of white and black sneakers. His Wattle and comb on his head are both\n\
  bright red. A fan of tail feathers stick out the back of his pants that\n\
  wave around as he struts his stuff. He loves to romance the ladies\n");
  add_spell("suckerfowl","#MN# throw a $M$sucker punch$N$ to the side of YOUR face.\n",
                       "#MN# throw a $M$sucker punch$N$ to the side of #TN#\'s face.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(1000)+1500);
  }