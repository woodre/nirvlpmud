inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/familyguy/armors/mjeans.c"), this_object()); 
  command("wear jeans", this_object());
  move_object(clone_object("/players/wicket/tv/familyguy/armors/mshirt.c"), this_object()); 
  command("wear shirt", this_object());
  move_object(clone_object("/players/wicket/tv/familyguy/armors/mglasses.c"), this_object()); 
  command("wear glasses", this_object());
  move_object(clone_object("/players/wicket/tv/familyguy/armors/mshoes.c"), this_object()); 
  command("wear shoes", this_object());
  set_name("meg");
  set_alt_name("griffin");
  set_race("toon");
  set_alias("toon meg");
  set_short(HIM+"Meg Griffin"+NORM);
  set_long("\
   A young girl that is full of depression, She is part of the Griffin family.\n\
  She has fat chubby lips and a poofed out belly. She seems to be of the nerdy\n\
  type and is very annoying. She is wearing a small beanie cap and some blue\n\
  jeans, Her glasses just the round coke bottle frames that just make her ugly.\n");
  add_spell("nutkick","#MN# $HW$SWIFTLY$N$ kicks you in the $HR$Groin$N$.\n",
                       "#MN# $HW$SWIFTLY$N$ kicks #TN#\ in the groin causing $Y$MASSIVE DAMAGE$N$.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(2000)+3000);
  }